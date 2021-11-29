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




//初始化通讯录
void Initial_Contact(struct Contact* ps);

//增加成员
void Add_Contact(struct Contact* ps);

//删除成员
void Del_Contact(struct Contact* ps);

//查找成员
void Search_Contact(struct Contact* ps);

//修改成员信息
void Modify_Contact(struct Contact* ps);

//保存成员信息
void Save_Contact(struct Contact* ps);


//显示通讯录
void Show_Contact(struct Contact* ps);


