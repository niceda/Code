#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct NODE1 {
  double estate, area;
} v[10000];
struct NODE2 {
  int minid = 999999999, num;
  double totalEstate, totalArea;
} result[10000];
int father[10000];
int flag[10000];
int findFather(int x) {
  int a = x;
  while (x != father[x]) {
    x = father[x];
  }
  while (a != x) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void Union(int a, int b) {
  int faA = findFather(a);
  int faB = findFather(b);
  if (faA != faB) {
    father[faA] = faB;
  }
}

bool cmp1(NODE2 a, NODE2 b) {
  if (a.minid == 999999999) return false;
  if (b.minid == 999999999) return true;
  if (a.totalArea / a.num != b.totalArea / b.num) {
    return a.totalArea / a.num > b.totalArea / b.num;
  } else {
    return a.minid < b.minid;
  }
}

int main() {
  int n, cnt = 0;
  set<int> exist;
  scanf("%d", &n);
  for (int i = 0; i < 10000; i++) {
    father[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int id, f, m, k, child;
    scanf("%d %d %d %d", &id, &f, &m, &k);
    exist.insert(id);
    if (f != -1) {
      Union(id, f);
      exist.insert(f);
    }
    if (m != -1) {
      Union(id, m);
      exist.insert(m);
    }
    for (int i = 0; i < k; i++) {
      scanf("%d", &child);
      Union(id, child);
      exist.insert(child);
    }
    scanf("%lf %lf", &v[id].estate, &v[id].area);
  }
  for (auto val : exist) {
    int faVal = findFather(val);
    if (flag[faVal] == 0) {
      cnt++;
      flag[faVal] = 1;
    }
    result[faVal].totalEstate += v[val].estate;
    result[faVal].totalArea += v[val].area;
    if (val < result[faVal].minid) {
      result[faVal].minid = val;
    }
    result[faVal].num++;
  }
  sort(result, result + 10000, cmp1);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%04d %d %.3lf %.3lf\n",result[i].minid, result[i].num, result[i].totalEstate / result[i].num, result[i].totalArea / result[i].num);
  }
  return 0;
}
