#pragma once

namespace itertools{


   template <typename T, typename T_2>
   class zip{

       public:
       T L_Iterable;
       T_2 R_Iterable;

       zip(T left, T_2 right) : L_Iterable(left), R_Iterable(right) {}

       class iterator{
          typename T::iterator L_Iter;
          typename T_2::iterator R_Iter;

       public:
          iterator(typename T::iterator left, typename T_2::iterator right):L_Iter(left),R_Iter(right){
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
       }

       auto end(){
           return L_Iterable.end();
       }
   };
}
