if(EXISTS "/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests[1]_tests.cmake")
  include("/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests[1]_tests.cmake")
else()
  add_test(lab1tests_NOT_BUILT lab1tests_NOT_BUILT)
endif()
