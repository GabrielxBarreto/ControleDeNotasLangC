#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"
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

        return "Fundamentos Matemáticos da Computação";
    break;
    case 2500://Funamentos da Computação
    
         return "Fundamentos da Computação";
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
    Professor p;                                
    for(int i = 0; i < capacidadeProfBD;i++){
        if(Repository_BD_Professor[i].id == id){
            strcpy(p.nome,Repository_BD_Professor[i].nome);
            strcpy(p.cpf,Repository_BD_Professor[i].cpf);
            strcpy(p.usuario,Repository_BD_Professor[i].usuario);
            for (int j = 0; j < quantMaterias; j++){
                 p.materias[j] = Repository_BD_Professor[i].materias[j];
            }
        } 
    }

//arte para os profs
int op = 0;  
 static int  c = 0;   
do{
   
    printf("\n");
    printf("\033[0;3%dm      adxnxnnda                \033[0m+-------------------------------------------------------------+\n",c);
    printf("\033[0;3%dm    xxxxxnxnnnnnn              \033[0m| ID:\t\t%d                                           \n",c,id);
    printf("\033[0;3%dm  axxxxu     unnnua            \033[0m| NOME:\t\t%s                                         \n",c,p.nome);
    printf("\033[0;3%dm axxxxx       nnnuua           \033[0m| USUÁRIO:\t%s                                      \n",c,p.usuario);
    printf("\033[0;3%dm hxxxxx.     .nnnuuh           \033[0m| CPF:\t\t%s                                          \n",c,p.cpf);
    printf("\033[0;3%dm axxxxxxuhqhunnnnuua           \033[0m+-------------------------------------------------------------+\n",c);
    printf("\033[0;3%dm  xxxxa       annuu            \033[0mMatérias:\n",c);
    printf("\033[0;3%dm   zx{         {nY             \033[0m",c);for(int i = 0; i < 3; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};printf("\n");
    printf("\033[0;3%dm                               \033[0m",c);for(int i=3 ; i < 5; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};
    printf("\n\n1-Criar uma nova turma       3-Cadastrar Alunos");
    printf("\n2-Listar Alunos              4-Acessar turma\n5-sair ");
    scanf("%d",&op);  
    switch (op){
        case 1:
            abrirTurma(criarTurma(p));
            system("cls");
            break;
        case 2:
        system("cls");
             listarAlunos();
            break;
        case 3:
            system("cls");
             cadastrarAluno();
            break;
        case 4:
            system("cls");
            int codigo;
            printf("Digite o código da turma: ");
            scanf("%d", &codigo);

            int pos = -1;
            for (int i = 0; i < capacidadeDeTurmas; i++){
                if (Repository_BD_Turma[i].codigoDaTurma!= 0 && Repository_BD_Turma[i].codigoDaTurma == codigo){
                    pos = i;
                    break;
                }
            }

            if (pos != -1) {
                abrirTurma(pos);
            } else {
                system("cls");
                printf("\033[0;31mTurma com código %d não encontrada.\033[0m\n", codigo);
            }
            break;
        

        default:
            system("cls");
            printf("\033[0;31mDigite uma Alternativa válida\033[0m\n");
    break;
    
}
}while(op != 5);      

    c++;
    return 0;
}
int menu(){
    system("cls");
    int op = 0;
    char nome[20],senha[20];
    
  do{
    
     /*printf("\033[0;31mTexto em vermelho\033[0m\n"); // Vermelho
    printf("\033[0;32mTexto em verde\033[0m\n");   // Verde
    printf("\033[0;33mTexto em amarelo\033[0m\n"); // Amarelo
    printf("\033[0;34mTexto em azul\033[0m\n");    // Azul
    printf("\033[0;35mTexto em magenta\033[0m\n"); // Magenta
    printf("\033[0;36mTexto em ciano\033[0m\n");   // Ciano

    // Fundo colorido
    printf("\033[41mFundo vermelho\033[0m\n");     // Fundo vermelho
    printf("\033[42mFundo verde\033[0m\n");        // Fundo verde
    printf("\033[43mFundo amarelo\033[0m\n");      // Fundo amarelo
    printf("\033[44mFundo azul\033[0m\n");         // Fundo azul

    // Texto em negrito
    printf("\033[1;31mTexto vermelho em negrito\033[0m\n");*/
 printf("           #####                                             ####   \033[0;35m#############  ####                \033[0m\n");        
 printf("          #######                                            ####   \033[0;35m############   ####                \033[0m\n");        
 printf("          ### ####          ####        ######         ####  ####   \033[0;35m####           ####       ####     \033[0m\n");        
 printf("         #### ####       ##########   ##########    #############   \033[0;35m####           ####    ##########  \033[0m\n");        
 printf("        ####   ####     ####                 ####   ####    #####   \033[0;35m###########    ####           #### \033[0m\n");        
 printf("       ####    #####   ####            ####  ####  ####      ####   \033[0;35m###########    ####     ####  #### \033[0m\n");        
 printf("       #############   ####          ############  ####      ####   \033[0;35m####           ####   ############ \033[0m\n");        
 printf("      ###############  #####         ####    ####   ####    #####   \033[0;35m####           ####   ###     #### \033[0m\n");        
 printf("     ####         ####  ###########  ############   #############   \033[0;35m#############  #####  ############ \033[0m\n");        
 printf("     ###          ####     ######      #####  ###     #####   ##    \033[0;35m ###########     ###    ####   ##  \033[0m\n");        
 printf("===========================================================================================================\n");        
 printf("===========================================================================================================\n");        
 printf("                                   Aplicativo de Controle Acadêmico                                      \n");        
 printf("                             e Desempenho Educacional Ligado à Avaliação                             \n");        
printf("BEM VINDO!\n\n1-Logar\n2-Criar Conta\n3-sair\n");                                                                               
   

    scanf("%d",&op);
   switch (op){
        case 1:
            system("cls");
            printf("Digite seu usuário:\n");
            scanf(" %[^\n]",nome);
            printf("Digite sua senha:\n");
            scanf(" %[^\n]",senha);

            int verificacao = logar(nome, senha);
            if(verificacao > 0){
                system("cls");
                
                printf("\033[0;32mLogado com sucesso!\033[0m\n");
                areaDeTrabalhoProfessor(verificacao);
            }else{
                system("cls");
                printf("\033[0;31mUsuário não encontrado -ERRO 403-Procure a equipe técnica\033[0m\n");
            }

        break;
        case 2:
            system("cls");
            cadastroDeProfessor(); //Chamada a função
             int idNovoProf = -1;
            //Vai recuperar o ID recem atribuido ao professor cadastrado
            for(int i = 0;i < capacidadeProfBD; i++){
                if(Repository_BD_Professor[i].id != 0){
                    idNovoProf = Repository_BD_Professor[i].id ;
                }
            }
            if (idNovoProf != -1){
                int qtdMaterias;
                system("cls");
                printf("Lista de Matérias Disponíveis\n");
                printf("+------------------------------------------------+\n");
                printf("|2500 - Fundamentos da Computação                |\n");
                printf("|2501 - Metodologia Científica                   |\n");
                printf("|2502 - ALgoritimos                              |\n");
                printf("|2504 - Fundamentos Matemáticos da Computação    |\n");
                printf("|2506 - Pré-Cálculo                              |\n");
                printf("+------------------------------------------------+\n");
                printf("Quantas matérias esse professor irá ministrar ? (máx %d)\n", quantMaterias );
                scanf("%d", &qtdMaterias);
                if (qtdMaterias>quantMaterias){qtdMaterias = quantMaterias;printf(" \033[0;31mSerá cadastrado apenas 5 matérias! \033[0m");}

                for (int j = 0; j < qtdMaterias ; j++){
                    int codMateria;
                    printf("Digite o código da matéria %d\n", j +1);
                    scanf("%d", &codMateria);

                    for (int i = 0 ; i < capacidadeProfBD ; i++){
                        if (Repository_BD_Professor[i].id == idNovoProf){
                            Repository_BD_Professor[i].materias[j] = codMateria;
                        }
                    }
                }
                system("cls");
                printf("\033[0;32mProfessor cadastrado com sucesso e máterias atribuidas !\033[0m \n");
                  }else {
                system("cls");
                    printf("\033[0;31mErro ao localizar o professor cadastrado.\033[0m\n");
                
            }
        break;
   
    default:
            system("cls");
            printf("\033[0;31mDigite uma opção válida!\033[0m\n");
    break;
   }
  } while (op!=3);
    return 0;
}

int main(){
    setlocale(LC_ALL,"");

    for(int i = 0; i <capacidadeDeTurmas; i++){
    Repository_BD_Turma[i].codigoDaTurma = 0;
    Repository_BD_Turma[i].nA = 0;
        for(int j = 0; j < capacidadeProfBD;j++ ){
            Repository_BD_Professor[i].codTurmas[j] = 0;
             Repository_BD_Aluno[i].turmasInscritos[j] =  0;
        }
        
    }
    menu();
    system("cls");
     printf("\033[0;32mObrigado, até mais!\033[0m\n");
    return 0;
}
