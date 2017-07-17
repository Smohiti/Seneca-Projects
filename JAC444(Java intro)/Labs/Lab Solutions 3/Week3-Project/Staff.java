package test;

public class Staff extends Person implements Talkable {
	
	private String title;
	
	public Staff(String firstName, String lastName, String emailAddress, String title) {
		super(firstName, lastName, emailAddress);
		this.title = title;
	}

	@Override
	public void say() {
		System.out.printf("Hello!, My name is %s %s, and my title is %s\n", getFirstName(), getLastName(), title);
	}

	@Override
	public void doing() {
		System.out.println("Working as staff!");
	}
	
	@Override
	public String toString() {
		return String.format("%s [Title = %s, %s]", getClass().getName(), title, super.toString());
	}

}
