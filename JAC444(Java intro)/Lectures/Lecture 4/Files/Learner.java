public class Learner implements Cloneable {

	public String name;
	public Address address;

	public Learner(String n, Address a) {
		name = n;
		address = a;
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {	
		return super.clone();
	}

	@Override
	public String toString() {
		return "Learner name= " + name + ", address= " + address ;
	}

	public static void main(String[] args) throws CloneNotSupportedException {
		Address a = new Address("The Pond Road", 70);
		Learner learner = new Learner("John", a);
		Learner cloned = null;
		
		//clone learner
		if(learner instanceof Cloneable){
			cloned = (Learner)learner.clone();
		}
		System.out.println("Learner Object = " + learner);

		// LET US change the address of the cloned learner to "Bloor"
		cloned.address.setStreet("Bloor");
		cloned.address.setNumber(10);
		// It seems that we did NOT change the Learner Object (we changed only the Cloned Object)
		// Although we change only the address of the cloned learner, the initial learner address is changed as well

		System.out.println("Cloned  Object = " +cloned);	
		System.out.println("Learner Object = " + learner);
	}
}