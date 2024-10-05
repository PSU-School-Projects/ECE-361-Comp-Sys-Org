# Individual Bit Manipulation in C

**Check if any bit is a 0:**
```C
//unsigned char is 8 bits
//so the binary value in this example is 8 bits long
bool check_any_0(unsigned char binaryVal) {
    /*flips bits in passed in binary value 
    if at least one bit in the flip array is 0 returns the index in 1-based index
    subtract one after to get 0 based index.
    returns 0 if no 0s are found
    */
    unsigned char flippedVal = ~binaryVal;
    if (flippedVal) {
        return ffs(flippedVal); //GCC or Clang only
    }
    return ~binaryVal
}
```

**Check if all bits are 0:**
```C
bool check_all_0(unsigned char binaryVal) {
    return binaryVal == 0;
}
```

**Check if only one 1:**
```C
int check_one_1(unsigned char binaryVal) {
    if (value != 0 && (value & (value - 1)) == 0) {
        /* Only one bit is set to 1
        return the 1-base index
        the index in 1-based index
        subtract one after to get 0 based index.
        returns 0 if no 0s are found
        */
        return ffs(flippedVal)
    }
}
```