import java.util.*;

public class FilterStudents {
	ArrayList<Student> myStudens = new ArrayList<>();

	public FilterStudents() {
		myStudens.add(new Student("John", 55));
		myStudens.add(new Student("Mary", 75));
		myStudens.add(new Student("Wei", 80));
	}

	public void filter(Collection<Student> coll) {		
		for (Iterator<Student> it = coll.iterator(); it.hasNext();)			
			if (!cond(it.next()))
				it.remove();
	}

	private static boolean cond(Student s) {
		return (s.marks < 70) ? false : true;
	}

	public String toString() {
		return "Students who got more than or equal to 70: " + myStudens;
	}

	public static void main(String[] args) {
		FilterStudents filteredStudents = new FilterStudents();
		filteredStudents.filter(filteredStudents.myStudens);
		System.out.println(filteredStudents);		
	}
}
