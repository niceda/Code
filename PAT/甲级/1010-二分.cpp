#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int getNum(char c) {
  int num;
  if (isdigit(c)) {
    num = c - '0';
  } else {
    num = c - 'a' + 10;
  }
  return num;
}

long long getSum(string s, int radix) {
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) {
    sum += getNum(s[i]) * pow(radix, s.length() - i - 1);
  }
  return sum;
}

int main() {
  string n1, n2;
  int tag, radix;
  cin >> n1 >> n2 >> tag >> radix;
  if (tag == 2) {
    swap(n1, n2);
  }
  long long n1Sum = getSum(n1, radix);

  char it = *max_element(n2.begin(), n2.end());
  long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
  long long high = max(n1Sum, low);
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long sum = getSum(n2, mid);
    if (sum == n1Sum) {
      cout << mid;
      return 0;
    } else if (sum > n1Sum || sum < 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << "Impossible";
  return 0;
}
