#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 100010;
const int sqrN = 317;
stack<int> st;
int block[sqrN];
int table[maxn];

void PeekMedian(int k) {
  int sum = 0, id = 0;
  while (sum + block[id] < k)
    sum += table[id++];
  int num = id * sqrN;
  while (sum + table[num] < k)
    sum += table[num++];
  printf("%d\n", num);
}

void push(int x) {
  st.push(x);
  block[x / sqrN]++;
  table[x]++;
}

void pop() {
  int x = st.top();
  st.pop();
  block[x / sqrN]--;
  table[x]--;
  printf("%d\n", x);
}

int main() {
  int n, t;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "Push") {
      cin >> t;
      push(t);
    } else if (s == "Pop") {
      if (st.empty())
        cout << "Invalid" << endl;
      else
        pop();
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
