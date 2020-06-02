## Using Intrinsics-VIMA library

You can choose optimizing Intrinsics-VIMA with inline option, compiling as it follows:

'**g++ -O3 vima.cpp -o vima**'

or not, by using noinline option to generate simulation traces, compiling as it follows:

'**g++ -O3 -DNOINLINE vima.cpp -o vima**'
