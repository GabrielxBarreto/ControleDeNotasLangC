#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "turma.h"
//finalização impar - Humanas
//finalização par - Exatas
char  *conversorDeMaterias(int code){

    switch (code)
    {
    case 2502://algoritimos
        return "ALgoritimos";
        break;
    case 2504://pre calculo
        return "Pré-Calculo";
    break;

    case 2506://Funamentos Matemáticos da Computação

        return "Funamentos Matemáticos da Computação";
    break;
    case 2500://Funamentos da Computação
    
         return "Funamentos da Computação";
    break;
    case 2501://metodologia 
    
        return "Metodologia Científica";
    break;
    
    default:
        return "\0";
        break;
    }
    
}
int areaDeTrabalhoProfessor(int id){

                                             
                                             
                                             
                                             
                                             
                                             
/*arte para os adms                                             
printf("\n   :#############:   \n");            
printf("  =###############=  \n");            
printf("  *##=::.*#*.::=##*  \n");            
printf("  *##.  =###=  :##*  \n");            
printf("  =###############=  \n");            
printf("   #######*######*   \n");            
printf("   .+##*******##+.   \n");            
printf("     -###* *###-     \n");            
printf("       -**:**-       \n"); */           
                                         
                                             
                                             
                                             
                                             
Professor p;                                

for(int i = 0; i < capacidadeProfBD;i++){
    if(Repository_BD_Professor[i].id == id){
        strcpy(p.nome,Repository_BD_Professor[i].nome);
        strcpy(p.cpf,Repository_BD_Professor[i].cpf);
        strcpy(p.usuario,Repository_BD_Professor[i].usuario);
         for (int j = 0; j < quantMaterias; j++){
                 p.materias[i] = Repository_BD_Professor[i].materias[j];
            }
       
        printf("%d", p.materias[i]);
    } 
}

//arte para os profs
int op = 0;    
do{
printf("\n");
printf("      adxnxnnda                +-------------------------------------------------------------+\n");
printf("    xxxxxnxnnnnnn              | ID: %d                                                      |\n",id);
printf("  axxxxu     unnnua            | NOME: %s                                                    |\n",p.nome);
printf(" axxxxx       nnnuua           | USUÁRIO: %s                                                 |\n",p.usuario);
printf(" hxxxxx.     .nnnuuh           | CPF: %s                                                     |\n",p.cpf);
printf(" axxxxxxuhqhunnnnuua           +-------------------------------------------------------------+\n");
printf("  xxxxa       annuu            Matérias:\n");
printf("   zx{         {nY             ");for(int i = 0; i < 3; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};printf("\n");
printf("     b         k               \n");for(int i=3 ; i < 5; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};
printf("\n1-Criar uma nova turma\n2-Listar Alunos\n3-Cadastrar Alunos\n4-sair");
scanf("%d",&op);  
switch (op)
{
case 1:
    abrirTurma(criarTurma(p));
    break;
case 2:
     listarAlunos();
    break;
case 3:
     cadastrarAluno();
    break;
default:
    break;
}
}while(op != 4);      


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
    setlocale(LC_ALL,"");
    for(int i = 0; i <capacidadeDeTurmas; i++){
    Repository_BD_Turma[i].codigoDaTurma = 0;
        for(int j = 0; j < capacidadeProfBD;j++ ){
            Repository_BD_Professor[i].codTurmas[j] = 0;
        }
        
    }
    menu();
    return 0;
}
