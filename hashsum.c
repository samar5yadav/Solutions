#include<stdio.h>
typedef struct hash_map{
    int data;
    struct hash_map *next;
};

int hash_func(int value, int n){
    return value%(2*n);
}


void hashing(struct hash_map hash_arr[], int arr[], int n){
    int i;
    int index;
    for(i=0;i<n;i++){
        index=hash_func(arr[i],n);
        //printf("im here\n");
        //printf("%d\n%d",hash_arr[index].data,hash_arr[index].next);
        if(hash_arr[index].next== NULL){
            hash_arr[index].data=arr[i];
            //printf("im here1\n");
            hash_arr[index].next= (struct hash_map *) malloc(sizeof(struct hash_map));
            hash_arr[index].next->data=-1;
            hash_arr[index].next->next=NULL;

        }
        else{
            //printf("im here2\n");
            struct hash_map *temp;
            temp=hash_arr[index].next;
            //printf("im here3\n");
            while(temp->next!=NULL){
                temp=temp->next;
                //printf("im here hu\n");
            }
            //printf("im here too\n");
            temp->data=arr[i];
            temp->next=(struct hash_map *) malloc(sizeof(struct hash_map));
            temp->next->data=-1;
            temp->next->next=NULL;
            //printf("im here4\n");
        }

    }
}

int hash_search(int search_element, struct hash_map hash_arr[], int n){
    if (search_element<0)
        return 0;

    int index=search_element%(2*n);
    if(hash_arr[index].data==search_element)
        return 1;
    else if(hash_arr[index].next->next!=NULL){
        struct hash_map *temp;
            temp=hash_arr[index].next;
            while(temp->next!=NULL ){
                if(temp->data==search_element){
                    return 1;
                }
                temp=temp->next;

            }
    }
    else
        return 0;

}
int main(){
    printf("enter the no of elements\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    struct hash_map hash_arr[2*n];
    printf("enter the values\n");
    int i=0;
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<2*n;i++){
        hash_arr[i].data=-1;
        hash_arr[i].next=NULL;
    }

    hashing(hash_arr, arr, n);

    printf("enter the element to search in hash_map");
    int search_element;
    scanf("%d",&search_element);
    int found=0;
    found=hash_search(search_element, hash_arr, n);
    if(found==1)
        printf("Search element has been found!\n");
    else
        printf("search element is not present!\n");


    return 0;
}
