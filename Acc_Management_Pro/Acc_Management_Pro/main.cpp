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
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
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
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> acc[index].id;
	cout << "�̸� : ";
	cin >> acc[index].name;
	cout << "�Աݾ� : ";
	cin >> acc[index].money;
	index++;
}
void InputM()
{
	int id;
	cout << "[��   ��]"<<endl;
	cout << "����ID : ";
	cin >> id;
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (acc[i].id == id)
			{
				int money;
				cout << "�Աݾ� : ";
				cin >> money;
				acc[i].money += money;
				cout << "�ԱݿϷ�" << endl;
				break;
			}
			//else cout << "��ġ�ϴ� ID�� �����ϴ�!" << endl;
		}
	}
	else cout << "������ ���°� �����ϴ�!" << endl;
}
void OutputM()
{
	int id;
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (acc[i].id == id)
			{
				int money;
				cout << "��ݾ� : ";
				cin >> money;
				if (acc[i].money < money) cout << "���� �����մϴ�!" << endl;
				else
				{
					acc[i].money -= money;
					cout << "��ݿϷ�" << endl;
				}
				break;
			}
			//else cout << "��ġ�ϴ� ID�� �����ϴ�!" << endl;
		}
	}
	else cout << "������ ���°� �����ϴ�!" << endl;
}
void PrintAll()
{
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			cout << "����ID : " << acc[i].id << endl;
			cout << "�̸� : " << acc[i].name << endl;
			cout << "�ܾ� : " << acc[i].money << endl;
			cout << endl;
		}
	}
	else cout << "������ ���°� �����ϴ�!" << endl;

}