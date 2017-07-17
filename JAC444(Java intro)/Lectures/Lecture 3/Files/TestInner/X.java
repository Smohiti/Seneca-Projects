public class X {
	private int i = 10;

	public void printI() {
		System.out.println(i + " " + this.new Y().i);
	}

	public class Y {
		private int i = 20;
		
		public void printI() {
			System.out.println(X.this.i + " " + i);
		}	 
	}
}