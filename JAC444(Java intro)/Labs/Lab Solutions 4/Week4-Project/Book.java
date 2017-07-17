import java.util.Arrays;

public class Book implements Cloneable {

	private String name;
	private double price;
	private int ISBN;

	public Book(String title, double price, int ISBN) {
		this.name = title;
		this.price = price;
		this.ISBN = ISBN;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public int getISBN() {
		return ISBN;
	}

	public void setISBN(int iSBN) {
		ISBN = iSBN;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Book)) return false;
		Book book = (Book) o;
		if (ISBN != book.ISBN) return false;
		if (Math.abs(price - book.price) > 1e-6) return false;
		if (name != null ? !name.equals(book.name) : book.name != null) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = (name != null) ? name.hashCode() : 0;
		result = 31 * result + new Double(price).hashCode();
		result = 31 * result + ISBN;
		return result;
	}

	@Override
	public String toString() {
		return "Book {" +
				" name = '" + name + '\'' +
				", price = " + price +
				", ISBN = " + ISBN +
				" }";
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

	public static void main(String[] args) {
		Book book = new Book("Java How to Program", 125.99, 94825321);
		System.out.println(book);

		try {
			Book copiedBook = (Book) book.clone();
			System.out.println(copiedBook);

		} catch (CloneNotSupportedException e) {
			System.out.println(book + " not cloned!");
		}
	}

}
