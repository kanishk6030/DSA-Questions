class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;

        int n = words.size();
        int i = 0;

        while (i < n) {

            // Find all words that fit on this line
            int j = i;
            int lineLength = 0;

            while (j < n) {

                int newLength = lineLength + words[j].size();

                // Add at least one space between words
                if (j > i)
                    newLength++;

                if (newLength > maxWidth)
                    break;

                lineLength = newLength;
                j++;
            }

            int numberOfWords = j - i;

            // Last line -> left justified
            if (j == n) {

                string line = "";

                for (int k = i; k < j; k++) {

                    if (k > i)
                        line += " ";

                    line += words[k];
                }

                // Add remaining spaces at the end
                line += string(maxWidth - line.size(), ' ');

                ans.push_back(line);
            }

            // Only one word -> left justified
            else if (numberOfWords == 1) {

                string line = words[i];

                line += string(maxWidth - line.size(), ' ');

                ans.push_back(line);
            }

            // Normal line -> fully justified
            else {

                // Total spaces that need to be distributed
                int totalSpaces = maxWidth;

                for (int k = i; k < j; k++) {
                    totalSpaces -= words[k].size();
                }

                int gaps = numberOfWords - 1;

                // Minimum spaces per gap
                int spacesPerGap = totalSpaces / gaps;

                // Extra spaces go to leftmost gaps
                int extraSpaces = totalSpaces % gaps;

                string line = "";

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {

                        int spaces = spacesPerGap;

                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }

                ans.push_back(line);
            }

            i = j;
        }

        return ans;
    }
};