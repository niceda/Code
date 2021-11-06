#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, temp;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    int total, laoshi = temp, stu = 0, sum = 0;
    for (int j = 1; j < N; j++) {
      cin >> temp;
      if(temp >= 0 && temp <= M) {
        stu += temp;
        sum++;
      }
    }
  }
  return 0;
}
