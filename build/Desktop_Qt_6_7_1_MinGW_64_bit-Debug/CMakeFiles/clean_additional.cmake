# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\hudak_uloha2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hudak_uloha2_autogen.dir\\ParseCache.txt"
  "hudak_uloha2_autogen"
  )
endif()
