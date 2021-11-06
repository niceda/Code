#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, min = 101, max = -1;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;
      int num = 1, pos1 = i + 1, pos2 = -1;
      for (int l = 0; l < n && num <= 2; l++) {
        int temppos = v[l][1] - '0';
        if (l == i || l == j) {
          if (v[l][0] == '+') {
            if (num == 1) {
              if (temppos != pos1) {
                num++;
                pos2 = temppos;
              }
            } else if (temppos != pos1 && temppos != pos2) {
              num++;
              break;
            }
          }
        } else if (v[l][0] == '-') {
          if (num == 1) {
            if (temppos != pos1) {
              num++;
              pos2 = temppos;
            }
          } else if (temppos != pos1 && temppos != pos2) {
            num++;
            break;
          }
        }
      }
      if (pos1 > pos2)
        swap(pos1, pos2);
      if (num == 2) {
        if (pos1 < min) {
          min = pos1;
          max = pos2;
        } else if (min == pos1 && max > pos2) {
          max = pos2;
        }
      }
    }
  }
  if(max == -1)
    cout << "No Solution";
  else
    cout << min << " " << max;
  return 0;
}
