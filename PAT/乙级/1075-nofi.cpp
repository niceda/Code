#include <iostream>
#include <map>
using namespace std;

struct node {
  int data;
  string nxt;
};

int main() {
  string s;
  int N, K, flag = 0;
  cin >> s >> N >> K;
  map<string, node> mapn;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp >> mapn[temp].data >> mapn[temp].nxt;
  }
  string firstad, leftad, rightad;
  // for (auto u : mapn) {
  //   if (u.second.data > 0 && u.second.data < K) {
  //     firstad = u.first;
  //   }
  //   if (u.second.data >= K && flag == 0) {
  //     leftad = u.first;
  //     flag = 1;
  //   }
  //   if (u.second.data == K && flag == 1) {
  //     rightad = u.first;
  //     break;
  //   }
  // }
  // if (firstad.empty()) {
  //   firstad = leftad;
  // }
  // if (rightad.empty()) {
  //   rightad = leftad;
  // }
  // for (auto it = mapn.begin(); it != mapn.end(); it++) {
  //   if (it->second.data > mapn[rightad].data) {
  //     string temp = it->second.nxt;
  //     it->second.nxt = mapn[rightad].nxt;
  //     mapn[rightad].nxt = it->first;
  //     it--;
  //     it->second.nxt = temp;
  //     it++;
  //   }
  // }
  // while(s == "-1") {
  //   cout << s 
  // }
  return 0;
}
