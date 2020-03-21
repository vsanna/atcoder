#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;
#define dump(x) cout << #x << " = " << (x) << endl;

// ==========
class RadixTree {
 public:
  string prefix;
  map<char, RadixTree *> children;

  RadixTree(string prefix)
      : prefix(prefix), children(map<char, RadixTree *>{}){};
  RadixTree() : prefix(""), children(map<char, RadixTree *>{}){};

  void insert(string s) {
    if (s == "") {
      if (children.count('$') == 0) {
        children['$'] = new RadixTree("$");
        return;
      }
    }

    if (children.count(s[0])) {
      // next位置に新しいnodeを挿入して、その子にnextを移す。またnodeの子に残りの要素を入れる
      RadixTree *next = children[s[0]];
      string lcp = getlcp(s, next->prefix);
      string nextPrefixToSearch =
          s.substr(lcp.length(), s.length() - lcp.length());

      /*
      s = "abcdef"
      next->prefix = "abc"
      -> next

      s = "a"
      next->prefix = "a"
      -> branchpoint("a") -> {newbranch("$")}

      s = "abcdef"
      next->prefix = "akk"
      -> branchpoint(lcp("a")) -> {existingbranch("kk"), newbranch("bcdef")}

      s = "abcdef"
      next->prefix = "abcxxx"
      -> branchpoint(lcp("abc")) -> {existingbranch("xxx"), newbranch("def")}
      s = "abc"
      next->prefix = "abcxxx"
      -> branchpoint(lcp("abc")) -> {existingbranch("xxx"), newbranch("$")}
      */

      if (s.length() > next->prefix.length() &&
          lcp.length() == next->prefix.length()) {
        next->insert(nextPrefixToSearch);
        return;
      }

      if (s == next->prefix) {
        next->children['$'] = new RadixTree("$");
        return;
      }

      RadixTree *branchPoint = new RadixTree(lcp);
      RadixTree *newBranch;
      if (nextPrefixToSearch.length() == 0) {
        newBranch = new RadixTree("$");
      } else {
        newBranch = new RadixTree(nextPrefixToSearch);
        newBranch->children['$'] = new RadixTree("$");
      }
      RadixTree *existingBranch = next;
      string newPrefixForExistingBranch = next->prefix.substr(lcp.length());
      existingBranch->prefix = newPrefixForExistingBranch;

      children[s[0]] = branchPoint;
      branchPoint->children[existingBranch->prefix[0]] = existingBranch;
      branchPoint->children[newBranch->prefix[0]] = newBranch;

      dump(branchPoint->prefix);
      dump(existingBranch->prefix);
      dump(newBranch->prefix);

    } else {
      RadixTree *newBranch = new RadixTree(s);
      newBranch->children['$'] = new RadixTree("$");
      this->children[s[0]] = newBranch;
    }
  }

  // has as word(can find $)
  bool has(string s) {
    pair<RadixTree *, string> result = trackOnPath(s);
    if (result.first == nullptr) return false;

    string finalpath = result.second + result.first->prefix;
    return finalpath.length() == s.length() &&
           result.first->children.count('$') > 0;
  }

  bool contain(string s) {
    pair<RadixTree *, string> result = trackOnPath(s);
    return result.first != nullptr;
  }

  vector<string> commonPrefixWords(string prefix) {
    vector<string> results;
    pair<RadixTree *, string> result = trackOnPath(prefix);
    RadixTree *node = result.first;

    if (node == nullptr) {
      return results;
    }

    // node, additional prefix
    queue<pair<RadixTree *, string>> queue;
    queue.push(make_pair(node, result.second));
    while (queue.size()) {
      pair<RadixTree *, string> current = queue.front();
      queue.pop();
      string word = current.second + current.first->prefix;
      if (current.first->children.count('$') > 0) {
        results.push_back(word);
      }

      for (auto kv : current.first->children) {
        RadixTree *nextnode = kv.second;
        queue.push(make_pair(nextnode, word));
      }
    }
    return results;
  }

  void bfs() {
    queue<RadixTree *> queue;
    RadixTree *separator = new RadixTree();
    queue.push(this);
    queue.push(separator);
    while (queue.size() > 0) {
      RadixTree *current = queue.front();
      queue.pop();
      if (current == separator) {
        cout << endl;
        if (queue.size() == 0) {
          return;
        }
        queue.push(separator);
        continue;
      }
      cout << current->prefix << ", ";
      for (auto kv : current->children) {
        queue.push(kv.second);
      }
    }
  }

 private:
  pair<RadixTree *, string> trackOnPath(string s) {
    return trackOnPathHelper(s, "");
  }

  // そのnodeまでのprefixとノードを返す
  // 最終的なpathは返り値のpath + 返り値のnode->prefix
  pair<RadixTree *, string> trackOnPathHelper(string s, string prefixOnPath) {
    if (s.length() == 0) {
      return make_pair(this, prefixOnPath);
    }

    if (children.count(s[0]) > 0) {
      RadixTree *next = children[s[0]];
      string lcp = getlcp(s, next->prefix);
      string nextPrefixToSearch =
          s.substr(lcp.length(), s.length() - lcp.length());
      /*
      s = "abcdef"
      next->prefix = "abcxxx"
      -> NG

      s = "abc"
      next->prefix = "abcxxx"
      -> OK, but not has $

      s = "abcdef"
      next->prefix = "abc"
      -> OK and it's still not clear if we can finish walking
      s = "abcdef"
      next->prefix = "akk"
      -> NG
      */

      if (s.length() > next->prefix.length()) {
        if (lcp.length() == next->prefix.length()) {
          return children[s[0]]->trackOnPathHelper(nextPrefixToSearch,
                                                   prefixOnPath + prefix);
        } else {
          return make_pair(nullptr, "");
        }
      } else {
        if (lcp.length() == s.length()) {
          return children[s[0]]->trackOnPathHelper(nextPrefixToSearch,
                                                   prefixOnPath + prefix);
        } else {
          return make_pair(nullptr, "");
        }
      }
    } else {
      return make_pair(nullptr, "");
    }
  }

  // longest common prefix
  string getlcp(string a, string b) {
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) {
      i++;
    }
    return a.substr(0, i);
  }
};
// ==========

/*
RadixTree suffixtree = new RadixTree()

*/
int main() {
  RadixTree *root = new RadixTree();
  root->insert("abc");
  root->insert("abb");
  root->insert("acb");
  root->insert("bb");
  root->insert("abcde");
  root->insert("abcdr");
  root->insert("cats");
  root->insert("cat");
  root->bfs();

  for (string key : vector<string>{
           //  "",
           //  "a",
           //  "ab",
           //  "abc",
           //  "abb",
           //  "b",
           //  "bb",
           //  "abcde",
           //  "abcdr",
           //  "cats",
           //  "cat",
           //  "ca",
           "o",
           "oabc",
       }) {
    cout << key << " contain " << root->contain(key) << endl;
    cout << key << " has     " << root->has(key) << endl;
  }

  for (string word : root->commonPrefixWords("a")) {
    cout << word << ", ";
  }
  cout << endl;
  for (string word : root->commonPrefixWords("ab")) {
    cout << word << ", ";
  }
  cout << endl;
  for (string word : root->commonPrefixWords("abc")) {
    cout << word << ", ";
  }
  cout << endl;
  for (string word : root->commonPrefixWords("b")) {
    cout << word << ", ";
  }
  cout << endl;
  for (string word : root->commonPrefixWords("c")) {
    cout << word << ", ";
  }
  cout << endl;

  root = new RadixTree();

  cout << "====" << endl;
  root->insert("umnp");
  root->insert("utulg");
  root->insert("u");
  root->insert("uagg");
  root->bfs();
  return 0;
}