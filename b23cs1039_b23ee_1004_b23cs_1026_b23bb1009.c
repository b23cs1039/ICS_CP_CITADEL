#include <stdio.h>

int determinant(int o,int only[o][o]){
    if(o==1) { return only[0][0]; }
    else if(o==2) { return (only[0][0]*only[1][1])-(only[0][1]*only[1][0]); }
    else{
        int mod=0;

        for(int u=0;u<o;u++){
            int sub[o-1][o-1];
            for(int p=1;p<o;p++){
                for(int q=0,r=0;q<o;++q){
                    if(q!=u){
                        sub[p-1][r++] = only[p][q];
                    }
                }
            }
            if(u%2==0){
                mod += only[0][u]*determinant(o-1,sub);
            }
            else if(u%2!=0){
                mod -= only[0][u]*determinant(o-1,sub);
            }
        }
        return mod;
    }
}

void add(){
    int o,p,u,v;
    printf("Enter the number of rows and columns of the matrices you want to add, separated by spaces: ");
    scanf("%d%d",&o,&p);

    int first[o][p];
    printf("Enter the elements of the first matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(first + u) + v));
        }
    }

    int second[o][p];
    printf("Enter the elements of the second matrix such that each element in a row is separated by spaces and each row is in separate line.\n");
    
    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(second + u) + v));
        }
    }

    int sum[o][p];

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            *(*(sum + u) + v) = *(*(first + u) + v) + *(*(second + u) + v);
        }
    }
    
    printf("The resultant addition matrix is\n");
    for(u=0;u<o;u++){
         for(v=0;v<p;v++){
            printf("%d ",*(*(sum + u) + v));
         }
         printf("\n");
    }
}

void subtract(){
    int o,p,u,v;
    printf("Enter the number of rows and columns of the matrices you want to subtract, separated by spaces: ");
    scanf("%d%d",&o,&p);

    int first[o][p];
    printf("Enter the elements of the first matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(first + u) + v));
        }
    }

    int second[o][p];
    printf("Enter the elements of the second matrix such that each element in a row is separated by spaces and each row is in separate line.\n");
    
    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(second + u) + v));
        }
    }

    int diff[o][p];

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            *(*(diff + u) + v) = *(*(first + u) + v) - *(*(second + u) + v);
        }
    }
    
    printf("The resultant subtraction matrix is\n");
    for(u=0;u<o;u++){
         for(v=0;v<p;v++){
            printf("%d ",*(*(diff + u) + v));
         }
         printf("\n");
    }
}

void multiply(){
    int o,p,q,r,u,v;
    printf("NOTE: If you want to multiply two matrices then, the number of columns of the first matrix should be equal to the number of rows of the second matrix.\n");

    printf("Enter the number of rows and columns of the first matrix, separated by spaces: ");
    scanf("%d%d",&o,&p);

    int first[o][p];
    printf("Enter the elements of the first matrix such that each element in a row is separated by spaces and each row is in separate line.\n");
    
    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(first + u) + v));
        }
    }
    
    printf("Enter the number of rows and columns of the second matrix, separated by spaces: ");
    scanf("%d%d",&q,&r);
    int second[q][r];

    printf("Enter the elements of the second matrix such that each element in a row is separated by spaces and each row is in separate line.\n");
    
    for(u=0;u<p;u++){
        for(v=0;v<q;v++){
            scanf("%d",(*(second + u) + v));
        }
    }
    
    if(p==q){
        int prod[o][r];
    
        for(u=0;u<o;u++){
            for(v=0;v<r;v++){
            
                int sum=0,pdt=1;
                for(int k=0;k<p;k++){
                    pdt= *(*(first + u) + k) * *(*(second + k) + v);
                    sum += pdt;
                }
            
                *(*(prod + u) + v) = sum;
            }
        }
    
        printf("The product matrix is\n");
        for(u=0;u<o;u++){
            for(v=0;v<r;v++){
                printf("%d ",prod[u][v]);
            }
            printf("\n");
        }
    }
    else if(p!=q){
        printf("Can't perform the multiplication of these matrices!\n");
        printf("Check the number of rows and columns of the matrices, they should satisfy the condition given in NOTE and try again.\n");
        multiply();
    }
}

void trace(){
    int o,u,v;
    printf("Enter the order of the square matrix of which you want to find trace: ");
    scanf("%d",&o);

    int only[o][o];
    
    printf("Enter the elements of the square matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            scanf("%d", *(only + u) + v);
        }
    }

    int sum=0;
    for(u=0;u<o;u++){
        sum += *(*(only + u) +u) ;
    }

    printf("The trace of the matrix is %d.\n",sum);
}

void transpose(){
    int o,p,u,v;
    printf("Enter the number of rows and columns of the matrix of which you want to find the transpose matrix: ");
    scanf("%d",&o);
    
    int only[o][p];
    
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d", *(only + u) + v);
        }
    }
    
    int trans[p][o];
    for(u=0;u<p;u++){
        for(v=0;v<o;v++){
            trans[u][v] = only[v][u];
        }
    }

    printf("The transpose matrix of the matrix is\n");
    for(u=0;u<p;u++){
        for(v=0;v<o;v++){
            printf("%d ",trans[u][v]);
        }
        printf("\n");
    }
}

void det(){
    int o,u,v;
    printf("Enter the order of the square matrix of which you want to find determinant: ");
    scanf("%d",&o);

    int only[o][o];
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            scanf("%d",*(only + u) + v);
        }
    }

    printf("The determinant for the matrix is %d.\n",determinant(o,only));
}

int subcofact(int o,int only[o][o],int u,int v){
    int sub[o-1][o-1];
    
    for(int i=0,p=0;i<o && p<o-1;i++){
        if(i!=u){
            for(int j=0,q=0;j<o && p<o-1;j++){
                if(j!=v){
                    sub[p][q++]=only[i][j];
                }
            } 
            p++;   
        }
    }
    
    int x=u+v;
    if(x%2==0){
        return determinant(o-1,sub);
    }
    else{
        return -determinant(o-1,sub);
    }
}

void cofactor(){
    int o,u,v;
    printf("Enter the order of the square matrix of which you want to find cofactor: ");
    scanf("%d",&o);

    int only[o][o];
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            scanf("%d",*(only + u) + v);
        }
    }
    
    int cofact[o][o];
    if(o==1) { cofact[0][0]=only[0][0]; }
    else if(o==2) {
         cofact[0][0]=  only[1][1];
         cofact[0][1]= -only[1][0];
         cofact[1][0]= -only[0][1];
         cofact[1][1]=  only[0][0];
    }
    else if(o>2){
        for(u=0;u<o;u++){
            for(v=0;v<o;v++){
                cofact[u][v] = subcofact(o,only,u,v);
            }
        }
    }
    
    printf("The cofactor matrix of the matrix is\n");
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            printf("%d ",cofact[u][v]);
        }
        printf("\n");
    }
}

void adjoint(){
    int o,u,v;
    printf("Enter the order of the square matrix of which you want to find adjoint: ");
    scanf("%d",&o);

    int only[o][o];
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            scanf("%d",*(only + u) + v);
        }
    }
    
    int cofact[o][o];
    if(o==1) { cofact[0][0]=only[0][0]; }
    else if(o==2) {
         cofact[0][0]=  only[1][1];
         cofact[0][1]= -only[1][0];
         cofact[1][0]= -only[0][1];
         cofact[1][1]=  only[0][0];
    }
    else if(o>2){
        for(u=0;u<o;u++){
            for(v=0;v<o;v++){
                cofact[u][v] = subcofact(o,only,u,v);
            }
        }
    }
    int adj[o][o];
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            adj[u][v] = cofact[v][u];
        }
    }

    printf("The adjoint matrix of the matrix is\n");
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            printf("%d ",adj[u][v]);
        }
        printf("\n");
    }
}

void inv(){
    int o,u,v;
    printf("Enter the order of the square matrix of which you want to find inverse: ");
    scanf("%d",&o);

    int only[o][o];
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            scanf("%d",*(only + u) + v);
        }
    }
    
    int fac;
    fac = determinant(o,only);

    int cofact[o][o];
    if(o==1) { cofact[0][0]=only[0][0]; }
    else if(o==2) {
         cofact[0][0]=  only[1][1];
         cofact[0][1]= -only[1][0];
         cofact[1][0]= -only[0][1];
         cofact[1][1]=  only[0][0];
    }
    else if(o>2){
        for(u=0;u<o;u++){
            for(v=0;v<o;v++){
                cofact[u][v] = subcofact(o,only,u,v);
            }
        }
    }
    int adj[o][o];
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            adj[u][v] = cofact[v][u];
        }
    }

    float inverse[o][o];
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            inverse[u][v] = adj[u][v]/(float)fac;
        }
    }
    printf("The inverse matrix of the matrix is\n");
    for(u=0;u<o;u++){
        for(v=0;v<o;v++){
            printf("%.2f ",inverse[u][v]);
        }
        printf("\n");
    }
}

void scalar(){
    int o,p,u,v;
    printf("Enter the number of rows and columns of the matrix you want to multiply with an integer, separated by spaces: ");
    scanf("%d%d",&o,&p);

    int only[o][p];
    printf("Enter the elements of the matrix such that each element in a row is separated by spaces and each row is in separate line.\n");

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            scanf("%d",(*(only + u) + v));
        }
    }

    int integer;
    printf("Enter the integer with which you want to multiply the matrix.\n");
    scanf("%d",&integer);

    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            only[u][v] *= integer;
        }
    }
    printf("The resultant matrix of the scalar multiplication is\n");
    for(u=0;u<o;u++){
        for(v=0;v<p;v++){
            printf("%d ",only[u][v]);
        }
        printf("\n");
    }
}

int main()
{
    int op;

    printf("Which operation of matrices do you want to perform?\n");
    printf("Enter 1 if you want to add two matrices.\n");
    printf("Enter 2 if you want to subtract two matrices.\n");
    printf("Enter 3 if you want to multiply two matrices.\n");
    printf("Enter 4 if you want to find trace of a square matrix.\n");
    printf("Enter 5 if you want to find transpose of a matrix.\n");
    printf("Enter 6 if you want to find determinant of a square matrix.\n");
    printf("Enter 7 if you want to find cofactor matrix of a square matrix.\n");
    printf("Enter 8 if you want to find adjoint matrix of a square matrix.\n");
    printf("Enter 9 if you want to find inverse matrix of a square matrix.\n");
    printf("Enter 10 if you want to multiply a matrix with an integer.\n");
    
    scanf("%d",&op);

    if(op==1) {add();}
    else if(op==2) {subtract();}
    else if(op==3) {multiply();}
    else if(op==4) {trace();}
    else if(op==5) {transpose();}
    else if(op==6) {det();}
    else if(op==7) {cofactor();}
    else if(op==8) { adjoint();}
    else if(op==9) {inv();}
    else if(op==10) {scalar();}
    else {printf("Invalid operation selected!\n");}
    
    int repeat;
    printf("Do you want to perform another operation?\n");
    printf("Enter 1 if you want to perform another operation.\n");
    printf("Enter 0 if you want to exit.\n");
    scanf("%d",&repeat);

    if(repeat==1) { main(); }
    else if(repeat!=1) { return 0;}
}