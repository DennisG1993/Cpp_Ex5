#pragma once
#include<iostream>
using namespace std;

namespace itertools{
   
    template<typename T1,typename T2>

    class chain{
        private:
        T1 left;
        T2 right;

        public:
        chain(const T1& start,const T2& end):left(start),right(end){ }

        class const_iterator {
            public:
                typename T1::const_iterator left_start;
                typename T1::const_iterator left_end;
                typename T2::const_iterator right_start;
                typename T2::const_iterator right_end;

                const_iterator(const typename T1::const_iterator& left_start, const typename T1::const_iterator& left_end
                ,const typename T2::const_iterator& right_start, const typename T2::const_iterator& right_end) :
                 left_start(left_start), left_end(left_end), right_start(right_start), right_end(right_end) { }

                const auto operator*() {
                    if (left_start != left_end) {
                        return *left_start;
                     }
                    return *right_start;
                }

                const const_iterator& operator++() {
                    if(left_start != left_end) {
                        ++left_start;
                     }
                    else {
                        ++right_start;
                    }
                    return *this;
                }

                bool operator!=(const const_iterator& itr) {
                    if (left_start != itr.left_start || right_start != itr.right_start) {
                        return true;
                     }
                    return false;
                }
        };

        const_iterator begin() const { return const_iterator(left.begin(), left.end(), right.begin(), right.end()); }
        const_iterator end() const { return const_iterator(left.end(), left.end(), right.end(), right.end()); }
    };
}
