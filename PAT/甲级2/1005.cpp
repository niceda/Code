#include<iostream>
#include<vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int total = 0;
  for (int i = 0; i < s.length(); i++) {
    total += s[i] - '0';
  }
  string results = to_string(total);
  string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  for (int i = 0; i < results.length(); i++) {
    if (i != 0) cout << " ";
    cout << digits[results[i] - '0'];
  }

  return 0;
}
