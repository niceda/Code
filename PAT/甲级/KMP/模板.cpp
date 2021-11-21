#include <iostream>
#include <vector>
using namespace std;
vector<int> Next, Nextval;
string s;

void getNext(string pattern, int len) {
  int j = -1;
  Next.resize(len);
  Next[0] = -1;
  for (int i = 0; i < len; i++) {
    while (j != -1 && s[j + 1] != s[i])
      j = Next[i];
    if (s[i] == s[j + 1])
      j++;
    Next[i] = j;
  }
}

bool KMP(string text, string pattern) {
  int n = text.length(), m = pattern.length();
  getNext(pattern, m);
  int j = -1;
  // int ans = 0; // ans 表示成功匹配次数
  for (int i = 0; i < n; i++) {
    while(j != -1 && text[i] != pattern[j+1]) {
      j = Next[j];
    }
    if (text[i] == pattern[j+1]) {
      j++;
    }

    if (j == m - 1)  {
      return true;
    }
    // if (j == m - 1) {
    //   ans++;
    //   j = Next[j];
    // }
  }

  return false;
  // return ans;
}

void getNextval(string s, int len) {
  int j = -1;
  Nextval.resize(len);
  Nextval[0] = -1;
  for (int i = 0; i < len; i++) {
    while(j != -1 && s[i] != s[j+1])
      j = Nextval[j];
    if (s[i] == s[j+1])
      j++;
    if (j == -1 || s[i+1] != s[j+1])
      Nextval[i] = j;
    else
      Nextval[i] = Nextval[j];
  }

}

int main() {
  cin >> s;
  return 0;
}
