#!/bin/bash

for ((i = 1;i <= 16;i = i + 1))
do
cp ${i}.in bbreeds.in
./a.out
cmp ${i}.out bbreeds.out
if [ $? = 0 ] ; then
echo "TEST CASE $i PASSED"
fi
done

rm bbreeds.in bbreeds.out
