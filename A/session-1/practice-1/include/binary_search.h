#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <vector>

// Search for the target number using binary search. The vector needs to be sorted
inline bool BinarySearch(const std::vector<int>& values, const int target) {
  
  if (values.empty()) {
  	return false;
  }
  
  int start = 0;
  int end = static_cast<int>(values.size()) - 1;
	
  while (start <= end) {
    int middle = (end + start) / 2;
    if (target < values[middle]) {
      end = middle - 1;
    } else if (target > values[middle]) {
      start = middle + 1;
    } else {
      return true;
    }
  }
  return false;
}

#endif
