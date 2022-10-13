#include "GraphicEditor.h"
void GraphicEditor::run() 
{
	pStart = NULL;
	static int numOfE = 0;
	cout << "그래픽 에디터 입니다." << endl;

	while (true)  //종료 명령이 나오기까지 계속 진행.
	{
		int selectMenu = UI::selectMenu();

		//1. 도형 추가
		if (selectMenu == 1) {
			int selectShape = UI::selectShape();
			if (numOfE == 0) { // 아무 것도 없을 때 (최초 삽입)
				switch (selectShape) { // 선택된 번호에 따른 Shape 객체 삽입
				//각 case 구문에서 동적바인딩이 일어난다.
				case 1: 
					pStart = new Line(); 
					pStart->type = 1;
					break;
				case 2: 
					pStart = new Circle(); 
					pStart->type = 2;
					break;
				case 3: 
					pStart = new Rect(); 
					pStart->type = 3;
					break;
				default: UI::error();
				}
				pLast = pStart; // Last 포인터를 Start로 지정한다.
			}

			// 최초 삽입이 아닌 경우
			else 
			{ 
				// 선택된 번호에 따른 종류별 Shape 객체를 추가
				// Shape::type 변수는 나중에 통계 정보 메뉴에서 사용 (문제 2 추가조건을 따름)
				switch (selectShape) { 
				case 1: 
					pLast = pLast->add(new Line()); 
					pLast->type = 1;
					break;
				case 2: 
					pLast = pLast->add(new Circle()); 
					pLast->type = 2;
					break;
				case 3: 
					pLast = pLast->add(new Rect()); 
					pLast->type = 3;
					break;
				default: 
					UI::error();
				}
			}
			numOfE++; // 요소 개수 증가
		}

		//2. 도형 삭제
		else if (selectMenu == 2) 
		{ 
			int indexOfDelete = UI::deleteMenu();

			p = pStart;

			// 0번을 삭제일 때
			if (indexOfDelete == 0) { 
				// start를 다음 객체를 가리키게 하고, 요소 개수를 하나 감소.
				pStart = p->getNext(); 
				numOfE--; 
			}

			// 그 이외의 모든 경우
			else if (indexOfDelete <= (numOfE - 1)) 
			{
				Shape *prev = p; 
				Shape *node = p->getNext();
				int num = indexOfDelete;

				//삭제하고자 하는 노드의 인덱스가 1이 아닐 때
				while (indexOfDelete != 1) 
				{
					//현재 노드를 다음 노드로, 다음 노드를 다다음 노드를 가리키게끔 바꾼 뒤, 요소 수를 하나 감소
					prev = node;
					node = node->getNext(); 
					indexOfDelete--;
				}

				prev->setNext(node); // 현재 노드를 다음 노드로 설정.
				numOfE--; // 요소 수르 하나 감소.

				if (numOfE == 1)  pLast = pStart;
				// 남은 요소가 1개일 때, 마지막 노트가 가리키는 주소는 처음 노드의 주소.	​

				if (numOfE == num) pLast = prev;
				delete node; // 삭제할 해당 노드를 해제한다.
			}
			else UI::error();
		}

		//3. 도형 출력
		else if (selectMenu == 3) { // print shape list
			int i = 0; p = pStart;

			// while 문을 이용한 탐색 조건, NULL이 아닐 때 까지!
			while (p != NULL) 
			{ 
				cout << i << " :";

				// 현재 p를 paint 시킨다.
				p->paint(); 

				// 포인터 p가 다음 노드를 가리키게 하고, i 증가
				p = p->getNext(); 
				i++; 
			}
		}

		//4. 통계 정보
		else if (selectMenu == 4) 
		{
			int l = 0; int c = 0; int r = 0;

			p = pStart;

			//카운트 변수에 대한 참조변수.
			int& lineCnt = l;
			int& circleCnt = c;
			int& rectCnt = r;

			//도형 종류별로 수를 센다.
			while (p != NULL) { 
				switch(p->type)
				{
					case 1:
						lineCnt++;
						break;
					case 2:
						circleCnt++;
						break;
					case 3:
						rectCnt++;
						break;
				}
				p=p->getNext();
			}
			cout << endl <<"선의 개수: " << lineCnt << endl;
			cout << "원의 개수: " << circleCnt << endl;
			cout << "사각형의 개수: " << rectCnt << endl << endl;
			
		}

		// 5. 종료
		else if (selectMenu == 5)
		{
			cout << "프로그램을 종료합니다." << endl;
			return;
		}

		// ?: 잘못 눌렀을 경우
		else  UI::error();
	}
}
