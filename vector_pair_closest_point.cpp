# include <iostream>
# include <map>
# include <vector>
# include <cmath>
# include <utility>
using namespace std;

vector<pair<int, int>> kClosest(vector<pair<int, int>> points, pair<int, int> origin, int k) {
  map<double, vector<pair<int, int>>> memo;
  int x_o = origin.first;
  int y_o = origin.second;

  for (auto point: points) {
    int x_p = point.first;
    int y_p = point.second;
    int distance = sqrt(pow((x_p - x_o), 2) + pow((y_p - y_o), 2));
    memo[distance].push_back(point);
  }
  vector<pair<int, int>> result_set;
  for (auto it: memo) {
    for (auto point: it.second) {
      if (k == 0)
        return result_set;
      result_set.push_back(point);
      k--;
    }
  }
  return result_set;
}

int main() {
  vector<pair<int, int>> points ({
    make_pair(-1, 0),
    make_pair(3, 0),
    make_pair(0, 8)

  });
  pair<int, int> origin = make_pair(1, 1);
  int k = 2;
  vector<pair<int, int>> result_set = kClosest(points, origin, k);
  for (auto result: result_set) {
    cout << "(" << result.first << "," << result.second << ")" <<endl;
  }
  return 0;

}













// end
