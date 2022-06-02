/*
k most unique frequent elements/most occurrance

*/
# include <iostream>
# include <queue>
# include <vector>
# include <unordered_map>
using namespace std;
// g++ vertex.cpp -o v --std=c++11

/*
  input = [1, 1, 1, 2, 2, 3]
  k = 2
  output = [1, 2]

  hashing: convert a large -> small string
  shorter val -> indexing/faster searches
  hashset: link list -> store key-val pairs

*/
// construct the vector function
vector<int> kMostFreq(vector<int> input, int k) {
  // hash map to store pair val: count
  unordered_map<int, int> counts;
  // increment/traverse within the input and count up
  for(int i = 0; i < input.size(); i ++) {
    counts[input[i]]++;
  }
  /*
   container adapter
   first -> largest element weak ordering top()
   max-heap by default non-increasing first/not the largest is the 'last'
   each element has priority/fixed order
   make pair in priority queue/min heap

  */
  priority_queue<pair<int, int>, vector<pair<int, int> > > minHeap;
  // O(m)
  for(auto curPair : counts) {
    int val = curPair.first;
    int count = curPair.second;
    pair<int, int> cur = make_pair(count, val);
    // pair<const int, int>
    // pair<second, first> <count, val> and insert
    // cout << "CurPair " << curPair;
    minHeap.push(cur);
    // compare
    // only pop the pair with more than k frequency
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  // O(klogk)
  vector<int> res;
  for (int i = 0; !minHeap.empty() || i < k; i++) {
    // traverse count of the val in decremental order into result
    cout << "\n k " << k;
    cout << "\n i " << i;
    pair<const int, int> curr = minHeap.top();
    minHeap.pop();
    // store/update/sort the array
    res.push_back(curr.second);
    for (int n: res) {
      cout << n << ", ";
    }
    
  }


  // max(O(klgk), O(n))
  return res;
 }

/*
// use a bucket, sliding window?
vector<int> kMostFreq2(vector<int> input, int k) {
  vector<vector<int>> bucket(input.size());

  unordered_map<int, int> counts;
  for (int i = 1; i < input.size(); i++) {
    counts[input[i]]++;
  }
  for(auto curPair : counts) {
    bucket[curPair.second].push_back(curPair.first);
  }

  vector<int> res;
  int numbersNeeded = k;
  for(int i = bucket.size() - 1; i >= 0; i--) {
    if(bucket[i].size() != 0) {
      for(int j = 1; j < bucket.size(); j++) {
        if (numbersNeeded == 0) {
          return res;
        res.push_back(bucket[i][j]);
        numbersNeeded--;
        }
      }
    }
    return res;
  }
}
*/

int main() {
  int k = 2;
  vector<int> input = {1, 1, 1, 2, 2, 3};

  kMostFreq(input, k);

  return 0;

}








// end
