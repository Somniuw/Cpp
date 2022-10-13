#include "PrinterManager.h"
#include <string>
PrinterManager::PrinterManager() 
{
	//업캐스팅이 일어나게 하여 동적바인딩이 되도록 함.
	ink = new InkjetPrinter("Officejet V40", "HP", 5, 10);
	laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	line = new LinePrinter("JP-8800", "퍼스텍", 4, 30);

	int sel=0;
	
	cout << " <System : Printer Manager의 메인 메뉴에 오셨습니다>" << endl <<endl;
	cout << " <System : 원하시는 메뉴를 선택해 주세요>" << endl << " <System : 1번은 프린터 정보, 2번은 잉크/토너/드럼 보충, 3번은 용지 추가, 4번은 인쇄, 5번 이외 아무 키는 프로그램 종료 명령입니다>" << endl;
	

	//메뉴별로 선택
	while (sel != 5)
	{
		cout << endl << " >> 명령 선택: ";
		cin >> sel;
		switch (sel)
		{
		case 1:
			this->info(); //메뉴 1
			break;
			continue;
		case 2:
			this->add(); //메뉴 2
			break;
			continue;
		case 3:
			this->pAdd(); //메뉴 3
			break;
			continue;
		case 4:
			this->printit(); //메뉴 4
			break;
			continue;
		default:
			this->terminate(); //메뉴 5
			break;
		}
	}
}

//메뉴1: 프린터 정보 출력
void PrinterManager::info()
{
	cout << "현재 작동중인 3대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laser->show();
	cout << "라인 : ";
	line->show();
	cout << endl;
}

//메뉴2: 잉크/토너/드럼 보충
void PrinterManager::add()
{
	while (1)
	{
		int printer;
		double amount;

		//2-1
		cout << " 프린터(1:잉크젯, 2:레이저, 3:라인) 선택 >>";
		cin >> printer;
		char op;

		//2-2
		if (printer == 1)
		{
			
			cout << " 추가할 잉크의 양 >>";
			cin >> amount;
			ink->add(amount);

			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				ink->show();
				break;
			}
		}
		else if (printer == 2)
		{
			cout << " 추가할 토너의 양 >>";
			cin >> amount;
			laser->add(amount);
			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				laser->show();
				break;
			}

		}
		else if (printer == 3)
		{
			cout << " 추가할 드럼의 양 >>";
			cin >> amount;
			ink->add(amount);
			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				line->show();
				break;
			}
		}
		else
		{
			cout << "프린터를 잘못 선택했습니다." << endl;
			break; //무한루프를 방지하기 위해 넣었음
		}
		break;
		cout << endl;
	}
}

//메뉴3: 종이 보충
void PrinterManager::pAdd()
{
	while (1)
	{
		//3-1
		int printer, pages;
		cout << " 용지를 보충할 프린터(1:잉크젯, 2:레이저, 3:라인) 선택 >>";
		cin >> printer;
		char op;
		
		cout << " 추가할 페이지 매수 >>";
		cin >> pages;

		//3-2
		if (printer == 1)
		{
			ink->paperAdd(pages);
			
			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				ink->show();
				break;
			}
			else ink->show();
		}
		else if (printer == 2)
		{
			laser->paperAdd(pages);
			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				laser->show();
				break;
			}
			else laser->show();
				
		}
		else if (printer == 3)
		{
			line->paperAdd(pages);
			cout << endl << "추가되었습니다. 더 추가하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
			{
				line->show();
				break;
			}
			else line->show();
		}
		else
		{
			cout << "프린터를 잘못 선택했습니다." << endl;
			break; //무한루프를 방지하기 위해 넣었음
		}
		
		cout << endl;
	}
}

//메뉴4: 인쇄
void PrinterManager::printit()
{
	while (1)
	{
		char op;
		int printer, pages;
		//4-1
		cout << " 프린터(1:잉크젯, 2:레이저, 3:라인) 선택 >>";
		cin >> printer;
		cout << " 인쇄할 페이지 매수 >>";
		cin >> pages;

		//4-2
		if (printer == 1)
		{
			bool cannot;
			ink->cannotPrint(cannot, pages);
			if (!cannot)
			{
				ink->print(pages);
				cout << endl << "프린트하였습니다." << endl;
				ink->show();
				laser->show();
				line->show();

			}
			//4-3
			cout << endl << "계속 프린트 하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
				break;
			else break;
		}
		else if (printer == 2)
		{
			bool cannot;
			laser->cannotPrint(cannot, pages);
			if (!cannot)
			{
				laser->print(pages);
				cout << endl << "프린트하였습니다." << endl;
				ink->show();
				laser->show();
				line->show();
			}
			//4-3
			cout << endl << "계속 프린트 하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
				break;
			else break;
		}
		else if (printer == 3)
		{
			bool cannot;
			line->cannotPrint(cannot, pages);
			if (!cannot)
			{
				line->print(pages);
				cout << endl << "프린트하였습니다." << endl<<endl;
				
				ink->show();
				laser->show();
				line->show();
			}
			//4-3
			cout << endl << "계속 프린트 하시겠습니까?(y/n)>>";
			cin >> op;
			if (op == 'n')
				break;
			else break;
		}
		else
		{
			cout << "프린터를 잘못 선택했습니다." << endl;
			break; //무한루프를 방지하기 위해 넣었음
		}
		cout << endl;
	}
}

//메뉴5: 프로그램 종료
void PrinterManager::terminate() { delete ink, laser, line; }
