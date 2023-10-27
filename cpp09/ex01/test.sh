#!/bin/bash
make re
expressions=(
  "2 3 +"
  "5 6 * 7 +"
  "9 2 / 3 +"
  "3 4 5 * -"
  "1 2 3 4 5 * * * * 6 +"
  "1 2 + 3 4 + *"
  "2 2 + 3 * 4 - 5 /"
  "4 5 * 3 / 2 -"
  "10 3 / 3 + 2 *"
  "1 2 + 3 - 4 *"
  "1 2 3 * + 4 /"
  "8 9 * 9 - 9 - 9 - 4 - 1 +"
  "7 7 * 7 -"
  "1 2 * 2 / 2 * 2 4 - +"
  "(1 + 1)"
)

expected_results=(
  "5"
  "37"
  "7"
  "-17"
  "126"
  "21"
  "1"
  "4"
  "Error"
  "0"
  "1"
  "42"
  "42"
  "0"
  "Error"
)

count=0
for exp in "${expressions[@]}"; do
  count=$((count + 1))
  echo -e "\n\033[1mExpression:\033[0m \033[1;32m$exp\033[0m"

  expected_result=${expected_results[count - 1]}

  result=$(./RPN "$exp")
  if [ "$result" == "$expected_result" ]; then
    echo -e "Output:\033[1;32m $result\033[0m"
    echo -e "Expected:\033[0\033[1;32m $expected_result\033[0m"
  elif [ -z "$result" ]; then
    echo -e "\033[33mExpected: $expected_result\033[0m"
    continue
  else
    echo -e "\033[1;31mOutput: $result\033[0m"
    echo -e "\033[1;31mExpected: $expected_result\033[0m"
  fi
  if ((count == 11)); then
    echo -e "\n\033[34mSubject tests:\033[0m"
  fi
done
echo -e "\n\nAll RPN executions completed.\n"
echo -e "Running make fclean: "

make fclean
