
#include <iostream>
using namespace std;

typedef struct HTNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode, *HuffmanTree;

typedef char** HuffmanCode;
 
void Select(HuffmanTree HT, int num, int &child1, int &child2);
 
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
    
    int m,i;
    int child1,child2;
    if (n <= 1) {
        return;
    }
    m = n*2-1;
    HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
    for (i = 1; i <= n; i++,w++) {
        HT[i] = {*w, 0, 0, 0};
    }
    for (; i <= m; i++) {
        HT[i] = {0, 0, 0, 0};
    }
    for (i = n+1; i <= m; i++) {
        Select(HT,i-1,child1,child2);
        HT[child1].parent = i;
        HT[child2].parent = i;
        HT[i].lchild = child1;
        HT[i].rchild = child2;
        HT[i].weight = HT[child1].weight + HT[child2].weight;
        printf("%d==%d\n",child1,child2);
    }
     
    HC = (char**)malloc((n+1)*sizeof(char *));
     
    char *cd = (char*)malloc(n*sizeof(char));
    //memset(cd, '\0', n*sizeof(char));
    int c = 0;
     
    int tempParent,count;
    for (i = 1; i <= n; i++) {
        count = 0;
        for (c = i,tempParent = HT[i].parent; tempParent != 0;c=tempParent, tempParent = HT[tempParent].parent) {
            if (HT[tempParent].lchild == c) {
                cd[count++] = '0';
            }else{
                cd[count++] = '1';
            }
        }
        cd[count]='\0';
        printf("%s~%d\n",cd,i);
        HC[i] = (char *)malloc((count)*sizeof(char));
         
        strcpy(HC[i], cd);
        //memset(cd,'\0', n*sizeof(char));//error
    }
}
 
void Select(HuffmanTree HT, int num, int &child1, int &child2){
    child1 = 0;
    child2 = 0;
    int w1 = 0;
    int w2 = 0;
    for (int i = 1; i <= num; i++) {
        if (HT[i].parent == 0) {
            if (child1 == 0) {
                child1 = i;
                w1 = HT[i].weight;
                continue;
            }
            if (child2 == 0) {
                child2 = i;
                w2 = HT[i].weight;
                continue;
            }
            if (w1 > w2 && w1 > HT[i].weight) {
                w1 = HT[i].weight;
                child1 = i;
                continue;
            }
            if (w2 > w1 && w2 > HT[i].weight) {
                w2 = HT[i].weight;
                child2 = i;
                continue;
            }
        }
    }
}
 
 
 
 
 
 
int main(int argc, const char * argv[]) {
    char a[] = "abcaab";
    int i = (int)strlen(a);
    printf("%d\n",i);
     
    int b[]={1,2,3,4};
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT, HC, b, 4);
    for (i = 1; i <= 7; i++) {
        printf("%d-%d\n",HT[i].weight,HT[i].parent);
    }
    for (i = 1; i <=4; i++) {
        printf("%s\n",HC[i]);
    }
    return 0;
}
</iostream>

