#include <string>
#include <set>

class Solution {
public:
    bool doesAliceWin(std::string s) {
        // Create a set of vowels for efficient lookup
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Iterate through the string to check for any vowel
        for (char c : s) {
            if (vowels.count(c)) {
                // If a vowel is found, Alice can win
                return true;
            }
        }

        // If no vowels are found, Alice cannot make a move, and Bob wins
        return false;
    }
};