#!/usr/bin/env bash
# Пример: ./tests/run_with_real_eeprom.sh ../Flprog_EEPROM/src
# Для этого теста нужны исходники отдельно установленной Flprog_EEPROM 1.0.1.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEP="${1:-$(cd "$ROOT/../Flprog_EEPROM/src" && pwd)}"
mapfile -d '' sources < <(find "$ROOT/src" -name '*.cpp' -print0)
CXX="${CXX:-g++}"
OUT="$(mktemp)"
trap 'rm -f "$OUT"' EXIT
"$CXX" -std=c++11 -Wall -Wextra -Werror -pedantic \
 -fsanitize=address,undefined -fno-omit-frame-pointer -g \
 -I "$ROOT/tests/real_stub" -I "$ROOT/src" -I "$ROOT/src/utilites" -I "$DEP" \
 "${sources[@]}" "$DEP/flprogEEPROM.cpp" "$ROOT/tests/real_eeprom_smoke.cpp" -o "$OUT"
ASAN_OPTIONS=detect_leaks=1 "$OUT"
