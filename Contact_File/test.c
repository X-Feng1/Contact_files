//����������ļ��汾ͨѶ¼�Ĳ���

#include "Contact.h"

void menu()
{
	printf("*****************************\n");
	printf("****  1. ���    2. ɾ�� ****\n");
	printf("****  3. ����    4. �޸� ****\n");
	printf("****  5. ��ʾ    6. ���� ****\n");
	printf("****  0. �˳�            ****\n");
	printf("*****************************\n");
}

int main()
{
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	Initial_Contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��Ҫ���еĲ�����>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
		{
			Add_Contact(&con);
			break;
		}
		case DEL:
		{
			Del_Contact(&con);
			break;
		}
		case SEARCH:
		{
			Search_Contact(&con);
			break;
		}
		case MODIFY:
		{
			Modify_Contact(&con);
			break;
		}
		case SHOW:
		{
			Show_Contact(&con);
			break;
		}
		case SAVE:
		{
			Save_Contact(&con);
			break;
		}
		case EXIT:
		{
			Save_Contact(&con);
			printf("�˳�ͨѶ¼��\n");
			free(con.data);
			con.data = NULL;
			break;
		}
		default:
		{
			printf("����������������룡\n");
			break;
		}
		}
	} while (input);
	return 0;
}