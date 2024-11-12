#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
main(){
	setlocale(LC_ALL,"Portuguese");
    char senha[20];
    char senha_correta[] = "empreguetes";
    while(true){
    	printf("Digite a senha: ");
	    fgets(senha, sizeof(senha),stdin);
	    senha[strcspn(senha,"\n")]='\0';
	    if(strcmp(senha, senha_correta)==0) {
	        printf("O erro aparece quando o estoque fica baixo");
	    }
	}
}

