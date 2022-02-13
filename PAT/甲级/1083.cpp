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
  string name, id;
  int grade;
};

bool cmp(node a, node b) {
  return a.grade > b.grade;  
}

int main() {
  int n, grade1, grade2;
  cin >> n;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].name >> v[i].id >> v[i].grade;
  }
  cin >> grade1 >> grade2;
  vector<node> v2;
  for (int i = 0; i < n; i++) {
    if (v[i].grade >= grade1 && v[i].grade <= grade2) {
      v2.push_back(v[i]);
    }
  }
  sort(v2.begin(), v2.end(), cmp);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i].name << " " << v2[i].id << endl;
  }
  if (v2.empty()) {
    cout << "NONE";
  }
  return 0;
}
