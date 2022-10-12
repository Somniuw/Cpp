#include <iostream>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Player {
	int num;
	int tmp;
	int& wn = num;
	int& T = tmp;
	string *pname;

public:
	Player(int);
	~Player() {
		delete[] pname;
	}
	string getName();
};

Player::Player(int n)
{
	wn = n, T = -1;
	pname = new string[wn];
	for (int i = 0; i < wn; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
		cin >> pname[i];
	}
}

string Player::getName()
{
	T++;
	if (T >= num)
		T = 0;
	string named = pname[T];
	return named;
}

class WordGame 
{
	int num;
	string *ar;
	string  *str;
	string prev, next;

public:
	WordGame();
	void game();
};

WordGame::WordGame() { prev = "아버지"; }

void WordGame::game() 
{
	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇 명입니까? ";
	cin >> num;	

	Player P(num);
	string named;

	int index = 0;
	string str[500] = { "아버지", };

	cout << "시작 단어는 아버지 입니다." << endl;
	while (1)
	{
		named = P.getName();
		cout << named << ">>";
		cin >> next;

		int size = prev.size();
		if (index != 499 && prev.at(size - 2) == next.at(0) && prev.at(size - 1) == next.at(1)) //
		{
			for (int i = 0; i < 500; i++) //진행하면서 사용했던 단어들을 저장했던 배열 원소와 비교.
			{
				if (str[i] == next)  //만약 전에 사용했던 단어와 일치하면 
				{
					cout << named << "이 졌습니다" << endl;
					return; //패배 처리하고 게임 종료.
				}
				continue;
			}
			str[++index] = next; //
			prev = next;
		}
		else if (index == 499) //사용자 사전이 다 찼을 경우 (500번째 단어가 나왔을 때)
		{
			cout << "무승부!" << endl;
			break; //무승부 처리하고 게임 종료.
		}
		else  //앞글자를 틀렸을 경우
		{
			cout << named << "이 졌습니다" << endl;
			break; //해당 플레이어를 패배처리 하고 종료.
		}
	}
}

int main() 
{
	WordGame G;
	G.game();
	return 0;
}
