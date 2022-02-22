#include <iostream>
#include <vector>
using namespace std;
vector<int> prime(500000, 1);

int main() {
  for (int i = 2; i * i < 500000; i++) {
    for (int j = 2; i * j < 500000; j++) {
      prime[i * j] = 0;
    }
  }
}
