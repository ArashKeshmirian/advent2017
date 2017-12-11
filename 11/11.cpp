#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct position {
	int x, y;
};

int distance (position endpos) {
	position pos;
	pos.x = endpos.x;
	pos.y = endpos.y;
	
	int stepcount = 0;
	while (pos.x != 0 || pos.y != 0) {
		if (pos.x > 0) {
			if (pos.y > 0) {
				//cout << "ne";
				++stepcount;
				pos.x -= 1;
				pos.y -= 1;
			} else if (pos.y < 0) {
				//cout << "se";
				++stepcount;
				pos.x -= 1;
				pos.y += 1;
			} else { //zigzag east
				cout << "ZIGZAG REQUIRED, NYI. position: (" << pos.x << "," << pos.y << ")\n\n";
				stepcount += 2;
				pos.x -= 2;
			}
		} else if (pos.x < 0) {
			if (pos.y > 0) {
				//cout << "nw";
				++stepcount;
				pos.x += 1;
				pos.y -= 1;
			} else if (pos.y < 0) {
				//cout << "sw";
				++stepcount;
				pos.x += 1;
				pos.y += 1;
			} else {
				cout << "ZIGZAG REQUIRED, NYI. position: (" << pos.x << "," << pos.y << ")\n\n";
				stepcount += 2;
				pos.x += 2;
			}
		} else if (pos.x == 0) {
			if (pos.y > 0) {
				//cout << "n";
				++stepcount;
				pos.y -= 2;
			} else {
				//cout << "s";
				++stepcount;
				pos.y += 2;
			}
		}
		//cout << ",";
	}
	
	return stepcount;
	
}

int main ()
{
    string line;
		position pos;
		pos.x = pos.y = 0;
		int maxdistance = 0;
		ifstream myfile("input.txt");
		if (myfile.is_open()) {
			while (getline(myfile,line,',')) {
				//cout << "move: " << line << ": ";
				if (line == "n") {
					//cout << "north" << '\n';
					pos.y += 2;
				} else if (line == "ne") {
					//cout << "north-east" << '\n';
					pos.x += 1;
					pos.y += 1;
				} else if (line == "se") {
					//cout << "south-east" << '\n';
					pos.x += 1;
					pos.y -= 1;
				} else if (line == "s") {
					//cout << "south" << '\n';
					pos.y -= 2;
				} else if (line == "sw") {
					//cout << "south-west" << '\n';
					pos.x -= 1;
					pos.y -= 1;
				} else if (line == "nw") {
					//cout << "north-west" << '\n';
					pos.x -= 1;
					pos.y += 1;
				}	else {
					cout << "UNKNOWN ORDINAL" << '\n';
				}
				//cout << "position: (" << pos.x << "," << pos.y << ")\n\n";
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

		cout << "\nmovement complete!\n" << distance(pos) << " steps. ";
		cout << "max distance:" << maxdistance << " steps.\n";

		return 0;
}