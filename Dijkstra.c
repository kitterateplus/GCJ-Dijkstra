#include<stdio.h>

char returnvalue(char i, char j);

void printcase(char c,int count);

char result(char c[],int L);

int signflag=0,X=0,L=0;

int main(){
    
    FILE *f;
    int num_test_case=0,count=0;
    char ch[100],ree;
    
    f = fopen("input.txt","r");
    
    fscanf(f,"%d",&num_test_case);
    
    //printf("%d",num_test_case);
    
    
    while(count<num_test_case){
                               
                     count++;
                     signflag=0;
                     //printf("\n");
                     
                     fscanf(f,"%d %d", &X, &L);
                     //printf("%d %d",X,L);
                     //printf("\n");
                     fscanf(f,"%s", ch);
                     //printf("%s",ch);
                     if( (X*L) < 3){
                         printcase('N',count);
                     }
                     else{
                          ree=result(ch,L);
                          printcase(ree,count);
                     }
    }
    
    getch();
    return 0;
}

char result(char c[],int L){
     
     int i=0;
     char re=c[0];
     
     for(i=1;c[i]!='\0';i++){
                             
                             re=returnvalue(re,c[i]);
     }
     
     if( signflag == 0){
         if( re=='i' || re=='j' || re=='k'){
             if(L%2==0){
                        return
         }
         else{
              return 'N';
         }
     }
}
    
char returnvalue(char i, char j){
     
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
         
         signflag += 1;
         return '1';
     }
     
     if( (i=='k' && j=='j') ){
         
         signflag += 1;
         return 'i';
     }
     
     if( (i=='i' && j=='k') ){
         
         signflag += 1;
         return 'j';
     }
     
     if( (i=='j' && j=='i') ){
         
         signflag += 1;
         return 'k';
     }
     
}

void printcase(char c,int count){
     
     if(c=='Y'){
                
                printf("\nTestCase #%d: YES",count);
     }
     if(c=='N'){
                printf("\nTestCase #%d: NO",count);
     }
}
