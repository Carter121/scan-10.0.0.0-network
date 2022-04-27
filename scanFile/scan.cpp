#include <iostream>
#include <fstream>
using namespace std;

void run(int files, int starting, string mode);

int main() {
    int fileNum;
    int starting;
    string mode;
    cout << "How many files?" << endl;
    cin >> fileNum;
    cout << "Where to start?" << endl;
    cin >> starting;
    cout << "What mode do you want to use? (normal, comma)" << endl;
    cin >> mode;
    run(fileNum, starting, mode);
}

void run(int files, int starting, string mode) {
    int filePlace = starting;
    fstream output;
    output.open("output.txt", ios::app);
    for(int i = 0; i < files; i++) {
        fstream file;
        file.open("10." + to_string(filePlace) + ".x.x",ios::in);
        if(file.is_open()) {
            string data;
            while(getline(file, data)) {
                if(data.find("10." + to_string(filePlace) + ".") != std::string::npos && data.find("#") == std::string::npos && data.find("ERROR") == std::string::npos) {
                    data = data.substr(21);
                    cout << data << endl;
                    if(mode != "comma") {
                        output << data << endl;
                    } else {
                        output << data << ",";
                    }
                }
                data = "";
            }
            filePlace++;
        }
        file.close();
    }
    output.close();
}