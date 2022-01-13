#include <iostream>
#include <vector>
using namespace std;

struct Time {
  int hour, minu, sec;
};

int main() {
  int m;
  cin >> m;
  vector<string> id(m);
  vector<Time> come;
  vector<Time> back;

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> id[i];
    scanf("%d:%d:%d", &a, &b, &c);
    come.push_back(Time{a, b, c});
    scanf("%d:%d:%d", &a, &b, &c);
    back.push_back(Time{a, b, c});
  }

  string id1, id2;
  Time t1 = Time{25, 25, 25};
  Time t2 = Time{-1, -1, -1};
  for (int i = 0; i < m; i++) {
    if ((come[i].hour < t1.hour) ||
        (come[i].hour == t1.hour && come[i].minu < t1.minu) ||
        (come[i].hour == t1.hour && come[i].minu == t1.minu &&
         come[i].sec < t1.sec)) {
         t1.hour = come[i].hour;
         t1.minu = come[i].minu;
         t1.sec = come[i].sec;
         id1 = id[i];
    }
    if ((back[i].hour > t2.hour) ||
        (back[i].hour == t2.hour && back[i].minu > t2.minu) ||
        (back[i].hour == t2.hour && back[i].minu == t2.minu &&
         back[i].sec > t2.sec)) {
         t2.hour = back[i].hour;
         t2.minu = back[i].minu;
         t2.sec = back[i].sec;
         id2 = id[i];
    }
  }
  cout << id1 << " " << id2;
  return 0;
}
