#!/usr/bin/env python3

from pathlib import Path
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
src_dir = os.path.join(current_dir, "src")
chapters_dir = os.path.join(current_dir, "chapters")

CLANGFORMATARGS = [
    "--style=LLVM",  # NOT FORMAT
    "-i",
]

for path in Path(src_dir).rglob('*.h'):
    COMMAND = " ".join(["clang-format"] + CLANGFORMATARGS) + " " + str(path)
    print(COMMAND)
    os.system(COMMAND)

for path in Path(src_dir).rglob('*.cpp'):
    COMMAND = " ".join(["clang-format"] + CLANGFORMATARGS) + " " + str(path)
    print(COMMAND)
    os.system(COMMAND)

for path in Path(chapters_dir).rglob('*.h'):
    COMMAND = " ".join(["clang-format"] + CLANGFORMATARGS) + " " + str(path)
    print(COMMAND)
    os.system(COMMAND)

for path in Path(chapters_dir).rglob('*.cpp'):
    COMMAND = " ".join(["clang-format"] + CLANGFORMATARGS) + " " + str(path)
    print(COMMAND)
    os.system(COMMAND)
