#!/bin/bash

# Maximum array size
max_size=10000

# Test with various array sizes
for size in $(seq 1 $max_size); do
  # Generate an array of random numbers of size $size
  arr=$(shuf -i 0-1000000 -n $size | tr "\n" " ")

  # Run the program and capture the return code
  ./PmergeMe $arr >/dev/null
  ret_code=$?

  # Log the results and exit if test failed
  if [ $ret_code -eq 1 ]; then
    echo "Test failed for size $size: Array not sorted"
    exit 1
  else
    echo "Test passed for size $size"
  fi
done

echo "Testing completed!"
