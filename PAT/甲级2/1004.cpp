#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int id;
  int depth;
};

vector<int> tree[100];
int maxdepth = -1;
int book[100];

// void dfs(int index, int depth) {
//   if (tree[index].empty()) {
//     book[depth]++;
//     maxdepth = max(maxdepth, depth);
//     return;
//   }

//   for (int i = 0; i < tree[index].size(); i++) {
//     dfs(tree[index][i], depth+1);
//   }
// }
void bfs(int index, int depth) {
  queue<node> q;
  q.push(node{index, depth});
  while (!q.empty()) {
    node top = q.front();
    q.pop();
    if (!tree[top.id].empty()) {
      for (int i = 0; i < tree[top.id].size(); i++) {
        q.push(node{tree[top.id][i], top.depth + 1});
      }
    } else {
      book[top.depth]++;
      maxdepth = max(maxdepth, top.depth);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int id, k, cid;
  for (int i = 0; i < m; i++) {
    cin >> id >> k;
    for (int j = 0; j < k; j++) {
      cin >> cid;
      tree[id].push_back(cid);
    }
  }
  // dfs(1, 0);
  bfs(1, 0);
  cout << book[0];
  for (int i = 1; i < maxdepth + 1; i++) {
    cout << " " << book[i];
  }
  return 0;
}
