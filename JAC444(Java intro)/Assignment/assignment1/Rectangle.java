package assignment1;

public class Rectangle extends Parallelogram implements Shape {
	
	//Properties
	private double length;
	private double width;
	
	//Default Constructor
	public Rectangle(){}
	
    //Getters
    public double getLength() {
		return length;
	}
    
  	public double getWidth() {
  		return width;
  	}

    //Setters
	public void setLength(double length) {
		this.length = length;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}

	//HashCode
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		long temp;
		temp = Double.doubleToLongBits(length);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(width);
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
		Rectangle other = (Rectangle) obj;
		if(this.perimeter()== other.perimeter()){
		if (Double.doubleToLongBits(length) != Double.doubleToLongBits(other.length))
			return false;
		if (Double.doubleToLongBits(width) != Double.doubleToLongBits(other.width))
			return false;
		}
		return true;
	}
	
}
