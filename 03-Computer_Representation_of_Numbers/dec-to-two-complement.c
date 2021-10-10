#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  // Check if an argument is provided
  if (argc==2) {

    // Set the destination string as 8 zeros
    char dst[]="00000000";

    // Get the parameter from the command line end convert to integer
    int src=atoi(argv[1]);

    // Set the twoComplement flag as false
    int twoComplement = 0;

    // Check if the input parameter is a negative number
    if (src<0) {

      // Set the twoComplement flag as true
      twoComplement = 1;

      // Make the input paraameter a positive numeber
      src = -src;
    }

    // Get the maximum number of the binary digits
    int maxDigits=strlen(dst);

    // Set the idx to the leftmost digit
    int idx=maxDigits-1;

    // While the input parameter is different than zero and the index is valid...
    while (src!=0 && idx>=0) {

      // Set the idx-th digit as 0 if the reminder of the by 2 division is 0 else 1 otherwise
      dst[idx]='0'+src%2;

      // Divide the input parameter by two
      src=src/2;

      // Decrease the index
      idx--;
    }

    // Check if the input parameter is 0 (if it is not 0 an OVERFLOW error is rised)
    if (src==0) {

      // Check if the twoComplement flag is true
      if (twoComplement) {

        // Reverse each binary digit
        for(idx=0;idx<maxDigits;idx++) {
          if (dst[idx] == '0') {
            dst[idx]='1';
          } else { 
            dst[idx]='0';
          }
        }

        // Add 1 
        idx = maxDigits-1;
        while (idx>=0) {
          if (dst[idx] == '1') {
            dst[idx] = '0';
          } else {
            dst[idx] = '1';
            break;
          }
          idx--;
        }
      }  

      // Print the result
      printf("%s\n",dst);

      // Return to the command line
      return 0;
    } else {

      // Print the overflow error
      printf("ERROR: Overflow\n");

    // Return to the command line with an error
    return -2;
    }
  } else {
    // Print the usage message
    printf("Convert an iteger to its sign and module binary representation.\n");
    printf("Usage %s int\n",argv[0]);

    // Return to the command line with an error
    return -1;
  }
}
