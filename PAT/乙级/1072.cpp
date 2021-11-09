#include <iostream>
#include <set>
using namespace std;

int main() {
  int N, M, bianhao, k, flag = 0, ssum = 0, fnum = 0;
  cin >> N >> M;
  set<int> set;
  for (int i = 0; i < M; i++) {
    cin >> bianhao;
    set.insert(bianhao);
  }
  string name;
  for (int i = 0; i < N; i++) {
    cin >> name >> k;
    for (int j = 0; j < k; j++) {
      cin >> bianhao;
      if (set.find(bianhao) != set.end()) {
        if (flag == 0) {
          ssum++;
          cout << name << ":";
          flag = 1;
        }
        printf(" %04d", bianhao);
        fnum++;
      }
    }
    if (flag == 1) {
      cout << endl;
      flag = 0;
    }
  }
  cout << ssum << " " << fnum;
  return 0;
}
