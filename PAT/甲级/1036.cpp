#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  string name, id;
  int grade;
};

bool cmpM(node a, node b) {
  return a.grade < b.grade;
};

bool cmpF(node a, node b) {
  return a.grade > b.grade;
};

int main() {
  int n;
  cin >> n;
  vector<node> male;
  vector<node> female;
  string name, gender, id;
  int grade;
  for (int i = 0; i < n; i++) {
    cin >> name >> gender >> id >> grade; 
    if (gender == "M") {
      male.push_back(node {
        name, id, grade
      });
    } else if (gender == "F") {
      female.push_back(node {
        name, id, grade
      });
    }
  }
  sort(male.begin(), male.end(), cmpM);
  sort(female.begin(), female.end(), cmpF);

  int flag = 0;
  if (female.size() == 0) {
    cout << "Absent" << endl;
    flag = 1;
  } else {
    cout << female[0].name << " " << female[0].id << endl;
  }
  if (male.size() == 0) {
    cout << "Absent" << endl;
    flag = 1;
  } else {
    cout << male[0].name << " " << male[0].id << endl;
  }
  if (flag == 0) {
    cout << female[0].grade - male[0].grade;
  } else {
    cout << "NA";
  }
  return 0;
}
