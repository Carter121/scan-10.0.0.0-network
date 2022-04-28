#include<iostream>
using namespace std;

int main()
{
    system("nmap -T5 -n -sn -oN fullOutput.txt -iL output.txt");
    return 0;
}