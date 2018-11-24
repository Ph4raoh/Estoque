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

    char nome[20] = "", marca[50] = "";

    float preco;

    int quantidade;

    int excluir;

    FILE *estoque;

    FILE *alterado;

    int linha_atual = 0, linha_selecionada = 0;

    char texto[1000] = "";

    char ler;


    char texto2[100] = "";

    FILE *alterado3;

   



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


                            estoque = fopen("estoque.txt", "a");
                          
                          loop = 0;

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

                            estoque = fopen("estoque.txt", "r");

                           while((ler=fgetc(estoque))!= EOF ){
		                    putchar(ler);
                           }
			
	                        fclose(estoque);
                       

                        puts("");

                        puts("Digite 1 para voltar ao menu");
            
                        scanf("%d",&deci);
                
                    break;

                    case 3: //Atualizar cadastro

                      system("clear");

                      estoque = fopen("estoque.txt", "r");


                           while((ler=fgetc(estoque))!= EOF){
		                    putchar(ler);
                           }
			
	                        fclose(estoque);
                       
                         puts("\nEscolha uma linha");

                         scanf("%d",&linha_selecionada);

                       linha_atual = 0;

                        estoque = fopen("estoque.txt", "r");
                        alterado = fopen("alterado.txt", "w");


                        while(fgets(texto, 1000, estoque) != NULL){
                                if(linha_atual == (linha_selecionada - 1)){
                                    fputs(texto, alterado);
                                    
                                }
                                linha_atual += 1;

        
                        }

                        
                            fclose(estoque);
                            fclose(alterado);

                            

                /*             

                              linha_atual = 0;

                             estoque = fopen("estoque.txt", "r");
                             alterado3 = fopen("alterado3.txt", "w");

                        while(fgets(texto2, 100, estoque) != NULL){
                                 if(linha_atual != (linha_selecionada - 1)){
                                    fputs(texto2, alterado3);
                                    }
                                    linha_atual += 1;
        
                            }

                            fclose(estoque);
                            fclose(alterado3);

                            remove("estoque.txt");
                            rename("alterado3.txt", "estoque.txt");
*/


                       alterado = fopen("alterado.txt", "r");
                       (fscanf(alterado,"%s %s %f %d\n",nome,marca,&preco,&quantidade));
                        printf("\nNome: %s Marca: %s Preço: %0.2f Quantidade: %d\n",nome,marca,preco,quantidade);

                        fclose(alterado);

                         puts("\nAtualizar: 1-Nome | 2-Marca | 3-Preço | 4-Quantidade");


                        scanf("%d",&atualizar);

                        if(atualizar == 1){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("clear");
                            puts("Nome:");
                            scanf("%s",nome);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }
                        

                         if(atualizar == 2){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("clear");
                            puts("Marca:");
                            scanf("%s",marca);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }

                         if(atualizar == 3){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("clear");
                            puts("Preço:");
                            scanf("%f",&preco);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }

                        if(atualizar == 4){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("clear");
                            puts("Quantidade:");
                            scanf("%d",&quantidade);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }

                        

                          remove("alterado.txt");


                        puts("");

                        system("clear");

                        puts("Atualizado com sucesso!");

                        puts("Digite 1 para voltar ao menu");
            
                        scanf("%d",&deci);
        
            
                    break;

                    case 4: //Salvar cadastro

                      
                      system("clear");

                      estoque = fopen("estoque.txt", "a");

                        for(x=0; x<3; x++){


                            fprintf(estoque, "Nome: %s | ",p.nome[x]);
                          
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

                        
                         estoque = fopen("estoque.txt", "r");

                           while( (ler=fgetc(estoque))!= EOF ){
		                    putchar(ler);
                           }
			
	                        fclose(estoque);
            
                        puts("");

                         linha_atual = 0;

                        estoque = fopen("estoque.txt", "r");
                        alterado = fopen("alterado.txt", "w");

                         scanf("%d",&linha_selecionada);


                        while(fgets(texto, 1000, estoque) != NULL){
                                if(linha_atual != (linha_selecionada - 1)){
                                    fputs(texto, alterado);
                                    
                                }
                                linha_atual += 1;

        
                            }
  
                            // fechando arquivo
                            fclose(estoque);
                            fclose(alterado);

                            remove("estoque.txt");
                            rename("alterado.txt", "estoque.txt");

                        


                        puts("");

                        system("clear");

                        puts("Excluido com sucesso!");

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