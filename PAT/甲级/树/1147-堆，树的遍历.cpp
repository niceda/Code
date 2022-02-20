#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
void postOrder(int index) {
  if (index > n - 1)
    return;
  postOrder(2 * index + 1);
  postOrder(2 * index + 2);
  printf("%d%s", v[index], index == 0 ? "\n" : " ");
}

int main() {
  cin >> m >> n;
  v.resize(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cin >> v[j];
    int flag = v[0] > v[1] ? 1 : -1;
      // important : i <= n / 2 -1;
      for (int i = 0; i <= n / 2 - 1; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (flag == 1 && ((v[i] < v[left]) || (right < n && v[i] < v[right])))
          flag = 0;
        if (flag == -1 && ((v[i] > v[left]) || (right < n && v[i] > v[right])))
          flag = 0;
      }
      if (flag == 0) cout << "Not Heap\n";
      else printf("%s Heap\n", flag == 1? "Max" : "Min");
      postOrder(0);
    }
  return 0;
}
