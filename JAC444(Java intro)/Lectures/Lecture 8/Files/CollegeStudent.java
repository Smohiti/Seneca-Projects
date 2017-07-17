//a program that sorts students using the following algorithm:
//The students will be sorted using their GPA, 
//If two students have the same GPA, their IDs will be used to sort them
import java.util.*;

public class CollegeStudent extends Student {

	private int gpa;
	private long id;

	public CollegeStudent(String firstName, String lastName, int gpa, long id) {
		super(firstName, lastName);
		this.gpa = gpa;
		this.id = id;
	}

	private static final Comparator<CollegeStudent> STUDENT_ORDER = new Comparator<CollegeStudent>() {
		public int compare(CollegeStudent s1, CollegeStudent s2) {
			int gpaCmp = s1.gpa - s2.gpa;
			if (gpaCmp != 0)
				return gpaCmp;
			return s1.id < s2.id ? -1 : (s1.id == s2.id ? 0 : 1);
		}
	};

	public String toString() {
		return super.toString() + "[GPA=" + gpa + ", id=" + id + "]";
	}

	public static void main(String[] args) {
		CollegeStudent[] cs = { new CollegeStudent("Abe", "Vu", 345, 123321),
				new CollegeStudent("Eric", "Marx", 340, 234432),
				new CollegeStudent("Cuong", "Marx", 340, 456654),
				new CollegeStudent("Oscar", "Savage", 345, 987789),
				new CollegeStudent("John", "Savage", 340, 876678) };

		List<CollegeStudent> list = Arrays.asList(cs);
		Collections.sort(list, STUDENT_ORDER);
		System.out.println(list);
	}
}
