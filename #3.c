#include<stdio.h>
#include<stdlib.h>

struct matrix{
    int n;
    int m;
    int** data;
};
void print_mat(struct matrix* mat){
    int r = mat -> n;
    int c = mat -> m;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            printf("%d ",mat -> data[i][j]);
        }
        printf("\n");
    }
    printf("\n \n");
    return;
}

void add(struct matrix* a,struct matrix*b){
    
    if(((a -> n) == (b -> n))&&((a -> m) == (b -> m))){
        int r = a -> n;
        int c = b -> m;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                 printf("%d ",((a -> data[i][j])+(b -> data[i][j])));
            }
            printf("\n");
        }
        printf("\n \n");
    }
    else{
        printf("Not possible to add");
    }
}

void subtract(struct matrix* a,struct matrix*b){
    
    if(((a -> n) == (b -> n))&&((a -> m) == (b -> m))){
        int r = a -> n;
        int c = b -> m;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                 printf("%d ",((a -> data[i][j])-(b -> data[i][j])));
            }
            printf("\n");
        }
        printf("\n \n");
    }
    else{
        printf("Not possible to subtract");
    }
}

void multiply(struct matrix* a,struct matrix*b){
    if((a -> m) == (b -> n)){
       int r = a -> n;
       int c = b -> m;
       for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            int sum = 0;
            for(int k = 0;k < (a -> m);k++){
                sum += (a -> data[i][k])*(b -> data[k][j]);
            }
            printf("%d ",sum); 
        }
        printf("\n");
       }

       printf("\n \n");
    }
    else{
        printf("Not possible to multiply");
    }
}
int main(){

    int n;scanf("%d",&n);
    struct matrix** mat_arr = (struct matrix**)malloc(n*sizeof(struct matrix*));
    for(int i = 0;i < n;i++){
        int r,c;scanf("%d %d",&r,&c);
        mat_arr[i] = (struct matrix*)malloc(sizeof(struct matrix));
        mat_arr[i] -> n = r;
        mat_arr[i] -> m = c;
        mat_arr[i] -> data = (int**)malloc(r*sizeof(int*));
        for(int j = 0;j < r;j++){
            mat_arr[i] -> data[j] = (int*)malloc(c*sizeof(int));
        }

        for(int j = 0;j < r;j++){

            for(int k = 0;k < c;k++){
                int num;scanf("%d",&num);
                mat_arr[i] -> data[j][k] = num;        
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        print_mat(mat_arr[i]);
    }

    int q;scanf("%d",&q);
    for(int i = 0;i < q;i++){
        int op;scanf("%d",&op);
        if(op == 0){
           int m1,m2;scanf("%d %d",&m1,&m2);
           add(mat_arr[m1-1],mat_arr[m2-1]);
        }
        else if(op == 1){
           int m1,m2;scanf("%d %d",&m1,&m2);
           subtract(mat_arr[m1-1],mat_arr[m2-1]);
        }
        else if(op == 2){
           int m1,m2;scanf("%d %d",&m1,&m2);
           multiply(mat_arr[m1-1],mat_arr[m2-1]);
        }
    }
    return 0;
}