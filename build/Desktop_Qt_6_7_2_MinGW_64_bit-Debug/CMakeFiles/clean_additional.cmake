# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Hive_FinalWork_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Hive_FinalWork_autogen.dir\\ParseCache.txt"
  "Hive_FinalWork_autogen"
  )
endif()
