#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, flag = 0;
  cin >> n >> m;
  vector<int> v;
  if(n == 1) {
    int tmp;
    cin >> tmp;
    cout << tmp;
    return 0;
    }
  if( m > n - 1)
    m = m % n;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  for(int i = n -m; i < n; i++) {
    if(flag != 0) cout << " ";
    cout << v[i];
    flag = 1;
  }
  for (int i = 0; i < n - m; i++) {
    if (flag != 0) cout << " ";
    cout << v[i];
    flag = 1;
  }
  return 0;
}


