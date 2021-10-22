#include <unordered_map>
#include <sstream>
#include <cctype>


#include "Problem1.h"

namespace p1
{
    constexpr int digitsGroupSize = 4;


    constexpr const std::array<const char*, 20> NUMS =
    { "", "um","dois","três", "quatro","cinco",
        "seis","sete","oito","nove","dez","onze","doze",
        "treze","quatorze","quinze","dezesseis","dezessete",
        "dezoito","dezenove" };

    constexpr const std::array<const char*, 10> TENS =
    { "","", "vinte","trinta","quarenta","cinquenta",
        "sessenta","setenta","oitenta","noventa" };

    constexpr const std::array<const char*, 10> HUNDREDS =
    { "","","duzentos","trezentos","quatrocentos",
        "quinhentos","seiscentos","setecentos","oitocentos",
    "novecentos" };

    constexpr const std::array<const std::array<const char*, 2>, 4> SCALE = 
    { "","", "mil","mil", "milhão","milhões", "bilhão","bilhões" };


    std::string Problem1::convertAmount2Words(int m, int n) const noexcept
    {
        if (m == 0 && n == 0)
        {
            return "Zero";
        }

        std::array<int, digitsGroupSize> numberGroups = { 0,0,0,0 };
        std::array<std::string, digitsGroupSize> wordsGroups;

        for (auto& d : numberGroups)
        {
            d = m % 1000;
            m /= 1000;
        }

        for (int i = 0; i < digitsGroupSize; i++)
        {
            wordsGroups[i] = threeDigit2Words(numberGroups[i]);
        }

        std::ostringstream result;

        for (int i = digitsGroupSize - 1; i >= 0; i--)
        {

            if (i == 1 && numberGroups[i] == 1) {
                result << (i > 1 ? SCALE[i][1] : SCALE[i][0]) << " ";
            }
            else if (!wordsGroups[i].empty())
            {
                result << wordsGroups[i] << " " << (numberGroups[i] > 1 ? SCALE[i][1] : SCALE[i][0]);
                if (i - 1 >= 0)
                {
                    if (numberGroups[i - 1] == 0) {
                        result << " e ";
                    }
                    else
                    {
                        result << " ";
                    }
                }
                
            }
           
        }

        result << [&numberGroups]() {if (numberGroups[0] == 1
            && numberGroups[1] == 0
            && numberGroups[2] == 0
            && numberGroups[3] == 0)
            return "real";
        return "reais";
        }();

        if (n > 0)
        {
            result << " e " << tensRule(n) << (n > 1 ? " centavos" : " centavo");
        }
        auto str = result.str();
        str[0] = toupper(str[0]);
        return str;
    }

    std::string Problem1::threeDigit2Words(int number) const noexcept
    {
        std::ostringstream words;
        const int hundreds = number / 100; //hundreds
        const int tensUnits = number % 100; //tens

        if (hundreds != 0)
        {
            const std::string w = HUNDREDS[hundreds];
            if (w.empty())
            {
                words << (tensUnits != 0 ? "cento e " : "cem ");
            }
            else
            {
                words << (tensUnits != 0 ? w + " e " : w + " ");
            }
        }

        words << tensRule(tensUnits);

        return words.str();
    }

    std::string Problem1::tensRule(int number) const noexcept
    {
        const int tens = number / 10;
        const int units = number % 10;

        std::ostringstream words;

        if (tens >= 2)
        {
            words << (units > 0 ? std::string(TENS[tens]) + " e " + NUMS[units] : TENS[tens]);
        }
        else if (tens == 1)
        {
            words << (units < 10 ? NUMS[units + 10] : NUMS[units]);
        }
        else
        {
            words << NUMS[units];
        }

        return words.str();
    }

}