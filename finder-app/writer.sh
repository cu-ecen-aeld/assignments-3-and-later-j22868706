#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Error: Two args required" >&2
	echo "Usage: $0 <writerfile> <writerstr>" >&2
	exit 1
fi

writefile=$1
writestr=$2

dirpath=$(dirname "$writefile")
mkdir -p "$dirpath"

if [ ! -d "$dirpath" ]; then
	echo "Error: Failed to create dirctory path '$dirpath'."
	exit 1
fi

echo "$writestr" > "$writefile"

if [ ! -f "$writefile" ]; then
	echo "Error: Failed to create or write to file '$writefile'."       
	exit 1
fi

exit 0
