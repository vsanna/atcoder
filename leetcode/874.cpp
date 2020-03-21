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

void chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll& a, ll b) {
  if (a < b) {
    a = b;
  }
}

class Solution {
  enum Direction { up = 0, right, down, left };

 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // stackに置けないサイズ。heapに置く
    // newなのでpointerで取り回し
    // bitset<32>* obstaclemap = new bitset<32>();
    // for (vector<int> obstacle : obstacles) {
    //   (*obstaclemap).set(mapRegularPos(make_pair(obstacle[0], obstacle[1])));
    // }

    vector<pair<int, int>> obstaclePairs{};
    for (vector<int> obstacle : obstacles) {
      obstaclePairs.push_back(make_pair(obstacle[0], obstacle[1]));
    }
    sort(obstaclePairs.begin(), obstaclePairs.end());

    // x, y
    pair<int, int> currentpos = make_pair(0, 0);
    Direction currentdir = up;
    ll ans = -INF;

    for (int comm : commands) {
      if (comm == -2) {
        currentdir = (Direction)((currentdir + 3) % 4);
      } else if (comm == -1) {
        currentdir = (Direction)((currentdir + 1) % 4);
      } else {
        for (int i = 1; i <= comm; i++) {
          pair<int, int> nextpos = calcNextpos(currentpos, currentdir);
          if (canMove(nextpos, obstaclePairs)) {
            currentpos = nextpos;
          } else {
            break;
          }
        }
        chmax(ans, (currentpos.first * currentpos.first +
                    currentpos.second * currentpos.second));
      }
    }

    return ans;
  }

  pair<int, int> calcNextpos(pair<int, int>& currentpos, Direction currentdir) {
    switch (currentdir) {
      case up:
        return make_pair(currentpos.first, currentpos.second + 1);
      case right:
        return make_pair(currentpos.first + 1, currentpos.second);
      case down:
        return make_pair(currentpos.first, currentpos.second - 1);
      case left:
        return make_pair(currentpos.first - 1, currentpos.second);
      default:
        throw exception{};
    }
  }

  bool canMove(pair<int, int> dist, vector<pair<int, int>>& obstaclePairs) {
    return binarySearch(dist, obstaclePairs) < 0;
  }

  // -1: not found
  int binarySearch(pair<int, int> dist, vector<pair<int, int>>& obstaclePairs) {
    int low = 0;
    int high = obstaclePairs.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (obstaclePairs[mid] == dist) {
        return mid;
      }

      if (obstaclePairs[mid] < dist) {
        low = mid + 1;
        continue;
      } else {
        high = mid - 1;
        continue;
      }
    }
    return -1;
  }
};

int main() {
  Solution s = Solution();
  vector<int> commands{-2, -1, 8, 9, 6};
  vector<vector<int>> obstacles{
      vector<int>{-1, 3},  vector<int>{0, 1},  vector<int>{-1, 5},
      vector<int>{-2, -4}, vector<int>{5, 4},  vector<int>{-2, -3},
      vector<int>{5, -1},  vector<int>{1, -1}, vector<int>{5, 5},
      vector<int>{5, 2},
  };
  // cout << s.robotSim(commands, obstacles) << endl;

  // commands = vector<int>{4, -1, 4, -2, 4};
  // obstacles = vector<vector<int>>{
  //     vector<int>{2, 4},
  // };
  // cout << s.robotSim(commands, obstacles) << endl;

  // commands = vector<int>{-2, 8, 3, 7, -1};
  // obstacles = vector<vector<int>>{
  //     vector<int>{-4, -1}, vector<int>{1, -1}, vector<int>{1, 4},
  //     vector<int>{5, 0},   vector<int>{4, 5},  vector<int>{-2, -1},
  //     vector<int>{2, -5},  vector<int>{5, 1},  vector<int>{-3, -1},
  //     vector<int>{5, -3},
  // };

  commands = vector<int>{
      1,  2,  -2, 5,  -1, -2, -1, 8,  3,  -1, 9,  4,  -2, 3,  2,  4,  3,
      9,  2,  -1, -1, -2, 1,  3,  -2, 4,  1,  4,  -1, 1,  9,  -1, -2, 5,
      -1, 5,  5,  -2, 6,  6,  7,  7,  2,  8,  9,  -1, 7,  4,  6,  9,  9,
      9,  -1, 5,  1,  3,  3,  -1, 5,  9,  7,  4,  8,  -1, -2, 1,  3,  2,
      9,  3,  -1, -2, 8,  8,  7,  5,  -2, 6,  8,  4,  6,  2,  7,  2,  -1,
      7,  -2, 3,  3,  2,  -2, 6,  9,  8,  1,  -2, -1, 1,  4,  7};

  // x: 62, y: 36, dir: 1
  // 5140
  commands =
      vector<int>{1,  2, -2, 5,  -1, -2, -1, 8, 3,  -1, 9, 4, -2, 3, 2, 4,
                  3,  9, 2,  -1, -1, -2, 1,  3, -2, 4,  1, 4, -1, 1, 9, -1,
                  -2, 5, -1, 5,  5,  -2, 6,  6, 7,  7,  2, 8, 9,  -1};

  // x: 62, y: 36, dir: 2
  // 4685
  commands =
      vector<int>{1,  2, -2, 5,  -1, -2, -1, 8, 3,  -1, 9, 4, -2, 3,  2, 4,
                  3,  9, 2,  -1, -1, -2, 1,  3, -2, 4,  1, 4, -1, 1,  9, -1,
                  -2, 5, -1, 5,  5,  -2, 6,  6, 7,  7,  2, 8, 9,  -1, 7};
  obstacles = vector<vector<int>>{
      vector<int>{-57, -58}, vector<int>{-72, 91},  vector<int>{-55, 35},
      vector<int>{-20, 29},  vector<int>{51, 70},   vector<int>{-61, 88},
      vector<int>{-62, 99},  vector<int>{52, 17},   vector<int>{-75, -32},
      vector<int>{91, -22},  vector<int>{54, 33},   vector<int>{-45, -59},
      vector<int>{47, -48},  vector<int>{53, -98},  vector<int>{-91, 83},
      vector<int>{81, 12},   vector<int>{-34, -90}, vector<int>{-79, -82},
      vector<int>{-15, -86}, vector<int>{-24, 66},  vector<int>{-35, 35},
      vector<int>{3, 31},    vector<int>{87, 93},   vector<int>{2, -19},
      vector<int>{87, -93},  vector<int>{24, -10},  vector<int>{84, -53},
      vector<int>{86, 87},   vector<int>{-88, -18}, vector<int>{-51, 89},
      vector<int>{96, 66},   vector<int>{-77, -94}, vector<int>{-39, -1},
      vector<int>{89, 51},   vector<int>{-23, -72}, vector<int>{27, 24},
      vector<int>{53, -80},  vector<int>{52, -33},  vector<int>{32, 4},
      vector<int>{78, -55},  vector<int>{-25, 18},  vector<int>{-23, 47},
      vector<int>{79, -5},   vector<int>{-23, -22}, vector<int>{14, -25},
      vector<int>{-11, 69},  vector<int>{63, 36},   vector<int>{35, -99},
      vector<int>{-24, 82},  vector<int>{-29, -98}, vector<int>{-50, -70},
      vector<int>{72, 95},   vector<int>{80, 80},   vector<int>{-68, -40},
      vector<int>{65, 70},   vector<int>{-92, 78},  vector<int>{-45, -63},
      vector<int>{1, 34},    vector<int>{81, 50},   vector<int>{14, 91},
      vector<int>{-77, -54}, vector<int>{13, -88},  vector<int>{24, 37},
      vector<int>{-12, 59},  vector<int>{-48, -62}, vector<int>{57, -22},
      vector<int>{-8, 85},   vector<int>{48, 71},   vector<int>{12, 1},
      vector<int>{-20, 36},  vector<int>{-32, -14}, vector<int>{39, 46},
      vector<int>{-41, 75},  vector<int>{13, -23},  vector<int>{98, 10},
      vector<int>{-88, 64},  vector<int>{50, 37},   vector<int>{-95, -32},
      vector<int>{46, -91},  vector<int>{10, 79},   vector<int>{-11, 43},
      vector<int>{-94, 98},  vector<int>{79, 42},   vector<int>{51, 71},
      vector<int>{4, -30},   vector<int>{2, 74},    vector<int>{4, 10},
      vector<int>{61, 98},   vector<int>{57, 98},   vector<int>{46, 43},
      vector<int>{-16, 72},  vector<int>{53, -69},  vector<int>{54, -96},
      vector<int>{22, 0},    vector<int>{-7, 92},   vector<int>{-69, 80},
      vector<int>{68, -73},  vector<int>{-24, -92}, vector<int>{-21, 82},
      vector<int>{32, -1},   vector<int>{-6, 16},   vector<int>{15, -29},
      vector<int>{70, -66},  vector<int>{-85, 80},  vector<int>{50, -3},
      vector<int>{6, 13},    vector<int>{-30, -98}, vector<int>{-30, 59},
      vector<int>{-67, 40},  vector<int>{17, 72},   vector<int>{79, 82},
      vector<int>{89, -100}, vector<int>{2, 79},    vector<int>{-95, -46},
      vector<int>{17, 68},   vector<int>{-46, 81},  vector<int>{-5, -57},
      vector<int>{7, 58},    vector<int>{-42, 68},  vector<int>{19, -95},
      vector<int>{-17, -76}, vector<int>{81, -86},  vector<int>{79, 78},
      vector<int>{-82, -67}, vector<int>{6, 0},     vector<int>{35, -16},
      vector<int>{98, 83},   vector<int>{-81, 100}, vector<int>{-11, 46},
      vector<int>{-21, -38}, vector<int>{-30, -41}, vector<int>{86, 18},
      vector<int>{-68, 6},   vector<int>{80, 75},   vector<int>{-96, -44},
      vector<int>{-19, 66},  vector<int>{21, 84},   vector<int>{-56, -64},
      vector<int>{39, -15},  vector<int>{0, 45},    vector<int>{-81, -54},
      vector<int>{-66, -93}, vector<int>{-4, 2},    vector<int>{-42, -67},
      vector<int>{-15, -33}, vector<int>{1, -32},   vector<int>{-74, -24},
      vector<int>{7, 18},    vector<int>{-62, 84},  vector<int>{19, 61},
      vector<int>{39, 79},   vector<int>{60, -98},  vector<int>{-76, 45},
      vector<int>{58, -98},  vector<int>{33, 26},   vector<int>{-74, -95},
      vector<int>{22, 30},   vector<int>{-68, -62}, vector<int>{-59, 4},
      vector<int>{-62, 35},  vector<int>{-78, 80},  vector<int>{-82, 54},
      vector<int>{-42, 81},  vector<int>{56, -15},  vector<int>{32, -19},
      vector<int>{34, 93},   vector<int>{57, -100}, vector<int>{-1, -87},
      vector<int>{68, -26},  vector<int>{18, 86},   vector<int>{-55, -19},
      vector<int>{-68, -99}, vector<int>{-9, 47},   vector<int>{24, 94},
      vector<int>{92, 97},   vector<int>{5, 67},    vector<int>{97, -71},
      vector<int>{63, -57},  vector<int>{-52, -14}, vector<int>{-86, -78},
      vector<int>{-17, 92},  vector<int>{-61, -83}, vector<int>{-84, -10},
      vector<int>{20, 13},   vector<int>{-68, -47}, vector<int>{7, 28},
      vector<int>{66, 89},   vector<int>{-41, -17}, vector<int>{-14, -46},
      vector<int>{-72, -91}, vector<int>{4, 52},    vector<int>{-17, -59},
      vector<int>{-85, -46}, vector<int>{-94, -23}, vector<int>{-48, -3},
      vector<int>{-64, -37}, vector<int>{2, 26},    vector<int>{76, 88},
      vector<int>{-8, -46},  vector<int>{-19, -68},
  };

  // vector<vector<int>> grid = vector<vector<int>>(201, vector<int>(201, 0));
  // for (auto obs : obstacles) {
  //   grid[obs[0] + 100][obs[1] + 100] = 1;
  // }
  // for (auto row : grid) {
  //   for (int n : row) {
  //     cout << n << "\t";
  //   }
  //   cout << endl;
  // }

  cout << s.robotSim(commands, obstacles) << endl;
}