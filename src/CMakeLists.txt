file(GLOB source_files *.cpp *.h)
add_library(projedii ${source_files})
target_include_directories(projedii PUBLIC ${PROJECT_SOURCE_DIR}/src  ${PROJECT_SOURCE_DIR}/include)
