mkdir build 
gcc $(find . -name "*.c") -o build/main
cd build
./main