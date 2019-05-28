

using namespace std;

namespace itertools{

	template<typename T1,typename T2>
	class zip{
		typename T1::iterator L_Iterable_start;
		typename T2::iterator R_Iterable_start;
		typename T1::iterator L_Iterable_end;
		typename T2::iterator R_Iterable_end;

		public:
			zip(T1 left,T2 right):
			L_Iterable_start( left.begin() ),R_Iterable_start( right.begin() ),
			L_Iterable_end( left.end() ),R_Iterable_end( right.end() ){}


			class iterator{
				typename T1::iterator L_Iterable;
				typename T2::iterator R_Iterable;

				public:
					iterator(typename T1::iterator left,typename T2::iterator right)
					:L_Iterable(left),R_Iterable(right){}

					bool operator!=(const iterator& other)const{
						return L_Iterable != other.L_Iterable || R_Iterable != other.R_Iterable;
					}

					bool operator==(const iterator& other)const{
						return !(this!=other);
					}

					iterator& operator++() {
						++L_Iterable;
						++R_Iterable;
						return *this;
					}

					auto operator*() {
						return make_pair(*L_Iterable,*R_Iterable);

					}

			};

			iterator begin() const {
				return iterator(L_Iterable_start,R_Iterable_start);
			}

			iterator end() const {
				return iterator(L_Iterable_end,R_Iterable_end);
			}
	};


	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
		os << p.first << "," << p.second;
		return os;
	}

	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const zip<T1,T2>& zi) {
		os << "test";
		return os;
	}



}
