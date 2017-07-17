package assignment1;

public class Parallelogram  implements Shape {
	
	private double length;
	private double width;
	private double height;
    
	//Default Constructor
    public Parallelogram() {	}
    
    //Getters
    public double getLength() {
		return length;
	}
  
  	public double getWidth() {
  		return width;
  	}

  	public double getHeight() {
  		return height;
  	}

    //Setters
	public void setLength(double length) {
		this.length = length;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	
	//Perimeter Function
    @Override
    public double perimeter() {
        return 2 * (getLength() + getWidth());
    }

    //HashCode
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		long temp;
		temp = Double.doubleToLongBits(height);
		result = prime * result + (int) (temp ^ (temp >>> 32));
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
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Parallelogram other = (Parallelogram) obj;
		if(this.perimeter()== other.perimeter()){
		if (Double.doubleToLongBits(height) != Double.doubleToLongBits(other.height))
			return false;
		if (Double.doubleToLongBits(length) != Double.doubleToLongBits(other.length))
			return false;
		if (Double.doubleToLongBits(width) != Double.doubleToLongBits(other.width))
			return false;
		}
		return true;
	}
	

}
