#include "Class.h"



Class::Class()
{
}


Class::~Class()
{
}

double x1 = 0;//��1
double x2 = 0;//��2

Console.WriteLine("�� ax^2+bx+c=0 �Ľ�");
Console.Write("������a��ֵ��");
double a = Convert.ToInt32(Console.ReadLine());
Console.Write("������b��ֵ��");
double b = Convert.ToInt32(Console.ReadLine());
Console.Write("������c��ֵ��");
double c = Convert.ToInt32(Console.ReadLine());

double dt = b * b - 4 * a * c; //����ֵ

if (dt < 0)
{
	Console.WriteLine("�˷�����ʵ����.");
}
else if (dt == 0)
{
	x1 = -b / 2 * a;
	Console.WriteLine("���̵Ľ�Ϊ��x1=x2= " + x1.ToString("F"));  //����С�������λ
}
else
{
	x1 = (-b + Math.Sqrt(dt)) / 2 * a;
	x2 = (-b - Math.Sqrt(dt)) / 2 * a;
	Console.WriteLine("���̵Ľ�Ϊ��x1= " + x1.ToString("F") + ", x2= " + x2.ToString("F"));
}

Console.ReadKey();