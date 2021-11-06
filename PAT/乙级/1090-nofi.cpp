#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m;
  map<string, set<string>> mapp;
  string s1, s2;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    mapp[s1].insert(s2);
    mapp[s2].insert(s1);
  }
  for (int i = 0; i < m; i++) {
    cin >> t;
    vector<string> v(t);
    for (int i = 0; i < t; i++) {
      cin >> v[i];
    }
    int flag = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        if(mapp[v[i]].find(v[j]) != mapp[v[i]].end()) {
          flag = 1;
          break;
        }
      }
      if(flag == 1)
        break;
    }
    if(flag == 0)
      cout << "Yes" << endl;
    else {
      cout << "No" << endl;
      flag = 0;
    }
  }
   return 0;
}
