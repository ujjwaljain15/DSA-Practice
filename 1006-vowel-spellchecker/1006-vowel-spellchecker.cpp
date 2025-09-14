#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> // For std::transform

class Solution {
public:
    std::string toLower(const std::string& s) {
        std::string res = s;
        std::transform(res.begin(), res.end(), res.begin(), ::tolower);
        return res;
    }

    std::string devowel(const std::string& s) {
        std::string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
        std::unordered_set<std::string> wordSet;
        std::unordered_map<std::string, std::string> lowerMap;
        std::unordered_map<std::string, std::string> vowelMap;

        for (const std::string& word : wordlist) {
            wordSet.insert(word);

            std::string lowerWord = toLower(word);
            if (lowerMap.find(lowerWord) == lowerMap.end()) {
                lowerMap[lowerWord] = word;
            }

            std::string vowelWord = devowel(lowerWord);
            if (vowelMap.find(vowelWord) == vowelMap.end()) {
                vowelMap[vowelWord] = word;
            }
        }

        std::vector<std::string> result;
        for (const std::string& query : queries) {
            if (wordSet.count(query)) { // Rule 1: Exact match
                result.push_back(query);
            } else {
                std::string lowerQuery = toLower(query);
                if (lowerMap.count(lowerQuery)) { // Rule 2: Case-insensitive match
                    result.push_back(lowerMap[lowerQuery]);
                } else {
                    std::string vowelQuery = devowel(lowerQuery);
                    if (vowelMap.count(vowelQuery)) { // Rule 3: Vowel error match
                        result.push_back(vowelMap[vowelQuery]);
                    } else { // No match
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};