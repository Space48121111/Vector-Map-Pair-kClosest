# include <iostream>
# include <unordered_map>
# include <vector>
# include <queue>
using namespace std;
// g++ vertex.cpp -o v --std=c++11

// time complexity: O(klogn + n) priority queue logn for each element
// space complexity: O(n)
struct compare {
  // operator overloading user-defined operator
  bool operator() (pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
      return p1.first < p2.first;
    return p1.second < p2.second;
  }
};

void kMostFreq(int input[], int size, int k) {
  // associative container key_val constant-time complexity
  // bucket -hash
  unordered_map<int, int> counts;
  for (int i = 0; i < size; i++) {
    counts[input[i]]++;
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >, compare>
    maxHeap(counts.begin(), counts.end());

  for (int i = 1; i <= k; i++) {
    cout << "\n Topping " << maxHeap.top().first;
    maxHeap.pop();
  }
}

int main() {
  int input[] = { 1, 1, 1, 2, 2, 3 };
  int size = (sizeof(input) / sizeof(input[0]));
  int k = 2;

  kMostFreq(input, size, k);

  return 0;

}


// end
