#include<stdio.h>

#define inputFile "input.in"
#define outputFile "outfile.out"

void readtestcase();
char returnachar(char a, char b);

//global File pointer for inputFile and outputFile
FILE *fi,*fo;

//Global declartion of variables :
int L=0,X=0,signflag=0,sfos=0;
char ch[100000];

int main(){
    
    int notc=0,tcc=0;
    
    //open inputFile in read mode
    fi=fopen(inputFile,"r");
    
    //read the number of test case from the input file
    fscanf(fi,"%d",&notc);
    //print("%d",notc);
    while(tcc < notc){
               
               tcc++;
               //function to read L X and ijk string from file
               readtestcase();
               returnachar('i','j');
    } 
    
    //close input file
    fclose(fi);                     
    getch();
    return 0;
}


void readtestcase(){
     fscanf(fi,"%d %d", &L, &X);
     //printf("\n%d %d",L,X);
     fscanf(fi,"%s", ch);
     //printf("\n%s",ch);
}

char returnachar(char a, char b){
     signflag = 0;
     
     if( (a=='1') && (b=='1') ){
         return '1';
     }
     
     if( ( (a=='1') && (b=='i') ) || ( (a=='i') && (b=='1') ) || ( (a=='j') && (b=='k') ) ){
         return 'i';
     }
     
     if( ( (a=='1') && (b=='j') ) || ( (a=='j') && (b=='1') ) || ( (a=='k') && (b=='i') ) ){
         return 'j';
     }
     
     if( ( (a=='1') && (b=='k') ) || ( (a=='k') && (b=='1') ) || ( (a=='i') && (b=='j') ) ){
         return 'k';
     }
     
     if( ( (a=='i') && (b=='i') ) || ( (a=='j') && (b=='j') ) || ( (a='k') && (b=='k') ) ){
         signflag = 1;
         return '1';
     }
     
     if( (a=='k') && (b=='j') ){
         signflag = 1;
         return 'i';
     }
     
     if( (a=='i') && (b=='k') ){
         signflag = 1;
         return 'j';
     }
     
     if( (a=='j') && (b=='i') ){
         signflag = 1;
         return 'k';
     }
}









