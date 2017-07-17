class A {
	public A() {
		System.out.println("A ctr called");
	}
}
/****************************************************/
class X extends A {
	private int i = 10;

	public X() {
		System.out.println("X ctr called");
	}

	public void printI() {
		System.out.println(i + " " + this.new Y().i);
	}

	public class Y {
		private int i = 20;

		public Y() {
			System.out.println("Y ctr called");
		}

		public void printI() {
			System.out.println(X.this.i + " " + i);
		}	 
	}
}
/****************************************************/
class X1 {

	class Y1 extends X.Y {
		Y1(X x) {
			x.super();
			System.out.println("Y1 ctr called");
		}

		public Y1() {
			new X().super();
			System.out.println("Y1 ctr called");
		}

	}
}
/****************************************************/
public class Inner {

	public static void main(String[] arg) {

		X x = new X();
		x.printI();

		X.Y y = x.new Y();
		y.printI();

		X.Y inner = new X().new Y();
		inner.printI();
		
		X1.Y1 x1Y1 = new X1().new Y1(x);
		
		X1.Y1 x1Y1h = new X1().new Y1();

	}
}