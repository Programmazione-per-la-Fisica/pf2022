# Esempio di uso di CMake

> Lavori in Corso

Per configurare in debug mode

```
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug
```

Per configurare in release mode

```
$ cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Release
```

Per buildare il codice

```
$ cmake --build build/debug
```

Per eseguire l'eseguibile prodotto (in questo caso `mandelbrot_sfml`)

```
$ build/debug/mandelbrot_sfml
```

Per eseguire i test

```
$ cmake --build build --target test
```

Per eseguire diretamente l'eseguibile dei test (in questo caso `all.t`), con maggiori dettagli

```
$ build/debug/all.t
```
