#include <stdio.h>
#include <stdlib.h>
int main() {
    
    struct stacknode{
        char value;
        struct stacknode *next;
    };
    
    struct stacknode *topstack=NULL;
    
    void push(char element){
        struct stacknode *newstack;
        newstack=(struct stacknode *)malloc(sizeof(struct stacknode));
        newstack->value=element;
        newstack->next=topstack;
        topstack=newstack;
        
    }
    
    void pop(){
        
        struct stacknode *tempstack;
        tempstack=topstack;
        topstack=topstack->next;    
        free(tempstack);
        
        
    }
    
    void display(){
        
        struct stacknode *newtop;
        newtop=topstack;
        
        while(newtop!=NULL){
            printf("%c ",newtop->value);
            newtop=newtop->next;
        }
        
    }
    
    
    char expression[11]={'(','a','+','b',')','*','(','c','+','d',')'};
    char reverseexpression[11];
    
    int z=0;
    for(int i=10;i>=0;i--){
        reverseexpression[z]=expression[i];
        z++;
    }
    
    char prefix[11];int t=0;
    
    for(int i=0;i<11;i++){
        
        if(reverseexpression[i]>='a' && reverseexpression[i]<='z'){
            prefix[t]=reverseexpression[i];
            t++;
        }
        else{
            
            if(reverseexpression[i]=='(' || reverseexpression[i]==')'){
                
                if(reverseexpression[i]==')'){
                  
                    push(reverseexpression[i]);
                }
                
                else if(reverseexpression[i]=='('){
                   
                   
                    if(topstack!=NULL){
                      
                       while(topstack->value!=')' && topstack!=NULL){
                           prefix[t]=topstack->value;
                           t++;
                           pop();
                       }
                       
                       
                      pop();
                     
                        
                    }
                    else{
                        //Do Nothing;
                    }
                }
                
            }
            
            
            
            else if(reverseexpression[i]=='^'){
                if(topstack!=NULL){
                     if(topstack->value==')'){
                        push(reverseexpression[i]);
                    }   
                    else if(topstack->value=='^'){
                            prefix[t]=topstack->value;
                            t++;
                            pop(); 
                    }
                    else{
                        push(reverseexpression[i]);
                    }
                }
                
                
            }
            
            
            else if(reverseexpression[i]=='*' || reverseexpression[i]=='/'){
                
                if(topstack!=NULL){
                    if(topstack->value=='('){
                     
                     push(reverseexpression[i]);
                  }
                    else if(topstack->value=='^'){
                    
                   
                    while(topstack->value=='^' && topstack!=NULL){
                        
                        if(topstack->next==NULL){
                            prefix[t]=topstack->value;
                            t++;
                            topstack=NULL;
                            push(reverseexpression[i]);
                            
                            break;
                        }
                        else{
                            prefix[t]=topstack->value;
                            t++;
                            pop();     
                        }
                       
                        
                    }
                    
                    
        
                }
                else{
                    push(reverseexpression[i]);
                }
                
                }
                else{
                    
                    push(reverseexpression[i]);
                }
                
            }
            
           else if(reverseexpression[i]=='+' || reverseexpression[i]=='-'){
                
                if(topstack!=NULL){
                    if(topstack->value=='('){
                     push(reverseexpression[i]);
                    }
                    else if(topstack->value=='^' || topstack->value=='*' || topstack->value=='/'){
                    
                   
                    while((topstack->value=='^' || topstack->value=='*' || topstack->value=='/') && topstack!=NULL){
                        
                        if(topstack->next==NULL){
                            prefix[t]=topstack->value;
                            t++;
                            topstack=NULL;
                            push(reverseexpression[i]);
                            break;
                        }
                        else{
                            prefix[t]=topstack->value;
                            t++;
                            pop();     
                        }
                    }
    
                }
                else{
                    push(reverseexpression[i]);
                }
                
                }
                else{
                    push(reverseexpression[i]);
                }
                
            }
            
            
        }
        
    }
    
    
    
    while(topstack!=NULL){
        prefix[t]=topstack->value;
        t++;
        topstack=topstack->next;
    }
    
    
    for(int i=t-1;i>=0;i--){
       printf("%c",prefix[i]);
    }
    
}
