package test;

public class Student extends Person implements Talkable {
	
	private String program;
	
	public Student(String firstName, String lastName, String emailAddress, String program) {
		super(firstName, lastName, emailAddress);
		this.program = program;
	}

	@Override
	public void say() {
		System.out.printf("Hello!, My name is %s %s, and I'm in %s program\n", getFirstName(), getLastName(), program);
	}

	@Override
	public void doing() {
		System.out.println("Studying as student!");
	}
	
	@Override
	public String toString() {
		return String.format("%s [Program = %s, %s]", getClass().getName(), program, super.toString());
	}

}
