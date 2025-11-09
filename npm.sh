#!/usr/bin/env bash
if [[ "$1" != "publish" ]]; then
  echo "This script only supports 'publish' command."
  exit 1
fi
url="https://github.com/pocketpy/pocketpy/releases/download/v2.1.3"
curl -L -o libpocketpy.a "$url/libpocketpy.a"
curl -L -o pocketpy.c "$url/pocketpy.c"
curl -L -o pocketpy.h "$url/pocketpy.h"
npm publish
rm libpocketpy.a pocketpy.c pocketpy.h
