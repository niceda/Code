#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, flag = 0;
  cin >> N;
  vector<string> v(N);
  vector<char> c = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  vector<int> q = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  int tmp = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 17; j++) {
      tmp += (v[i][j] - '0') * q[j];
    }
    tmp %= 11;
    if(c[tmp] != v[i][17]) {
      cout << v[i] << endl;
      flag = 1;
    } 
    tmp = 0;
  }
  if( flag == 0)
    cout << "All passed";
  return 0;
}
