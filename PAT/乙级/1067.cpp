#include <iostream>
using namespace std;

int main() {
  string password, t;
  int N;
  cin >> password >> N >> t;
  getchar();
   while (t != "#" && N != 0) {

    if (t == password) {
      cout << "Welcome in";
      break;
    } else {
      cout << "Wrong password: " << t << endl;
    }
    getline(cin, t);
    N--;
  }
  if (N == 0)
    cout << "Account locked";
  return 0;
}
