#! /bin/sh
echo "Compiling $1"
clang++ -Wall -std=c++2a -stdlib=libc++ -fimplicit-modules -fimplicit-module-maps $1.cpp -o $1.out
