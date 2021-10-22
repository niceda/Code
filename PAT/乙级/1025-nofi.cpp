#include <iostream>
#include <map>
using namespace std;

struct node {
  int data;
  string next;
};

int main() {
  int n, k, flag = 0;
  string ad,ead;
  cin >> ad >> n >> k;
  map<string, node> m;
  for (int i = 0; i < n; i++) {
    string t1;
    cin >> t1;
    cin >> m[t1].data >> m[t1].next;
  }
  string s = ad;
  for (int i = 0; i < k -1 ; i++) {
    ead = m[s].next;
    s = m[s].next;
  }
  for (int i = 0; i < k - 1; i++) {
    string temp1 = m[ead].next;
    string temp2 = m[ad].next;
    m[ad].next = temp1;
    m[ead].next = ad;
    ad = temp2;
  }
  for (int i = 0; i < n; i++) {
    if (flag != 0) cout << endl;
    cout << ad << " " << m[ad].data << " " << m[ad].next;
    ad = m[ad].next;
    flag = 1;
  }
  return 0;
  
}
