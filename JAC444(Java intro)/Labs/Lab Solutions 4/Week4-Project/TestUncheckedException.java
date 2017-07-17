public class TestUncheckedException {

	public static void test(int num) throws UnexpectedUserInputException {

		int x = 10;
		int[] ia1 = null, ia2 = new int[2];

		try {
			if (num == 0) {
				x = 20 / num;
			} else if (num == 1) {
				x = ia1.length;
			} else if (num == 2) {
				x = ia2[2];
			} else {
				throw new UnexpectedUserInputException("Your input should be 0-2");
			}
		} 

		catch (ArithmeticException e) {
			System.out.println(e);
			System.out.println(x);
		}

		catch (NullPointerException e) {
			System.out.println(e);
			System.out.println(x);
		}

		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println(e);
			System.out.println(x);
		}
	}

	public static void main(String[] args) {
		System.out.println("Please enter 0, 1, 2 or any other number: ");
		java.util.Scanner sc = new java.util.Scanner(System.in);
		try {
			test(sc.nextInt());
		} catch (UnexpectedUserInputException e) {
			System.out.println(e);
		}
	}
}