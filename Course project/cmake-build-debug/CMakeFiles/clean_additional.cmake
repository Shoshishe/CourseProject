# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Course_project_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Course_project_autogen.dir/ParseCache.txt"
  "Course_project_autogen"
  )
endif()
