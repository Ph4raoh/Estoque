#include<stdio.h>

int main(){


    struct produto{
        char nome[6][300];
        char marca [6][300];
        float preco[300];
        int quantidade[300];
    };

    struct produto p;

 int loop = 0,x,temp;

 int deci,linha;

    while( loop != -1){

     system("clear");

     puts("Nome:");
     scanf("%s",p.nome[loop]);
     puts("");

     puts("Marca:");
     scanf("%s",p.marca[loop]);
     puts(""); 

     puts("Preço:");
     scanf("%f",&p.preco[loop]);
     puts("");

     puts("Quantidade:");
     scanf("%d",&p.quantidade[loop]);

     puts("");

     puts("Continuar? 1 = Sim || 2 = Não");
     
     scanf("%d",&deci);

        if(deci == 1){
         loop++;
         temp = loop + 1;
        }
        
        else{
         loop = -1;
        }

    }

   system("clear");
   
    for(x=0; x<temp; x++){

     puts("---------------------------------------------------------------");
     printf("[%d]-Nome: %s | Marca: %s | Preço: %0.2f | Quantidade: %d\n",x + 1,p.nome[x],p.marca[x],p.preco[x],p.quantidade[x]);
    }

    puts("");

    scanf("%d",&linha);


    for(x=0; x<5; x++){
     
     if( x == linha){
       
       puts("Nome:");
     scanf("%s",p.nome[x - 1]);
     puts("");

     puts("Marca:");
     scanf("%s",p.marca[x - 1]);
     puts(""); 

     puts("Preço:");
     scanf("%f",&p.preco[x - 1]);
     puts("");

     puts("Quantidade:");
     scanf("%d",&p.quantidade[x - 1]);


     }

    }

    puts("");

    for(x=0; x<3; x++){

     puts("---------------------------------------------------------------");
     printf("[%d]-Nome: %s | Marca: %s | Preço: %0.2f | Quantidade: %d\n",x + 1,p.nome[x],p.marca[x],p.preco[x],p.quantidade[x]);
    }

    return 0;
}