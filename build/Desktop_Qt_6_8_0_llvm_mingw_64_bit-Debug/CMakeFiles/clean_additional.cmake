# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LAB7_bryan_banegas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LAB7_bryan_banegas_autogen.dir\\ParseCache.txt"
  "LAB7_bryan_banegas_autogen"
  )
endif()
