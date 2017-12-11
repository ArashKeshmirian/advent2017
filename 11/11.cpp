#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct position {
  int x, y;
};

int distance(position endpos) {
  position pos;
  pos.x = endpos.x;
  pos.y = endpos.y;
  int stepcount = 0;
  while (pos.x != 0 || pos.y != 0) {
    if (pos.x > 0) {
      if (pos.y > 0) {  // ne
        ++stepcount;
        pos.x -= 1;
        pos.y -= 1;
      } else if (pos.y < 0) {  // se
        ++stepcount;
        pos.x -= 1;
        pos.y += 1;
      } else {  // zigzag east
        stepcount += 2;
        pos.x -= 2;
      }
    } else if (pos.x < 0) {
      if (pos.y > 0) {  // nw
        ++stepcount;
        pos.x += 1;
        pos.y -= 1;
      } else if (pos.y < 0) {  // sw
        ++stepcount;
        pos.x += 1;
        pos.y += 1;
      } else {  // zigzag west
        stepcount += 2;
        pos.x += 2;
      }
    } else if (pos.x == 0) {
      if (pos.y > 0) {  // n
        ++stepcount;
        pos.y -= 2;
      } else {  // s
        ++stepcount;
        pos.y += 2;
      }
    }
  }
  return stepcount;
}

int main() {
  string line;
  position pos;
  pos.x = pos.y = 0;
  int maxdistance = 0;
  ifstream myfile("input.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line, ',')) {
      if (line == "n") {
        pos.y += 2;
      } else if (line == "ne") {
        pos.x += 1;
        pos.y += 1;
      } else if (line == "se") {
        pos.x += 1;
        pos.y -= 1;
      } else if (line == "s") {
        pos.y -= 2;
      } else if (line == "sw") {
        pos.x -= 1;
        pos.y -= 1;
      } else if (line == "nw") {
        pos.x -= 1;
        pos.y += 1;
      } else {
        cout << "UNKNOWN ORDINAL" << '\n';
      }
      int dist = distance(pos);
      if (dist > maxdistance) {
        maxdistance = dist;
      }
    }
    myfile.close();
  } else {
    cout << "File open failure\n";
    return 0;
  }
  cout << "movement complete! stats:\n   distance: " << distance(pos)
       << " steps. ";
  cout << "max distance: " << maxdistance << " steps.\n";
  return 0;
}