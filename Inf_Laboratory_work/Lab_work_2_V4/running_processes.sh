#!/bin/bash
echo "All processes:"
ps aux
echo "Amount processes:"
t1=$(ps aux | wc -l)
t2=$((t1 - 1))
echo $t1
