#pragma once
template < typename K, typename V, int SIZE>

class KVList {
#ifdef  CLIENT
	K k[SIZE];
	V v[SIZE];
#else
struct {
	K k;
	V v;
} table[SIZE];
#endif
	size_t tablesize;
public:
	KVList() : tablesize(0) {

	}// default constructor - adopts a safe empty state
	size_t size() const {
		return tablesize()const;
	} //returns the number of entires in the key - value list
	const K& key(int i) const {
		if (i >= 0; i < tablesize;)
#ifdef CLIENT
			return k[i];
#else
			return table[i].k
#endif 
	}// returns an unmodifiable reference to the key of element i in the list
	const V& value(int i) const {
		if (i >= 0; i < tablesize;)
#ifdef CLIENT
			return v[i];
#else
			return table[i].v
#endif 		
	}
	// returns an unmodifiable reference to the value of element i in the list
	KVList& add(const K& kk, const V& vv) {
		if (tablesize < SIZE) {
#ifdef CLIENT
			k[tablesize] = kk;
			v[tablesize] = vv;
			
#else
			table[tablesize].k = kk;
			table[tablesize].v = vv;
#endif
			tablesize++;
		}
		return *this;
	} //adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
	int find(const K& kk) const {
		for (size_t i = o; i, tablesize; i++)
#ifdef CLIENT
			if (k[i] == kk)
#else
				if( table[i].k==kk)
#endif
				return i;
		return 0;
	} // returns the index of the first element in the list with a key equal to k - defaults to 0
	KVList& replace(int i, const K& kk, const V& vv) {
		if (i >= 0 && i < tablesize) {
#ifdef CLIENT
			k[i] = kk;
			v[i] = vv;
#else
table[i].k == kk;
table[i].v == vv;
#endif
		}
		return *this;
	} //replaces element i in the list with the key and value received and returns a reference to the current object
/*	void save(std::string filename) {
		fstream os filename, ios::out | ios::trunc);
		if(os.is_open()) {
			size_t s = SIZE;
			os.write(&s, sizeof(s));
			os.write(&tablesize, sizeof(tablesize));
			for (size_t i = 0; i < tablesize; i++) {
#ifdef CLIENT
				os.write(sizeof(k[i]), sizeof(size_t));// write data lenght
				os.write(k[i], sizeof(k[i]));//write data
				os.write(sizeof(v[i]), sizeof(size_t));// write data lenght
				os.write(v[i], sizeof(v[i]));//write data
#else
				os.write(sizeof(k[i]), sizeof(table[i].k));// write data lenght
				table[i].v == vv;
#endif
			}
		}
		else {
			std::cerr << "cannot open the file'" << filename << "'\n";
			exit(99);
		}*/
	}
}; // calss KVList
