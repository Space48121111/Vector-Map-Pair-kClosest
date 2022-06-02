# include <iostream>
# include <cmath>
# include <map>
# include <utility>
# include <vector>
// g++ vertex.cpp -o v --std=c++11

using namespace std;

// double sqrt(int value) {
//   double a = value;
//   double b = 1.0; // for a > 1, if a < 1, b = 0 or a - b
//   double e = 0.000001; // epsilon
//
//   while (a - b > e) {
//   // reduce by half vs division
//   a = (a + b) / 2.0; // infinitely getting close by cutting into halves
//   // 101/2
//   cout << a << endl;
//   b = value / a; // the difference between the estimate and the value
//   // 100/50.5
//   cout << b << endl;
//   }
//   return a;
// }

// int main() {
//
//   cout << sqrt(100) << endl;
//   return 0;
// }

// 50.5
// 1.9802
// 26.2401
// 3.81096
// 15.0255
// 6.65534
// 10.8404
// 9.22472
// 10.0326
// 9.96753
// 10.0001
// 9.99995
// 10
// 10
// 10

// vector pair points
// pair origin
// k edges

// O(nlogn) going through each points-n and compare and operate with the origin-logn
// optimized version: constantly compare the shortest path O(logn)

vector< pair<int, int> > kClosestPoints(vector< pair<int, int> > points, pair<int, int> origin, int k)
{
  map<double, vector< pair<int, int> > > memo;
  // name of the map: memo
  // priority_queue< pair<int, int>, vector< pair <int, int> >, lower< pair(int, int)> > q;

  int x_o = origin.first;
  int y_o = origin.second;

  for(auto point: points)
  // auto declare types instead of specific integer/double
  {
    int x_p = point.first;
    int y_p = point.second;

    int distance = sqrt(pow((x_p - x_o), 2)  + pow((y_p - y_o), 2));

    memo[distance].push_back(point);
    // push_back: add a new element/distance at the end of the vector/map

    // double minX = q.top().first;
    // // put it on the top of the stack
    // double minY = q.top().second;
    // double minDis = sqrt(pow((minX - x_o), 2) + pow((minY - y_o), 2));
    //
    // if(distance < minDis)
    // {
    //   if(q.size() > k)
    //     q.pop();
    //   // pop/remove items as long as the distance is bigger than k
    //   q.push(point);
    //   // loop to the next insert/push
    // }

  }

  vector< pair<int, int> > result_set;
  for(auto it: memo)
  {
    for(auto point: it.second) {
    // for the points in the map, within the y/second, measure the k/distance
      if(k == 0)
      // until k/distance is the closest, end the loop
        return result_set;

      result_set.push_back(point);
      // push_back: add-on the points
      k--;
      // keep k decremental

      // while(q != empty())
      // {
      //   result_set.push_back(q.top());
      //   // keep putting the min into the queue top in the stack
      //   q.pop();
      //   //  and then pop/remove as long as there're elements
      // }

    }
  }

  return result_set;
}

int main() {
  vector< pair<int, int> > points ({
    make_pair(0, -1),
    make_pair(1, 13),
    make_pair(2, 0),
    make_pair(1, 0)
  });
  pair<int, int> origin = make_pair(1, 1);
  int k = 2;

  vector< pair<int, int> > result_set = kClosestPoints(points, origin, k);
  //use the vector function parameters to get the result set

  for(auto result: result_set)
    cout << "(" << result.first << "," << result.second << ")" << endl;
    // first/x and second/y (x, y)

}
