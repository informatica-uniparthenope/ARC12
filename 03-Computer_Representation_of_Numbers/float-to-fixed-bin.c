#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc==2) {
    char intDst[]="00000000";
    char floatDst[]="00000000";
    float src=atof(argv[1]);
    int intSrc=(int)src;
    float floatSrc=src-intSrc;

    int intMaxDigits=strlen(intDst);
    int floatMaxDigits=strlen(floatDst);
    int idx=intMaxDigits-1;

    while (intSrc!=0 && idx>=0) {
      intDst[idx]='0'+intSrc%2;
      intSrc=intSrc/2;
      idx--;
    }
    if (intSrc==0) {  

      idx=floatMaxDigits-1;

      while (floatSrc!=0 && idx>=0) {
        floatSrc=floatSrc*2;
        floatDst[idx]='0'+(int)floatSrc;
        if ((int)floatSrc==1) {
          floatSrc=floatSrc-1;
        }
        idx--;
      }
      
      printf("%s.%s\n",intDst,floatDst);
      return 0;
    } else {
      printf("ERROR: Overflow\n");
    return -2;
    }
  } else {
    printf("Convert a float to its vanilla binary fixed point representation.\n");
    printf("Usage %s float\n",argv[0]);
    return -1;
  }
}
