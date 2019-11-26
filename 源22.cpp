//example5_03_2.cpp:用类的组合关系实现掷骰子 
2 #include<iostream>
3 #include<ctime>
4 #include<cstdlib>
5 using namespace std;
6

7 class Dice			//骰子类 
8 {
9 public:
	10 		int run()
		11 		{
		12 			return (rand() % 6 + 1);
		13 		}
	14 };
15

16 class Gambler		//赌徒类 
17 {
18 public:
	19 		void play()
		20 		{
		21 			int num1, num2, num3;
		22 			num1 = a.run();
		23 			num2 = b.run();
		24 			num3 = c.run();
		25 			if (num1 == num2 && num1 == num3)
			26 				cout << num1 << " " << num2 << " " << num3 << " 豹子" << endl;
		27 			else if (num1 + num2 + num3 > 10)
			28 				cout << num1 << " " << num2 << " " << num3 << " 大" << endl;
		29 			else
			30 				cout << num1 << " " << num2 << " " << num3 << " 小" << endl;
		31 		}
32 private:
	33 		Dice a, b, c;
	34 };
35

36 int main()
37 {
	38 		Gambler Jack;
	39 		srand(time(NULL));
	40 		Jack.play();
	41 		return 0;
	42 }
