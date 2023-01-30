#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define statement

typedef struct node{
    char *data;
    struct node * next;
}stack1;

void bastir(stack1 * root){//Düz giren elemanlar struct'a aktariliyor. istenirse struct bastýrýlabilir.
    stack1*iter=root;
    while(iter!=NULL){
        printf("%c",iter->data);
        iter=iter->next;
    }
}
bool iscouple(char character1, stack1* root){
    stack1* iter=root;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    if (character1 == ']' && iter->data == '['){
        printf("%c %c",iter->data,character1);
        pop(root);
        return 1;
    }
    else if (character1 == '}' && iter->data == '{'){
        printf("%c %c",iter->data,character1);
        pop(root);
        return 1;
    }
    else{
        printf("%c %c",iter->data,character1);
        return 0;
    }
}
void pop(stack1* root){
    int sayac=0;
    if(root==NULL){
        printf("stack bos.");
    }
    if(root->next==NULL){
        int tempvl=root->data;
        free(root);
        printf("\n<<<<<<Balanced>>>>>>>\n");
        printf("Son Eleman da Eslesti.\n");
        printf("Dizi Dengeli Bir Dizidir");
        exit(1);
    }
    stack1* iter;
    iter=root;
    while(iter->next->next!=NULL){
        iter=iter->next;
    }
    stack1* temp=iter->next;
    int tempv=temp->data;
    free(temp);
    iter->next=NULL;

}
stack1 * push(stack1 *root,int a){
    if(root==NULL){
        root=(stack1*)malloc(sizeof(stack1));
        root->data=a;
        root->next=NULL;
        return root;
    }
    stack1* iter=root;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(stack1*)malloc(sizeof(stack1));
    iter->next->data=a;
    iter->next->next=NULL;
    return root;

}
stack1 * balanced(char a[], stack1* root,int boyut){
    stack1 * iter=root;
    for(int i=0;i<boyut+1;i++){
        if(a[i]=='{'||a[i]=='['){
            root=push(root,a[i]);
        }
        else if(a[i]=='}'||a[i]==']'){
            if(root==NULL){
                printf("\n<<<<<<Unbalanced>>>>>>>\n");
                printf("%c Elemani Ters",a[i]);
                exit(0);
            }
            else if(iscouple(a[i],root)){
                printf("\n<<<<<<Balanced>>>>>>>\n");
            }
            else{
                printf("Eleman Eslesmedi...");
                printf("\n<<<<<<Dizi Unbalanced>>>>>>>\n");
                exit(0);
            }
        }
        else{
            if(root!=NULL){
                printf("Acikta bu eleman kaldi=   %c\n",root->data);
                printf("<<<<<<Dizi Unbalanced>>>>>>>\n");
                exit(0);
            }
            else{
                printf("Tüm elemanlar eslesti.\n");
                printf("<<<<<<Dizi Balanced>>>>>>>\n");
                exit(1);
            }
        }
    }
}

int main()
{
    stack1 * s=NULL;
    char dizi[7]={'{','[',']','[',']','}','\0'};
    char dizi2[9]={'{','[',']','[',']','{','}','}','\0'};
    char dizi3[7]={'{','[',']',']','}','{','\0'};
    char dizi4[7]={']','[',']',']','}','{','\0'};
    char dizi5[6]={'{','[',']','{','}','\0'};
    printf("Dizi1:  %s\n",dizi);
    printf("Dizi2:  %s\n",dizi2);
    printf("Dizi3:  %s\n",dizi3);
    printf("Dizi4:  %s\n",dizi4);
    printf("Dizi5:  %s\n",dizi5);
    int secim;
    printf("Hangi Diziyi Denemek Istiyorsunuz?   1,2,3,4,5 ?\n");
    scanf("%d",&secim);
    switch(secim){
    case 1:
        printf("Dizi1:  %s\n",dizi);
        s=balanced(dizi,s,strlen(dizi));
        break;
    case 2:
        printf("Dizi2:  %s\n",dizi2);
        s=balanced(dizi2,s,strlen(dizi2));
        break;
    case 3:
        printf("Dizi3:  %s\n",dizi3);
        s=balanced(dizi3,s,strlen(dizi3));
        break;
    case 4:
        printf("Dizi4:  %s\n",dizi4);
        s=balanced(dizi4,s,strlen(dizi4));
    case 5:
        printf("Dizi5:  %s\n",dizi5);
        s=balanced(dizi5,s,strlen(dizi5));
        break;
    }
    return 0;
    }


