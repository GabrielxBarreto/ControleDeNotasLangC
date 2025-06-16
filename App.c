#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
int areaDeTrabalhoProfessor(int id){

                                             
                                             
                                             
                                             
                                             
                                             
//arte para os adms                                             
printf("\n   :#############:   \n");            
printf("  =###############=  \n");            
printf("  *##=::.*#*.::=##*  \n");            
printf("  *##.  =###=  :##*  \n");            
printf("  =###############=  \n");            
printf("   #######*######*   \n");            
printf("   .+##*******##+.   \n");            
printf("     -###* *###-     \n");            
printf("       -**:**-       \n");            
                                         
                                             
                                             
                                             
                                             
                                
char nome[50];
//int materias[20];
char cpf[20];
for(int i = 0; i < capacidadeProfBD;i++){
    if(Repository_BD_Professor[i].id == id){
        strcpy(nome,Repository_BD_Professor[i].nome);
        strcpy(cpf,Repository_BD_Professor[i].cpf);
    } 
}
//arte para os profs          
printf("      adxnxnnda      \n");
printf("    xxxxxnxnnnnnn               ID:%d\n",id);
printf("  axxxxu     unnnua             NOME: %s\n",nome);
printf(" axxxxx       nnnuua \n");
printf(" hxxxxx.     .nnnuuh            CPF:%s\n",cpf);
printf(" axxxxxxuhqhunnnnuua \n");
printf("  xxxxa       annuu  \n");
printf("   zx{         {nY   \n");
printf("     b         k     \n");
    return 0;
}
int menu(){
    int op = 0;
    char nome[20],senha[20];
  do{
    printf("BEM VINDO PROFESSOR!:\n\n1-Logar\n2-Criar Conta\n3-sair\n");
    scanf("%d",&op);
   switch (op){
        case 1:
            printf("Digite seu usuário:\n");
            scanf(" %[^\n]",nome);
            printf("Digite sua senha:\n");
            scanf(" %[^\n]",senha);

            int verificacao = logar(nome, senha);
            if(verificacao > 0){
                printf("Logado com sucesso!\n");
                areaDeTrabalhoProfessor(verificacao);
            }else{
                printf("Usuário não encontrado -ERRO 403-Procure a equipe técnica\n");
            }

        break;
        case 2:
            cadastroDeProfessor();
        break;
   
    default:
    break;
   }
  } while (op!=3);
    return 0;
}

int main(){
    menu();
    return 0;
}
