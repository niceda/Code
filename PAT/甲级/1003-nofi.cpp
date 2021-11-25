#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int id;
  int level;
  vector<node> next;
};

int main() {
  int n, m, id, k, tid;
  cin >> n >> m;
  vector<node> v(n+1);
  for (int i = 0; i < m; i++) {
    cin >> id >> k;
    v[id].id = id;
    for (int j = 0; j < k; j++) {
      cin >> tid;
      v[id].next.push_back({tid});
    }
  }
  int s[101] = {0}, max = -1;
  queue<node> q;
  q.push(v[1]);
  while(!q.empty()) {
    node t = q.front();
    q.pop();
    if (t.next.size() == 0) {
      s[t.level]++;
      if (t.level > max) 
        max = t.level;
      continue;
    }
    for (int i = 0; i < t.next.size(); i++) {
      t.next[i].level = t.level + 1;
      q.push(t.next[i]);
    }
  }
  for (int i = 0; i <= max; i++) {
    if (i != 0) cout << " ";
    cout << s[i];
  }
  return 0;
}
