package test;

public class Professor extends Person implements Talkable {
	
	private String office;
	
	public Professor(String firstName, String lastName, String emailAddress, String office) {
		super(firstName, lastName, emailAddress);
		this.office = office;
	}

	@Override
	public void say() {
		System.out.printf("Hello!, My name is %s %s, and I'm in %s\n", getFirstName(), getLastName(), office);
	}

	@Override
	public void doing() {
		System.out.println("Teaching as professor!");
	}
	
	@Override
	public String toString() {
		return String.format("%s [Office = %s, %s]", getClass().getName(), office, super.toString());
	}

}
