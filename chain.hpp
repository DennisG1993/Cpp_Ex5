#pragma once

namespace itertools{


   template <typename T, typename T_2>
   class chain{

   public:
       T L_Iterable;
       T_2 R_Iterable;

       chain(T left, T_2 right) : L_Iterable(left),R_Iterable(right) {}

       class iterator{

         typename T::iterator L_Iter;
         typename T_2::iterator R_Iter;

       public:

           iterator(T left, T_2 right) : L_Iter(left),R_Iter(right) {}

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
             return (L_Iter == other.L_Iter) || (R_Iter == other.R_Iter);
          }

          bool operator!=(const iterator& other)const{
             return !(this == other);
          }

       };


       auto begin(){
           return L_Iterable.begin();
           //return chain::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(),second.begin()); // add operators

       }

       auto end(){
          return L_Iterable.end();
          //return chain::iterator<decltype(first.end()),decltype(second.end())>(first.end(),second.end()); // add operators
       }

   };
}
