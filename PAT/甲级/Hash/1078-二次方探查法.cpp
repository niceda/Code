#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int ssize, n, hashTable[10100];
bool isprime(int num) {
  if (num == 1) return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
void insert(int key) {
  for (int step = 0; step < ssize; step++) {
    int index = (key + step * step) % ssize;
    if (hashTable[index] == 0) {
      hashTable[index] = 1;
      cout << index;
      return ;
    }
  }
  cout << "-";
}


int main() {
  cin >> ssize >> n;
  while (!isprime(ssize)) ssize++;
  for (int i = 0; i < n; i++) {
    int key;
    cin >> key;
    if (i != 0) cout << " ";
    insert(key);
  }
  return 0;
}
