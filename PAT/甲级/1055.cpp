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
  string name;
  int age, netWorth;
};


bool cmp(node a, node b) {
  return a.netWorth != b.netWorth
             ? a.netWorth > b.netWorth
             : (a.age != b.age ? a.age < b.age : a.name < b.name);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].name >> v[i].age >> v[i].netWorth;
  }
  sort(v.begin(), v.end(), cmp);
  int max, agemin, agemax;
  for (int i = 1; i <= k; i++) {
    cin >> max >> agemin >> agemax;
    printf("Case #%d:\n", i);
    int copymax = max;
    for (int j = 0; j < v.size() && max != 0; j++) {
      if (v[j].age <= agemax && v[j].age >= agemin) {
        cout << v[j].name << " " << v[j].age << " " << v[j].netWorth << endl;
        max--;
      }
    }
    if (max == copymax) {
      cout << "None" << endl;
    }
  }
  return 0;
}
