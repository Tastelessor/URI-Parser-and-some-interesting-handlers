#include "Check.h"

using namespace std;

class checkEncrypted : public Check{
    // Count the number of 4 types of characters
    bool isUpper = false;
    bool isLower = false;
    bool isNum = false;
    bool isPlus = false;
    bool isEqual = false;
    bool isSlash = false;
    // Maximum length of a string
    int maxLength = 0;

public:
    checkEncrypted(string f) : Check(f) {
    }

    bool checkFile(){
        // Record the length of the current string
        int temp = 0;

        fs.open(filename);
        if (fs.is_open())
        {
            while (!fs.eof())
            {

                getline(fs,line);
                // In case that the file includes a link that can be misunderstood as encrypted content
                if ((offset = line.find("https://", 0)) != string::npos){
                    fs.close();
                    cout << filename << " Not encrypted" << endl;
                    return false;
                }
                for(char x : line){
                    /*
                     * These branch predictions would heavily harm the performance
                     * I came up with another idea that's much better than this one:
                     * Gzip the file and if the size of it is reduced a lot, then there
                     * is a great chance that the file is encrypted.
                     * As for the relationship between the reduced size and whether the file
                     * is encrypted, it can be tested out by performing some experiments on
                     * different encryption patterns.
                     */
                    if ('A' <= x && x <= 'Z')
                        isUpper = true;
                    else if ('a' <= x && x <= 'z')
                        isLower = true;
                    else if ('0' <= x && x <= '9')
                        isNum = true;
                    else if (x == '+')
                        isPlus = true;
                    else if (x == '/')
                        isSlash = true;
                    else if (x == '=')
                        isEqual = true;

                    // Record the length of the current string
                    temp++;

                    // A space indicates that the count of string length should be restarted
                    if(x == ' '){
                        if(isEncrypted())
                            return true;
                        maxLength = maxLength > temp ? maxLength : temp;
                        temp = 0;
                        isUpper = false;
                        isLower = false;
                        isNum = false;
                        isPlus = false;
                        isEqual = false;
                        isSlash = false;
                    }
                }
            }
            // Repeat the check in case that the file contains only one string
            maxLength = maxLength > temp ? maxLength : temp;
            if(isEncrypted())
                return true;
            else
                cout << filename << " Not encrypted" << endl;
        }
        else{
            cout << "Unable to open " << filename << endl;
        }
        return false;
    }

private:

    /*
     * Check if a string looks like encrypted content
     */
    bool isEncrypted(){
        // If it's long and contains 6 types of characters, then there's a great chance it's encrypted
        if(isLower && isUpper && isEqual && isSlash && isPlus && isNum && maxLength > 27) {
            fs.close();
            cout << filename << " is encrypted" << endl;
            return true;
        }
        return false;
    }
};

