#include "iostream"
#include <set>
#include <cmath>
#include <iostream>
#include <iterator>

using namespace std;

namespace itertools {

    template <class T>
    class powerset {
    private:
        T iterable;
        uint setSize;

    public:
    powerset(T start) : iterable(start) {
        setSize = 0;
        for(auto i : start) {
            ++setSize;
        }
    }

        class const_iterator {
        private:
        int size;
        T powerSet;

        public:
            const_iterator(const T& powerset, int i):powerSet(powerset) , size(i) {}

            const_iterator& operator++() {
                ++size;
                return *this;
            }

            auto operator*() const {
               std::set<typename std::remove_reference<typename std::remove_const<decltype(*(iterable.begin()))>::type>::type> mySet = {};
               int i = 1;
               for (auto item : powerSet) {
                     if (i & size) {
                        mySet.insert(item);
                        }
                     i <<= 1;}
               return mySet;
               }

            const const_iterator& operator++(int) {
                const_iterator temp = *this;
                ++size;
                return temp;
            }

            bool operator!=(const const_iterator& other) {
                return !(size == other.size);
            }
        };

        auto begin() const{
            return const_iterator(iterable, 0);
        }
        auto end() const{
            return const_iterator(iterable, pow(2, setSize));
            }
    };

template <typename T2>
std::ostream &operator<<(std::ostream &os, const std::set<T2> &out){
   os << "{";

    auto itr = out.begin();
    if(itr != out.end()){
        os << *itr;
        ++itr;
    }
    while (itr != out.end()){
        os << ',' << *itr;
        ++itr;
    }
    os << "}";
    return os;
   }
}
