The following will successfully compile under Apple's OS X 10.14.1 (Mojave):

```sh
clang++ --analyze -Wall -DSC_INCLUDE_DYNAMIC_PROCESSES -isystem $SYSTEMC/include -std=c++14 -o hasprocess.o -c hasprocess.cpp
```
