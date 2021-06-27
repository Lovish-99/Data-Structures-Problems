class Solution {
    bool isCharacter(char s) {
        if (s >= 'a' && s <= 'z') return true;
        if (s >= 'A' && s <= 'Z') return true;
        return false;
    }
    public:
    int myAtoi(string str) {
        long result = 0;
        int type = 0;
        bool numEncountered = false;
        for (int i = 0; i < str.size(); i++) {
            if (i == 0 && (str[i] == ' ' || str[i] == '+' || str[i] == '-')) {
                // clean up initial spaces and types
                int j;
                for (j = i; j < str.size(); j++) // clean up spaces
                    if (str[j] != ' ') { // first element that is not space
                        i = j;
                        break;
                    }
                if (j == str.size() && i == 0) return 0; // Only spaces
                if (str[i] == '+' || str[i] == '-') {
                    type = (str[i] == '+')? 1: -1;
                    i++;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') { // number handling
                numEncountered = true;
                result = (result * 10) + (str[i] - '0');
                if (result >= INT_MAX) { // if result is going beyond range
                    if (type != -1)
                        return INT_MAX;
                    else {
                        if ((result * -1) <= INT_MIN) return INT_MIN;
                    }
                }
            } else if (str[i] == '+' || str[i] == '-') { // extra type handling
                if (!numEncountered) return 0;
                break;
            } else if (isCharacter(str[i]) || str[i] == '.') {
                // when characters or dot is encountered
                if (!numEncountered) return 0; // has numbers been encountered or not.
                break;
            } else if (str[i] == ' ') { // space encountered after initial cleaning
                break;
            }
        }
        return (type == -1)? (result * -1): result;
    }
};
