public class ThirdExample {

	public static void TwoParams () {
		RunnerTwo r = new RunnerTwo();
    	r.run( (x, y) -> {System.out.println("lambda with two params: " + x + y);}, "I ", "understand");

	}
}
