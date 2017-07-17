public class WalkExceptions {

	private Object[] data;

	public WalkExceptions() {
		data = new Object[3];
	}

	public void one() {

		int m = 666, n = 100;
		String s = "pre-test";

		data[2] = new String("java");
		data[1] = new Integer(7);
		data[0] = new Double("99.99");

		try {
			m = Integer.parseInt(data[1].toString());
			try {
				s = (String) data[0];
				System.out.println("... ok ...");
			} catch (ClassCastException e) {
				System.out.println(e);
				n = 0;
			}
			System.out.println("m = " + m + " n = " + n);
			m = m / n;
		} catch (NumberFormatException e) {
			System.out.println("NumberFormatException caught!");
		}
		System.out.println("... return ...");
	}

	public String toString() {

		String s = (String)data[data.length - 1];

		for (int k = 0; k < data.length - 1; k++)
			s += " " + data[k];

		return s;
	}

	public static void main(String[] args) {

		WalkExceptions z = new WalkExceptions();

		try {
			System.out.println(z);
			z.one();
		} catch (Exception e) {
			System.out.println("Exception caught in main ->" + e);
		}

		System.out.println("data = " + z);
	}
}