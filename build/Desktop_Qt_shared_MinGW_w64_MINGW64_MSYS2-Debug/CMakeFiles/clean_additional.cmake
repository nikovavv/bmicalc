# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BMIcalc_autogen"
  "CMakeFiles\\BMIcalc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BMIcalc_autogen.dir\\ParseCache.txt"
  )
endif()
