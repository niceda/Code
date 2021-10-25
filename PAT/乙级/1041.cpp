#include <iostream>
#include <vector>
using namespace std;

struct node {
  string s;
  int a, b;
};

int main() {
  int n;
  cin >> n;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].s >> v[i].a >> v[i].b;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    int j = 0;
    for (; j < n; j++) {
      if (v[j].a == tmp)
        break;
    }
    cout << v[j].s << " " << v[j].b << endl;
  }
  return 0;
}
