#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  int x, y;
};

int n, m;
int flag[100][100];
int flag2[100][100];
node v[100][100];
node rescue;

vector<node> maxV;
set<string> minpath;
void findMinPath() {
  for (int i = 0; i < maxV.size(); i++) {
    int tx = maxV[i].x, ty = maxV[i].y;
    string result;
    while (rescue.x - tx != 0 || rescue.y - ty != 0) {
      if (rescue.x - tx > 0 && tx + 1 < n && flag[tx + 1][ty] == 1) {
        result += '2';
        tx += 1;
      } else if (rescue.x - tx < 0 && tx - 1 >= 0 && flag[tx - 1][ty] == 1) {
        tx -= 1;
        result += '0';
      } else if (rescue.y - ty > 0 && ty + 1 < m && flag[tx][ty + 1] == 1) {
        ty += 1;
        result += '1';
      } else if (rescue.y - ty < 0 && ty - 1 >= 0 && flag[tx][ty - 1] == 1) {
        ty -= 1;
        result += '3';
      }
    }
    minpath.insert(result);
  }
}

int findis(int x, int y) {
  int tx = x, ty = y, dis = 0;
  fill(flag2[0], flag2[0] + 100 * 100, 0);
  flag2[x][y] = 1;
  while (rescue.x - tx != 0 || rescue.y - ty != 0) {
    cout << "good";
    if (rescue.x - tx > 0 && tx + 1 < n && flag[tx + 1][ty] == 1 && flag2[tx + 1][ty] == 0) {
      tx += 1;
      dis++;
    } else if (rescue.x - tx < 0 && tx - 1 >= 0 && flag[tx - 1][ty] == 1 && ) {
      dis++;
      tx -= 1;
    } else if (rescue.y - ty > 0 && ty + 1 < m && flag[tx][ty + 1] == 1) {
      ty += 1;
      dis++;
    } else if (rescue.y - ty < 0 && ty - 1 >= 0 && flag[tx][ty - 1] == 1) {
      ty -= 1;
      dis++;
    }
    flag2[tx][ty] = 1;
    flag2[x][y] = 0;
  }
  return dis;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    getchar();
    char c;
    for (int j = 0; j < m; j++) {
      scanf("%c", &c);
      v[i][j].x = i;
      v[i][j].y = j;
      if (c == 'O' || c == 'X')
        flag[i][j] = 1;
      else if (c == '#')
        flag[i][j] = 0;
      if (c == 'X') {
        rescue.x = i;
        rescue.y = j;
      }
    }
  }
  int max;
  do {
    max = 0;
    maxV.clear();
    minpath.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (flag[i][j] == 1) {
          int dis = findis(i, j);
          if (max < dis) {
            maxV.clear();
            maxV.push_back({i, j});
            max = dis;
          } else if (max == dis) {
            maxV.push_back({i, j});
          }
        }
      }
    }
    break;
    // findMinPath();
    // string t = *minpath.begin();
    // cout << t;
    // int increaseX = 0, increaseY = 0;
    // for (int i = 0; i < t.length(); i++) {
    //   if (t[i] == '0')
    //     increaseX--;
    //   else if (t[i] == '1')
    //     increaseY++;
    //   else if (t[i] == '2')
    //     increaseX++;
    //   else if (t[i] == '3')
    //     increaseY--;
    // }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     if (flag[i][j] == 1 && v[i][j].x != rescue.x && v[i][j].y != rescue.y) {
    //       if (v[i][j].x + increaseX < 0)
    //         v[i][j].x = 0;
    //       else if (v[i][j].x + increaseX >= n)
    //         v[i][j].x = n - 1;
    //       else
    //         v[i][j].x = v[i][j].x + increaseX;

    //       if (v[i][j].y + increaseY < 0)
    //         v[i][j].y = 0;
    //       else if (v[i][j].y + increaseY >= m)
    //         v[i][j].y = m - 1;
    //       else
    //         v[i][j].y = v[i][j].y + increaseY;
    //     }
    //   }
    // }
  } while (max > 0);
  return 0;
}