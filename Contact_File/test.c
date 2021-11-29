//本程序进行文件版本通讯录的测试

#include "Contact.h"

void menu()
{
	printf("*****************************\n");
	printf("****  1. 添加    2. 删除 ****\n");
	printf("****  3. 查找    4. 修改 ****\n");
	printf("****  5. 显示    6. 保存 ****\n");
	printf("****  0. 退出            ****\n");
	printf("*****************************\n");
}

int main()
{
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	Initial_Contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择要进行的操作：>");
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
			printf("退出通讯录！\n");
			free(con.data);
			con.data = NULL;
			break;
		}
		default:
		{
			printf("输入错误，请重新输入！\n");
			break;
		}
		}
	} while (input);
	return 0;
}