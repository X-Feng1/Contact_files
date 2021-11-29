#include "Contact.h"


void menu2()
{
	printf("*************************\n");
	printf("**** 1.姓名   2.年龄 ****\n");
	printf("**** 3.性别   4.地址 ****\n");
	printf("**** 5.学校   6.全部 ****\n");
	printf("**** 0.退出          ****\n");
	printf("*************************\n");

}

//扩容
void ADD_CAPACITY(struct Contact* ps)
{
	struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (DEFAULT_CAPACITY + 2) * sizeof(struct PeoInfo));
	ps->data = ptr;
	ps->capacity += 2;
	printf("扩容成功!\n");
}


//初始化通讯录
void Initial_Contact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	ps->data = (struct PeoInfo*)malloc(DEFAULT_CAPACITY * sizeof(struct PeoInfo));
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;

	//从已有文件中读取通讯录信息
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("Initial_Contact::%s\n", strerror(errno));
	}
	else
	{
		while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
		{
			if (ps->size == ps->capacity)
			{
				ADD_CAPACITY(ps);
			}
			ps->data[ps->size] = tmp;
			ps->size++;
		}
	}

}



//增加成员
void Add_Contact(struct Contact* ps)
{
	//判断当前通讯录空间是否充足
	if (ps->size == ps->capacity)
	{
		ADD_CAPACITY(ps);
	}
	//添加成员
	printf("请输入成员姓名：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入成员年龄：>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入成员性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入成员地址：>");
	scanf("%s", ps->data[ps->size].addr);
	printf("请输入成员学校：>");
	scanf("%s", ps->data[ps->size].school);

	ps->size++;
	printf("添加成功！\n");
}


//找到成员
int Find_element(struct Contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//删除成员
void Del_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要删除成员的姓名:>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		memcpy(&(ps->data[i]), &(ps->data[i + 1]), (ps->size - 1 - i) * sizeof(struct PeoInfo));
		ps->size--;
	}
	else
	{
		printf("要删除的成员不存在!\n");
	}
}

//查找成员
void Search_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要查找成员姓名：>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "姓名", "年龄", "性别", "地址", "学校");
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}
	else
		printf("要查找的成员不存在！\n");
}


//修改成员信息
void Modify_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要修改的成员姓名：>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		int input = 0;
		do
		{
			menu2();
			printf("请输入要修改的特征：>");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
			{
				printf("请输入修改后的姓名：>");
				scanf("%s", ps->data[i].name);
				break;
			}
			case AGE:
			{
				printf("请输入修改后的年龄：>");
				scanf("%d", &(ps->data[i].age));
				break;
			}
			case SEX:
			{
				printf("请输入修改后的姓名：>");
				scanf("%s", ps->data[i].sex);
				break;
			}
			case ADDR:
			{
				printf("请输入修改后的地址：>");
				scanf("%s", ps->data[i].addr);
				break;
			}
			case SCHOOL:
			{
				printf("请输入修改后的学校：>");
				scanf("%s", ps->data[i].school);
				break;
			}
			case ALL:
			{
				printf("请输入修改后的姓名：>");
				scanf("%s", ps->data[i].name);
				printf("请输入修改后的年龄：>");
				scanf("%d", &(ps->data[i].age));
				printf("请输入修改后的性别：>");
				scanf("%s", ps->data[i].sex);
				printf("请输入修改后的地址：>");
				scanf("%s", ps->data[i].addr);
				printf("请输入修改后的学校：>");
				scanf("%s", ps->data[i].school);
			}
			case EXT:
			{
				printf("退出修改！\n");
				break;
			}
			default:
			{
				printf("输入错误，请重新输入！\n");
				break;
			}
			}
		} while (input);
	}
}



//保存成员信息
void Save_Contact(struct Contact* ps)
{
	int i = 0;
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("Save_Contact::$s", strerror(errno));
	}
	else
	{
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
		}

		fclose(pfWrite);
		pfWrite = NULL;
	}
}



//显示通讯录
void Show_Contact(struct Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "姓名", "年龄", "性别", "地址", "学校");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}
}