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
printf("\n :#############:   \n");            
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
                 p.materias[j] = Repository_BD_Professor[i].materias[j];
            }
       
        printf("%d", p.materias[i]);
    } 
}

//arte para os profs
int op = 0;    
do{
printf("\n");
printf("\033[0;34m      adxnxnnda                \033[0m+-------------------------------------------------------------+\n");
printf("\033[0;34m    xxxxxnxnnnnnn              \033[0m| ID:\t\t%d                                           \n",id);
printf("\033[0;34m  axxxxu     unnnua            \033[0m| NOME:\t\t%s                                         \n",p.nome);
printf("\033[0;34m axxxxx       nnnuua           \033[0m| USUÁRIO:\t%s                                      \n",p.usuario);
printf("\033[0;34m hxxxxx.     .nnnuuh           \033[0m| CPF:\t\t%s                                          \n",p.cpf);
printf("\033[0;34m axxxxxxuhqhunnnnuua           \033[0m+-------------------------------------------------------------+\n");
printf("\033[0;34m  xxxxa       annuu            \033[0mMatérias:\n");
printf("\033[0;34m   zx{         {nY             \033[0m");for(int i = 0; i < 3; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};printf("\n");
printf("\033[0;34m     b         k               \033[0m");for(int i=3 ; i < 5; i++){printf("%s ",conversorDeMaterias(p.materias[i]));};
printf("\n\n1-Criar uma nova turma\n2-Listar Alunos\n3-Cadastrar Alunos\n4-Acessar turma\n 5-sair ");
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
case 4:{
        int codigo;
        printf("Digite o código da turma: ");
        scanf("%d", &codigo);

        int pos = -1;
        for (int i = 0; i < capacidadeDeTurmas; i++) {
            if (Repository_BD_Turma[i].codigoDaTurma!= 0 && Repository_BD_Turma[i].codigoDaTurma == codigo) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            abrirTurma(pos);
        } else {
            printf("Turma com código %d não encontrada.\n", codigo);
        }
        break;
    }

default:
    printf("Digite uma Alternativa válida");
    break;
}
}while(op != 4);      


    return 0;
}
int menu(){


    int op = 0;
    char nome[20],senha[20];
    
  do{
     printf("\033[0;31mTexto em vermelho\033[0m\n"); // Vermelho
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
    printf("\033[1;31mTexto vermelho em negrito\033[0m\n");
    printf("=====================\n");
    printf("BEM VINDO!:\n\n1\t-\tLogar\n2\t-\tCriar Conta\n3\t-\tsair\n");
    printf("=====================\n");

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
            cadastroDeProfessor(); //Chamada a função
             int idNovoProf = -1;
            //Vai recuperar o ID recem atribuido ao professor cadastrado
            for(int i = 0;i < capacidadeProfBD; i++){
                if(Repository_BD_Professor[i].id != 0){
                    idNovoProf = Repository_BD_Professor[i].id ;
                }
            }
            printf("\033[0;31mTexto em vermelho\033[0m\n");
            if (idNovoProf != -1){
                int qtdMaterias;
                printf("Quantas matérias esse professor irá ministrar ? (máx %d)\n", quantMaterias );
                scanf("%d", &qtdMaterias);
                if (qtdMaterias>quantMaterias) qtdMaterias = quantMaterias;

                for (int j = 0; j < qtdMaterias ; j++){
                    int codMateria;
                    printf("Digite o código da matéria %d", j +1);
                    scanf("%d", &codMateria);

                    for (int i = 0 ; i < capacidadeProfBD ; i++){
                        if (Repository_BD_Professor[i].id == idNovoProf){
                            Repository_BD_Professor[i].materias[j] = codMateria;
                        }
                    }
                }
                
                printf("Professor cadastrado com sucesso e máterias atribuidas ! \n");
                  }else {
                    printf("Erro ao localizar o professor cadastrado.\n");
                
            }
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
             Repository_BD_Aluno[i].turmasInscritos[j] =  0;
        }
        
    }
    menu();
    return 0;
}
