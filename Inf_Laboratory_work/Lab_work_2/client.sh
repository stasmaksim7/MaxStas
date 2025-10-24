#!/bin/bash
echo "Text:"
read message
echo $message | nc localhost 1234
