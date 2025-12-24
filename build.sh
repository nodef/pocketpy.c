#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "pocketpy" ]; then return; fi
URL1="https://github.com/pocketpy/pocketpy/releases/download/v2.1.4/pocketpy.c"
URL2="https://github.com/pocketpy/pocketpy/releases/download/v2.1.4/pocketpy.h"
FILE1="${URL1##*/}"
FILE2="${URL2##*/}"

# Download the release
if [ ! -d "pocketpy" ]; then
  mkdir -p pocketpy
  echo "Downloading $FILE1 from $URL1 ..."
  curl -L "$URL1" -o "pocketpy/$FILE1"
  echo "Downloading $FILE2 from $URL2 ..."
  curl -L "$URL2" -o "pocketpy/$FILE2"
  echo ""
fi
}


# Test the project
test() {
echo "Running 01-basic.c ..."
clang -I. -o 01.exe examples/01-basic.c      && ./01.exe && echo -e "\n"
echo "Running 02-embedding.c ..."
clang -I. -o 02.exe examples/02-embedding.c  && ./02.exe && echo -e "\n"
echo "Running 03-extension.c ..."
clang -I. -o 03.exe examples/03-extension.c  && ./03.exe && echo -e "\n"
echo "Running 04-advanced.c ..."
clang -I. -o 04.exe examples/04-advanced.c   && ./04.exe && echo -e "\n"
echo "Running 05-demo.c ..."
clang -I. -o 05.exe examples/05-demo.c && ./05.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
