// -----------
// Collatz.c++
// -----------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <tuple>    // make_tuple, tie, tuple
#include <utility>  // make_pair, pair
#include <unordered_map>

#include "Collatz.hpp"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i, j;
    sin >> i >> j;
    return make_pair(i, j);
}

// ------------
// collatz_eval
// ------------

//computes the cycle length for an individual number without looking up the cache
//utilizes the n + (n >> 1) + 1 optimization
int cycleLengthOfNum(long num) {
    int length = 1;
    while(num > 1) {
        if((num % 2) == 0) {
            num /= 2;
            length += 1;
        }
        else {
            num = num + (num >> 1) + 1;
            length += 2;
        }
    }
    return length;
}

//cache of groups of 1000 numbers, stores the maximum cycle length of that group
int cache[1000];

//initializes the cache with the maximum cycle length in each group, called in collatz_solve
void setupCache() {
    for(int x = 0; x < 1000; ++x) {
        int maxLengthOfPortion = 0;
        for(long y = x * 1000 + 1; y < x * 1000 + 1000; ++y) {
            int length = cycleLengthOfNum(y);
            if(length > maxLengthOfPortion) {
                maxLengthOfPortion = length;
            }
        }
        cache[x] = maxLengthOfPortion;
    }
}


tuple<int, int, int> collatz_eval (const pair<int, int>& p) {
    int i, j;
    tie(i, j) = p;
    //use long to make sure there isnt overflow
    long min = (long)i;
    long max = (long)j;
    //making sure order doesnt matter on the input
    if(i > j) {
        min = j;
        max = i;
    }
    //second optimization shown to us
    long m = (max / 2) + 1;
    if(min < m) {
        min = m;
    }
    //iterate over range, utilize cache whenever possible
    int maximumLength = 0;
    for(long x = min; x <= max; ++x) {
        int length;
        if(x % 1000 == 1 && max - x >= 1000) {
            length = cache[x / 1000];
            x += 999;
        }
        else {
            length = cycleLengthOfNum(x);
        }
        if(length > maximumLength) {
            maximumLength = length;
        }
    }
    return make_tuple(i, j, maximumLength);
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& sout, const tuple<int, int, int>& t) {
    int i, j, v;
    tie(i, j, v) = t;
    sout << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& sin, ostream& sout) {
    setupCache();
    string s;
    while (getline(sin, s))
        collatz_print(sout, collatz_eval(collatz_read(s)));
}
