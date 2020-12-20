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
    cout << "n: 다음페이지, p: 이전페이지, i: 삽입, d: 삭제, c:변경, s: 찾기, t: 저장후종료" << endl;
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
    cout << "입력: ";
    cin >> input;
    div();

    return 0;
}