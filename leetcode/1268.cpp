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

    if (children.count(s[0]) > 0) {
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

      // find next path
      if (s.length() > next->prefix.length() &&
          lcp.length() == next->prefix.length()) {
        next->insert(nextPrefixToSearch);
        return;
      }

      // just finish at next
      if (s == next->prefix) {
        next->children['$'] = new RadixTree("$");
        return;
      }

      // couldn't find path. so separate and insert
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

    } else {
      RadixTree *newBranch = new RadixTree(s);
      newBranch->children['$'] = new RadixTree("$");
      children[s[0]] = newBranch;
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
    return commonPrefixWords(prefix, IINF);
  }

  vector<string> commonPrefixWords(string prefix, int searchLimit) {
    vector<string> results;
    pair<RadixTree *, string> result = trackOnPath(prefix);
    RadixTree *node = result.first;

    if (node == nullptr) {
      return results;
    }

    // node, additional prefix
    // NOTE: stackにすると辞書昇順に回収できる
    stack<pair<RadixTree *, string>> stack;
    stack.push(make_pair(node, result.second));
    while (stack.size() && results.size() < searchLimit) {
      pair<RadixTree *, string> current = stack.top();
      stack.pop();
      string word = current.second + current.first->prefix;
      if (current.first->children.count('$') > 0) {
        results.push_back(word);
      }

      // for (auto kv : current.first->children) {
      //   RadixTree *nextnode = kv.second;
      //   queue.push(make_pair(nextnode, word));
      // }
      for (char c = 'z'; c >= 'a'; c--) {
        if (current.first->children.count(c) > 0) {
          RadixTree *nextnode = current.first->children[c];
          stack.push(make_pair(nextnode, word));
        }
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
          return next->trackOnPathHelper(nextPrefixToSearch,
                                         prefixOnPath + prefix);
        } else {
          return make_pair(nullptr, "");
        }
      } else {
        if (lcp.length() == s.length()) {
          return next->trackOnPathHelper(nextPrefixToSearch,
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

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    // preparation
    RadixTree *root = new RadixTree();
    for (string p : products) {
      root->insert(p);
    }

    vector<vector<string>> result{};

    for (int i = 1; i <= searchWord.length(); i++) {
      string substr = searchWord.substr(0, i);
      result.push_back(root->commonPrefixWords(substr, 3));
    }

    return result;
  }
};

int main() {
  Solution s = Solution();
  vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};

  // for (vector<string> row : s.suggestedProducts(products, "mouse")) {
  //   for (string c : row) {
  //     cout << c << ", ";
  //   }
  //   cout << endl;
  // }

  // products = vector<string>{"havana"};

  // for (vector<string> row : s.suggestedProducts(products, "havana")) {
  //   for (string c : row) {
  //     cout << c << ", ";
  //   }
  //   cout << endl;
  // }

  products = vector<string>{"vsmadqkolyduhygaprdqhxzjrapvvvv",
                            "gnsgdxf",
                            "utulgnjlkotgccloguvktwaxzjwplmdnhvihum",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnei",
                            "utulgnjlkotgccloguvktwaxoaeogbsgegteviopb",
                            "utulgnjlkzqsbzvkoauvhnh",
                            "utulgnjlggueayqfanngdjnsgehwj",
                            "utulgnjlkotgvqieu",
                            "utulgnjlkotgccloguvktwaxoakxozjn",
                            "utmuklxtpgxdervbnzbgmccjccoycs",
                            "utulgnjlkotgccloguvktypqzymmtrzgpvhah",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwlvx",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoar",
                            "kmsrjmkuukyhwbpgxpejgcqpcgsgseerbp",
                            "utulgnjlkotgccloguvktwaxoaeogvv",
                            "esbxhykgbdkjwwvlgxltj",
                            "utulgnjlkotgccloguvktwaxquuohbwrgjcebwdixr",
                            "utzxzjzxioeamaxfvzurwimglzu",
                            "pxnokuo",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpu",
                            "utulgnjlkotgccloguvktwaxoapfgodyjitrins",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnw",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgxzknnbqgr",
                            "utyuhabivmnntumqhitxrphorqopssgxdsm",
                            "utulgnjlkotgcvhrlilruzgrvkkglwfocfehzh",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbs",
                            "kmclwrvk",
                            "xlisxvedubbilwymuhbomexpcsmfvtowvadoxxu",
                            "phsqsyjqxeiljhgxycpapkqlavk",
                            "cvk",
                            "utupstizwflwvmgaiumdmowhjsr",
                            "fus",
                            "cafvusslvaawrb",
                            "utsipqaypgwwipqmeetburywagj",
                            "rutpcaapvjkoiibcmwhtyex",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoal",
                            "utulgnjlkotgcclzkfzwupomzeuwjklgnvvjgip",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlbg",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlggcrsko",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpktctm",
                            "bkkecavljaqptalivkjpmeznobypskxsklik",
                            "utulgnjlkotgccloguvktwaxoaeogvzlqrbgf",
                            "tciykqznfynxocmfdyrajrakbvlfpgox",
                            "utulgnjlkotgccloguvktwaxoafiedq",
                            "iwtmzpzmumxbmx",
                            "qdypizxv",
                            "utulgnjlkotgccloguvktwjyg",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpknuym",
                            "utulgnjlkotgcclohqajnq",
                            "utulgnjlkakihrdycmqbgofiijshoze",
                            "utulgnjlkjchoopnwlzzxxhnhsvcblddfnvwafel",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwetkk",
                            "utulgnjlkotgccloguvktwaxoaeorbivmjlgtyhuota",
                            "undqysjlwjlhzohtshhqznmxcdastfhlrwdbyfm",
                            "utulgnjlkotgccloguvktwunrvdo",
                            "devwgwhyprthrjdaqusrbdndgdaxcklrvhrghzpk",
                            "utulgnjlkotgccldjzkjkykyiblgfltbhhe",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoav",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkby",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgnx",
                            "utulgnhmuwqr",
                            "utulgnjlkotgccloguvktwaxoaeogvtsubz",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwu",
                            "utulgnjlkotlczqiyxkaues",
                            "utulgnjlkotgccloguvktwaxvmkkocyo",
                            "essrqlgjkrjaayzttkwlvwwdvepm",
                            "dfuyxgzpydsqinsnjkt",
                            "sk",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbntrs",
                            "utulgnjlkotgcclogugjrghwermdgbxlldpfd",
                            "uazugxdbqqjqbwduxivxtdiyvheyreslwbmyacfcfma",
                            "ynxdlrofnaaamzsmebxiwohegshbowxoyrvme",
                            "utulgnwwlgnyxovnedpemuglpmdenhxxdyanuprd",
                            "utulgnjlkotgccloguvktwaxupfrxxxwdsd",
                            "ndumnexlqqbtooreattnhibhucyldmvt",
                            "komrvcl",
                            "utulgnjskqxvzfbrbnojeuzgsgbi",
                            "utulgnjlkotgccloguvktwhrxjmorbpwmdytjch",
                            "mjzeqelitxftczpllcgcdwbrgtxmfyb",
                            "ksgeyluhppaddondhgc",
                            "utulgnjlkotgcclswgbhprbtisuztpmvosapsmzao",
                            "utulgnjlkotgf",
                            "utulgnjlkotgfwyxlsjgllacymld",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnpqn",
                            "utulgnjlkotgccloguvktwhfni",
                            "utulgnjlkotgcclodug",
                            "utulgnjlkotgcclogcrfvumyaahcenikybwkxjppjuwv",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgpplgud",
                            "ghpgyiaavavthztpjchgjllrdhlrnfjwme",
                            "wlesdjzspxjcbfnodtsxl",
                            "ftgpsuwcqmofdpyxfcwdjbbgakbzyqvcg",
                            "wmbfnwixbtnuayoxssehabhrbvdyymkaocs",
                            "kunfcklqrjhdollzyhjg",
                            "utulgnjlkotgccloguvktwaxoaeogvp",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoah",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnor",
                            "utulgnjlyciphuyhlqmglsffkkyfyvvelnurmode",
                            "dypguyuxzjbxpclvzcgbohgwtllfmevybgczcyumpwuo",
                            "utulgnjlkotgcclogugbfyitsmmflcimwpummldpw",
                            "mvsxzfklguypsrkpnmvntpchcx",
                            "utulgnjlkotgccloguvktwaxoaaflmyadalkhkz",
                            "rnjftmxry",
                            "utulgnjlkotgcclogmysnkzaxlddfhaihcfrv",
                            "utulgnjlkotgccpdfmxltawcsmoktylqhlbdnrwlm",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwvziee",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbjusm",
                            "utulgnjlkotgccloguoljf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbd",
                            "utfqlnc",
                            "utulgnjlkotgccloguvktwawzhivexshqnkgvvpphf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlu",
                            "utulgnjlkotgcclorbjpaspmbuhqp",
                            "sazlasfuzoxg",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbny",
                            "utulgnjlkotgccvgqj",
                            "utulgnjlkotgccloguvktwaxoaeogvzqljhd",
                            "ecgwsubbui",
                            "utulgnjlkotgccrfjyjtaqi",
                            "pawokwnjurovmihsladrbkwxkpdduswrponatk",
                            "ezblwzrilwfcjvnasmtzso",
                            "ekqdugfmyjnbqefeorbaypcqxs",
                            "utulgnjlkotgcclobuxzogirrfdpbuxjejfofpo",
                            "kjzmhvdxtkjzrzsazmigqilixtcogtj",
                            "utulgnjlkotgccldtfgzrvqtnfjrmmylfesof",
                            "uwdjovpphryyrpyxemldhzkmmetaceoxgiseemxgar",
                            "utulgnjlkotgccloguvbekcs",
                            "cuprucyavitshrjvgtdnfqftw",
                            "ulynvxattqhevjadhbhpswozfoctauswnfj",
                            "nwluotzssluyvpf",
                            "idqnmhnkdehgvycznhjlhwyig",
                            "mzcikveabrvdtynkbhigvcmjwqtbla",
                            "hjrjiwumuhrraqrkmxkufvjwpvyvkkcylmc",
                            "utulgnjlkotgccloguvktwlqoilzjd",
                            "utulgnjlkotgccloguvktwaxoaeogpjbxgeaagfjo",
                            "jerkgaqyxtsjwawqunyriirnwarox",
                            "utibmuliyumbkxttleqwxencuyk",
                            "iswibazkfuczzbveezdiyuac",
                            "fkktqmwxidcdfahnqwqnw",
                            "exyfpfmjzgakogpnufew",
                            "utulgnjvbergkszcgibvqdwfmoujwvvgzvgvo",
                            "xzwycfgsvbjpdbqqwnkgxrheeutu",
                            "utulgajwidklidnddk",
                            "brkluarnqnxhdksiw",
                            "utulgnjlkotgccccihuhymrrtcpyhxbxrcsas",
                            "ygyepkkpttqazxjbpfk",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtgspmps",
                            "utulgnjlkotgcclogmvxxwmrmciqytq",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkkc",
                            "utulgnjlkotgccloguvktwaxoaeogfunv",
                            "zow",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkxmxml",
                            "mmfthjgvvgorgrd",
                            "jevrpakiwqxxifnajpdcdlqglnnalwifihutrz",
                            "utulgnjlkotgckuyzufsnfipwc",
                            "iykdstmvuaontqcddadldjmgw",
                            "utulgnjlkotgccljkrkeokjiesywqaxgvr",
                            "utulgnjlkotgccloguvktwaxoaeogrmyvaznzot",
                            "utulgnjlkosrhtgteokwlxrsm",
                            "utulgnjlkotgccloguvktwaxoaeogvzqzkkrcrugjd",
                            "r",
                            "qaoskkzcfiefemnf",
                            "utulgnjlkotgccloguvktwaxoaezddwpnpvnslqa",
                            "vjurawhjtlwytsogqvwdpeojopxutv",
                            "utulgnqebiiwbuueqse",
                            "utumehejudsigjacolisxegtegzo",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnosp",
                            "utulgnjlkotgcccnislait",
                            "utulgnjlgt",
                            "utulgnjlkotgcclockykbnfigttqp",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnofu",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtciyzjyv",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlozduvyxmhyb",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlggl",
                            "utulukx",
                            "utulgnjlkotgccloguvktwaxoidev",
                            "utulgnjlkotgccloguvktwalaafjonuoemllze",
                            "utulgnjlkotgccloguvktrwahdfvgbshw",
                            "ukdpjsnogirtwyffy",
                            "tndxyinnemiuqguigzfuztgcrjjnpptkbjhyfo",
                            "utulgnjlkotgccloguvktwaxoib",
                            "faljccfzctjecnaicvofio",
                            "uyxnwavopzycofkcridolmylgikxpzlq",
                            "utulgnjlkotgcclsmgqb",
                            "nmpmmbldbkctubifqgpfzgaxtcbfpvjgqhizwoxkopw",
                            "u",
                            "utulgnjlkbfhqskkbhssbtxvlodvscsnsrvalzm",
                            "miluljnowlrwoikspoowsmecyoxpqzucilgcjzevyr",
                            "umnpllhttf",
                            "utulgnjlkotgcclf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoao",
                            "utulgnjlkotgcclyqhmabtundhnysxelp",
                            "ljcridpvtgafadflnjguwmgksjfzihyqx",
                            "hekbxxcwzrtqsjovrwsn",
                            "utulgnjlkotgccloguvktwaxoaeogvzxbd",
                            "pfpcmpvikefvgowazugyzdozbu",
                            "cyotwihtbdsvvotpffxarybdhvtmpzedihyqtddflc",
                            "iuvn",
                            "nrdybnl",
                            "utulgnjlkotgccloguvnlvaholcs",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgltljgwiarv",
                            "aazqse",
                            "qualx",
                            "qzjzyt",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaxx",
                            "utulgnjllfaoletsmqwxhucduuxhbq",
                            "fvickpphhiembucfjtv",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaxg",
                            "mvgifsstqalozynscrfkinni",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaxj",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlwpi",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaxk",
                            "utulgnjlkotgccloguvktwaxoaeogvzgjnqunjdje",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlymcanevcuj",
                            "utulgnjlkotgccloguvktwaxoaeogqzshdtcab",
                            "ltguwbygbqyteuvejxluncbkrzwoeojcn",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpf",
                            "utulgnjlkotgccloguvktwaxoaeogvzqlgqwxzycy",
                            "wouhaqsblqomgkayjgmcbulgbdgukrmoomgtwoyqq",
                            "utulgnjlkotgcclogunkjbuthlp",
                            "utulgnjlkotgccloguvktwaxoaeogiehtfoblea",
                            "utulgnjlkotgcclogugwjtnwmotwrkwloxljcnswqun"};

  for (vector<string> row : s.suggestedProducts(
           products,
           "utulgnjlkotgccloguvktwaxoaeogvzqlgqwtpkbnoaxwwlwxitmrdoizupxnqtvlvv"
           "shqzmrgnzmrsjbpiugddrmljdfmgtwzlizrzkclqwgzlsjfjlggptosvbzvxbyerlbd"
           "feoeoewriznnhajvoxeqgebucuyvkrlpyngzbgezthhkgprzuecvgcdkzdldazpzjec"
           "rxendmrxukqrbcslsmyeheiterutvmjjvntmsvsnpcmjiludnuqeabldzjzubccrbhc"
           "xtysjrcixkiyputrkdzjkojzvfgocyaxdqytdcziqjufqlhryqrmmtxjyeptwxcoazx"
           "hljkutbmbsueoalunqugrzsdpxfojrjksmoqtqqvhrmzfgwmqhyrkqnrkzxzbpwalfq"
           "xfjuldztedjpjgkjkpabcarbvrhxgwktvyxbdnqynxpbrmrsrlcyslcidtoabscne"
           "s")) {
    for (string c : row) {
      cout << c << ", ";
    }
    cout << endl;
  }

  RadixTree *root = new RadixTree();
}