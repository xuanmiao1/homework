#include "student.h"
#include <iostream>

using namespace std;


student::student(int id, const char *user_name)
{
	cout << "���캯��������" << endl;
	this->id = id;

	if (user_name != NULL)
	{
		int len = strlen(user_name);

		name = new char[len + 1];

		strcpy(name, user_name);

	}



}

student::student(const student & r)
{
	this->id = r.id;

	// this->name = r.name;//ǳ����<-----ջ�ϲ���

	if (r.name != NULL)//��ȿ���<---���ϲ���
	{
		int len = strlen(r.name);

		this->name = new char[len + 1];

		strcpy(this->name, r.name);
	}
}


student::~student()
{
	cout << "--��������������--" << endl;

	delete[] name;
}

void student::display()
{
	cout << "ѧ��id  = " << id << endl;

	cout << "����name= " << name << endl;


}