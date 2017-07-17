import java.util.*;

interface Predicate<T> {
	boolean test(T element);
}

public class ExerciseTwo {

	public static <T> List<T> filter(List<T> list, Predicate<T> predicate) {
		List<T> result = new ArrayList<>(0);
		for (T element : list)
			if (predicate.test(element))
				result.add(element);
		return result;
	}

	public static void main(String[] args) {
		List<String> listOfStrings = Arrays.asList("first", "second", "third");
		List<String> sol = filter(listOfStrings, s -> (s.length() % 2 == 0 && s.contains("s")));
		System.out.println(sol);

		List<Integer> listOfIntegers = Arrays.asList(1, 2, 3);
		List<Integer> iol = filter(listOfIntegers, i -> (i % 2 == 0));
		System.out.println(iol);		
	}
}


/**
 * A better solution is to use
 * java.util.function.Predicate
 * to filter strings
 */
//import java.util.Arrays;
//import java.util.List;
//import java.util.function.Predicate;
//
//public class ExerciseTwo {
//	public static void filter(List<String> list, Predicate<String> predicate) {
//		for (String s : list)
//			if (predicate.test(s))
//				System.out.println(s + " ");
//	}
//
//	public static void main(String[] args) {
//		List<String> list = Arrays.asList("Java is simple", "Python is simpler", "Lambda" );
//
//		System.out.println("\nPrint all strings:");
//		filter(list, s -> true);
//
//		System.out.println("\nPrint no strings:");
//		filter(list, s -> false);
//
//		System.out.println("\nPrint only Lambda:");
//		filter(list, s -> s.compareTo("Lambda") == 0);
//
//		System.out.println("\nPrint all Strings containing simple:");
//		filter(list, s -> s.contains("simple"));
//	}
//}