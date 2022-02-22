#include <iostream>
#include <queue>
using namespace std;
  
int main() {
  priority_queue<int, vector<int>, greater<int>> q;
  int n, temp, x, y, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    q.push(temp);
  }
  while(q.size() > 1) {
    x = q.top();
    q.pop();
    y = q.top();
    q.pop();
    q.push(x + y);
    ans += x + y;
  }
  cout << ans;
  return 0;
}
