#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    int no;
    int sinif;
    char isim[20];
    char soyisim[20];
    char bolum[20];
    struct n *next;
    struct n* prev;
};
typedef struct n node;



node* createLinkedList(node* r){//LISTE OLUSTURULDU...
    r=(node*)malloc(sizeof(node));
    r->no=0;
    r->sinif=0;
    strcpy(r->isim,"Baslangic");
    strcpy(r->soyisim,"Deger");
    strcpy(r->bolum,"Yok");

    r->next=NULL;
    r->prev=NULL;
    return r;
}



//node* addNode(node* r,int x){      //SIRASIZ EKLEMEK ICIN BU FONKSIYON KULLANILABILIR.
//    while(r->next!=NULL){
//            r=r->next;
//        }
//        r->next=(node*)malloc(sizeof(node));
//        r->next->no=x;
//        r->next->next=NULL;
//}


node * addNodeInOrder(node*r, int x, int y, char is [20],char si[20], char b [20]){//BU FONKSIYON BUYUKTEN KUCUGE SIRALI EKLER.
    if(r==NULL){//liste Bos
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->prev=NULL;
        r->no=x;
        r->sinif=y;
        strcpy(r->isim,is[20]);
        strcpy(r->soyisim,si[20]);
        strcpy(r->bolum,b[20]);
        return r ;
    }
    else if(r->no> x){//ilk elemandan kucuk
        node * temp=(node*)malloc(sizeof(node));
        temp->no=x;
        temp->sinif=y;
        strcpy(temp->isim,is[20]);
        strcpy(temp->soyisim,si[20]);
        strcpy(temp->bolum,b[20]);
        temp->next=r;
        r->prev=temp;
        temp->prev=NULL;
        return temp;
    }
    else{
        node* iter=r;
        while(iter->next!=NULL&&iter->next->no < x){
            iter=iter->next;
        }
        node * temp=(node*)malloc(sizeof(node));
        temp->no=x;
        temp->sinif=y;
        strcpy(temp->isim,is);
        strcpy(temp->soyisim,si);
        strcpy(temp->bolum,b);
        temp->next=iter->next;
        temp->prev=iter;
        if(temp->next!=NULL){
            temp->next->prev=temp;
        }
        iter->next=temp;
        return r;
    }
}


void yazdir(node* r){
    int i=0;
    printf("     No  Sinif  Isim  Soyisim  Bolum\n");
        while(r!=NULL){
            printf("%d. Node: { ",i);
            printf("%d %d  %s  %s  %s",r->no,r->sinif,r->isim,r->soyisim,r->bolum);
            r=r->next;
            printf("}\n\n");
            i=i+1;
        }

}


node * deleteNode(node* r, int x){//VERILEN VERIYI LISTEDEN SILER.
    node * iter=r;
    node * temp;
    if(r->no==x){
        temp=r;
        r=r->next;
        free(temp);
        printf("%d Numarali Ogrenci Silinmistir.\n\n", x);

        return r;
    }
    else{
        while(iter->next!=NULL&&iter->next->no!=x){
            iter=iter->next;
        }
        if(iter->next==NULL){
            printf("Numara Bulunamadi...\n");
            printf("<<<<<<<Eleman Silinemedi.>>>>>>>\n\n");
            return r;
        }
        else{
            temp=iter->next;
            iter->next=temp->next;
            if(iter->next!=NULL){
                temp->next->prev=iter;
            }
            free(temp);
            printf("%d Numarali Ogrenci Silinmistir.\n\n", x);

            return r;
        }
    }
}


node * searchNode(node* r, int x){
    node * iter=r;
    node* temp;
    while(iter->next!=NULL&&iter->next->no!=x){
        iter=iter->next;
    }
    if(iter->no!=x&&iter->next==NULL){
        return iter;
    }
    if(iter->next->no==x){
        temp=iter->next;
        return temp;
    }

}


node* destroyLinkedList(node* r){
    node* iter=r;
    while(iter->next!=NULL){
        node* temp= iter;
        iter=iter->next;
        free(temp);
    }
    r=(node*)malloc(sizeof(node));
    r->no=0;
    r->sinif=0;
    strcpy(r->isim,"Baslangic");
    strcpy(r->soyisim,"Deger");
    strcpy(r->bolum,"Yok");
    r->next=NULL;
    r->prev=NULL;
    return r;


}


node* Menu(node * root){
    int a,b,f;
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>>>>>>> \n\n");
    printf("Create Linked List= 1\nDestroy Linked List= 2\nAdd Node= 3\nDelete Node= 4\nSearch Node= 5\nDisplay List= 6\n\n");
    printf("Make Your Choice:  ");
    scanf("%d",&a);
    printf("\n");
    switch(a){
    case 1: createLinkedList(root);
        printf("<<<<<<<Ilk Ogrenci 0 Olacak Sekilde Liste Olusturuldu.>>>>>>>\n\n");
        Menu(root); break;
    case 2: root=destroyLinkedList(root);
    printf("<<<<<<<Liste yok edildi.>>>>>>>\n\n");
    Menu(root);
    break;
    case 3:
        printf("Kac Ogrenci Kaydetmek Istiyorsunuz?");
        scanf("%d",&f);
        for(int i=0;i<f;i++){
        int x,y;
        char is[20];
        char si[20];
        char c[20];
        printf("%d. Ogrenci Numarasininin Son 4 Hanesini Giriniz...\n",i+1);//LISTEYE SIRAYLA YAZDIRIYOR.
        scanf("%d",&x);
        printf("%d. Ogrencinin Sinifini Giriniz...\n",i+1);
        scanf("%d",&y);
        printf("%d. Ogrencinin Adini Giriniz...\n",i+1);
        scanf(" %[^\n]s",&is);
        printf("%d. Ogrencinin Soyadini Giriniz...\n",i+1);
        scanf(" %[^\n]s",&si);
        printf("%d. Ogrencinin Bolumunu Giriniz...\n",i+1);
        scanf(" %[^\n]s",&c);
        addNodeInOrder(root,x,y,is,si,c);
        }
        printf("<<<<<<<Liste Numaralara Gore Sýrasiyla Kaydedildi.>>>>>>>\n");
        Menu(root);
    break;
    case 4:
        printf("Silmek Istediginiz Ogrencinin Numarasini Giriniz:\n");
        yazdir(root);
        scanf("%d",&b);
        root=deleteNode(root,b);
        Menu(root);
        break;
    case 5:
        printf("Bulmak Istediginiz Ogrencinin Numarasini Giriniz: \n");
        int a;
        scanf("%d",&a);
        node* found=searchNode(root,a);
        if(found->no==a){
            printf("<<<<<<<Numara Bulundu.>>>>>>>\n");
            printf("Adi: %s\nSoyadi: %s\nNumarasi: %d\nBolumu: %s \nSinifi: %d\n\n",found->isim,found->soyisim,found->no,found->bolum,found->sinif);
        }
        else if(found->no!=a){
            printf("<<<<<<<Numara Bulunamadi... -1>>>>>>>\n");
        }
        Menu(root);
        break;
    case 6:
        yazdir(root);
        printf("<<<<<<<Numaraya Gore Sirasiyla Yazdirildi.>>>>>>>\n");
        Menu(root);
        break;
    default:
        printf("Gecersiz sayi girdiniz.\n");
        Menu(root);
    }
    return root;

}

int main()
{
    node* root;
    root=createLinkedList(root);
    root=Menu(root);

    return 0;
}
