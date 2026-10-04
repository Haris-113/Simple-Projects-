#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * do not use in real code this is just an example!
 * This reads in 1 character at a time filling in a buffer
 */
char *gets(char *buf)
{
  char *p = buf;
  int ch;

  while (1) {
    ch = getchar();
    if (ch == EOF) {
      return NULL;
    }

    if (ch == 8) {
      if (p > buf) {
        putchar('\b');
        putchar(' ');
        putchar('\b');
        p--;
      }
    } else if (ch == '\r' || ch =='\n' || ch >= ' ') {
      putchar(ch);
      if (ch == '\r') putchar('\n');
      if (ch == '\n' || ch == '\r') break;
      *p++ = ch;
    }
  }

  *p = 0;
  return buf;
}


/* 
 * Check the users password
 */
int check_pass(){

    char buff[13];
    int correct = 0;
    int attempts = 0;
    do {
        printf ("Please enter your password:");
        gets(buff);
        if (strcmp(buff, "magnolia")!=0){
            printf ("Try again\n");
            attempts++;
        }
        else{
            printf("Correct\n");
            correct=1;
        }
    }while (correct==0 && attempts<3);
    return correct;
}
    

int main(int argc, char * argv[]){
    
    int ok=0;
    ok=check_pass();
    if(ok==0){
        printf ("Failed authentication\n");
        return -1; //error code returned by program
    }else{
        printf("Authenticated! Welcome back!\n");
        
    }                                                                     
    return 0;//successful completion of program
}
          
