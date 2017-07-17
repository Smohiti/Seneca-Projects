package assignment1;

public class Circle implements Shape {
    
	//Properties
	private double radius;
    
	//Default Constructor
    public Circle() {	}
    
    //Constructor
    public Circle(double radius) {
        this.radius = radius;
    }
    
    //Getters
	public double getRadius() {
		return radius;
	}

	//Setters
	public void setRadius(double radius) {
		this.radius = radius;
	}

	//Perimeter Function
	@Override
    public double perimeter() {
        return 2 * 3.14 * getRadius();
    }
   
	//HashCode
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		long temp;
		temp = Double.doubleToLongBits(getRadius());
		result = prime * result + (int) (temp ^ (temp >>> 32));
		return result;
	}

	//Equals
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Circle other = (Circle) obj;
		if (Double.doubleToLongBits(radius) != Double.doubleToLongBits(other.radius))
			return false;
		return true;
	}
    
}