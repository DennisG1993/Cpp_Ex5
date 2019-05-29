#pragma once
#include <iostream>

namespace itertools{
	
	template<typename T1, typename T2>

	class product{
	private:
		T1 _start;
		T2 _end;

	public:

		product(T1 start, T2 end)
			: _start(start),_end(end){}


		class const_iterator {
			private:
            typename T1::const_iterator left_start;
            typename T1::const_iterator left_end;
            typename T2::const_iterator right_start;
            typename T2::const_iterator right_end;
				typename T2::const_iterator right2_start;


			public:
				const_iterator(const typename T1::const_iterator& left_start, const typename T1::const_iterator& left_end,
            const typename T2::const_iterator&  right_start, const typename T2::const_iterator& right_end):
            left_start(left_start), left_end(left_end),right2_start(right_start), right_start(right_start), right_end(right_end) {}

				const auto operator*() {
                return  std::pair(*left_start , *right_start);
            }

            bool operator==(const_iterator other){
                return !(*this != other);

            }

            bool operator!=(const_iterator other) {
               return (left_start != other.left_start) && (right_start != other.right_start);
            }

				const_iterator& operator++() {
               ++right_start;
               if(right_start == right_end){
						++left_start;
                    if(left_start != left_end){
                        right_start = right2_start;
                    }
                }
               return *this;
            }

        };

 		auto begin() const{
            return const_iterator(_start.begin(), _start.end() ,_end.begin(), _end.end());}

   	auto end() const{
			return const_iterator(_start.end(), _start.end() ,_end.end(), _end.end());}
    };
}
