#!/bin/bash
for i in {1..20}; do
	if [ $((i % 2)) -eq 0 ]; then
		echo $i
	fi
done
