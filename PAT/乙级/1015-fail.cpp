#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  long int num;
  int d, c;
};

int cmp(node a, node b) {
  if (a.d + a.c != b.d + b.c)
    return (a.d + a.c) > (b.d + b.c);
  else if (a.d != b.d)
    return a.d > b.d;
  else
    return a.num < b.num;
}

int main() {
  long int N;
  int L, H;
  cin >> N >> L >> H;
  vector<node> v[4];
  node tmp;
  int total = N;
  for (int i = 0; i < N; i++) {
    cin >> tmp.num >> tmp.d >> tmp.c;
    if (tmp.d < L || tmp.c < L)
      total--;
    else if (tmp.d >= H && tmp.c >= H)
      v[0].push_back(tmp);
    else if (tmp.d >= H && tmp.c < H)
      v[1].push_back(tmp);
    else if (tmp.d >= tmp.c)
      v[2].push_back(tmp);
    else
      v[3].push_back(tmp);
  }

  printf("%d\n", total);
  for (int i = 0; i < 4; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
    for (int j = 0; j < v[i].size(); j++) {
      printf("%ld %d %d\n", v[i][j].num, v[i][j].d, v[i][j].c);
    }
  }

  return 0;
}
