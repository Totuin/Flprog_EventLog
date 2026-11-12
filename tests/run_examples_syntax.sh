#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
for f in "$ROOT"/examples/*/*.ino; do
 g++ -x c++ -std=c++11 -Wall -Wextra -Werror -pedantic -fsyntax-only -include "$ROOT/tests/stub/example_tools.h" \
  -I "$ROOT/tests/stub" -I "$ROOT/src" -I "$ROOT/src/utilites" "$f"
 echo "EXAMPLE_SYNTAX_PASS: $(basename "$f")"
done
