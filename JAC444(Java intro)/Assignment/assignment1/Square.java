package assignment1;

public class Square extends Rectangle implements Shape {
    
	//Properties
	private double length;

	//Getters
	public double getLength() {
		return length;
	}

	//Setters
	public void setLength(double length) {
		this.length = length;
	}

	//HashCode
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		long temp;
		temp = Double.doubleToLongBits(length);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		return result;
	}

	//Equals
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Square other = (Square) obj;
		if(this.perimeter()== other.perimeter()){
		if (Double.doubleToLongBits(length) != Double.doubleToLongBits(other.length))
			return false;
		}
		return true;
	}
    
   
}