#!/bin/bash

declare -a paths=( ./src/ ./test/ );
declare -a exts=( *.h *.hpp *.c *.cpp *.cxx *.tpp );

for path in ${paths[@]}; do
    for ext in ${exts[@]}; do
        echo Formatting $ext in $path
        find $path -iname $ext -print0 | xargs -d0 clang-format -i
    done
done
