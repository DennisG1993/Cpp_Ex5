#pragma once
#include <sstream>
#include <iostream>

namespace itertools{

    template<typename T,typename T2>
    class zip{
        private:
        T zip_start;
        T2 zip_end;

        public:
        zip(const T& start,const T2& end):zip_start(start),zip_end(end){}

        class const_iterator{
            private:
            typename T::const_iterator L_Iterable_start;
            typename T::const_iterator L_Iterable_end;
            typename T2::const_iterator R_Iterable_start;
            typename T2::const_iterator R_Iterable_end;

            public:
            const_iterator(const typename T::const_iterator& it1begin, const typename T::const_iterator& it1end,
            const typename T2::const_iterator&  it2begin, const typename T2::const_iterator& it2end):
            L_Iterable_start(it1begin), L_Iterable_end(it1end), R_Iterable_start(it2begin), R_Iterable_end(it2end) {}

            const_iterator& operator++() {
               ++L_Iterable_start;
               ++R_Iterable_start;
               return *this;
            }

            const auto operator*() {
                return  std::pair(*L_Iterable_start , *R_Iterable_start);
            }

            bool operator!=(const_iterator other){
                return (L_Iterable_start != other.L_Iterable_start) && (R_Iterable_start != other.R_Iterable_start);

            }

 template<typename T3, typename T4>
   friend ostream& operator<<(ostream& os, const pair<T3, T4> pair);
   };
        const_iterator begin() const{return const_iterator(zip_start.begin(),zip_start.end(),zip_end.begin(), zip_end.end());}
        const_iterator end() const{return const_iterator(zip_start.end(),zip_start.end(),zip_end.end(), zip_end.end());
        }
     };

    template<typename T3, typename T4>
    ostream& operator<<(ostream& os, const pair<T3, T4> pair) {
        return os << pair.first << "," << pair.second;
    }
}
