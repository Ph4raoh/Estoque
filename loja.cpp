#include<stdio.h>
#include<stdlib.h>

int main(){


    char nome1[50][50];
    char marca1 [50][50];
    float *preco1;
    int *quantidade1;

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

    int comprar;

    FILE *Historio_Compra;

    int vender;

    int i,cont;

    FILE *Historio_Venda;

    char texto2[1000] = "";

    FILE *alterado3;





    while(con = 1){

     system("cls");


	 puts("======Controle de Estoque======");

     puts("\n");

     puts("[1] - Cadastro de produtos\n");
     puts("[2] - Compras de produtos\n");
     puts("[3] - Vendas de produtos\n");


     puts("Escolha:");
     scanf("%d",&Controle_de_estoque);


        switch (Controle_de_estoque){


            case 1:

             system("cls");

			 puts("======Cadastro de Produto======");


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

                    cont = 0;
                    i = 0;

                    system("cls");


                   puts("Quantos produtos desseja cadastrar?");

                          scanf("%d",&loop);

						  preco1 = (float *)malloc(loop * sizeof(float));
	                      quantidade1 = (int *)malloc(loop* sizeof(int));


                            estoque = fopen("estoque.txt", "a");



                         for(i=0; i < loop; i++){

                            system("cls");

                            printf("Produto: %d\n",i + 1);

                            puts("Nome:");
                            scanf("%s",nome1[i]);
                            puts("");

                            puts("Marca:");
                            scanf("%s",marca1[i]);
                            puts("");

                            puts("Preço:");
                            scanf("%f",&preco1[i]);
                            puts("");

                            puts("Quantidade:");
                            scanf("%d",&quantidade1[i]);

                            puts("");

                            cont++;


                            }



                    break;



                    case 2: //Exibir cadastros

                      system("cls");

                            estoque = fopen("estoque.txt", "r");

                           while((ler=fgetc(estoque))!= EOF ){
		                    putchar(ler);
                           }

	                        fclose(estoque);


                        puts("");

                        	system("pause");

                    break;

                    case 3: //Atualizar cadastro

                      system("cls");

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





                              linha_atual = 0;

                             estoque = fopen("estoque.txt", "r");
                             alterado3 = fopen("alterado3.txt", "w");

                        while(fgets(texto2, 1000, estoque) != NULL){
                                 if(linha_atual != (linha_selecionada - 1)){
                                    fputs(texto2, alterado3);
                                    }
                                    linha_atual += 1;

                            }

                            fclose(estoque);
                            fclose(alterado3);

                            remove("estoque.txt");
                            rename("alterado3.txt", "estoque.txt");



                       alterado = fopen("alterado.txt", "r");
                       (fscanf(alterado,"%s %s %f %d\n",nome,marca,&preco,&quantidade));
                        printf("\nNome: %s Marca: %s Preço: %0.2f Quantidade: %d\n",nome,marca,preco,quantidade);

                        fclose(alterado);

                         puts("\nAtualizar: 1-Nome | 2-Marca | 3-Preço | 4-Quantidade");


                        scanf("%d",&atualizar);

                        if(atualizar == 1){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("cls");
                            puts("Nome:");
                            scanf("%s",nome);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }


                         if(atualizar == 2){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("cls");
                            puts("Marca:");
                            scanf("%s",marca);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }

                         if(atualizar == 3){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("cls");
                            puts("Preço:");
                            scanf("%f",&preco);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }

                        if(atualizar == 4){
                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");

                            system("cls");
                            puts("Quantidade:");
                            scanf("%d",&quantidade);

                            fprintf(estoque,"%s %s %0.2f %d\n",nome,marca,preco,quantidade);
                            fclose(estoque);
                            fclose(alterado);
                        }



                         // remove("alterado.txt");


                        puts("");

                        system("cls");

                        puts("Atualizado com sucesso!");

                        	system("pause");


                    break;

                    case 4: //Salvar cadastro


                      system("cls");

                      estoque = fopen("estoque.txt", "a");



                        for(x=0; x<cont; x++){


                            fprintf(estoque,"%s ",nome1[x]);

                            fprintf(estoque, "%s ",marca1[x]);

                            fprintf(estoque, "%0.2f ",preco1[x]);

                            fprintf(estoque, "%d\n",quantidade1[x]);

                        }

                        puts("");

                        fclose(estoque);

                        puts("Salvo com sucesso!");

                         free(preco1);
                         free(quantidade1);


                        	system("pause");

                        break;

                    break;

                    case 5:

                        system("cls");


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

                        system("cls");

                        puts("Excluido com sucesso!");

						system("pause");


                        break;

                    break;

                }


            break;

            case 2:




                system("cls");


				puts("======Compra de Produtos======");


                puts("\n");

                puts("[1] - Realizar compra\n");
                puts("[2] - Ver histórico de compras\n");

                puts("Escolha:");
                scanf("%d",&Compras_de_produtos);

                switch (Compras_de_produtos){

                case 1:

                 system("cls");

                      estoque = fopen("estoque.txt", "r");


                           while((ler=fgetc(estoque))!= EOF){
		                    putchar(ler);
                           }

	                        fclose(estoque);

                         puts("\n\nEscolha um produto");

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





                              linha_atual = 0;

                             estoque = fopen("estoque.txt", "r");
                             alterado3 = fopen("alterado3.txt", "w");

                        while(fgets(texto2, 1000, estoque) != NULL){
                                 if(linha_atual != (linha_selecionada - 1)){
                                    fputs(texto2, alterado3);
                                    }
                                    linha_atual += 1;

                            }

                            fclose(estoque);
                            fclose(alterado3);

                            remove("estoque.txt");
                            rename("alterado3.txt", "estoque.txt");



                       alterado = fopen("alterado.txt", "r");
                       (fscanf(alterado,"%s %s %f %d",nome, marca, &preco, &quantidade));
                        printf("\nNome: %s Marca: %s Preço: %0.2f Quantidade: %d",nome,marca,preco,quantidade);

                        fclose(alterado);

                         puts("\n\nQuantos itens deste produto deseja comprar?");


                        scanf("%d",&comprar);


                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");
                           Historio_Compra = fopen("HistoricoC.txt", "a");

                            system("cls");

                            fprintf(estoque,"\n%s %s %0.2f %d\n",nome,marca,preco,quantidade + comprar);

                            fprintf(Historio_Compra,"Produto: %s | Quantidade: %d | Data: %s | Hora: %s\n",nome,comprar,__DATE__,__TIME__);


                            fclose(estoque);
                            fclose(alterado);
                            fclose(Historio_Compra);


                          remove("alterado.txt");

                          puts("\nComprado com sucesso!\n");



                            	system("pause");

                          break;


                          case 2:
                          system("cls");

                            Historio_Compra = fopen("HistoricoC.txt", "r");

                           while((ler=fgetc(Historio_Compra))!= EOF ){
		                    putchar(ler);
                           }

	                        fclose(Historio_Compra);


                        puts("");

                       	system("pause");

                    break;



                }

            break;

            case 3:

                system("cls");

				puts("======Venda de Produtos======");

                int escolha3;


                puts("\n");

                puts("[1] - Realizar venda\n");
                puts("[2] - Ver histórico de vendas\n");

                puts("Escolha:");
                scanf("%d",&Vendas_de_produtos);

                switch(Vendas_de_produtos){

                    case 1:

                 system("cls");

                      estoque = fopen("estoque.txt", "r");


                           while((ler=fgetc(estoque))!= EOF){
		                    putchar(ler);
                           }

	                        fclose(estoque);

                         puts("\n\nEscolha um produto");

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





                              linha_atual = 0;

                             estoque = fopen("estoque.txt", "r");
                             alterado3 = fopen("alterado3.txt", "w");

                        while(fgets(texto2, 1000, estoque) != NULL){
                                 if(linha_atual != (linha_selecionada - 1)){
                                    fputs(texto2, alterado3);
                                    }
                                    linha_atual += 1;

                            }

                            fclose(estoque);
                            fclose(alterado3);

                            remove("estoque.txt");
                            rename("alterado3.txt", "estoque.txt");



                       alterado = fopen("alterado.txt", "r");
                       (fscanf(alterado,"%s %s %f %d",nome, marca, &preco, &quantidade));
                        printf("\nNome: %s | Marca: %s | Preço: %0.2f | Quantidade: %d",nome,marca,preco,quantidade);

                        fclose(alterado);

                         puts("\n\nQuantos itens deste produto deseja vender?");


                        scanf("%d",&vender);


                           alterado = fopen("alterado.txt", "r");
                           estoque = fopen("estoque.txt", "a");
                           Historio_Venda = fopen("HistoricoV.txt", "a");

                            system("cls");

                            fprintf(estoque,"\n%s %s %0.2f %d\n",nome,marca,preco,quantidade - vender);

                            fprintf(Historio_Venda,"Produto: %s | Quantidade: %d | Data: %s | Hora: %s\n",nome,vender,__DATE__,__TIME__);


                            fclose(estoque);
                            fclose(alterado);
                            fclose(Historio_Venda);


                          remove("alterado.txt");

                          break;

                          puts("\nVendido com sucesso!\n");



                        	system("pause");


                          case 2:
                          system("cls");

                            Historio_Venda = fopen("HistoricoV.txt", "r");

                           while((ler=fgetc(Historio_Venda))!= EOF ){
		                    putchar(ler);
                           }

	                        fclose(Historio_Venda);


                        puts("");

                        	system("pause");

                    break;




                }

                break;

        }

    }


    return 0;
}
