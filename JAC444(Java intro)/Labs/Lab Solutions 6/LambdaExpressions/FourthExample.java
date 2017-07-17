public class FourthExample {

	public static void ObjectParam() {
		new Runner().run((c) -> {
			System.out.println("run the car: " + c.getName());
		}, new Car("VW"));

	}
}
