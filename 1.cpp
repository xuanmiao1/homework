public class Student {
	String name;
	int age;
	String degree;
	public Student() {
	}
	public Student(String name, int age, String degree) {
		super();
		this.name = name;
		this.age = age;
		this.degree = degree;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getDegree() {
		return degree;
	}
	public void setDegree(String degree) {
		this.degree = degree;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	//disPlay为输出参数的方法，需传入一个Student对象。
	public void disPlay(Student s) {
		System.out.println("name:" + s.getName() + ",age:" + s.getAge() + ",degree:" + s.getDegree());
	}
}
==================================
//Undergraduate 类
public class Undergraduate extends Student {
	String specialty;
	// disPlay为输出参数的方法，需传入一个Undergraduate对象。
	public void disPlay(Undergraduate u) {
		System.out.println("name:" + u.getName() + ",age:" + u.getAge() + ",degree:" + u.getDegree() + ",specialty:" + u.getSpecialty());
	}
	public String getSpecialty() {
		return specialty;
	}
	public void setSpecialty(String specialty) {
		this.specialty = specialty;
	}
}
========================================
//Graduate 类
public class Graduate extends Student {
	String studydirection;
	public String getStudydirection() {
		return studydirection;
	}
	public void setStudydirection(String studydirection) {
		this.studydirection = studydirection;
	}
	//disPlay为输出参数的方法，需传入一个Graduate对象。
	public void disPlay(Graduate g) {
		System.out.println("name:" + g.getName() + ",age:" + g.getAge() + ",degree:" + g.getDegree() + ",studydirection:" + g.getStudydirection());
	}
}
============================================
//测试类（创建对象，调用方法，输出参数）
public class Test {
	Student s = new Student();
	Undergraduate u = new Undergraduate();
	Graduate g = new Graduate();
	public void doTest() {
		//设置3个对象的参数
		s.setName("AAA");
		s.setAge(22);
		s.setDegree("dazhuan");
		s.disPlay(s);
		u.setName("BBB");
		u.setAge(23);
		u.setDegree("xueshi");
		u.setSpecialty("math");
		u.disPlay(u);
		g.setName("CCC");
		g.setAge(24);
		g.setDegree("yanjiusheng");
		g.setStudydirection("EC");
		g.disPlay(g);
	}
	public static void main(String[] args) {
		Test t = new Test();
		t.doTest();
	}
}
========================== =