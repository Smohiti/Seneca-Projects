package assignment1;

public class Triangle implements Shape {
	
	//Properties
	private double side1;
	private double side2;
	private double base;
	
	//Default Constructor
	public Triangle(){}
       
	//Getters
   	public double getSide1() {
		return side1;
	}
   	
   	public double getSide2() {
		return side2;
	}
   	
   	public double getBase() {
		return base;
	}
   	
   	//Setters
	public void setSide1(double side1) {
		this.side1 = side1;
	}
	
	public void setSide2(double side2) {
		this.side2 = side2;
	}

	public void setBase(double base) {
		this.base = base;
	}

	//Perimeter Function
    @Override
    public double perimeter() {
        return getSide1() + getSide2() + getBase();
    }

    //HashCode
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		long temp;
		temp = Double.doubleToLongBits(base);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(side1);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(side2);
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
		Triangle other = (Triangle) obj;
		if(this.perimeter()== other.perimeter())
		{
			if (Double.doubleToLongBits(base) != Double.doubleToLongBits(other.base))
				return false;
			if (Double.doubleToLongBits(side1) != Double.doubleToLongBits(other.side1))
				return false;
			if (Double.doubleToLongBits(side2) != Double.doubleToLongBits(other.side2))
				return false;
		}
		return true;
	}
    
   
}
