// ---------------
// TestCollatz.c++
// ---------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>  // istringtstream, ostringstream
#include <tuple>    // make_tuple, tuple
#include <utility>  // make_pair, pair

#include "gtest/gtest.h"

#include "Collatz.hpp"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    ASSERT_EQ(collatz_read("1 10\n"), make_pair(1, 10));
}

// ----
// eval
// ----

TEST(CollatzFixture, eval0) {
    ASSERT_EQ(collatz_eval(make_pair(1, 10)), make_tuple(1, 10, 20));
}

TEST(CollatzFixture, eval1) {
    ASSERT_EQ(collatz_eval(make_pair(100, 200)), make_tuple(100, 200, 125));
}

TEST(CollatzFixture, eval2) {
    ASSERT_EQ(collatz_eval(make_pair(201, 210)), make_tuple(201, 210, 89));
}

TEST(CollatzFixture, eval3) {
    ASSERT_EQ(collatz_eval(make_pair(900, 1000)), make_tuple(900, 1000, 174));
}

TEST(CollatzFixture, eval4) {
    ASSERT_EQ(collatz_eval(make_pair(10, 1)), make_tuple(10, 1, 20));
}

TEST(CollatzFixture, eval5) {
    ASSERT_EQ(collatz_eval(make_pair(200, 100)), make_tuple(200, 100, 125));
}

TEST(CollatzFixture, eval6) {
    ASSERT_EQ(collatz_eval(make_pair(210, 201)), make_tuple(210, 201, 89));
}

TEST(CollatzFixture, eval7) {
    ASSERT_EQ(collatz_eval(make_pair(1, 1)), make_tuple(1, 1, 1));
}

TEST(CollatzFixture, eval8) {
    ASSERT_EQ(collatz_eval(make_pair(1, 2)), make_tuple(1, 2, 2));
}

TEST(CollatzFixture, eval9) {
    ASSERT_EQ(collatz_eval(make_pair(2, 1)), make_tuple(2, 1, 2));
}

TEST(CollatzFixture, eval10) {
    ASSERT_EQ(collatz_eval(make_pair(1500, 3500)), make_tuple(1500, 3500, 199));
}

TEST(CollatzFixture, eval11) {
    ASSERT_EQ(collatz_eval(make_pair(3500, 1500)), make_tuple(3500, 1500, 199));
}

TEST(CollatzFixture, eval12) {
    ASSERT_EQ(collatz_eval(make_pair(1, 100)), make_tuple(1, 100, 119));
}

TEST(CollatzFixture, eval13) {
    ASSERT_EQ(collatz_eval(make_pair(100, 1)), make_tuple(100, 1, 119));
}

TEST(CollatzFixture, eval14) {
    ASSERT_EQ(collatz_eval(make_pair(999, 2001)), make_tuple(999, 2001, 51));
}

TEST(CollatzFixture, eval15) {
    ASSERT_EQ(collatz_eval(make_pair(2001, 999)), make_tuple(2001, 999, 51));
}

TEST(CollatzFixture, eval16) {
    for(int x = 0; x < 1000; x++) {
        ASSERT_EQ(get<2>(collatz_eval(make_pair(1, 1 + x))), get<2>(collatz_eval(make_pair(1 + x, 1))));
    }
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream sout;
    collatz_print(sout, make_tuple(1, 10, 20));
    ASSERT_EQ(sout.str(), "1 10 20\n");
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream sin("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream sout;
    collatz_solve(sin, sout);
    ASSERT_EQ(sout.str(), "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");
}
