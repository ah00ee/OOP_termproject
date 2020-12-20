#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void div() {
    cout << "-------------------------------------------------------------------------------------------------" << endl;
}

void menu() {
    cout << "n: ����������, p: ����������, i: ����, d: ����, c:����, s: ã��, t: ����������" << endl;
    div();
}

int main() {
    ifstream textFile("test.txt");
    string line;
    string word;
    vector<string> arr;
    vector<string> lines;

    getline(textFile, line);
    istringstream tmp(line);

    while (getline(tmp, word, ' ')) {
        arr.push_back(word);
    }

    int cnt = 0;
    string m = "";
    for (int i = 0; i < arr.size(); i++) {
        if (cnt + arr[i].length() > 75) {
            lines.push_back(m);
            cnt = arr[i].length() + 1;
            m = arr[i] + " ";
            continue;
        }
        cnt += arr[i].length() + 1;
        m += arr[i] + " ";

        if (i == arr.size() - 1) {
            lines.push_back(m);
        }
    }

    for (int i = 0; i < 20; i++) {
        printf("%2d", i + 1);
        cout << "| " << lines[i] << endl;
    }
    
    div();
    menu();

    string input;
    cout << "�Է�: ";
    cin >> input;
    div();

    return 0;
}