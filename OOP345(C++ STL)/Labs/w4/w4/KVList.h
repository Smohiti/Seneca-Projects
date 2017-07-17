// workshop 4
//M.Saeed Mohiti
#pragma once
#define CLIENT
template < typename K, typename V, int SIZE>

class KVList {
	K k[SIZE];
	V v[SIZE];
	size_t tablesize;
public:
	KVList(): tablesize(0) {

	}// default constructor - adopts a safe empty state
	size_t size() const {
		return tablesize;
	} //returns the number of entires in the key - value list
	const K& key(int i) const {
		//if (i >= 0; i < tablesize;)
			return k[i];
	}// returns an unmodifiable reference to the key of element i in the list
	const V& value(int i) const {
		//if (i >= 0; i < tablesize;)
			return v[i];	
	}
	// returns an unmodifiable reference to the value of element i in the list
	KVList& add(const K& kk, const V& vv) {
		if (tablesize < SIZE) {
			k[tablesize] = kk;
			v[tablesize] = vv;
			tablesize++;
		}
		return *this;
	} //adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
	int find(const K& kk) const {
		for (size_t i = 0; i, tablesize; i++)
			if (k[i]==kk)
				return i;
		return 0;
	} // returns the index of the first element in the list with a key equal to k - defaults to 0
	KVList& replace(int i, const K& kk, const V& vv) {
		if (i >= 0 && i < tablesize) {
			k[i] = kk;
			v[i] = vv;
		}
		return *this;
	} //replaces element i in the list with the key and value received and returns a reference to the current object
}; // calss KVList