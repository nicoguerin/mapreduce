#include <iostream>
#include <map>
#include <fstream>
using namespace std;

bool esCaracterValid(char c) {
    return (c>='a' && c<='z') || (c>='A' && c<='Z') || c==',' || c=='.' || c==';';
}

int main() {
    ifstream f("./fitxer.txt");
    map<char, int> freq;

    if (f.is_open()) {
        while (f) {
            char act = f.get();
            if (esCaracterValid(act)) ++freq[act];
        }
    }
    
    for (auto it : freq) cout << it.first << ": " << it.second << endl;
}