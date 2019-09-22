#include "Class.h"



Class::Class()
{
}


Class::~Class()
{
}

double x1 = 0;//解1
double x2 = 0;//解2

Console.WriteLine("求 ax^2+bx+c=0 的解");
Console.Write("请输入a的值：");
double a = Convert.ToInt32(Console.ReadLine());
Console.Write("请输入b的值：");
double b = Convert.ToInt32(Console.ReadLine());
Console.Write("请输入c的值：");
double c = Convert.ToInt32(Console.ReadLine());

double dt = b * b - 4 * a * c; //Δ的值

if (dt < 0)
{
	Console.WriteLine("此方程无实数解.");
}
else if (dt == 0)
{
	x1 = -b / 2 * a;
	Console.WriteLine("方程的解为：x1=x2= " + x1.ToString("F"));  //保留小数点后两位
}
else
{
	x1 = (-b + Math.Sqrt(dt)) / 2 * a;
	x2 = (-b - Math.Sqrt(dt)) / 2 * a;
	Console.WriteLine("方程的解为：x1= " + x1.ToString("F") + ", x2= " + x2.ToString("F"));
}

Console.ReadKey();