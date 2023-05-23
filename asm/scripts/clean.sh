#!/bin/bash

patterns=(
    "*.o"
    "*.gcda"
    "*.gcno"
    "vgcore*"
)

for pattern in "${patterns[@]}"
    do
    find . -name "${pattern}" -delete
    done
