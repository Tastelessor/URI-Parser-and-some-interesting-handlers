#include "Check.h"

using namespace std;

class checkSSH : public Check{
public:
    checkSSH(string f) : Check(f) {
    }

    bool checkFile(){
        fs.open(filename, ios_base::in | ios::binary);

        if (fs.is_open())
        {
            while (!fs.eof())
            {
                getline(fs,line);
                // This is a SSH client if the word "OpenSSH" is found
                if ((offset = line.find("OpenSSH", 0)) != string::npos)
                {
                    cout << "Yes, this is a SSH client" << endl;
                    fs.close();
                    return true;
                }
            }
            cout << "This is not a SSH client" << endl;
            fs.close();
        }
        else
            cout << "Unable to open " << filename << endl;
        return false;
    }
};

