/*************************************************
2 ** 功能 : 类三种继承的定义形式,三种继承关系的深刻理解
3 ** 作者 : tsingke
4 ** 时间 : 2019-11-25 / 21:37
5 ***************************************************/
6

7 #include <iostream>
8 #include <cstdlib>
9 #include <windows.h>
10

11 using namespace std;
12

13

14 class A            //作为基类 
15 {
	16 //------------------成员数据------------------ 
		17

18 public:
	19 	int a_pub;
20 protected:
	21 	int a_pro;
22 private:
	23 	int a_pri;
	24 //------------------成员函数------------------ 
25 public:
	26 	A(int pub = 0, int pro = 0, int pri = 0)  //有参构造 
		27 	{
		28 		cout << "A() is called" << endl;
		29

			30 		this->a_pub = pub;
		31 		this->a_pro = pro;
		32 		this->a_pri = pri;
		33

			34

			35 	}
	36 	~A()//析构函数 
		37 	{
		38 		cout << "~A() is called" << endl;
		39 		getchar();
		40

			41 	}
	42

		43 	void dispaly()
		44 	{
		45 		cout << "基类对象成员数据:" << a_pub << " " << a_pro << " " << a_pri << endl;
		46 	}
	47

		48

		49 };
50

51 //--------------------研究三种不同的继承方式------------------------ 
52 class B :public A  //公有继承 
53 {
54 private:
	55 	int bb;
	56

57 public:
	58 	B(int b = 2) :A(2, 2, 2)
		59 	{
		60 		this->bb = b;
		61 		cout << "B() is called" << endl;
		62 	}
	63 	~B()
		64 	{
		65 		cout << "~B() is called" << endl;
		66 		getchar();
		67

			68 	}
	69

		70 	void display()//探索公有继 
		71 	{
		72 		//基类数据传承探索 
			73 		a_pub = 200;//a_pub仍为公有数据,子类内可以直接访问 
		74 		a_pro = 200;//a_pro仍为保护数据,子类内可以直接访问 
		75 		//a_pri = 200;//报错,基类私有成员在子类不可见 
			76

			77 		//基类函数传承探索 
			78 		A::dispaly();
		79 		cout << "自身添加数据成员: bb = " << bb << endl;
		80

			81

			82 	}
	83

		84 };
85

86 class C : protected A //保护继承 
87 {
	88

89 private:
	90 	int cc;
91 public:
	92 	C(int c = 3) :A(3, 3, 3)
		93 	{
		94 		cout << "C() is called" << endl;
		95

			96 		this->cc = c;
		97 	}
	98 	~C()
		99 	{
		100 		cout << "~C() is called" << endl;
		101 		getchar();
		102

			103

			104 	}
	105

		106 	void display()//探索保护继承 
		107 	{
		108 		//基类数据传承探索 
			109 		a_pub = 300;//a_pub变为保护数据,类内可以直接访问 
		110 		a_pro = 300;//a_pro变为保护数据,类内可以直接访问 
		111 		//a_pri = 300;//报错,基类私有成员在子类不可见 
			112

			113 		//基类函数传承探索 
			114 		A::dispaly();
		115 		cout << "自身添加数据成员: cc = " << cc << endl;
		116

			117

			118 	}
	119 };
120

121 class D : private A  //私有继承 
122 {
	123

124 private:
	125 	int dd;
126 public:
	127 	D(int d = 4) : A(4, 4, 4)
		128 	{
		129 		cout << "D() is called" << endl;
		130

			131 		this->dd = d;
		132 	}
	133

		134 	~D()
		135 	{
		136 		cout << "~D() is called" << endl;
		137 		getchar();
		138

			139 	}
	140 	void display()//探索私有继承 
		141 	{
		142 		//基类数据传承探索 
			143 		a_pub = 400;//a_pub变为私有数据,子类内可以直接访问 
		144 		a_pro = 400;//a_pro变为私有数据,子类内可以直接访问 
		145 		//a_pri = 400;//报错,基类私有成员在子类不可见 
			146

			147 		//基类函数传承探索 
			148 		A::dispaly();
		149 		cout << "自身添加数据成员: dd = " << dd << endl;
		150

			151

			152 	}
	153 };
154

155 /*----------------------------------*
156           Main Function
157 *-----------------------------------*/
158

159 int main()
160 {
	161

		162 	//功能1:通过比较类的大小,证明无论哪种继承方式都会全盘接受基类成员,包括私有的成员 
		163

		164 #if 1
		165

		166 	cout << "基类A的大小为: " << sizeof(A) << endl;
	167 	cout << "--类B的大小为: " << sizeof(B) << endl;
	168 	cout << "--类C的大小为: " << sizeof(C) << endl;
	169 	cout << "--类D的大小为: " << sizeof(D) << endl;
	170

		171 	cout << "---------------------------------" << endl;
	172

		173 #endif
		174
		175

		176 	//功能2:构造函数和析构函数的调用 
		177 #if 1
		178 	A a;
	179 	cout << "---------------" << endl;
	180

		181 	B b;
	182 	cout << "---------------" << endl;
	183

		184

		185 	C c;
	186 	cout << "---------------" << endl;
	187

		188

		189 	D d;
	190 	cout << "---------------" << endl;
	191

		192 #endif
		193

		194 	//功能3:三种继承的使用(类外访问探索) 
		195

		196 #if 0
		197 	//------------类B--公有继承--类A--------------- 
		198 	B b;//派生类B的对象 
	199

		200 	  b.a_pub = 200; //正确, 子类内仍然为公有成员,类内外均可访问 
	201 	//b.a_pro = 200; //错误,子类内仍然为保护成员,类内可直接访问,类外部可以 
		202 	//b.a_pri = 200; //错误,基类私有成员在子类内外均不可见 
		203

		204 	//b.dispaly();   //正确,访问的是子类自身的公有成员 
		205 	//b.A::dispaly();//正确, 子类内函数仍然为公有成员,类内外均可访问 
		206

		207 #endif
		208
		209 #if 0
		210 	//------------类C--保护继承--类A--------------- 
		211 	C c;//派生类C的对象 
	212 	//c.a_pub = 300;//错误,变为子类保护成员,无法类外直接访问 
		213 	//c.a_pro = 300;//错误,变为子类保护成员,无法类外直接访问 
		214 	//c.a_pri = 300;//错误,基类私有成员在子类内外均不可见 
		215

		216 	//c.display();    //正确,访问的是子类自身的公有成员 
		217 	//c.A::dispaly(); //错误,变为子类的保护函数,不可类外访问 
		218

		219
		220 #endif
		221

		222 #if 0
		223 	//------------类D--私有继承--类A--------------- 
		224

		225 	D d;//派生类D的对象 
	226

		227 	//d.a_pub = 400; //报错,变为子类的私有成员,无法类外直接访问 
		228 	//d.a_pro = 400; //报错,变为子类的私有成员,无法类外直接访问 
		229 	//d.a_pri = 400; //报错,基类私有成员在子类内外均不可见 
		230

		231 	//d.dispaly();    //报错,变为子类私有成员,无法类外直接访问 
		232 	//d.A::dispaly(); //错误,继承后变为子类私有函数,无法类外直接访问 
		233

		234 #endif
		235
		236 	system("pause");
	237
		238 	return 0;
	239 }