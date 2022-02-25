#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, i = 0, flag = 0, s;
vector<int> origin, ch;
void downAdjust(int low, int high) {
  int i = low, j = 2 * i;
  while (j <= high) {
    if (j + 1 <= high && ch[j + 1] > ch[j]) {
      j = j + 1;
    }
    if (ch[i] < ch[j]) {
      swap(ch[j], ch[i]);
      i = j;
      j = 2 * i;
    } else {
      break;
    }
  }
}

int main() {
  cin >> n;
  origin.resize(n + 1);
  ch.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> origin[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> ch[i];
  }
  while (i != n) {
    if (ch[i] > ch[i + 1])
      break;
    i++;
  }
  s = i + 2;
  for (i = i + 1; i <= n; i++) {
    if (origin[i] != ch[i]) {
      flag = 1;
      break;
    }
  }
  if (!flag) {
    cout << "Insertion Sort" << endl;
    sort(ch.begin(), ch.begin() + s);
  } else {
    cout << "Heap Sort" << endl;
    i = 2;
    while(i <= n && ch[1] >= ch[i]) i++;
    swap(ch[1], ch[i - 1]);
    downAdjust(1, i - 2);
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1)
      cout << " ";
    cout << ch[i];
  }
  return 0;
}
