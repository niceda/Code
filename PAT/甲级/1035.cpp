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
  string name, password;
};

int main() {
  int n;
  cin >> n;
  vector<node> v(n);
  vector<node> modified;
  for (int i = 0; i < n; i++) {
    cin >> v[i].name >> v[i].password;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < v[i].password.length(); j++) {
      switch (v[i].password[j]) {
      case '1':
        v[i].password[j] = '@';
        flag = 1;
        break;
      case '0':
        v[i].password[j] = '%';
        flag = 1;
        break;
      case 'O':
        v[i].password[j] = 'o';
        flag = 1;
        break;
      case 'l':
        v[i].password[j] = 'L';
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      modified.push_back(node{v[i].name, v[i].password});
      count++;
    }
  }
  if (count == 0) {
    if (n == 1) {
      cout << "There is 1 account and no account is modified";
    } else if (n > 1) {
      printf("There are %d accounts and no account is modified", n);
    }
  } else {
    cout << count << endl;
    for (int i = 0; i < count; i++) {
      cout << modified[i].name << " " << modified[i].password << endl;
    }
  }
  return 0;
}
