/**
 *
 * Decimal to binary converter, by Martin Brown
 *
*/
char * decimalToBinary(int decimal, int maxBits) {

    int i;
    int gotLeftmostBit = 0; // don't start concatenating until we have most significant bit
    char * binary = malloc(maxBits * sizeof(char));

    char lowBit[2] = "0";
    char highBit[2] = "1";

    if(decimal == 0) // special case
        return "0";

    int isHighBit = 1; // flag is on if the next bit is 1

    // start looping at the most significant bit down to the least
    for(i = maxBits - 1; i >= 0; i--) {

        // get the i'th bit
        // shift to move it in the 0th position, to clear the bits less significant than the ith bit
        // then mask with leading 0s to clear the bits more significant than the ith bit
        if((decimal >> i) & 1) {

            gotLeftmostBit = 1; // turn concatenation on
            isHighBit = 1; // the ith bit = 1
        }   
        else {
            isHighBit = 0; // the ith bit = 0
        }   

        if(gotLeftmostBit) // if concatenation is on, start concatenating!
            strcat(binary, isHighBit ? highBit : lowBit);
    }   

    return binary;
}
