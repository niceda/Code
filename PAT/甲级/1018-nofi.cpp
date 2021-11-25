#include<iostream>
#include <algorithm>
#include<vector>
#include <map>
using namespace std;

struct node {
  string time, state;
};

int main() {
  int n, c[24];
  map<string, vector<node>> m;
  for (int i = 0; i < 24; i++) {
    cin >> c[i];
  }
  cin >> n;
  string t1, t2;
  int M, d, h, tm;
  for (int i = 0; i < n; i++) {
    cin >> t1;
    scanf("%d:%d:%d:%d", &M, &d, &h, &tm);
    cin >> t2;
    m[t1].push_back(node{M, d, h, tm , t2});
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    sort(it->second.begin(), it->second.end(), cmp);
    cout << it->first << " ";
    printf("%2d", it->second[0].M);
    int total = 0, flag = 0, ont, offt;
    for (int i = 0; i < it->second.size(); i++) {
      if (flag == 0 && it->second[i].state == "on-line") {
        ont = it->second[i].d * 24 * 60 + it->second[i].h * 60 + it->second[i].m; 
        flag = 1;
      }
      if (flag == 1 && it->second[i].state == "off-line") {
        offt = it->second[i].d * 24 * 60 + it->second[i].h * 60 + it->second[i].m;
        
      }
    }
  }
  return 0;
}
