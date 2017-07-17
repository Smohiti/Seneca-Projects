import java.util.Arrays;

//Our implementation of clone method is often called: SHALLOW CLONE, 
//However, if you have a class with mutable fields, 
//you need to override clone method properly to clone all of its mutable fields 
//by calling clone() individually on these fields after super.clone()
//Check Course.java for DEEP CLONE

public class Book implements Cloneable {
	String title;
	String[] authors;
	int ISBN;

	public Book(String title, String[] authors, int ISBN) {
		this.title = title;
		this.authors = authors;
		this.ISBN = ISBN;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Book)) return false;
		Book book = (Book) o;
		if (ISBN != book.ISBN) return false;
		if (!Arrays.equals(authors, book.authors)) return false;
		if (!title.equals(book.title)) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = title.hashCode();
		result = 31 * result + Arrays.hashCode(authors);
		result = 31 * result + ISBN;
		return result;
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

	@Override
	public String toString() {
		return "Book {" +
				"title='" + title + '\'' +
				", authors=" + Arrays.toString(authors) +
				", ISBN=" + ISBN +
				'}';
	}

	public static void main(String[] args) {
		String[] sa = new String[]{ "Peter L.", "Jordan A." };
		Book book = new Book("JavaCourse", sa, 94825321);
		System.out.println(book);

		try {
			Book copyBook = (Book) book.clone();
			System.out.println(copyBook);
		} catch (CloneNotSupportedException e) {
			System.out.println("caught " + e.getMessage() + ", not cloned!");
		}

	}
}
