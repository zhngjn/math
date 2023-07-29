#!/usr/bin/env python3
import sys
import os.path
import os

cur_dir = os.getcwd()
default_unit_tests_bin_dir = os.path.join(cur_dir, "../build/test")

unit_tests = [
    "test_geometry",
    "test_util",
]

for unit_test in unit_tests:
    unit_test_bin_path = os.path.join(default_unit_tests_bin_dir, unit_test)
    res = os.system(unit_test_bin_path)
    if res != 0:
        print('\033[31munit test {} failed!\033[0m'.format(unit_test))
        sys.exit(1)
        
print('\033[32mall unit tests passed\033[0m')