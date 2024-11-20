#!/bin/bash

find default-handlers/ -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i
find demo/ -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i
find engine/ -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i
