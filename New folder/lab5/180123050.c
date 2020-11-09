#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int lseeks = 0;


int main(int vimc, char* vimv[]){
   
    int input[3], output;
    
        input[1] = open("students03.csv", O_RDONLY);


   
        mode_t filePerms =
 S_IRUSR |

 S_IWUSR | 

 S_IRGRP |

 S_IWGRP |

 S_IROTH |

 S_IWOTH;

    char coma,null;

    for(int i=0;i<158;i++){
        char* sname = (char*)calloc(30, sizeof(char));
        char* sroll = (char*)calloc(9, sizeof(char));
         input[2] = open("grades03.csv", O_RDONLY);
         lseek(input[2],i*20,SEEK_CUR);
           lseeks= +;
         input[0] = open("courses03.csv",O_RDONLY); 
        read(input[1],sname,30);
        read(input[1],&coma,1);
        read(input[1],sroll,9);
        read(input[1],&null,1);
        char* temp[20];
	    sprintf(temp, "%s.txt", sroll);
        output = open(temp,O_WRONLY | O_CREAT | O_TRUNC  , filePerms);
        write(output,"name: ",6);
        write(output,sname,30);
        write(output,"\nRoll number: ",14);
        write(output,sroll,9);
        write(output,"\n\n",2);

        
        int previous=0,current=0;
        for(int k=0;k<63;k++){
            
            char* sem = (char*)calloc(1, sizeof(char));

             char* Course = (char*)calloc(6, sizeof(char));
              char* CourseName = (char*)calloc(48, sizeof(char));
               char* lecture = (char*)calloc(1, sizeof(char));
            	char* tutorial = (char*)calloc(1, sizeof(char));
            	 char* practical = (char*)calloc(2, sizeof(char));
                   char* credi = (char*)calloc(2, sizeof(char));
            	    char* roll = (char*)calloc(9, sizeof(char));
            	      char* coid = (char*)calloc(6, sizeof(char));
            		char* grade = (char*)calloc(2, sizeof(char));
            read(input[0],sem,1);
            read(input[0],&coma,1);
            read(input[0],Course,6);
            read(input[0],&coma,1);
            read(input[0],CourseName,48);
            read(input[0],&coma,1);
            read(input[0],lecture,1);
            read(input[0],&coma,1);
            read(input[0],tutorial,1);
            read(input[0],&coma,1);
            read(input[0],practical,2);
            read(input[0],&coma,1);
            read(input[0],credi,2);
            read(input[0],&null,1);
            current=(int)(sem[0]-'0');
            if(current!=previous){
                write(output,"\n",1);
                write(output,"Semester ",9);
                write(output,sem,1);
            
                write(output,":\n",2);
                previous=current;
            }
            
            write(output,Course,6);
            write(output," ",1);
            write(output,CourseName,48);
            write(output," ",1);
            write(output,credi,2);
            write(output," ",1);

            read(input[2],roll,9);
            read(input[2],&coma,1);
            read(input[2],coid,6);
            read(input[2],&coma,1);
            read(input[2],grade,2);
            read(input[2],&null,1);
            write(output,grade,2);
            write(output,"\n",1);
            lseek(input[2],20*157,SEEK_CUR);
            lseeks = +;

        }
    
        close(output); 
        close(input[0]);
        close(input[2]);

    }
    close(input[1]);

}
