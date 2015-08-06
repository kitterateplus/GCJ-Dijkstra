#include<stdio.h>

char returnvalue(char i, char j);

void printcase(char c,int count);

char result(char c[], int L);

void setsignflag();

char findsubstringijk(char cgh[], int L1, int X);

FILE *f1;

int signflag=0,X=0,L=0;

int main(){
    
    FILE *f;
    int num_test_case=0,count=0;
    char ch[100000],ree,reee;
    
     
   f1=fopen("input.txt","a");
    
    f = fopen("inputs.in","r");
    
    fscanf(f,"%d",&num_test_case);
    
    //printf("%d",num_test_case);
    
    
    while(count<num_test_case){
                               
                     count++;
                     //printf("\n");
                     
                     fscanf(f,"%d %d", &X, &L);
                    //printf("%d %d",X,L);
                     //printf("\n");
                     fscanf(f,"%s", ch);
                   // printf("%s\n",ch);
                     if( (X*L) < 3){
                         printcase('N',count);
                     }
                     else{
                          signflag=0;
                          ree=result(ch,L);
                          
                          
                          if(ree == 'Y'){
                                 //printf("\n -1 condition met Entering Y loop");
                                 signflag=0;
                                 reee=findsubstringijk(ch,L,X);
                                 printcase(reee,count);
                          }
                          else{
                              //printf(" -1 condition not met Entering Y loop");
                               printcase(ree,count);
                          }
                     }
    }
    fclose(f);
    fclose(f1);
    getch();
    return 0;
}

char result(char c[], int L){
     
     int i=0;
     char re=c[0];
     
     for(i=1;c[i]!='\0';i++){
                             
             re=returnvalue(re,c[i]);
     }             
     //printf("\n%c %d",re,signflag);
     if( re == '1' && signflag==0){
         return 'N';
     }
     if( re == '1' && signflag==1){
         if( (L%2) !=0){
             return 'Y';
         }
         else{
              return 'N';
         }
     }
     
     if( re=='i' || re =='j' || re=='k' ){
         
         if( L%2 == 0){
             if( ((L/2) % 2) !=0){
                 return 'Y';
             }
             else{
                  return 'N';
             }
         }
         else{
              return 'N';
         }
     }
}


char findsubstringijk(char c[], int L, int X){
     
     int i=0,j=0,count=0,flagi=0,openj=0;
     char re=c[0];
     j=1;
     openj=0;
     //printf("\n entering while Loop");
     while( count < L){
            //printf("\n entered while Loop");
            for(i=j;c[i]!='\0';i++){
                                   // printf("\n Inside substring ");
                        if(re=='i' && signflag==0 && flagi==0){
                                  // printf("\n met the i condition");
                                   flagi=1;
                                   openj=1;
                        }
                        else{
                             //printf("\n does not met the i condition");
                             re=returnvalue(re,c[i]);
                        }
                        
                        if(flagi==1 && openj==1){
                                     //printf("\n met the i condition looking for J");
                                     if(c[i] == 'j'){
                                           // printf("\n met the j condition");
                                            if(i<(X-1)){
                                                       return 'Y';
                                             }
                                             else{
                                                  return 'N';
                                             }
                                     }
                                     else{
                                          //printf("\n does not met the j condition");
                                         re=returnvalue(re,c[i]);
                                     }
                        }
             
             }
            //printf("\n Going for another round");
            count++;
            j=0;
     }
     //printf("\n i j could not be found");
     return 'N'; 
  
}     
    
char returnvalue(char i, char j){
     
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
         setsignflag();
         return '1';
     }
     
     if( (i=='k' && j=='j') ){
         setsignflag();
         return 'i';
     }
     
     if( (i=='i' && j=='k') ){
         setsignflag();
         return 'j';
     }
     
     if( (i=='j' && j=='i') ){
         setsignflag();
         return 'k';
     }
        
}

void setsignflag(){
     
     signflag += 1;
     if( signflag == 0){
         signflag=0;
     }
     else{
          if( (signflag % 2) == 0){
              signflag = 0;
          }
          else{
               signflag = 1;
          }
     } 
}

void printcase(char c,int count){
     
     if(c=='Y'){
                
                fprintf(f1,"Case #%d: YES\n",count);
                //printf("\nCase #%d: YES\n",count);
     }
     if(c=='N'){
                fprintf(f1,"Case #%d: NO\n",count);
                //printf("\nCase #%d: NO\n",count);
     }
}
