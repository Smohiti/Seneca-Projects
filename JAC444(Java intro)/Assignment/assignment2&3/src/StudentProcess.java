// M.Saeed Mohiti 116236159
import java.util.*;
import java.util.stream.*;

public class StudentProcess {

	static Student[] students = { new Student("Jack", "Smith", 50.0, "IT"), new Student("Aaron", "Johnson", 76.0, "IT"),
			new Student("Maaria", "White", 35.8, "Business"), new Student("John", "White", 47.0, "Media"),
			new Student("Laney", "White", 62.0, "IT"), new Student("Jack", "Jones", 32.9, "Business"),
			new Student("Wesley", "Jones", 42.89, "Media") };

	public static void main(String[] args) {

		List<Student> stList = new ArrayList<>(Arrays.asList(students));

		System.out.println("Task 1:\n");
		System.out.println("Complete Student list:");
		stList.forEach(System.out::println);
		System.out.println("\n");

		System.out.println("Task 2:\n");
		System.out.println("Students who got 50.0-100.0 sorted by grade:");
		List<Student> slist = stList.stream().sorted(Comparator.comparing(Student::getGrade))
				.collect(Collectors.toList());
		slist.removeIf(s -> s.getGrade() < 50.0);
		slist.forEach(name -> System.out.println(name));
		System.out.println("\n");

		System.out.println("Task 3:\n");
		System.out.println("First Student who got 50.0-100.0:");
		Optional<Student> firstS = stList.stream().filter(emp -> emp.getGrade() >= 50.00).findFirst();
		System.out.println(firstS.get());
		System.out.println("\n");

		System.out.println("Task 4:\n");
		System.out.println("Students in ascending order by last name then first:");
		Comparator<Student> byFirstName = (e1, e2) -> e1.getFirstName().compareTo(e2.getFirstName());
		Comparator<Student> byLastName = (e1, e2) -> e1.getLastName().compareTo(e2.getLastName());
		stList.stream().sorted(byLastName.thenComparing(byFirstName)).forEach(e -> System.out.println(e));
		System.out.println("\n");

		System.out.println("Students in descending order by last name then firs");
		stList.stream().sorted(byLastName.reversed().thenComparing(byFirstName.reversed()))
				.forEach(e -> System.out.println(e));
		System.out.println("\n");

		System.out.println("Task 5:\n");
		System.out.println("Unique Student last names:");
		List<String> unique = stList.stream().sorted(byLastName).map(unq -> unq.getLastName()).distinct()
				.collect(Collectors.toList());
		unique.forEach(name -> System.out.println(name));
		System.out.println("\n");

		System.out.println("Task 6:\n");
		System.out.println("Student names in order by last name then first name:");
		stList.stream().sorted(byLastName.thenComparing(byFirstName)).map(s -> s.getName())
				.forEach(e -> System.out.println(e));
		System.out.println("\n");

		System.out.println("Task 7:\n");
		System.out.println("Students by department:");
		Map<String, List<Student>> group = stList.stream().collect(Collectors.groupingBy(p -> p.getDepartment()));
		group.forEach((k, v) -> {
			System.out.println(k);
			System.out.print(" ");
			// v.forEach(System.out::println);
			v.stream().map(n -> n + " \n ").forEach(System.out::print);
			System.out.println();
		});
		// group.forEach((a, p) -> System.out.format("%s:\n %s\n", a, p));
		System.out.println("\n");

		System.out.println("Task 8:\n");
		System.out.println("Count of Students by department:");
		Map<String, Long> counted = stList.stream()
				.collect(Collectors.groupingBy(Student::getDepartment, TreeMap::new, Collectors.counting()));
		counted.forEach((a, p) -> System.out.format("%s has %s Student(s)\n", a, p));
		System.out.println("\n");

		System.out.println("Task 9:\n");
		double s = stList.stream().collect(Collectors.summingDouble(Student::getGrade));
		System.out.format("Sum of Students' grades: %.2f", s);
		System.out.println("\n");

		System.out.println("Task 10:\n");
		double a = stList.stream().collect(Collectors.averagingDouble(Student::getGrade));
		System.out.format("Average of Students' grades: %.2f", a);
		System.out.println("\n");

	}

}
