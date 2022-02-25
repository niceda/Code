#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n,cnt = 0, max = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];   
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if(b[i] == a[i] && a[i] > max) {
      v.push_back(b[i]);
      cnt++;
    }
    if (a[i] > max)
      max = a[i];
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    if(i != 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
  return 0;
}

