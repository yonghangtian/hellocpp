#!/bin/bash
echo "Total: "
find . \( -wholename "*chapter*.cpp" -o -wholename "*chapter*.h" \) -exec wc -l {} + | awk '{total += $1} END {print total}'
echo "CppPrimer5th:"
#find CppPrimer5th \( -wholename "*chapter*.cpp" -o -wholename "*chapter*.h" \) -exec ls -l {} +
find CppPrimer5th \( -wholename "*chapter*.cpp" -o -wholename "*chapter*.h" \) -exec wc -l {} + | awk '{total += $1} END {print total}'
echo "CppPrimerPlus:"
#find CppPrimerPlus \( -wholename "*chapter*.cpp" -o -wholename "*chapter*.h" \) -exec ls -l {} +
find CppPrimerPlus \( -wholename "*chapter*.cpp" -o -wholename "*chapter*.h" \) -exec wc -l {} + | awk '{total += $1} END {print total}'
