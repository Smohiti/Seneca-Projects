package test;

public class Meeting {

	public static void main(String[] args) {
		
		Student st1 = new Student("John", "Smith", "jsmith@myseneca.ca", "CPD");
		Student st2 = new Student("Colin", "Thomas", "cthomas@myseneca.ca", "CPD");
		Professor p1 = new Professor("Jordan", "Anastasiade", "jordan.anastasiade@senecacollege.ca", "T1034");
		Professor p2 = new Professor("Wei", "Song", "wei.song@senecacollege.ca", "T2099");
		Staff sf1 = new Staff("Jack", "Brown", "jack.brown@senecacollege.ca", "Admin");
		Staff sf2 = new Staff("Paul", "Miller", "paul.miller@senecacollege.ca", "Technical Support");
		
		Person[] working = new Person[6];
		working[0] = st1;
		working[1] = st2;
		working[2] = p1;
		working[3] = p2;
		working[4] = sf1;
		working[5] = sf2;

		for (int i = 0; i < working.length; i++) {
			System.out.println(working[i].toString());
			working[i].doing();
			System.out.println();
		}
		
		Talkable[] meeting = new Talkable[6];
		meeting[0] = st1;
		meeting[1] = st2;
		meeting[2] = p1;
		meeting[3] = p2;
		meeting[4] = sf1;
		meeting[5] = sf2;
		
		for (Talkable talkable : meeting) {
			talkable.say();
		}

	}

}
