#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Grade {
  int id;
  int grade;
};

struct Rank {
  char c;
  int rank;
};

int cmp(Grade a, Grade b) {
  return a.grade != b.grade ? b.grade < a.grade : a.id < b.id;
}

int main() {
  int n, m;
  cin >> n >> m;
  map<int, Rank> rank;
  vector<Grade> cpl;
  vector<Grade> math;
  vector<Grade> eg;
  vector<Grade> average;
  int id;
  int a, b, c;
  for (int i = 0; i < n; i++) {
    cin >> id >> a >> b >> c;
    cpl.push_back(Grade{id, a});
    math.push_back(Grade{id, b});
    eg.push_back(Grade{id, c});
    average.push_back(Grade{id, (int)((a + b + c) / 3.0 + 0.5)});
  }
  string cid, mid, eid;
  sort(cpl.begin(), cpl.end(), cmp);
  sort(math.begin(), math.end(), cmp);
  sort(eg.begin(), eg.end(), cmp);
  sort(average.begin(), average.end(), cmp);

  int index = 1;
  for (auto it = average.begin(); it != average.end(); it++) {
    rank[it->id].rank = index++;
    rank[it->id].c = 'A';
  }

  index = 1;
  for (auto it = cpl.begin(); it != cpl.end(); it++) {
    if (index < rank[it->id].rank) {
      rank[it->id].rank = index;
      rank[it->id].c = 'C';
    }
    index++;
  }

  index = 1;
  for (auto it = math.begin(); it != math.end(); it++) {
    if (index < rank[it->id].rank) {
      rank[it->id].rank = index;
      rank[it->id].c = 'M';
    }
    index++;
  }

  index = 1;
  for (auto it = eg.begin(); it != eg.end(); it++) {
    if (index < rank[it->id].rank) {
      rank[it->id].rank = index;
      rank[it->id].c = 'E';
    }
    index++;
  }

  for (int i = 0; i < m; i++) {
    cin >> id;
    if (rank.find(id) != rank.end()) {
      cout << rank[id].rank << " " << rank[id].c << endl;
    } else {
      cout << "N/A" << endl;
    }
  }
  return 0;
}
