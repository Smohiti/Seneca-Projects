import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

interface Transform<T, R> {
	R change(T element);
}

public class ExerciseFour {

	public static <T, R> List<R> modify(List<T> list, Transform<T, R> transform) {
		List<R> result = new ArrayList<>(0);
		for (T element : list)
			result.add(transform.change(element));
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

		List<Integer> loi1 = modify(listOfStrings, s -> s.indexOf('r'));
		System.out.println(loi1);

		List<Integer> loi2 = modify(listOfStrings, s -> s.length());
		System.out.println(loi2);

		List<Integer> listOfIntegers = Arrays.asList(11, 12, 13, -1);
		
		List<String> los = modify(listOfIntegers, i -> Integer.toBinaryString(i));
		System.out.println(los);
	}
}
