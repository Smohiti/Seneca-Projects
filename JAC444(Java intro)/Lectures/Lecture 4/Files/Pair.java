public class Pair<F, S> {

	private F first;
	private S second;

	public Pair(F f, S s) {
		first = f;
		second = s;
	}

	public String toString() {
		return "("+ first + ", " + second + ")";
	}

	public static <F, S> Pair<S, F> flip(Pair <F, S> p) {
		Pair<S, F> flipped = new Pair<S, F>(p.second, p.first);
		return flipped;
	}

	public static void main(String[] args) {
		Pair<Integer, String> p = new Pair<>(1, "Test");
		System.out.println(p);
		System.out.println(Pair.<Integer, String>flip(p));//OR SIMPLY AS: System.out.println(Pair.flip(p));
	}
}