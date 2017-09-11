// M.Saeed Mohiti 116236159
public class Student {

	private String firstName;
	private String lastName;
	private double grade;
	private String department;

	public Student(String firstName, String lastName, double grade, String department) {

		if (firstName == null || lastName == null || grade == 0 || department == null)
			throw new NullPointerException();

		this.firstName = firstName;
		this.lastName = lastName;
		this.grade = grade;
		this.department = department;
	}

	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public double getGrade() {
		return grade;
	}

	public String getDepartment() {
		return department;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public void setLastNam(String lastName) {
		this.lastName = lastName;
	}

	public void setGrade(double grade) {
		this.grade = grade;
	}

	public void setDepartment(String department) {
		this.department = department;
	}

	public String getName() {

		return firstName + " " + lastName;
	}

	@Override
	public String toString() {
		// return firstName + " " + lastName + " " + grade + " " + department;
		return String.format("%s\t%3s\t\t%-7.2f\t%s", firstName, lastName, grade, department);

	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((department == null) ? 0 : department.hashCode());
		result = prime * result + ((firstName == null) ? 0 : firstName.hashCode());
		long temp;
		temp = Double.doubleToLongBits(grade);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		result = prime * result + ((lastName == null) ? 0 : lastName.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Student other = (Student) obj;
		if (department == null) {
			if (other.department != null)
				return false;
		} else if (!department.equals(other.department))
			return false;
		if (firstName == null) {
			if (other.firstName != null)
				return false;
		} else if (!firstName.equals(other.firstName))
			return false;
		if (Double.doubleToLongBits(grade) != Double.doubleToLongBits(other.grade))
			return false;
		if (lastName == null) {
			if (other.lastName != null)
				return false;
		} else if (!lastName.equals(other.lastName))
			return false;
		return true;
	}

}
