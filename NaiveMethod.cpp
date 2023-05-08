#include <iostream>
#include <string>

using namespace std;

int main() {
    string text, pattern;
    cout << "Enter the text string: ";
    getline(cin, text);
    cout << "Enter the pattern string: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "Pattern not found in text." << endl;
    } else {
        cout << "Pattern found " << count << " times in text." << endl;
    }

    return 0;
}

