add_test([=[Lab1Hash.AddOneElement]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=Lab1Hash.AddOneElement]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Lab1Hash.AddOneElement]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Lab1Hash.Add4Elements]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=Lab1Hash.Add4Elements]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Lab1Hash.Add4Elements]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Lab1Hash.AddAndRemoveMany]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=Lab1Hash.AddAndRemoveMany]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Lab1Hash.AddAndRemoveMany]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Lab1Hash.AddFileRandom]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=Lab1Hash.AddFileRandom]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Lab1Hash.AddFileRandom]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Lab1Hash.AddFilelength8]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=Lab1Hash.AddFilelength8]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Lab1Hash.AddFilelength8]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[AuxLab1Hash.HashValueIsInsideVector]=]  [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build/lab1tests]==] [==[--gtest_filter=AuxLab1Hash.HashValueIsInsideVector]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AuxLab1Hash.HashValueIsInsideVector]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/marcelversiani/Laboratórios/Lab1_Hash/lab1hash230309_1658/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  lab1tests_TESTS Lab1Hash.AddOneElement Lab1Hash.Add4Elements Lab1Hash.AddAndRemoveMany Lab1Hash.AddFileRandom Lab1Hash.AddFilelength8 AuxLab1Hash.HashValueIsInsideVector)
