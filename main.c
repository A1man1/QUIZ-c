#include "fileproc.c"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 5
void get_test1();
void get_test2();
void getchoic();
char *replace(char *s)
{
 char *n=malloc(strlen(s ? s:"\n"));
  if(s)
     strcpy(n,s);
   n[strlen(n)-1]='\0';
    return n;
}
int getwords(char * base,char tar[30][500]);
int main()
{
system("clear");
 const char*Ban="\t\t============================================================================================================================================\b\n"
                                                                      "\t\t\t\t\t\t\t\tWELCOME  IN QUIZ\b\t\t\t\n"
                                                                   "\t\t\t\t\t\t\tQuiz version 0.0.1 develop by Aman Sharma\b\t\t\t\n"                          
               "\t\t\t\t\t\t\tplease follow instruction carefully\t\t\t\n"
                 "\t\t\t\t\t\t\t1.choose from given option and of given number\t\t\n"
                 "\t\t\t\t\t\t\t2.You will got 10 question in each instance\t\t\t\n"
                 "\t\t\t\t\t\t\t3.In each correct answer. You will got 1 point and 5 point need to pass the quiz\t\t\t\n"   
             "\t\t=============================================================================================================================================\b\n\0";   
     puts(Ban);
     time_t t;
  srand((unsigned)time(&t));
                         
                        char ch='y';  
                       char choice; 
                            printf("\n\t\t\t\tPLEASE CHOOSE YOUR QUIZ CATEGORY FROM OPTION\n");
                        const char *option="\t\t\t\tYour option are:-------------------------------\n "
                                            "\t\t\t\t\t1.Gernal Knowledge.\n"
                                            "\t\t\t\t\t2.Sports.\n";
                             puts(option);
                             printf("\t\t\t\t\tEnter your number for choose: ");  
                             choice=getchar();
                             int count=0;  
                              while(ch!='n')
                              {
                                      if(choice== '1')
                                       {
                                       get_test1();
                                       count++;
                                       choice='\0';
                                       }
                                else if( choice=='2')
                                      {
                                       get_test2();
                                       count++;
                                        choice='\0';
                                      }
                         
                                  else if(count==0)
                                       {
                                       printf("choose correct from given option: ");
                                        choice='\0';
                                        choice=getchar();
                                       }
                                       
                                  if(count>=1)
                                       { 
                                        printf("Do you wanna continue[y/n]: ");
                                        ch=getchar();
                                        wait(+10);
                                       if(ch=='y')
                                        { 
                                          printf("press your next choice: \n");
                                            choice=getchar();
                                           
                                           if(choice<'3') 
                                              {
                                               printf("choose correct from given option: \n");
                                               choice=getchar();
                                              }
                                        }
                                     else if(choice=='n') 
                                       {
                                         printf("Have a nice day!\n");
                                         exit(1);
                                        }
                                   }
                                }
  return 0;
}

 void get_test1()
   {
   printf("You have choose 'Gernal knowlegde' quiz\b\nYour question are:\b\n\a");
   
   int length=0;
        int len1=0;
      char *file="question1.txt";
      char **words=loadfile(file, &length);
      char *file1="answer1.txt";
      char **words1=loadfile(file1,&len1);
      char *random, *ran, *ptr, * a1, *a2, *a3, *a4, *ser1, *ser,*io;
     char answer;
     int count=0;
   char arr[20][500];
     int jb , jc=0,n1;
    char ar[20][500];
   int j=0,k=0,i=10,g=0;
       int n; 
    while(g<10)
      {  
        jb=(rand() % 20+i)+1;
        if(jb!=jc)
         {
            jb++;
         }
         jc=jb;
        random=words[jb];
        ran =words1[jb];
        n=getwords(random,arr); 
        n1=getwords(ran,ar);
         ser=arr[n];
         ser1=replace(ser);
         a1=arr[n-1];
         a2=arr[n-2];
         a3=arr[n-3];
         a4=arr[n-4];
          ran=replace(ran);
           //printf("%s",ran);
          //printf("%s",ser1); 
        ptr=strchr(random,'?'); 
        if(ptr!=NULL)
        {
          *ptr='\0';
        }
         
        printf("\nQ%i.%s?",g+1,random); 
        printf("\nA.%s\nB.%s\nC.%s\nD.%s\n",a1,a2,a3,a4); 
        printf("choose Your option:\n"); 
        answer=getchar() ;
         printf("Your answer is %c ",answer);
         if(answer==' '||answer=='\0'||answer=='\n')
          {
           answer=getchar();
          }
        switch(answer)
          {
            case 'a':
                  //strcat(ser1,a1);
                  //printf("%s\n",ser);
 
                        if(strcmp(ran,a1)==0)
                           {
                             count++;
                printf("Right answer! %s\nyour score is %i",a1,count); 
                          break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a1);
                            }
              break;
            case 'b':
                   //printf("%s\n",strcat(ser1,a2));
                        
                        if(strcmp(ran,a2)==0)
                           {
                             count++;
         printf("Right answer! %s\nyour score is %i",a2,count);
                            
                            }
                           else
                            {
                            printf("Worng answer! %s",a2);
                            
                            }
                 break;
            case 'c':
                // strcat(ser1,a3);
                 //ccsd printf("%s\n",ser1);
           
                        if(strcmp(ran,a3)==0)
                           {
                             count++;
                   printf("Right answer! %s\nyour score is %i\n",a3,count);
                              break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a3);
                              break;
                            }
                        
              break;
            case 'd':
                // strcat(ser1,a4);
                  // printf("c%s\n",ser);
               
                        if(strcmp(ran,a4)==0)
                           {
                             count++;
            printf("Right answer! %s\nyour score is %i",a4,count);
                           break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a4);
                              break;
                            }
                        
              break;
           }
         
          g+=1;
          i++;
          wait(60);   
         }
      if(count >4)
          {
             printf("congrats you passed quiz by score %i \n",count);
          }
        else
            {
             printf("please try again you below score 10\n");
            }
  }


// chooic second
 void get_test2()
   {
   printf("You are choosing 'sports' quiz\nYour question are:\n\a");
     int length=0;
        int len1=0;
      char *file="question2.txt";
      char **words=loadfile(file, &length);
      char *file1="answer2.txt";
      char **words1=loadfile(file1,&len1);
      char *random, *ran, *ptr, * a1, *a2, *a3, *a4, *ser1, *ser,*io;
     char answer;
     int count=0;
   char arr[20][500];
     int jb , jc=0,n1;
    char ar[20][500];
   int j=0,k=0,i=0,g=1;
       int n; 
    while(i<10)
      {  
        jb=(rand() % 20+i)+1;
        if(jb!=jc)
         {
            jb++;
         }
         jc=jb;
        random=words[jb];
        ran =words1[jb];
        n=getwords(random,arr); 
        n1=getwords(ran,ar);
         ser=arr[n];
         ser1=replace(ser);
         a1=arr[n-1];
         a2=arr[n-2];
         a3=arr[n-3];
         a4=arr[n-4];
          ran=replace(ran);
           //printf("%s",ran);
          //printf("%s",ser1); 
        ptr=strchr(random,'?'); 
        if(ptr!=NULL)
        {
          *ptr='\0';
        }
         
        printf("\nQ%i.%s?",g,random); 
        printf("\nA.%s\nB.%s\nC.%s\nD.%s\n",a1,a2,a3,a4); 
        printf("choose Your option:\n"); 
        answer=getchar() ;
         printf("Your answer is %c ",answer);
         if(answer==' '||answer=='\0'||answer=='\n')
          {
           answer=getchar();
          }
        switch(answer)
          {
            case 'a':
                  //strcat(ser1,a1);
                  //printf("%s\n",ser);
 
                        if(strcmp(ran,a1)==0)
                           {
                             count++;
                printf("Right answer! %s\nyour score is %i",a1,count); 
                          break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a1);
                            }
              break;
            case 'b':
                   //printf("%s\n",strcat(ser1,a2));
                        
                        if(strcmp(ran,a2)==0)
                           {
                             count++;
         printf("Right answer! %s\nyour score is %i",a2,count);
                            
                            }
                           else
                            {
                            printf("Worng answer! %s",a2);
                            
                            }
                 break;
            case 'c':
                // strcat(ser1,a3);
                 //ccsd printf("%s\n",ser1);
           
                        if(strcmp(ran,a3)==0)
                           {
                             count++;
                   printf("Right answer! %s\nyour score is %i\n",a3,count);
                              break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a3);
                              break;
                            }
                        
              break;
            case 'd':
                // strcat(ser1,a4);
                  // printf("c%s\n",ser);
               
                        if(strcmp(ran,a4)==0)
                           {
                             count++;
            printf("Right answer! %s\nyour score is %i",a4,count);
                           break;
                            }
                           else
                            {
                             printf("Worng answer! %s",a4);
                              break;
                            }
                        
              break;
           }
         
          g+=1;
          i++;
          wait(60);   
         }
      if(count >4)
          {
             printf("congrats you passed quiz by score %i \n",count);
          }
        else
            {
             printf("please try again you below score 10\n");
            }
   
    }




//choice 3


  

//core machine
int getwords(char *base,char tar[30][500])
 {
  int n=0,i,j=0;
   for(i=0;TRUE;i++)
        {
        if(base[i]!=' ')
          {
           tar[n][j++]=base[i];
          }
          else
           {
            tar[n][j++]='\0';
             n++;
              j=0;
           }
          if(base[i]=='\0')
           break;
        }
     return n;
}


//int compare(char *ser,char *answer,char *ser1,char *userans)
  //{
   //if()
   //return count;
 // }



