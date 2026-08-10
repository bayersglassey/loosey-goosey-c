# Example files to play with

These are files copy-pasted from large C codebases, like CPython, the linux
kernel, etc.
The goal is to be able to run functions from them using the loosey goosey C
interpreter.

Some of the files in here were passed through the C preprocessor:
```
cp_cpython() {
    dir="$1"
    file="$2"
    cp "$dir/$file.c" examples/
    cpp -P \
        -DPy_BUILD_CORE \
        -I/usr/include/python3.12 \
        -I/usr/include/python3.12/internal \
        "$dir/$file.c" \
        >"examples/$file.pp.c"
}

cp_cpython ~/repos/cpython/Objects listobject
cp_cpython ~/repos/cpython/Objects dictobject
```
