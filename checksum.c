/********************************/
/* Program Name: Checksum.c     */
/* Author: Garrette Clarke      */
/* Date:    2/16/21             */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;
  byte header[10];

  int checksumposition = 5; 
  int quotient; 
  int remainder; 
  int tempsum = 0;

  
  int retval;
  
  retval = read(STDIN_FILENO, &header, 10);  
```

    
    for (int i = 0; i < count; i++) {
      
      
      if (i == checksumposition) {
         checksum = header[i];
         header[i] = 0;
      } 

      sum = header[i] + sum;
 

      quotient = sum/(max_int + 1);
      remainder = sum%(max_int + 1);
      tempsum = quotient + remainder;
      complement = max_int - tempsum;
    }  
   

    


```
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}