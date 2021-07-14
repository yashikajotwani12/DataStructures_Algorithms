// Sample Input 1:
// cba
// Sample Output 1:
// abc
// acb
// bac
// bca
// cab
// cba

#include<bits/stdc++.h>
using namespace std;



// Swaping two alphabets in a string.
void swap(string &s, int i, int j) {
    char te = s[i];
    s[i] = s[j];
    s[j] = te;
}

void findPermutationsHelper(string &s, int i, int j, vector <string> &ans) {
    if (i >= j) {
        // Storing the string in the vector ans.
        string permutation = "";

        for (int k = 0; k < s.length(); k++) {
            permutation += (s[k]);
        }

        ans.push_back(permutation);
        return;
    }

    // Fixing a character at index i and then swapping with characters from index i to j and by this way building up permutation strings.
    for (int k = i; k <= j; k++) {
        swap(s, i, k);

        findPermutationsHelper(s, i + 1, j, ans);

        swap(s, i, k);
    }

}

vector <string> findPermutations(string &s) {
    // Declaring a vector of string to store all the possible permutations of the string.
    vector <string> ans;

    // Calling the user defined function which stores all the possible permutations of the string in the vector ans.
    findPermutationsHelper(s, 0, s.length() - 1, ans);

    return ans;
}