#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

//通讯录程序
//打印菜单
void menu()
{
	printf("********************************\n");
	printf("*****1、添加用户 2、删除用户****\n");
	printf("*****3、查找用户 4、修改用户****\n");
	printf("*****5、展示用户 0、退出    ****\n");
	printf("********************************\n");
}

//扩容
void SLCheckCapacity(SLT* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//realloc申请以字节为单位
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//初始化通讯录
void SLInit(SLT* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void InitContact(SLT* con)
{
	SLInit(con);
}

//添加通讯录数据
void SLPushBack(SLT* ps, SLDataType x)
{
	assert(ps);
	//判断是否扩容
	SLCheckCapacity(ps);

	//空间足够，直接插入
	ps->arr[ps->size++] = x;
}

void AddContact(SLT* con)
{
	PeoInfo info;
	printf("请输入姓名：\n");
	scanf("%s", &info.name);
	printf("请输入性别：\n");
	scanf("%s", &info.sex);
	printf("请输入年龄：\n");
	scanf("%d", &info.age);
	printf("请输入联系电话：\n");
	scanf("%s", &info.tel);
	printf("请输入地址：\n");
	scanf("%s", &info.addr);

	SLPushBack(con, info);
	printf("插入成功！\n");
}

//展⽰通讯录数据
void ShowContact(SLT* con)
{
	printf("%-5s %-5s %-5s %-5s %-5s\n", "姓名", "性别", "年龄", "电话","地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%-5s %-5s %-5d %-5s %-5s\n",
		con->arr[i].name,
		con->arr[i].sex,
		con->arr[i].age,
		con->arr[i].tel,
		con->arr[i].addr);
	}
}

//查找通讯录数据
int FindByName(SLT* con, char name[]) 
{
	for (int i = 0; i < con->size; i++)
	{
		//strcmp是比较2个字符串的大小
		if (0 == strcmp(con->arr[i].name, name)) 
		{
			return i;
		}
	}
	return -1;
}

void FindContact(SLT* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名：\n");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos < 0)
	{
		printf("要查找的用户不存在，查找失败！\n");
		return;
	}
	printf("查找成功！\n");
	printf("%-5s %-5s %-5d %-5s %-5s\n",
		con->arr[pos].name,
		con->arr[pos].sex,
		con->arr[pos].age,
		con->arr[pos].tel,
		con->arr[pos].addr);
}

//修改通讯录数据
void ModifyContact(SLT* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的用户名称:\n");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos < 0) {
		printf("要查找的用户不存在，修改失败！\n");
		return;
	}
	PeoInfo info;
	printf("请输入要修改的姓名：\n");
	scanf("%s", &con->arr[pos].name);
	printf("请输入要修改的性别：\n");
	scanf("%s", &con->arr[pos].sex);
	printf("请输入要修改的年龄：\n");
	scanf("%d", &con->arr[pos].age);
	printf("请输入要修改的联系电话：\n");
	scanf("%s", &con->arr[pos].tel);
	printf("请输入要修改的地址：\n");
	scanf("%s", &con->arr[pos].addr);
	printf("修改成功！\n");
}

//删除通讯录数据
void SLErase(SLT* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//pos以后的数据往前挪动一位
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

void DelContact(SLT* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的用户姓名：\n");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos < 0) {
		printf("要删除的用户不存在，删除失败！\n");
		return;
	}
	SLErase(con, pos);
	printf("删除成功！\n");
}

//销毁通讯录数据
void SLDestroy(SLT* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void DestroyContact(SLT* con)
{
	SLDestroy(con);
}