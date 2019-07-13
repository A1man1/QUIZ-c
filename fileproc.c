#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **loadfile(char * filename,int *len);

/* int main(int argc,char *argv[])
   {
   //lenght of charater
   int length=0;
   char *file;
   
   
   if(argc==1)
    {
     printf("User is not giving any  question file path.\n"
             "Now,file  is set on  default name\n");
       file="question.txt";
   }
   else
    {
       file=argv[1];
    }
     srand(time(NULL));
     char *random;
     char **words=loadfile(file, &length);
     //puts(file);
      printf("%d",length);
      int n;
     for(int i=0;i<10;i++)
        {
          random=words[rand() % 10];
          printf("%s",random);
        }
   return 0;
 }*/

char **loadfile(char *filename,int *len)
             {
               FILE *file=fopen(filename,"r");
                 if(!file)
                  {
                    fprintf(stderr,"Can't open %s for reading \n",filename);
                     return NULL;
                   }
                char **lines =(char **)malloc(100 * sizeof(char *));
                 char buff[1000];  
                  
                  int index=0;
              while (fgets(buff,1000,file))
                {
                   if(index==100)
                         {
                           char** newl=(char **)realloc(lines,200* sizeof(char *));
                                if(!newl)
                                 {
                                     fprintf(stderr,"Memory fail to reallocate\n");
                                      exit(0);
                                 }
                                 lines=newl;
                          }
                   //get length of buffer
                    int slen=strlen(buff);
                     
                   //allocate string acqurate space
                     char *str=(char *)malloc((slen+1) *sizeof(char));
                   
                  //copy string in buffer (key point of idea)
                       strcpy(str,buff);
                
                  //Attach str to data structure
                        lines[index]=str;
                       index++;

                 }
                 * len=index;//set the ;length of the array
               return lines;
             }
