#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

//定义通讯录的结构，以及要实现的接口/方法
//定义通讯录结构体
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//动态顺序表
typedef struct PersonInfo SLDataType;

typedef struct ContactList
{
	SLDataType* arr; //存储数据的底层结构
	int capacity;    //记录顺序表的空间大小
	int size;        //记录顺序表当前有效的数据个数
}SLT;

//初始化通讯录
void InitContact(SLT* con);
//添加通讯录数据
void AddContact(SLT* con);
//删除通讯录数据
void DelContact(SLT* con);
//展⽰通讯录数据
void ShowContact(SLT* con);
//查找通讯录数据
void FindContact(SLT* con);
//修改通讯录数据
void ModifyContact(SLT* con);
//销毁通讯录数据
void DestroyContact(SLT* con);