#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
using namespace std;
const int maxn = 100010;
stack<int> st;
int c[maxn];

void update(int x, int v) {
  for (int i = x; i < maxn; i += lowbit(i)) {
    c[i] += v;
  }
}

int getnum(int x) {
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    sum += c[i];
  }
  return sum;
}

void PeekMedian(int k) {
  int l = 1, r = maxn;
  while (l < r) {
    int mid = (l + r) / 2;
    if (getnum(mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}

int main() {
  int n, t;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "Push") {
      cin >> t;
      st.push(t);
      update(t, 1);
    } else if (s == "Pop") {
      if (st.empty())
        cout << "Invalid" << endl;
      else {
        cout << st.top() << endl;
        update(st.top(), -1);
        st.pop();
      }
    } else {
      if (st.empty())
        cout << "Invalid" << endl;
      else {
        int k = (st.size() + 1) / 2;
        PeekMedian(k);
      }
    }
  }
  return 0;
}
