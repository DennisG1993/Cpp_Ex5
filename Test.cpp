#include <iostream>
using namespace std;
using std::string;
#include "product.hpp"
#include "zip.hpp"
#include "powerset.hpp"
#include "chain.hpp"
#include "range.hpp"
#include "badkan.hpp"

using namespace itertools;


int main() {
  badkan::TestCase testcase;


  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

/////////////****Range Tests****/////////////
/////////////****Range Tests****/////////////

      string test_case1 = "";
      string test_case2 = "";
      string test_case3 = "";
      string test_case_chars = "";
      string test_case1_expectation = "012345678910";
      string test_case2_expectation = "10";
      string test_case3_expectation = "1.4 - 2.4 - 3.4 - 4.4 - 5.4 - ";
      string test_case_chars_expectation = "defgh";


    for(int i : range(0,11)){
        test_case1+=to_string(i);
    }

    for(int i : range(10,11)){
        test_case2+=to_string(i);
    }


    for(double i : range(1.4,6.4)){
        test_case3_expectation+=to_string(i)+ " - ";
    }

    for(char i : range('d','i')){
      test_case_chars+=i;
   }

   testcase.setname("Range test: \n")
  .CHECK_OK(range a(0,11))
  .CHECK_OK(range a(0,1))
  .CHECK_OK(range a('a','z'))
  .CHECK_OK(range a(0.7,2.7))
  .CHECK_EQUAL(test_case1, test_case1_expectation)
  .CHECK_EQUAL(test_case2, test_case2_expectation)
  .CHECK_EQUAL(test_case3_expectation, test_case3_expectation)
  .CHECK_EQUAL(test_case_chars, test_case_chars_expectation)

;

/////////////****Chain Tests****/////////////
/////////////****Chain Tests****/////////////


    test_case1 = "";
    test_case2 = "";
    test_case_chars = "";
    test_case3_expectation = "";
    test_case1_expectation=  "1-2-3-4-5-10-11-12-13-14-15-"  ;
    test_case2_expectation="a-b-c-1-2-3-4-5-";
    test_case_chars_expectation="Testoabc";
    test_case3_expectation="test1.12.1";


    for(int i : chain(range(1,6), range(10,16))){

        test_case1+=to_string(i) + "-";
    }

    for(char i : chain(range('a', 'd'), range(1, 6))){
        test_case2+=char(i);
        test_case2+="-";
    }

    for(char i :chain(string("Testo"), range('a','d'))){
        test_case_chars+=i;
    }

    for(auto i :chain(string("test"), range(1.1,3.1))){
        test_case3_expectation+=i;
    }


    testcase.setname("Chain test: \n")
    .CHECK_EQUAL(test_case1, test_case1_expectation)
    .CHECK_EQUAL(test_case2, test_case2_expectation)
    .CHECK_EQUAL(test_case_chars,test_case_chars_expectation)
    .CHECK_EQUAL(test_case3_expectation, test_case3_expectation)

   ;
   /////////////****Zip Tests****/////////////
   /////////////****Zip Tests****/////////////

    test_case1 = "";
    test_case2 = "";
    test_case_chars = "";
    test_case3_expectation = "";
    test_case1_expectation=  "120222323424525";
    test_case2_expectation="11to52345";
    test_case_chars_expectation="dabcd";
    test_case3_expectation="55.566.577.588.599.51010.5"  ;


    for(auto i : zip(range(1,6), range(20,26))){
        test_case1+=to_string(i);
    }

    for(auto i : zip(range(1, 6), string("1to5"))){

        test_case2+=to_string(i);
    }

    for(auto i :zip(range('d', 'e'), range('a','e'))){
        test_case_chars+=to_string(i);
    }

    for(auto i :zip(range(5,11), range(5.5,11.5))){

        test_case2_expectation+=to_string(i);
    }


    testcase.setname("zip test: \n")
    .CHECK_EQUAL(test_case1, test_case1_expectation)
    .CHECK_EQUAL(test_case2, test_case2_expectation)
    .CHECK_EQUAL(test_case_chars,test_case_chars_expectation)
    .CHECK_EQUAL(test_case2_expectation, test_case3_expectation)

   ;

   /////////////****Product Tests****/////////////
   /////////////****Product Tests****/////////////

    test_case1 = "";
    test_case2 = "";
    test_case_chars = "";
    test_case1_expectation=  "110-111-112-113-114-210-211-212-213-214-310-311-312-313-314-410-411-412-413-414";
    test_case2_expectation = "test1-test2-test3-test4";
    test_case2_expectation="t21t22t23a21a22a23l21l22l23";
    test_case_chars_expectation="testatestbtestctestd";
    test_case3_expectation="10.411.412.413.420.421.422.423.4"         ;


    for(auto i : product(range(1,5), range(10,15))){

        test_case1+=to_string(i)+"-";
    }

    for(auto i : product(string("test"), range(1,5))){

        test_case2+=to_string(i)+"-";
    }

    for(auto i :product(string("test"), range('a','e'))){

        test_case_chars+=to_string(i);
    }

    for(auto i :product(range(1,3), range(0.4,4.4))){

        test_case3+=to_string(i);
    }


    testcase.setname("product test: \n")
    .CHECK_EQUAL(test_case1, test_case1_expectation)
    .CHECK_EQUAL(test_case2, test_case2_expectation)
    .CHECK_EQUAL(test_case_chars, test_case_chars_expectation)
    .CHECK_EQUAL(test_case2_expectation, test_case3_expectation)

   ;

   /////////////****PowerSet Tests****/////////////
   /////////////****PowerSet Tests****/////////////


    test_case1 = "";
    test_case2 = "";
    test_case_chars = "";
    test_case2_expectation = "";
    test_case1_expectation=  "{}{1}{2}{3}{1,2}{1,3}{2,3}{1,2,3}";
    test_case2_expectation="{}{1}";
    test_case_chars_expectation="{}{1}{2}{a}{b}{1,2}{1,a}{1,b}{2,a}{2,b}{1,2,a}{1,2,b}{2,a,b}{a,b}{a,b,1}{1,2,a,b}";
    test_case3_expectation="{}{1}{2}{}{3}{1,2}{1,.}{1,3}{2,3}{2,3}{1,2,.}{1,2,3}{2,.,3}{.,3}{.,3,1}{1,2,.,3}";

    for(auto i : powerset(range(1,4))){

        test_case1+=to_string(i);
    }

    for(auto i : powerset(range(1,2))){

        test_case2+=to_string(i);
    }

    for(auto i :powerset(zip(range(1,3),range('a', 'c')))){
        test_case_chars+=to_string(i);
        //powerset(1a2b)
    }

     for(auto i :powerset(product(range(1,2), range(2.3,3.3)))){
        //powerset(12.3)
        test_case3+=to_string(i);
    }



    testcase.setname("powerset test: \n")
    .CHECK_EQUAL(test_case1, test_case1_expectation)
    .CHECK_EQUAL(test_case2, test_case2_expectation)
    .CHECK_EQUAL(test_case_chars, test_case_chars_expectation)
    .CHECK_EQUAL(test_case2_expectation, test_case3_expectation)
    // .CHECK_EQUAL(powerset(), "{}")
   ;

    }
    else {
      testcase.print_signal(signal);
    }
    //this line has been taken from TreeTest.cpp!!
    cout << "\nYou have " << testcase.right() << " right answers and " << testcase.wrong() << " wrong answers so your grade is " << testcase.grade() << ". Great!" << endl;
    return 0;
}
