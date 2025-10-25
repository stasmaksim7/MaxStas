#!/bin/bach
echo "Run"
while true; do
	echo "Conecting true" | nc -l -p 1234 -q 1
done
