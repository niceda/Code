#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> course[2510];
vector<string> name;
bool cmp1(int a, int b) {
  return name[a] < name[b];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  name.resize(n);
  for (int i = 0; i < n; i++) {
    int cnt, temp;
    cin >> name[i];
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) {
      scanf("%d", &temp);
      course[temp].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++) {
    printf("%d %d\n", i, (int)course[i].size());
    sort(course[i].begin(), course[i].end(), cmp1);
    for (int j = 0; j < course[i].size(); j++) {
      cout << name[course[i][j]] << endl;
    }
  }
  return 0;
}
