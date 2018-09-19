#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

void automato(char *str, int tam_str) {
	int i = 0, erro = 0;
	
	goto q0;
	
	q0:
		if (i == tam_str){
	        printf("\nERRO! Estado q0 nao e final =========\n");
	        erro++;
	        goto FINAL;
	    } else if(str[i] == '0') {
	    	printf("=> q1\n");
	    	i++;
	    	goto q1;
		}else if(str[i] == '1') {
			printf("=> q2\n");
			i++;
			goto q2;
		} else {
			printf("Continua no estado q0\n");
			i++;
			goto q0;
		}
	
	q1:
		if (i == tam_str){
	        printf("\nERRO! Estado q0 nao e final =========\n");
	        erro++;
	        goto FINAL;
	    } else if(str[i] == '0') {
	    	printf("=> q0\n");
	    	i++;
	    	goto q0;
		} else if(str[i] == '1') {
			printf("=> q3\n");
			i++;
			goto q3;
		} else {
			printf("Continua no estado q1\n");
			i++;
			goto q1;
		}
	
	q2:
		if (i == tam_str){
	        goto FINAL;
	    } else if(str[i] == '0') {
	    	printf("=> q3\n");
	    	i++;
	    	goto q3;
		} else if(str[i] == '1') {
			printf("=> q0\n");
			i++;
			goto q0;
		} else {
			printf("Continua no estado q2\n");
			i++;
			goto q2;
		}
	
	q3:
		if (i == tam_str){
	        printf("\nERRO! Estado q0 nao e final =========\n");
	        erro++;
	        goto FINAL;
	    } else if(str[i] == '0') {
	    	printf("=> q2\n");
	    	i++;
	    	goto q2;
		} else if(str[i] == '1') {
			printf("=> q1\n");
			i++;
			goto q1;
		} else {
			printf("Continua no estado q3\n");
			i++;
			goto q3;
		}
	
	FINAL:
	    if(erro == 0){
	        printf("\nEntrada aceita! -SIM-\n");
	    }
	    else if(erro > 0){
	        printf("\nERRO: Entrada não aceita! -NAO-\n");
	    }
}


int main(int argc, char *argv[ ]) {
	FILE *arq;
	
	int tam_str = 20;
	char str[tam_str];
	
	arq = fopen(argv[1], "r");
	
	while(fgets(str, 20, arq) != NULL){
		printf("\n==================================================================================");
		printf("\n Verificando string: %s\n\n  ", str);
		automato(str, tam_str);
	}
	
	fclose(arq);
}
