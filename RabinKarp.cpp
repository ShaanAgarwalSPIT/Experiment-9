#include <iostream>
#include <string>

using namespace std;

const int prime = 13;

int rabin_karp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * 256) % prime;
    }

    for (int i = 0; i < m; i++) {
        pattern_hash = (256 * pattern_hash + pattern[i]) % prime;
        text_hash = (256 * text_hash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == m) {
                return i;
            }
        }

        if (i < n - m) {
            text_hash = (256 * (text_hash - text[i] * h) + text[i + m]) % prime;

            if (text_hash < 0) {
                text_hash += prime;
            }
        }
    }

    return -1;
}

int main() {
    string text = "MY NAME IS SHAAN";
    string pattern = "SHAAN";
    int result = rabin_karp(text, pattern);

    if (result == -1) {
        cout << "Pattern not found in text" << endl;
    } else {
        cout << "Pattern found at index " << result << endl;
    }

    return 0;
}

