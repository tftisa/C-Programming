#include<stdio.h>
#include<string.h>

void *lsearch(void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, void *));
int intCmp(void *elem1, void *elem2);

void *lsearch(void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, void *)){
    for(int i = 0; i < n; i++){
        void *elemAddr = (char *)base + i * elemSize;
        
        if(cmpfn(key, elemAddr) == 0){
            return elemAddr;
        }
    }

    return NULL;
}

/*
int intCmp(void *elem1, void *elem2){
    return memcmp(elem1, elem2, sizeof(int));
}
*/

int intCmp(void *elem1, void *elem2){
    int *vp1 = elem1;
    int *vp2 = elem2;
    
    return *vp1 - *vp2;
}

int strCmp(void *elem1, void *elem2){
    char *vp1 = *elem1;
    char *vp2 = *(char **)elem2;

    return strcmp(vp1, vp2);
}

int main(){
    
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int key = 3;
    int *elemAddr = lsearch(&key, a, 7, sizeof(int), intCmp);

    printf("%d", *elemAddr);
    

   /*
   char *notes[] = {"Ab", "F#", "B", "Gb", "D"};
   char *foundNote = "Eb";
   char **found = lserach(&foundNote, notes, 5, sizeof(char *), strCmp);
   
   */
   return 0;
}