#include "Contact.h"


void menu2()
{
	printf("*************************\n");
	printf("**** 1.����   2.���� ****\n");
	printf("**** 3.�Ա�   4.��ַ ****\n");
	printf("**** 5.ѧУ   6.ȫ�� ****\n");
	printf("**** 0.�˳�          ****\n");
	printf("*************************\n");

}

//����
void ADD_CAPACITY(struct Contact* ps)
{
	struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (DEFAULT_CAPACITY + 2) * sizeof(struct PeoInfo));
	ps->data = ptr;
	ps->capacity += 2;
	printf("���ݳɹ�!\n");
}


//��ʼ��ͨѶ¼
void Initial_Contact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	ps->data = (struct PeoInfo*)malloc(DEFAULT_CAPACITY * sizeof(struct PeoInfo));
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;

	//�������ļ��ж�ȡͨѶ¼��Ϣ
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



//���ӳ�Ա
void Add_Contact(struct Contact* ps)
{
	//�жϵ�ǰͨѶ¼�ռ��Ƿ����
	if (ps->size == ps->capacity)
	{
		ADD_CAPACITY(ps);
	}
	//��ӳ�Ա
	printf("�������Ա������>");
	scanf("%s", ps->data[ps->size].name);
	printf("�������Ա���䣺>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�Ա�>");
	scanf("%s", ps->data[ps->size].sex);
	printf("�������Ա��ַ��>");
	scanf("%s", ps->data[ps->size].addr);
	printf("�������ԱѧУ��>");
	scanf("%s", ps->data[ps->size].school);

	ps->size++;
	printf("��ӳɹ���\n");
}


//�ҵ���Ա
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

//ɾ����Ա
void Del_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫɾ����Ա������:>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		memcpy(&(ps->data[i]), &(ps->data[i + 1]), (ps->size - 1 - i) * sizeof(struct PeoInfo));
		ps->size--;
	}
	else
	{
		printf("Ҫɾ���ĳ�Ա������!\n");
	}
}

//���ҳ�Ա
void Search_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫ���ҳ�Ա������>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "����", "����", "�Ա�", "��ַ", "ѧУ");
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}
	else
		printf("Ҫ���ҵĳ�Ա�����ڣ�\n");
}


//�޸ĳ�Ա��Ϣ
void Modify_Contact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫ�޸ĵĳ�Ա������>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		int input = 0;
		do
		{
			menu2();
			printf("������Ҫ�޸ĵ�������>");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
			{
				printf("�������޸ĺ��������>");
				scanf("%s", ps->data[i].name);
				break;
			}
			case AGE:
			{
				printf("�������޸ĺ�����䣺>");
				scanf("%d", &(ps->data[i].age));
				break;
			}
			case SEX:
			{
				printf("�������޸ĺ��������>");
				scanf("%s", ps->data[i].sex);
				break;
			}
			case ADDR:
			{
				printf("�������޸ĺ�ĵ�ַ��>");
				scanf("%s", ps->data[i].addr);
				break;
			}
			case SCHOOL:
			{
				printf("�������޸ĺ��ѧУ��>");
				scanf("%s", ps->data[i].school);
				break;
			}
			case ALL:
			{
				printf("�������޸ĺ��������>");
				scanf("%s", ps->data[i].name);
				printf("�������޸ĺ�����䣺>");
				scanf("%d", &(ps->data[i].age));
				printf("�������޸ĺ���Ա�>");
				scanf("%s", ps->data[i].sex);
				printf("�������޸ĺ�ĵ�ַ��>");
				scanf("%s", ps->data[i].addr);
				printf("�������޸ĺ��ѧУ��>");
				scanf("%s", ps->data[i].school);
			}
			case EXT:
			{
				printf("�˳��޸ģ�\n");
				break;
			}
			default:
			{
				printf("����������������룡\n");
				break;
			}
			}
		} while (input);
	}
}



//�����Ա��Ϣ
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



//��ʾͨѶ¼
void Show_Contact(struct Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "����", "����", "�Ա�", "��ַ", "ѧУ");
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