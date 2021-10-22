#include <string>
#include <string_view>
class Problem2
{
public:
    Problem2() = default;
    ~Problem2() = default;

    /*
    * Identify when the robot returns to a point where it has already been, closing a loop (circle). Print which commands the robot executed to close the loop.
    * @param    commands:  String with commands
    * @return   A string with the command to the closed loop
    */
    std::string getLastLoop(std::string_view commands)const noexcept;
};