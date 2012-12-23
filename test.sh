#!/bin/bash

for ((i = 1;i <= 10;i = i + 1))
do
cp ${i}.in wifi.in
./3
cmp ${i}.out wifi.out
if [ $? = 0 ] ; then
echo "TEST CASE $i PASSED"
else
diff ${i}.out wifi.out
fi
done

rm wifi.in wifi.out
