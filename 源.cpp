#include<iostream>
#include<cstring>
using namespace std;
//定义Person类
class Person {
public:
	friend class Student;
private:
	char name[10];
	char gender;
	int age;
};
//定义Student类
class Student {
public:
	//因为Student类中的函数要用到Person中的数据
	//所以先在Student类中定义一个Person对象
	Person person;
	Student(char myname[10], int myage, char mygender, char myid[10], char mycname[10], int myscore)
	{
		//将学生姓名、年龄、性别赋值给Person对象中的成员数据
		strcpy(person.name, myname);
		person.age = myage;
		person.gender = mygender;
		//剩下的赋值给Student类中的成员数据
		strcpy(id, myid);
		strcpy(cname, mycname);
		score = myscore;
	};
	//定义display()函数，输出学生信息
	void display() {
		//这里注意要加"person."表明是访问另一个类中的成员
		cout << "my name is" << person.name << endl;
		if (person.gender == 'B')
			cout << "I am a boy" << endl;
		else
			cout << "I am a girl" << endl;
		cout << "my age is " << person.age << endl;
		cout << "my id is " << this->id << endl;
		cout << "my class name is" << this->cname << endl;
		cout << "my score is " << this->score << endl;
	}
private:
	char id[10];
	char cname[10];
	int score;
};

//测试部分
int main(void)
{
	Student A("LiMing", 19, 'B', "10123", "1701", 422);
	A.display();
	return 0;
}
