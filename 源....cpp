#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
	double X, Y;
public:
	Point(double a, double b);
	double GetX();
	double GetY();
	friend double GetLength(Point &A, Point &B);
};
Point::Point(double a, double b)
{
	X = a;
	Y = b;
}
double Point::GetX()
{
	return X;
}
double Point::GetY()
{
	return Y;
}
double GetLength(Point &A, Point &B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}
int main()
{
	Point a(2.1, 5.6);
	Point b(5.1, 9.6);
	cout << "the length betweeen a and b is:" << GetLength(a, b) << endl;
	return 0;
}