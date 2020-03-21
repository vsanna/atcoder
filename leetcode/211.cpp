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
const int IINF = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define dump(x) cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl

template <typename T>
class ResultObject {
 public:
  T result;
  bool err;  // TODO error object
  ResultObject(T result, bool err) {
    this->result = result;
    this->err = err;
  }
};

void chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

class DictTreeNode {
 public:
  map<char, DictTreeNode *> children;
  DictTreeNode() : children(map<char, DictTreeNode *>{}) {}
};

class WordDictionary {
  DictTreeNode *root;

 public:
  /** Initialize your data structure here. */
  WordDictionary() { root = new DictTreeNode(); }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    DictTreeNode *current = root;
    for (char c : word) {
      if (current->children[c] == nullptr) {
        current->children[c] = new DictTreeNode();
      }
      current = current->children[c];
    }
    if (current->children['$'] == nullptr) {
      current->children['$'] = new DictTreeNode();
    }
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return searchTree(root, word, 0); }

  bool searchTree(DictTreeNode *current, string word, int pos) {
    if (pos == word.length() - 1) {
      char c = word[pos];
      if (c == '.') {
        for (char nextc = 'a'; nextc <= 'z'; nextc++) {
          if (current->children[nextc] != nullptr) {
            bool hasEnd = current->children[nextc] != nullptr &&
                          current->children[nextc]->children['$'] != nullptr;
            if (hasEnd) {
              return true;
            }
          }
        }
        return false;
      } else {
        return current->children[word[pos]] != nullptr &&
               current->children[word[pos]]->children['$'] != nullptr;
      }
    }

    char c = word[pos];
    if (c != '.') {
      if (current->children[c] == nullptr) {
        return false;
      } else {
        return searchTree(current->children[c], word, pos + 1);
      }
    } else {
      bool hasNext = false;
      for (char nextc = 'a'; nextc <= 'z'; nextc++) {
        if (current->children[nextc] != nullptr) {
          hasNext = true;
          bool result = searchTree(current->children[nextc], word, pos + 1);
          if (result) {
            return true;
          }
        }
      }
      if (!hasNext) {
        return false;
      }
    }

    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  WordDictionary *dict = new WordDictionary();
  dict->addWord("bad");
  dict->addWord("dad");
  dict->addWord("mad");
  dict->addWord("ba");
  cout << dict->search("pad") << endl;
  cout << dict->search("bad") << endl;
  cout << dict->search(".ad") << endl;
  cout << dict->search("..d") << endl;
  cout << dict->search("ba") << endl;
  cout << dict->search("bc") << endl;
  cout << dict->search("bd") << endl;
  cout << dict->search("ab") << endl;
  cout << dict->search(".a") << endl;
  cout << dict->search("b.") << endl;
  cout << dict->search("..") << endl;

  cout << "====" << endl;
  dict->addWord("aiueo");
  dict->addWord("kakikukeko");
  dict->addWord("sasisuseso");
  cout << dict->search("aiueo") << endl;
  cout << dict->search("ai..o") << endl;
  cout << dict->search(".....") << endl;
  cout << dict->search("sasi....so") << endl;
  cout << dict->search("aiuoo") << endl;
  cout << dict->search("ai.a.") << endl;
  cout << dict->search("..t..") << endl;
  cout << dict->search("sasa....so") << endl;
  cout << dict->search("sasa....so") << endl;
  cout << dict->search("") << endl;
  cout << dict->search(".") << endl;
  cout << dict->search("...") << endl;

  cout << "======" << endl;
  WordDictionary *dict2 = new WordDictionary();
  dict2->addWord("at");
  dict2->addWord("and");
  dict2->addWord("an");
  dict2->addWord("add");
  cout << dict2->search("a") << endl;
  cout << dict2->search(".at") << endl;
  dict2->addWord("bat");
  cout << ".at: " << dict2->search(".at")
       << endl;  // showing false (should be true)
  cout << dict2->search("an.") << endl;
  cout << dict2->search("a.d.") << endl;
  cout << dict2->search("b.") << endl;
  cout << dict2->search("a.d.") << endl;
  cout << dict2->search(".") << endl;
  // cout << dict->search("aiuoo") << endl;
  // cout << dict->search("ai.a.") << endl;
  // cout << dict->search("..t..") << endl;
}