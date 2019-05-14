#pragma once

#include <iostream>
#include <string>

namespace itertools{


   template <typename T, typename T_2>
   class product
   {
       public:
       T L_Iterable;
       T_2 R_Iterable;

       product(T a, T_2 b) : L_Iterable(a), R_Iterable(b) {}

       class iterator
       {
          typename T::iterator L_Iter;
          typename T_2::iterator R_Iter;

       public:
           iterator(typename T::iterator left, typename T_2::iterator right) : L_Iter(left), R_Iter(right) {}

            T& operator*(){
               return L_Iter;
           }

           iterator& operator++(){
               L_Iter++;
               return *this;
           }

           iterator &operator++(int){
               iterator tmp = *this;
               L_Iter++;
               return tmp;
           }

           bool operator==(const iterator& other)const{
             return L_Iter == other.L_Iter || R_Iter == other.R_Iter;
           }

           bool operator!=(const iterator& other)const{
             return !(this == other);
           }
       };

   public:
       auto begin(){
           return L_Iterable.begin();
       }

       auto end(){
           return L_Iterable.begin();
       }
   };
}
