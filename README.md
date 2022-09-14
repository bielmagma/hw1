NOTE: I do not know if it necessary to consider .get() at an invalid location as a test case. In my .cpp file, I am accounting for all invalid locations, but as testing this would cause the program to throw invalid_argument("bad location") from the get(size_t loc) function, I wrote one appropriate test case for each scenario, but left it as a comment below. To run these tests, just uncomment line 402, run it, then comment it back. Then, uncomment line 405, run it, then comment it back. Then, uncomment lines 407 and 408.

g++ command to compile my code:

g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test
