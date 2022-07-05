// ---------
// Collatz.h
// ---------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <tuple>    // tuple
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param a string
 * @return a pair of ints
 */
pair<int, int> collatz_read (const string&);

// ------------
// cycleLengthOfNum
// ------------

/**
 * finds the cycle length of a  num
 * @param a long
 * @return an int
 */
int cycleLengthOfNum(long num);

// ------------
// setupCache
// ------------

/**
 * Sets up the cache with the maximum cycle length of a group of 1000 numbers
 */
void setupCache();

// ------------
// collatz_eval
// ------------

/**
 * @param a pair of ints
 * @return a tuple of three ints
 */
tuple<int, int, int> collatz_eval (const pair<int, int>&);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param an ostream
 * @param a tuple of three ints
 */
void collatz_print (ostream&, const tuple<int, int, int>&);

// -------------
// collatz_solve
// -------------

/**
 * @param an istream
 * @param an ostream
 */
void collatz_solve (istream&, ostream&);

#endif // Collatz_h
