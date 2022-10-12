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

class GamblingGame
{
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



int main() 
{
	int n;
	GamblingGame Game;
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "플레이어 수 입력: ";
	cin >> n;
	Player *P = new Player[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "플레이어" << i + 1 << " 이름: ";
		P[i].getN();
	}

	int j = 0;
	while (true) {
		cout << P[j].call() << ":<Enter>";
		cin.get();
		cout << endl;
		if (Game.start()) {
			cout << P[j].call() << "님 승리!!" << endl;
			break;
		}
		else
		{
			cout << "아쉽군요 !" << endl;
			j++;
			continue;
		}
	}
}
