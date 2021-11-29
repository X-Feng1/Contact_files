#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX_SCHOOL 20
#define DEFAULT_CAPACITY 3


struct  PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	char school[MAX_SCHOOL];
};

struct Contact
{
	struct PeoInfo* data;
	int size;
	int capacity;
};

enum SELECTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE
};

enum Charter
{
	EXT,
	NAME,
	AGE,
	SEX,
	ADDR,
	SCHOOL,
	ALL
};




//��ʼ��ͨѶ¼
void Initial_Contact(struct Contact* ps);

//���ӳ�Ա
void Add_Contact(struct Contact* ps);

//ɾ����Ա
void Del_Contact(struct Contact* ps);

//���ҳ�Ա
void Search_Contact(struct Contact* ps);

//�޸ĳ�Ա��Ϣ
void Modify_Contact(struct Contact* ps);

//�����Ա��Ϣ
void Save_Contact(struct Contact* ps);


//��ʾͨѶ¼
void Show_Contact(struct Contact* ps);


