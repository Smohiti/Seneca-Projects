public class TestInner {

	public static void main(String[] arg) {

		X x = new X();
		x.printI();

		X.Y y = x.new Y();
		y.printI();

		X.Y inner = new X().new Y();
		inner.printI();

	}
}