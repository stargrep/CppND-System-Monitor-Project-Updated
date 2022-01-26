#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    long hour{seconds / 3600}, min{(seconds - hour * 3600) / 60};
    string sec = seconds % 60 < 10 ? "0" + to_string(seconds % 60) : to_string(seconds % 60);
    return to_string(hour) + ":" + to_string(min) + ":" + sec; 
}