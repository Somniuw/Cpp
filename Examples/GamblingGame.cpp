#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

class Player {
	string name;
public:
	void getN() { cin >> name; }
	string call() { return name; }
};

class GamblingGame {
	int num[3];
public:
	bool start() {
		for (int i = 0; i < 3; i++) {
			num[i] = rand() % 3;
			srand((unsigned)time(NULL));
		}
		cout << "\t" << num[0] << "\t" << num[1] << "\t" << num[2] << "\t";
		if (num[0] == num[1] && num[0] == num[2] && num[1] == num[2])
			return true;
		else
			return false;
	}
};

int main() {
	int n;
	GamblingGame Game;
	cout << "Type the number of players: ";
	cin >> n;
	Player *P = new Player[n];
	
	for (int i = 0; i < n; i++) {
		cout << "Player" << i + 1 << " Name: ";
		P[i].getN();
	}

	int j = 0;
	while (true) {
		cout << P[j].call() << ":<Enter>";
		cin.get();
		cout << endl;
		if (Game.start()) {
			cout << P[j].call() << "YOU WIN!" << endl;
			break;
		}
		else {
			cout << "Aww... Maybe next time!" << endl;
			j++;
			continue;
		}
	}
}
