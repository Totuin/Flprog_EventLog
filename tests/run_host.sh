#!/usr/bin/env bash
# Самодостаточные тесты алгоритма с имитацией FLProg EEPROM.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
mapfile -d '' sources < <(find "$ROOT/src" -name '*.cpp' -print0)
CXX="${CXX:-g++}"
OUT="$(mktemp)"
trap 'rm -f "$OUT"' EXIT
"$CXX" -std=c++11 -Wall -Wextra -Werror -pedantic \
 -fsanitize=address,undefined -fno-omit-frame-pointer -g \
 -I "$ROOT/tests/stub" -I "$ROOT/src" -I "$ROOT/src/utilites" \
 "${sources[@]}" "$ROOT/tests/test_eventlog.cpp" -o "$OUT"
ASAN_OPTIONS=detect_leaks=1 "$OUT"
