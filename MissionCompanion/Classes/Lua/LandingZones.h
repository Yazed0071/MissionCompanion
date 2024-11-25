#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>



// Function to split a string into a vector based on a delimiter
std::vector<std::string> SplitString(const std::string& str, char delimiter);

// Function to filter and format landing zones
std::string GetListLandingZone(const std::string& checkedLZs);