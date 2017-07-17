#include "CString.h"

namespace w1 {
	CString::CString(char* str) {
		if (str == NULL) {
			str_[0] = '\0';
			return;
		}

		strncpy(str_, str, MAX);
		str_[MAX] = '\0';
	}

	void CString::display(std::ostream& os) {
		os << str_;
	}

	std::ostream& operator<<(std::ostream& os, CString cs) {
		static int calls = 0;
		os << calls++ << ": ";
		cs.display(os);

		return os;
	}
}