#include <iostream>
using namespace std;

int main() {
    int starting;
    cout << "Where do you want to start?" << endl;
    cin >> starting;
    cout << "Starting at 10." << starting << ".0.0" << endl;
    for(int i = starting; i < 256; i++) {
        string number = to_string(i);
        string str = "nmap 10." + number + ".0.0/16 -oN 10." + number + ".x.x";
        const char *command = str.c_str();
        system(command);
        cout << command << endl;
    }
    return 0;
}