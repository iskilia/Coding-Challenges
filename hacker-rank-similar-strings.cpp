/* Similar Strings - HackerRank */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// Two subranges that are similar will always give same hash
int hash_subrange_similar(const string& s, int start, int len) {
    unsigned long hash = 5381;
    int similar_map[11] = {0};
    int count = 1;
    for (int i=start; i < start + len; i++) {
        int c = s[i];
        if (similar_map[c] == 0) {
            similar_map[c] = count;
            count++;
        }
        hash = hash * similar_map[c] + 33;
    }
    return (int)hash;
}

// Test if s[i..i+len] and s[j..j+len] are similar substrings
bool are_similar(const string& s, int i, int j, int len) {
    int similar_map_i[11] = {0};
    int similar_map_j[11] = {0};
    for (int k=0; k < len; k++) {
        int ci = s[i + k];
        int cj = s[j + k];
        if (similar_map_i[ci] == 0 && similar_map_j[cj] == 0) {
            similar_map_i[ci] = cj;
            similar_map_j[cj] = ci;
        } else if (similar_map_i[ci] != cj || similar_map_j[cj] != ci) {
            return false;
        }
    }
    return true;
}

int main() {
    int s_len, num_tests;
    cin >> s_len >> num_tests;
    string s;
    cin >> s;

    // Reduce characters to 1-10 range (reserve 0 for "unknown")
    for (int i=0; i < s.length(); i++) {
        s[i] = s[i] - 'a' + 1;
    }

    // To speed things up we start by creating an index:
    // we hash the first 12 characters at each position and
    // then track for each hash which positions match that hash.
    const int hash_length = 12;
    unordered_map<int, vector<int>> index;
    for (int i=0; i <= (int)s.length() - hash_length; i++) {
        int hash = hash_subrange_similar(s, i, hash_length);
        index[hash].push_back(i);
    }

    for (int i=0; i < num_tests; i++) {
        int start, end;
        cin >> start >> end;
        int query_start = start - 1; // start is 1-based
        int query_len = end - start + 1; // start/end are inclusive

        int count = 0;
        if (query_len >= hash_length) {
            // Hash first 12 chars of query then use index to get possible matching positions
            int hash = hash_subrange_similar(s, query_start, hash_length);
            for (int j : index[hash]) {
                if (j <= s.length() - query_len) {
                    if (are_similar(s, query_start, j, query_len)) {
                        count++;
                    }
                }
            }
        } else {
            // Brute force for short queries
            for (int j=0; j <= s.length() - query_len; j++) {
                if (are_similar(s, query_start, j, query_len)) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
