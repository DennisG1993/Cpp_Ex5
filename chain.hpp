
namespace itertools{

	template<typename T1,typename T2>
	class chain{

		typename T1::iterator L_Iterable;
		typename T2::iterator R_Iterable;
		typename T1::iterator L_Iterable_end;
		typename T2::iterator R_Iterable_end;

		public:
			chain(T1 left,T2 right):
			L_Iterable( left.begin() ),
			R_Iterable( right.begin() ),
			L_Iterable_end( left.end() ),
			R_Iterable_end( right.end() ){
			}


			class iterator{
				typename T1::iterator L_Iterable;
				typename T2::iterator R_Iterable;
				typename T1::iterator L_Iterable_end;
				bool isLeft;


				public:
					iterator(typename T1::iterator left,typename T2::iterator right,typename T1::iterator left_end,bool is_left)
					:L_Iterable(left),R_Iterable(right),L_Iterable_end(left_end),isLeft(is_left){

					}

					bool operator!=(const iterator& other)const{
						return L_Iterable != other.L_Iterable || R_Iterable != other.R_Iterable;

					}

					bool operator==(const iterator& other)const{
						return !(  L_Iterable != other.L_Iterable || R_Iterable != other.R_Iterable );
					}

					iterator& operator++() {
						if(isLeft){
							++L_Iterable;

							if(L_Iterable == L_Iterable_end){
								isLeft = false;}
						}else{
							++R_Iterable;
                  }
						return *this;
					}

					const auto& operator*(){
						if(isLeft) return *L_Iterable;
						else return *R_Iterable;
					}


			};

			iterator begin() const{
				return iterator(L_Iterable,R_Iterable,L_Iterable_end, true);
			}

			iterator end() const{
				return iterator(L_Iterable_end,R_Iterable_end,
				L_Iterable_end, false);
			}
	};

	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const chain<T1,T2>& ch) {
		os << "test";
		return os;
	}




}
