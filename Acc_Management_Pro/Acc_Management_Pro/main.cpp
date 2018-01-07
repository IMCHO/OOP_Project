#include <iostream>

using namespace std;

typedef struct
{
	int id;
	char name[50];
	int money = 0;
}Account;

Account acc[100];
int index = 0;

void MakeAcc();
void InputM();
void OutputM();
void PrintAll();

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main()
{
	int option;
	while (true)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> option;

		cout << endl << endl;
		switch (option)
		{
		case MAKE:
		{
			MakeAcc();
			break;
		}
		case DEPOSIT:
		{
			InputM();
			break;
		}
		case WITHDRAW:
		{
			OutputM();
			break;
		}
		case INQUIRE:
		{
			PrintAll();
			break;
		}
		case EXIT:
		{
			return 0;
		}
		default:
		{
			break;
		}
		}
		cout << endl << endl;
	}

	return 0;
}

void MakeAcc()
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> acc[index].id;
	cout << "이름 : ";
	cin >> acc[index].name;
	cout << "입금액 : ";
	cin >> acc[index].money;
	index++;
}
void InputM()
{
	int id;
	cout << "[입   금]"<<endl;
	cout << "계좌ID : ";
	cin >> id;
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (acc[i].id == id)
			{
				int money;
				cout << "입금액 : ";
				cin >> money;
				acc[i].money += money;
				cout << "입금완료" << endl;
				break;
			}
			//else cout << "일치하는 ID가 없습니다!" << endl;
		}
	}
	else cout << "생성된 계좌가 없습니다!" << endl;
}
void OutputM()
{
	int id;
	cout << "[출   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (acc[i].id == id)
			{
				int money;
				cout << "출금액 : ";
				cin >> money;
				if (acc[i].money < money) cout << "돈이 부족합니다!" << endl;
				else
				{
					acc[i].money -= money;
					cout << "출금완료" << endl;
				}
				break;
			}
			//else cout << "일치하는 ID가 없습니다!" << endl;
		}
	}
	else cout << "생성된 계좌가 없습니다!" << endl;
}
void PrintAll()
{
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			cout << "계좌ID : " << acc[i].id << endl;
			cout << "이름 : " << acc[i].name << endl;
			cout << "잔액 : " << acc[i].money << endl;
			cout << endl;
		}
	}
	else cout << "생성된 계좌가 없습니다!" << endl;

}