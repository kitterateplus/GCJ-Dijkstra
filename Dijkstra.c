#include<stdio.h>

char returnvalue(int i, int j);

int signflag=0;

int main(){
    
    int m=0,n=0;
    char ch,ck,val;
    
    for( m=0;m<4;m++){
         printf("\n");
         for(n=0;n<4;n++){
                          if(m==0){
                                  ch='1';
                          }
                          if(m==1){
                                  ch='i';
                          }
                          if(m==2){
                                  ch='j';
                          }
                          if(m==3){
                                 ch='k';
                          }
                          if(n==0){
                                  ck='1';
                          }
                          if(n==1){
                                  ck='i';
                          }
                          if(n==2){
                                  ck='j';
                          }
                          if(n==3){
                                 ck='k';
                          }
                          
                          val=returnvalue(ch,ck);
                          if(signflag == 1){
                          printf("\t-%c",val);
                          }
                          printf("\t%c",val);
         }
         }
    getch();
    return 0;
}

    
char returnvalue(int i, int j){
     
     signflag=0;
     
     if( (i=='1' && j=='1') ){

         return '1';
     }
     
     if( (i=='1' && j=='i') || (i=='i' && j=='1') || (i=='j' && j=='k') ){
         
         return 'i';
     }
     
     if( (i=='1' && j=='j') || (i=='j' && j=='1') || (i=='k' && j=='i') ){
         
         return 'j';
     }
     
     if( (i=='1' && j=='k') || (i=='i' && j=='j') || (i=='k' && j=='1') ){
         
         return 'k';
     }
     
     if( (i=='i' && j=='i') || (i=='j' && j=='j') || (i=='k' && j=='k') ){
         
         signflag = 1;
         return '1';
     }
     
     if( (i=='k' && j=='j') ){
         
         signflag = 1;
         return 'i';
     }
     
     if( (i=='i' && j=='k') ){
         
         signflag = 1;
         return 'j';
     }
     
     if( (i=='j' && j=='i') ){
         
         signflag = 1;
         return 'k';
     }
     
}
