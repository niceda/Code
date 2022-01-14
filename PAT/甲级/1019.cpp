#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  int n, b;
  cin >> n >> b;
  while (n != 0) {
    v.push_back(n % b);
    n /= b;
  }
  int flag = true;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != v[v.size() - i - 1]) {
      flag = false;
      cout << "No" << endl;
      break;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    if (i != v.size() - 1)
      cout << " ";
    cout << v[i];
  }
  return 0;
}
