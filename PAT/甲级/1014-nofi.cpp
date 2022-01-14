#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Time1 {
  int hour, minu;
};

struct Time2 {
  int sthour, stminu;
  int fihour, fiminu;
};

int main() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<Time1> wt(n);
  vector<Time2> pt(k);
  vector<queue<int>> w(n);
  int hour = 8, minu = 0, max = n * m, t;
  for (int i = 0; i < k; i++) {
    cin >> t;
    if (i + 1 <= n * m) {
      if (i + 1 <= n) {
        pt[i].sthour = 8 + t / 60;
        pt[i].stminu = t % 60;
        pt[i].fihour = 8 + t / 60;
        pt[i].fiminu = t % 60;
        // cout << i << "-----" << pt[i].hour << "--------" << pt[i].minu
        //      << "---------" << endl;
        wt[i].hour = pt[i].fihour;
        wt[i].minu = pt[i].fiminu;
        w[i].push(i);
      } else {
        pt[i].sthour = wt[i % n].hour;
        pt[i].stminu = wt[i % n].minu;
        pt[i].fihour = wt[i % n].hour + (wt[i % n].minu + t) / 60;
        pt[i].fiminu = (wt[i % n].minu + t) % 60;
        // cout << i << "-----" << pt[i].hour << "--------" << pt[i].minu
        //      << "---------" << endl;
        wt[i % n].hour = pt[i].fihour;
        wt[i % n].minu = pt[i].fiminu;
        w[i % n].push(i);
      }
    } else {
      int wid = 0, min = pt[w[0].front()].fihour * 60 + pt[w[0].front()].fiminu;
      for (int j = 1; j < n; j++) {
        int t = pt[w[j].front()].fihour * 60 + pt[w[j].front()].fiminu;
        if (t < min) {
          min = t;
          wid = j;
        }
      }
      w[wid].pop();
      w[wid].push(i);
      pt[i].sthour = wt[wid].hour;
      pt[i].stminu = wt[wid].minu;
      pt[i].fihour = wt[wid].hour + (wt[wid].minu + t) / 60;
      pt[i].fiminu = (wt[wid].minu + t) % 60;
      wt[wid].hour = pt[i].fihour;
      wt[wid].minu = pt[i].fiminu;
    }
  }

  int id;
  for (int i = 0; i < q; i++) {
    cin >> id;
    if (pt[id - 1].sthour < 17) {
      // cout << id << "-----" << pt[id - 1].hour << "--------" << pt[id -
      // 1].minu
      //      << "---------" << endl;
      printf("%02d:%02d\n", pt[id - 1].fihour % 24, pt[id - 1].fiminu);
    } else {
      printf("Sorry\n");
    }
  }

  return 0;
}
