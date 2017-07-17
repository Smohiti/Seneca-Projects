package test;

public abstract class Person {
	private String firstName;
	private String lastName;
	private String emailAddress;
	
	public Person(String firstName, String lastName, String emailAddress) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.emailAddress = emailAddress;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setEmailAddress(String emailAddress) {
		this.emailAddress = emailAddress;
	}

	public abstract void doing();
	
	public String toString() {
		return String.format("[firstName=%s, lastName=%s, email=%s]", firstName, lastName, emailAddress);
	}
}