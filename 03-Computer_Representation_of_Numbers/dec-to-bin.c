#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc==2) {
    char dst[]="00000000";
    int src=atoi(argv[1]);
    int maxDigits=strlen(dst);
    int idx=maxDigits-1;

    while (src!=0 && idx>=0) {
      dst[idx]='0'+src%2;
      src=src/2;
      idx--;
    }
    if (src==0) {  
      printf("%s\n",dst);
      return 0;
    } else {
      printf("ERROR: Overflow\n");
    return -2;
    }
  } else {
    printf("Convert an iteger to its vanilla binary representation.\n");
    printf("Usage %s int\n",argv[0]);
    return -1;
  }
}
