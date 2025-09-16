#include <vector>
#include <numeric> // For std::gcd

class Solution {
public:
    // Function to calculate LCM of two numbers
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / std::gcd(a, b)) * b;
    }

    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::vector<int> result; // Acts as a stack

        for (int num : nums) {
            // Continuously process the current number with the last element in 'result'
            // as long as they are non-coprime
            while (!result.empty()) {
                long long last_val = result.back();
                long long current_val = num;

                long long common_divisor = std::gcd(last_val, current_val);

                // If they are coprime, break and add the current number
                if (common_divisor == 1) {
                    break;
                }

                // If non-coprime, replace them with their LCM
                result.pop_back();
                num = lcm(last_val, current_val); // Update 'num' with the new LCM
            }
            result.push_back(num); // Add the processed number (or LCM) to the result
        }
        return result;
    }
};