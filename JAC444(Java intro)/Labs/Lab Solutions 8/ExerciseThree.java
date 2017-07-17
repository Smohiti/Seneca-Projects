import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

interface Transform {
	String change(String in);
}


public class ExerciseThree {

	public static List<String> modify(List<String> ls, Transform transform) {
		List<String> result = new ArrayList<>(0);
		for (String s : ls)
			result.add(transform.change(s));
		return result;
	}

	public static void main(String[] args) {
		List<String> listOfStrings = Arrays.asList("first", "second", "third", "fourth");

		List<String> los1 = modify(listOfStrings, s -> s + "! ");
		System.out.println(los1);
		List<String> los2 = modify(listOfStrings, s -> s.replace('r', 'x'));
		System.out.println(los2);
		List<String> los3 = modify(listOfStrings, String::toUpperCase);
		System.out.println(los3);
	}
}
