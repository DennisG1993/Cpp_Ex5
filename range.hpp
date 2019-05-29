#pragma once
#include <iostream>

namespace itertools{

    template<typename T>

    class range{
    private:
        T _start;
        T _end;
    public:

        range(const T& begins,const T& ends){
            _start=begins;
            _end=ends;
        }

        class const_iterator{
            private:
            T itr;

            public:
            const_iterator(T iter): itr(iter) {}

            const T operator*()const{
                return  itr;
            }
            //prefix
            const_iterator& operator++(){
                itr++;
                return *this;
            }
            //postfix
            const const_iterator operator ++(int){
                const_iterator temp =*this;
                itr++;
                return temp;
            }
            bool operator==(const const_iterator& other) const {
                return itr==other.itr;
            }
            bool operator!=(const const_iterator& other) const {
                return itr!=other.itr;
            }
        };

        public:
        const_iterator begin() const{
         return const_iterator(_start);
        }
        const_iterator end() const{
            return const_iterator(_end);
        }
    };
}
