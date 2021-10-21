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
        * @param    m      reais
        * @param    n      cents
        * @return   string representing the amount in words
        */
        std::string convertAmount2Words(int m, int n)const noexcept;

    private:

        std::string threeDigit2Words(int number)const noexcept;
        std::string tensRule(int number)const noexcept;

    };
}
