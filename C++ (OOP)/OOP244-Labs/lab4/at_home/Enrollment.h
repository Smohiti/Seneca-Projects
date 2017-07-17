///////////////////////////////////////////////////////////
// Name    			 Date 		   Reason
//M.Saeed Mohiti     10/10/2016    workshop4
///////////////////////////////////////////////////////////
#ifndef SICT_Enrollment_H_
#define SICT_Enrollment_H_

namespace ict {
	class Enrollment {
		char name_[30 + 1];
		char code_[10 + 1];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;

	public:
		void setEmpty();
		Enrollment(const char*, const char*, int, int, int);
		Enrollment();
		void set(const char*, const char*, int, int, int, bool enrolled = false);
		bool isEnrolled()const;
		bool hasConflict(const Enrollment &other) const;
		void display(bool nameOnly = false) const;
		bool isValid()const;
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);

	};
}
#endif