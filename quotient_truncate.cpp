# include <iostream>

// g++ quotient_truncate.cpp -o q --std=c++11
using namespace std;

/*
dividend = 7
divisor = -3
output = -2
algorithm/brutal force:
c = a - b b = a - c ct O(n)
overflow: [-2^31, 2^31 - 1] heuristic ret int_max
bit shift: >> mul/div by the power of 2
O(logn): double the accumulator accum += accum
*/

class S{
public:
  int divide(int dvd, int dvs) {
    if (dvd == INT_MIN and dvs == -1) return INT_MAX;
    if (dvd == INT_MIN and dvs == 1) return INT_MIN;
    bool n = (dvd < 0) ^ (dvs < 0);
    dvd = dvd > 0 ? -dvd : dvd;
    dvs = dvs > 0 ? -dvs : dvs;
    int q = 0;

    // brutal force/naive O(n)
    // while (dvd <= dvs) {
    //   dvd -= dvs;
    //   q ++;
    // }

    // half truncating/double accum 64 32 16 O((logn)^2)
    // while (dvd <= dvs) {
    //   int i = 1;
    //   int a = dvs;
    //   while (a >= INT_MIN >> 1 and dvd <= a + a) {
    //     i += i;
    //     a += a;
    //   }
    //   dvd -= a;
    //   q += i;
    // }

    // max truncating accumulator outer loop
    int i = 1;
    int a = dvs;
    while (a >= INT_MIN >> 1 and dvd <= a + a) {
      i <<= 1; // doubling, counter i always positive
      a += a;
      cout << "Counter: " << i << " Accumulator: " << a << endl;
    }
    while (dvd <= dvs) {
      // testing
      if (dvd <= a) {
        dvd -= a;
        q += i;
        cout <<  "Dividend: " << dvd << " Quotient: " << q << endl;
      }
      a >>= 1; // O(32)
      i >>= 1;
      cout << "Counter1: " << i << " Accumulator1: " << a << endl;
    }
    return n ? -q : q;
  }
};

int main() {
  S s1;
  int dividend = 7;
  int divisor = -3;
  // int int_max = 2^31 - 1;
  // int int_min = -2^31;
  cout << "Returns: " << s1.divide(dividend, divisor) << endl;

  return 0;

}




// end
