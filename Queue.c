#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    char *data;
    int idata;
    struct n* next;
    struct n* prev;
}node;
int sayac=0;
node* Enqueue(node *r, int a){
     if(r==NULL){//liste Bos
        r=(node*)malloc(sizeof(node));
        if(a=='*'||a=='+'||a=='-'){
            r->data=a;
            r->idata=NULL;
        }
        else{
            r->idata=a;
            r->data=NULL;
        }
        r->next=NULL;
        r->prev=NULL;
        sayac++;
        return r;
     }

    node* iter=r;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    if(a=='*'||a=='+'||a=='-'){
        iter->next->data=a;
        iter->next->idata=NULL;
        }
    else{
        iter->next->idata=a;
        iter->next->data=NULL;
    }
    sayac++;
    iter->next->next=NULL;
    iter->next->prev=iter;
    return r;
}

node* check(node*r){
    node*iter=r;
    while(iter->next!=NULL){

        if((iter->data!=NULL) && (iter->next->idata!=NULL) && (iter->next->next->idata!=NULL)){
            node* temp=(node*)malloc(sizeof(node*));
            char temp2=iter->data;
            int value;
            switch(temp2){
            case '*' :
                value = (iter->next->idata)*(iter->next->next->idata);
                printf("%d %c %d = %d\n",iter->next->idata,iter->data,iter->next->next->idata,value);
                iter->idata=value;
                iter->data=NULL;
                node* temp7=(node*)malloc(sizeof(node*));
                node* temp8=(node*)malloc(sizeof(node*));
                temp7=iter->next;
                temp8=iter->next->next;
                iter->next=iter->next->next->next;
                free(temp7);
                free(temp8);
                break;
            case '+' :
                value = (iter->next->idata)+(iter->next->next->idata);
                printf("%d %c %d = %d\n",iter->next->idata,iter->data,iter->next->next->idata,value);
                iter->idata=value;
                node* temp5=(node*)malloc(sizeof(node*));
                node* temp6=(node*)malloc(sizeof(node*));
                temp5=iter->next;
                temp6=iter->next->next;
                iter->data=NULL;
                iter->next=iter->next->next->next;

                free(temp5);
                free(temp6);
                break;
            case '-' :
                value = (iter->next->idata)-(iter->next->next->idata);
                printf("%d %c %d = %d\n",iter->next->idata,iter->data,iter->next->next->idata,value);
                iter->idata=value;
                iter->data=NULL;
                if(iter->next->next->next==NULL){
                        printf("sonuc=%d",value);
                    exit(0);
                }
                iter->next=iter->next->next->next;
                free(iter->next);
                free(iter->next->next);
                break;
            default:
                printf("\n");
            }
        }
        iter=iter->next;
    }
    return r;

}
void bastir(node * root){
    node*iter=root;
    printf("Dizi= ");
    while(iter!=NULL){
        if((iter->data=='*')||(iter->data=='+')||(iter->data=='-'))
            printf("%c ",iter->data);
        else
            printf("%d ",iter->idata);
        iter=iter->next;
    }
    printf("\n");
}
int main()
{
    char prex[13] = {'-', '+', '*', '9', '+', '2', '8', '*', '+' ,'4', '8', '6', '3'};
    node* root;
    root=NULL;
    for(int i=0; i<13;i++){
        char temp=prex[i];
        if(temp=='*'||temp=='+'||temp=='-'){
            root=Enqueue(root,temp);
        }
        else{
            char a = prex[i];
            int val = a - '0';
            root=Enqueue(root,val);
        }
    }
    bastir(root);
    root=check(root);
    bastir(root);
    root=check(root);
    bastir(root);
    root=check(root);
    bastir(root);
    root=check(root);
    bastir(root);
    return 0;
}
