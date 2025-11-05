#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    int M, N;
    char resp;
  
    scanf("%d%d\n", &M,&N);
    
    int comp = 2;
    int total = M*N;
    int dif = total/comp;
    
    printf ("\n%d", dif);
    
    
    return 0; 
}
