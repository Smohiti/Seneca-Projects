//Comparable Interface imposes a total ordering on the objects of each class that implements it. 
//This ordering is referred to as the class's natural ordering, 
//and the class's compareTo method is referred to as its natural comparison method.
//Lists (and arrays) of objects that implement this interface can be sorted automatically by Collections.sort 
//(and Arrays.sort). Objects that implement this interface can be used as keys in a sorted map 
//or as elements in a sorted set, without the need to specify a comparator.

public class OperatingSystem implements Comparable<OperatingSystem> {
	String name;
	float version;

	public OperatingSystem(String name, float version) {
		super();
		this.name = name;
		this.version = version;
	}

	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + Float.floatToIntBits(version);
		return result;
	}


	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (!(obj instanceof OperatingSystem)) {
			return false;
		}
		OperatingSystem other = (OperatingSystem) obj;
		if (name == null) {
			if (other.name != null) {
				return false;
			}
		} else if (!name.equals(other.name)) {
			return false;
		}
		if (Float.floatToIntBits(version) != Float
				.floatToIntBits(other.version)) {
			return false;
		}
		return true;
	}


	public String toString() {
		return "OperatingSystem [name=" + name + ", version=" + version + "]";
	}


	public int compareTo(OperatingSystem o) {
		int compName = name.compareTo(o.name);
		if (compName != 0)
			return compName;
		else 
			return (int)(version*100 - o.version* 100);
	}

}
