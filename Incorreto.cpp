#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
main(){
	setlocale(LC_ALL,"portuguese");
	int mat[3][2], op, id, qtd, linha;
	float vet[3], valorVenda;
	bool eb = false,sair = false, opInv=false, idEncontrado=false;
	while(sair==false){
		
		if(opInv==false){
			//Preencher matriz e vetor
			for(int i=0;i<3;i++){
				for(int j=0;j<2;j++){
					if(j==0){
						printf("Digite o ID do produto %d: ",i+1);
						scanf("%d",&mat[i][j]);
					}else if(j==1){
						printf("Digite a quantidade do produto %d: ",i+1);
						scanf("%d",&mat[i][j]);
					}
				}
				printf("Digite o preço do produto %d: ",i+1);
				scanf("%f",&vet[i]);
			}
		}
		
		
		//Menu
		printf("\n\n	MENU\nDigite uma opção para continuar\n1 - Exibir produtos\n2 - Vender produto\n3 - Sair do programa\n");
		scanf("%d",&op);
		opInv=false;
		
		if(op==1){//Exibir produtos
			printf("\nID - QTD - PREÇO");
			for(int i=0;i<3;i++){
				for(int j=0;j<2;j++){
					if(j==0){
						printf("\n%d -",mat[i][j]);
					}else if(j==1){
						if(mat[i][j]<3){
							eb=true;							
						}
						printf(" %d -",mat[i][j]);
					}
				}
				if(eb==true){
					printf(" R$%.2f -> Estoque baixo",vet[i]);
					eb=false;
				}else if(eb==false){
					printf(" R$%.2f",vet[i]);
				}
			}
			opInv=true;
		}else if(op==2){//Vender produtos
			do{
				printf("Digite o ID do produto a ser vendido: ");
				scanf("%d",&id);
				for(int i=0;i<3;i++){
					if(id==mat[i][0]){
						idEncontrado=true;
					}
				}
				if(idEncontrado==false){
					printf("ID inválido, tente novamente \n");
				}
			}while(idEncontrado==false);
			idEncontrado=false;
			printf("Digite a quantidade: ");
			scanf("%d",&qtd);
			for(int i=0;i<3;i++){
				if(id==mat[i][0]){
					linha=i;
				}
			}
			if(qtd<=mat[linha][1]&&mat[linha][1]>2){
				mat[linha][1]-=qtd;
				valorVenda=vet[linha]*qtd;
				printf("Venda sucedida. Valor total: R$%.2f\n",valorVenda);
			}else if(qtd>mat[linha][1]&&mat[linha][1]!=0){
				printf("Estoque insuficiente!\n");
				printf("Sistema em crise!\n");
			}else if(mat[linha][1]==0){
				printf("Estoque esgotado!\n");
			}else{
				for(int l=0;l<30;l++){
					printf("PANE!\n");
				}
			}
			opInv=true;	
		}else if(op==3){
			printf("Você decidiu sair do programa! Volte sempre\n");
			sair=true;
		}else{
			printf("Você digitou uma opção inválida, tente novamente:");
			opInv=true;
		}
	}
}
