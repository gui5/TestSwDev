#include "Problem2.h"
#include <unordered_map>
#include <utility>

using Pair = std::pair<int, int>;

struct PairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const noexcept
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
std::string Problem2::getLastLoop(std::string_view commands) const noexcept
{
    std::unordered_map<Pair, int, PairHash> positionHistory;
    std::string sequence;
    positionHistory.reserve(commands.size());

    // {horizontal,vertical}
    Pair currentPos;

    // U == vertical -
    // D == vertical +
    // L == horizoltal -
    // R == horizontal +

    for (size_t i = 0; i < commands.size(); i++)
    {
        const char c = commands[i];

        switch (c)
        {
        case 'U':
            currentPos.second--;
            positionHistory[currentPos]++;
            break;
        case 'D':
            currentPos.second++;
            positionHistory[currentPos]++;
            break;
        case 'L':
            currentPos.first--;
            positionHistory[currentPos]++;
            break;
        case 'R':
            currentPos.first++;
            positionHistory[currentPos]++;
            break;
        default:
            break;
        }
        sequence.push_back(c);
        if (positionHistory[currentPos] > 1)
        {
            break;
        }
    }
    return std::string(sequence.data() + currentPos.first, sequence.data() + sequence.size());
}