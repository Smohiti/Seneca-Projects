// solution for 1 * 1 + 2 * 2 + · · · + n * n
public class Series {

	public static int iteration(int n) {
		int sum = 0;
		for (int i = 1; i <=n; i++)
			sum += i * i;
		return sum;
	}

	public static int recursive(int n) {
		if (n == 1)
			return 1;
		else
			return n * n + recursive(n-1);
	}

	public static void main(String[] args) {
		System.out.println(recursive(7));
		System.out.println(iteration(7));
	}
}