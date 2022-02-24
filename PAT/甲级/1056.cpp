#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int np, ng;  
  scanf("%d %d", &np, &ng);
  vector<int> weight(np), playOrder(np), rank(np);
  for (int i = 0; i < np; i++) {
    cin >> weight[i];
  }
  for (int i = 0; i < np; i++) {
    cin >> playOrder[i];
  }
  while(!playOrder.empty()) {
    if (playOrder.size() == 1) {
      rank[playOrder[0]] = 1;
      break;
    }
    int n, temprank; 
    vector<int> nextorder;
    if (playOrder.size() % ng == 0) {
      n = playOrder.size() / ng;
    } else {
      n = playOrder.size() / ng + 1;
    }
    temprank = n + 1;
    for (int i = 0; i < n; i++) {
      int max = -1, index = -1;
      for (int j = i * ng; j < (i + 1) * ng && j < playOrder.size(); j++) {
        if (weight[playOrder[j]] > max) {
          index = playOrder[j];
          max = weight[playOrder[j]];
        }
      }
      for (int j = i * ng; j < (i + 1) * ng && j < playOrder.size(); j++) {
        if (playOrder[j] != index) {
          rank[playOrder[j]] = temprank;
        }
      }
      nextorder.push_back(index);
    }
    playOrder = nextorder;
  }
  for (int i = 0; i < np; i++) {
    if (i != 0) cout << " ";
    cout << rank[i];
  }
  return 0;
} 
