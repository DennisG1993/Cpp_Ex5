#pragma once

namespace itertools{


   template <typename T>
   class range
   {

   public:
       T _start;
       T _end;

       range(T first, T last) : _start(first),_end(last) {}

       class iterator
       {
           T _val;

       public:
          iterator( T val) :_val(val){}

           iterator& operator++(){
               _val++;
               return *this;
           }

           T& operator*(){
               return _val;
           }

           iterator &operator++(int){
               iterator tmp = *this;
               _val++;
               return tmp;
           }

           bool operator!=(const iterator& other)const{
             return this->_val != other._val;
           }

           bool operator==(const iterator& other)const{
             return this->_val == other._val;
           }
       };

       iterator begin(){
           return range<T>::iterator(_start);
       }

       iterator end(){
           return range<T>::iterator(_end);
       }

   };
}
