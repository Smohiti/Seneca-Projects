import java.util.*;

public class SortStudents {

	public void buildCollection(String sortType) {

		TreeSet<Student> coll = null;
		if (sortType.equals("name"))
			coll = new TreeSet<Student>(new NameComparator()); 

		if (sortType.equals("marks"))
			coll = new TreeSet<Student>(new MarkComparator()); 

		if (sortType.equals("grades"))
			coll = new TreeSet<Student>(new GradeComparator()); 

		coll.add(new Student("Mary", 65, "C"));
		coll.add(new Student("Wei", 95, "A+"));
		coll.add(new Student("John", 75, "B+"));
		coll.add(new Student("Vi", 85, "A"));

		for(Student s : coll)
			System.out.println(s); 
	}

	public static void main(String[] args) {
		SortStudents ss = new SortStudents();
		System.out.println("===Sorted by Names======");
		ss.buildCollection("name");
		System.out.println("===Sorted by Marks======");
		ss.buildCollection("marks");
		System.out.println("===Sorted by Grades======");
		ss.buildCollection("grades");
	}
}

class NameComparator implements Comparator<Student> {

	public int compare(Student e1, Student e2) {
		return e1.name.compareTo(e2.name);
	}
}  

class MarkComparator implements Comparator<Student> {

	public int compare(Student e1, Student e2) {
		if (e1.marks > e2.marks) return 1; else return -1;
	}
}

class GradeComparator implements Comparator<Student> {

	String[] order = {"A+","A","B+","B","C+","C","D"};

	public int compare(Student e1, Student e2) {
		int x = Arrays.asList(order).indexOf(e1.grade);
		int y = Arrays.asList(order).indexOf(e2.grade);

		if (x > y) return 1; else return -1;
	}
}

class Student {
	String name;
	Integer marks;
	String grade;

	public Student(String name, Integer marks, String grade) {
		super();
		this.name = name;
		this.marks = marks;
		this.grade = grade;
	}

	@Override
	public String toString() {
		return "Student [name=" + name + ", marks=" + marks + ", grade=" + grade
				+ "]";
	}
}
