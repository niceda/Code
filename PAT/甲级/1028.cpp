#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  string id, name;
  int grade;
};

bool cmp1(node a, node b) { return a.id < b.id; }

bool cmp2(node a, node b) {
  return a.name != b.name ? a.name < b.name : a.id < b.id;
}

bool cmp3(node a, node b) {
  return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}

int main() {
  int n, c;
  cin >> n >> c;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].id >> v[i].name >> v[i].grade;
  }
  switch (c) {
  case 1:
    sort(v.begin(), v.end(), cmp1);
    break;
  case 2:
    sort(v.begin(), v.end(), cmp2);
    break;
  case 3:
    sort(v.begin(), v.end(), cmp3);
    break;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].id << " " << v[i].name << " " << v[i].grade << endl; 
  }
  return 0;
}
