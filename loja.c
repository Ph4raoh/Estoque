#include<stdio.h>

int main(){

    struct produto{
        char nome[6][300];
        char marca [6][300];
        float preco[300];
        int quantidade[300];
    };

    struct produto p;

    int con = 1;

    int Cadastro_de_produtos;

    int Compras_de_produtos;

    int Vendas_de_produtos;

    int Controle_de_estoque;

    int loop = 0,x,temp;

    int deci,linha;

    int atualizar;

    FILE *estoque;

    estoque = fopen("estoque.txt", "a");


    while(con = 1){

     system("clear");


     puts("╔═╗┌─┐┌┐┌┌┬┐┬─┐┌─┐┬  ┌─┐  ┌┬┐┌─┐  ╔═╗┌─┐┌┬┐┌─┐┌─┐ ┬ ┬┌─┐");
     puts("║  │ ││││ │ ├┬┘│ ││  ├┤    ││├┤   ║╣ └─┐ │ │ ││─┼┐│ │├┤ ");
     puts("╚═╝└─┘┘└┘ ┴ ┴└─└─┘┴─┘└─┘  ─┴┘└─┘  ╚═╝└─┘ ┴ └─┘└─┘└└─┘└─┘");
                                                        
                                                      
     puts("\n");

     puts("[1] - Cadastro de produtos\n");
     puts("[2] - Compras de produtos\n");
     puts("[3] - Vendas de produtos\n");


     puts("Escolha:");
     scanf("%d",&Controle_de_estoque);


        switch (Controle_de_estoque){

    
            case 1:

             system("clear");

             puts("╔═╗┌─┐┌┬┐┌─┐┌─┐┌┬┐┬─┐┌─┐  ┌┬┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┬ ┬┌┬┐┌─┐┌─┐");
             puts("║  ├─┤ ││├─┤└─┐ │ ├┬┘│ │   ││├┤   ├─┘├┬┘│ │ │││ │ │ │ │└─┐");
             puts("╚═╝┴ ┴─┴┘┴ ┴└─┘ ┴ ┴└─└─┘  ─┴┘└─┘  ┴  ┴└─└─┘─┴┘└─┘ ┴ └─┘└─┘");

             puts("\n");

             puts("[1] - Realizar cadastro\n");
             puts("[2] - Exibir cadastros\n");
             puts("[3] - Atualizar cadastro\n");
             puts("[4] - Salvar cadastro\n");
             puts("[5] - Excluir cadastro\n");

             puts("Escolha:");
             scanf("%d",&Cadastro_de_produtos);


                switch(Cadastro_de_produtos){

                    case 1: //Realizar cadastro


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
                            }
                    
                            else{
                            loop = -1;
                            }

                            }

                    break;
                    
                    

                    case 2: //Exibir cadastros

                      system("clear");

                        for(x=0; x<3; x++){

                            puts("---------------------------------------------------------------");
                            printf("ID-%d | Nome: %s | Marca: %s | Preço: %0.2f | Quantidade: %d\n",x + 1,p.nome[x],p.marca[x],p.preco[x],p.quantidade[x]);

                        }
                       

                        puts("");

                        puts("Digite 1 para voltar ao menu");
            
                        scanf("%d",&deci);
                
                    break;

                    case 3: //Atualizar cadastro

                      system("clear");

                        for(x=0; x<3; x++){

                            puts("---------------------------------------------------------------");
                            printf("ID-%d | Nome: %s | Marca: %s | Preço: %0.2f | Quantidade: %d\n",x + 1,p.nome[x],p.marca[x],p.preco[x],p.quantidade[x]);

                        }

                        puts("");

                        puts("Qual produto deseja atualizar?");

                        scanf("%d",&linha);

            
                        puts("");

                        puts("Atualizar: 1-Nome | 2-Marca | 3-Preço | 4-Quantidade");

                        scanf("%d",&atualizar);

                        if(atualizar == 1){
                            system("clear");
                            puts("Nome:");
                            scanf("%s",p.nome[linha - 1]);

                        }

                        if(atualizar == 2){
                            system("clear");
                            puts("Marca:");
                            scanf("%s",p.marca[linha - 1]);

                        }

                        if(atualizar == 3){
                            system("clear");
                            puts("Preço:");
                            scanf("%f",&p.preco[linha - 1]);

                        }

                        if(atualizar == 4){
                            system("clear");
                            puts("Quantidade:");
                            scanf("%d",&p.quantidade[linha - 1]);

                        }

                        puts("");

                        system("clear");

                        puts("Atualizado com sucesso!");

                        puts("Digite 1 para voltar ao menu");
            
                        scanf("%d",&deci);
        
            
                    break;

                    case 4: //Salvar cadastro

                      
                      system("clear");

                      estoque = fopen("estoque.txt", "w");

                        for(x=0; x<3; x++){


                            fprintf(estoque, "ID-%d | Nome: %s | ",x + 1,p.nome[x]);
                          
                            fprintf(estoque, "Marca: %s | ",p.marca[x]);

                            fprintf(estoque, "Preço: %0.2f | ",p.preco[x]);

                            fprintf(estoque, "Quantidade: %d\n",p.quantidade[x]);
   
                        }

                        puts("");
                      
                        fclose(estoque);

                        puts("Salvo com sucesso!");

                        puts("Digite 1 para voltar ao menu");
            
                        scanf("%d",&deci);

                        break;

                    break;

                    case 5:

                        system("clear");

                        estoque = fopen("estoque.txt", "w");

                        fclose(estoque);

                        puts("");

                        puts("Excluido com sucesso!\n");

                        puts("Digite 1 para voltar ao menu");
        
                        scanf("%d",&deci);

                        break;

                    break;

                }

            break;

            case 2:

                system("clear");

                puts("╔═╗┌─┐┌┬┐┌─┐┬─┐┌─┐┌─┐  ┌┬┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┬ ┬┌┬┐┌─┐┌─┐");
                puts("║  │ ││││├─┘├┬┘├─┤└─┐   ││├┤   ├─┘├┬┘│ │ │││ │ │ │ │└─┐");
                puts("╚═╝└─┘┴ ┴┴  ┴└─┴ ┴└─┘  ─┴┘└─┘  ┴  ┴└─└─┘─┴┘└─┘ ┴ └─┘└─┘");
            
                puts("\n");

                puts("[1] - Realizar compra\n");
                puts("[2] - Ver histórico de compras\n");

                puts("Escolha:");
                scanf("%d",&Compras_de_produtos);
            
            break;

            case 3:

                system("clear");

                int escolha3;

                puts("╦  ╦┌─┐┌┐┌┌┬┐┌─┐┌─┐  ┌┬┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┬ ┬┌┬┐┌─┐┌─┐");
                puts("╚╗╔╝├┤ │││ ││├─┤└─┐   ││├┤   ├─┘├┬┘│ │ │││ │ │ │ │└─┐");
                puts(" ╚╝ └─┘┘└┘─┴┘┴ ┴└─┘  ─┴┘└─┘  ┴  ┴└─└─┘─┴┘└─┘ ┴ └─┘└─┘");

                puts("\n");
            
                puts("[1] - Realizar venda\n");
                puts("[2] - Ver histórico de compras\n");

                puts("Escolha:");
                scanf("%d",&Vendas_de_produtos);
            
                break;

        }

    }
    

    return 0;
}