
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
