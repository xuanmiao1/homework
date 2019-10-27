#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Tri
{
public:
	Tri() { sidea = 0;sideb = 0;sidec = 0; }
	Tri(double a, double b, double c) { sidea = a;sideb = b;sidec = c; }
	double operator +(Tri&tri);
	void dispTri();
private:
	double sidea, sideb, sidec;
	double area();
};
double Tri::area()
{
	double s;
	s = (sidea + sideb + sidec) / 2;
	double S;
	S = sqrt(s*(s - sidea)*(s - sideb)*(s - sidec));
	return S;
}
double Tri::operator +(Tri&tri)
{
	return area() + tri.area();
}
void Tri::dispTri()
{
	cout << "三角形的三边为：";
	cout << setfill(' ');
	cout << setw(2) << sidea << "," << setw(2) << sideb;
	cout << "," << setw(2) << sidec << endl;
}
int main()
{
	double a, b, c, i, j, k;
	cout << "请输入第一个三角形三边：";
	cin >> a >> b >> c;
	Tri t1(a, b, c);
	t1.dispTri();
	cout << "请输入第二个三角形三边：";
	cin >> i >> j >> k;
	Tri t2(i, j, k);
	t2.dispTri();
	cout << "两个三角形面积之和为：" << t2 + t1 << endl;
	return 0;
}