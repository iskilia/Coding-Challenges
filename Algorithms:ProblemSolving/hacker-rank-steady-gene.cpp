#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

bool isBalanced(int limit, unordered_map<char, int> dictionary){
    if (dictionary['A'] <= limit && dictionary['C'] <= limit && dictionary['G'] <= limit
            && dictionary['T'] <= limit){
        return true;
    } else {
        return false;
    }
}

// Complete the steadyGene function below.
int steadyGene(string gene) {
    unordered_map<char, int> dictionary;
    for(int i = 0; i < gene.length(); i++){
        dictionary[gene[i]] += 1;
    }
    int maxOccurences = gene.length()/4;
    int minimumSubstringLength = INT_MAX;
    int i = 0, j = 0;
    while(i < gene.length() && j < gene.length()){
        if (!isBalanced(maxOccurences, dictionary)) {
            dictionary[gene[j]] -= 1;
            j++;
        } else {
            minimumSubstringLength = min(minimumSubstringLength, j - i);
            dictionary[gene[i]] += 1;
            i++;
        }
    }
    return minimumSubstringLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
