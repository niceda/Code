#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  string name;
  int height;
};

int cmp(node a, node b) {
  return a.height != b.height ? a.height > b.height : a.name < b.name;
}

int main() {
  int N, K, m;
  cin >> N >> K;
  vector<node> stu(N);
  for (int i = 0; i < N; i++) {
    cin >> stu[i].name >> stu[i].height;
  }
  sort(stu.begin(), stu.end(), cmp);
  int t = 0, row = K;
  while (row) {
    if (row == K) {
      m = N - N / K * (K - 1);
    } else
      m = N / K;
    vector<string> ans(m);
    ans[m / 2] = stu[t].name;
    int j = m / 2 - 1;
    for (int i = t + 1; i < t + m; i = i + 2) {
      ans[j--] = stu[i].name;
    }
    j = m / 2 + 1;
    for (int i = t + 2; i < t + m; i= i + 2) {
      ans[j++] = stu[i].name;
    }
    for (int i = 0; i < m; i++) {
      if (i != 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
    t = t + m;
    row--;
  }
  return 0;
}
