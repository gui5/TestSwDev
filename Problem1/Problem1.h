#pragma once
#include <string>
#include <array>



namespace p1
{
   

    class Problem1
    {
    public:
        Problem1() = default;
        ~Problem1() = default;

        /*
        * Converts a numeric currency amount to words in Portuguese
        * @param    m:      reais amouth
        * @param    n:     cents amounth
        * @return   A string representing the amount in words
        */
        std::string convertAmount2Words(int m, int n)const noexcept;

    private:

        /*
        * Apply the three digits rule
        * @param    number: Integer representing a three digit group
        * @return   A string in portuguese of the three digit group
        */
        std::string threeDigit2Words(int number)const noexcept;

        /*
       * Apply the tens digits rule
       * @param    number: Integer representing the tens digit group
       * @return   A string in portuguese of the tens digit group
       */
        std::string tensRule(int number)const noexcept;

    };
}
