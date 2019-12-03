public abstract class Location {

	public abstract double getX();


	public abstract double getY();

	public abstract void move(double x, double y);

	public abstract void draw();
}

public class Point extends Location {
	private double x;
	private double y;

	public Point() {
		this.x = 0;
		this.y = 0;
	}

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	@Override
		public double getX() {
		return x;
	}

	@Override
		public double getY() {
		return y;
	}

	@Override
		public void move(double x, double y) {
		this.x = x;
		this.y = y;

		System.out.println("move to Point: (" + this.getX() + ", " + this.getY() + ")");
	}

	@Override
		public void draw() {
		System.out.println("draw positon: (" + this.getX() + ", " + this.getY() + ")");

	}
}


public class Circle extends Location {
	private Point point;
	private double radius;

	public Circle() {
		this.point = new Point();
		radius = 10;
	}

	public Circle(Point point, double radius) {
		this.point = point;
		this.radius = radius;
	}

	@Override
		public double getX() {
		return point.getX();
	}

	@Override
		public double getY() {
		return point.getY();
	}

	@Override
		public void move(double x, double y) {
		this.point.move(x, y);
	}

	@Override
		public void draw() {
		System.out.println("draw positon: Point (" + this.getX() + ", " + this.getY() + "), radius= " + this.getRadius());
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
}

≤‚ ‘¿‡
==================================== =
public class MyTest {

	public static void main(String[] args) {
		Point p1 = new Point();
		Point p2 = new Point(88, 86.55);
		p1.draw();
		p1.move(120.87, 66.34);
		p2.draw();
		p2.move(666, 777);

		Circle c1 = new Circle();
		c1.draw();
		c1.move(22, 33);
		Circle c2 = new Circle(new Point(55, 66), 33);
		c2.draw();
		c2.move(888, 999);
	}
}
