#include <string>
#include <string_view>
class Problem2
{
public:
    Problem2() = default;
    ~Problem2() = default;

    std::string getLastLoop(std::string_view commands)const noexcept;
};