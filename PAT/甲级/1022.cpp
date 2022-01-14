#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct book {
  string infor[6];
  set<string> keywords;
};

int main() {
  int n;
  scanf("%d\n", &n);
  vector<book> v(n);
  for (int i = 0; i < n; i++) {
    getline(cin, v[i].infor[0]);
    getline(cin, v[i].infor[1]);
    getline(cin, v[i].infor[2]);
    string key;
    while (cin >> key) {
      v[i].keywords.insert(key);
      if (getchar() == '\n') {
        break;
      }
    }
    getline(cin, v[i].infor[4]);
    getline(cin, v[i].infor[5]);
  }

  int k;
  scanf("%d\n", &k);
  for (int i = 0; i < k; i++) {
    string s;
    getline(cin, s);
    int queryid = s[0] - '0';
    string querystr = s.substr(3);
    set<string> result;
    if (queryid != 3) {
      for (int j = 0; j < n; j++) {
        if (v[j].infor[queryid] == querystr) {
          result.insert(v[j].infor[0]);
        }
      }
    } else {
      for (int j = 0; j < n; j++) {
        if (v[j].keywords.find(querystr) != v[j].keywords.end()) {
          result.insert(v[j].infor[0]);
        }
      }
    }
    cout << s << endl;
    if (result.empty()) {
      cout << "Not Found" << endl;
    } else {
      for (auto bookid : result) {
        cout << bookid << endl;
      }
    }
  }
  return 0;
}
