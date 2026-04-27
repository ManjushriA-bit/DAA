#include <iostream>
#include <string>
using namespace std;

#define MAX 256

// Function to build shift table
void buildShiftTable(string pattern, int table[]) {
    int m = pattern.length();

    // Initialize all shifts to pattern length
    for (int i = 0; i < MAX; i++)
        table[i] = m;

    // Fill shift values based on pattern
    for (int j = 0; j < m - 1; j++)
        table[(int)pattern[j]] = m - 1 - j;
}

// Horspool search function
int horspool(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int table[MAX];
    buildShiftTable(pattern, table);

    int i = m - 1;

    while (i < n) {
        int k = 0;

        // Compare from right to left
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1; // match found

        i += table[(int)text[i]]; // shift
    }

    return -1; // not found
}

int main() {
    string text = "THIS IS A TEST TEXT";
    string pattern = "TEST";

    int result = horspool(text, pattern);

    if (result != -1)
        cout << "Pattern found at index: " << result;
    else
        cout << "Pattern not found";

    return 0;
}