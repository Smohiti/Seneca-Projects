import java.util.Arrays;

public class Course implements Cloneable {

	private String name;
	private int id;
	private String description;
	private Book[] books;

	public Course(String name, int id, String description, Book[] books) {
		this.name = name;
		this.id = id;
		this.description = description;
		this.books = (books != null) ? (Arrays.copyOf(books, books.length)) : null;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public Book[] getBooks() {
		return books;
	}

	public void setBooks(Book[] books) {
		this.books = (books != null) ? Arrays.copyOf(books, books.length) : null;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Course)) return false;

		Course course = (Course) o;

		if (name != null ? !name.equals(course.name) : course.name != null) return false;
		if (id != course.id) return false;
		if (description != null ? !description.equals(course.description) : course.description != null) return false;
		if (books != null ? !Arrays.equals(books, course.books) : course.books != null) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = (name != null) ? name.hashCode() : 0;
		result = 31 * result + new Integer(id).hashCode();
		result = 31 * result + ( (description != null) ? description.hashCode() : 0 );
		result = 31 * result + ( (books != null) ? Arrays.hashCode(books) : 0 );
		return result;
	}

	@Override
	public String toString() {
		return "Course {" +
				" name = '" + name + '\'' +
				", id = " + id +
				", description = " + description +
				", books = " + Arrays.toString(books) +
				" }";
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		Course course = (Course) super.clone();
		course.books = books.clone();

		for (int i = 0; i < course.books.length; i++) {
			course.books[i] = (Book) books[i].clone();
		}

		return course;
	}

	public static void main(String[] args) {
		Course course = new Course("JAC", 444, "Java for C++ Programmers", new Book[]{ new Book("Java How to Program", 125.99, 94825321), new Book("Big Java", 259.55, 94853426) });
		System.out.println(course);

		try {
			Course copiedCourse = (Course) course.clone();
			System.out.println(copiedCourse);

		} catch (CloneNotSupportedException e) {
			System.out.println(course + " not cloned!");
		}
	}
}
