
#define capacidadeDeTurmas 10
#include "aluno.h"
#include "professor.h"
typedef struct 
{
    int codigoDaTurma;
    int codigoMateria;
    int cargaHoraria;
    int nA;//numero de Avaliações
    int nP;//possui peso?
    //Relacionamento do BD
    int idprof;
    int listaDeAlunosInscritos[capacidadeAlunoBD];
    
}Turma;



Turma Repository_BD_Turma[capacidadeDeTurmas]; 


static int codrefT = 369;
void definirMetodoDeAvaliacao(int posTabela){
      if(Repository_BD_Turma[posTabela].nP == 0){
                int matriculaA;
                printf("Digite o codigo de Matricula do aluno:");
                scanf("%d",&matriculaA);

                for(int i = 0; i < capacidadeAlunoBD; i++){
                    if(Repository_BD_Aluno[i].matricula == matriculaA){
                        float nota;
                        int peso;
                        printf("Até aqui foi!!");
                        for(int j = 0; j < Repository_BD_Turma[posTabela].nA; j++){
                            printf("Digite a nota do aluno:\n");
                            scanf("%f",&nota);
                            printf("Digite o peso da nota do aluno: \n");
                            scanf("%d",&peso);
                            Repository_BD_Aluno[i].notas[i][j] = Repository_BD_Turma[posTabela].codigoDaTurma;
                            Repository_BD_Aluno[i].notas[i][j+1] = (nota*peso);
                            Repository_BD_Aluno[i].mediaFinal +=  Repository_BD_Aluno[i].notas[i][j+1] /Repository_BD_Turma[posTabela].nA;
                             printf("Até aqui foi 2!!");
                        }
                       
                    }else{
                        printf("Matricula não encontrada!");
                    }
                }
                printf("Notas:");
                for (int i = 0; i < Repository_BD_Turma[posTabela].nA; i++)
                {
                    for (int j = 0; i < Repository_BD_Turma[posTabela].nA; i++)
                    {
                        printf("%.2f", Repository_BD_Aluno[i].notas[i][j]);
                        printf("Media Final: %f",Repository_BD_Aluno[i].mediaFinal);
                    }
                    
                }
                
                
            }else if(Repository_BD_Turma[posTabela].nP == 1){
                int matriculaA;
                printf("Digite o codigo de Matricula do aluno:");
                scanf("%d",&matriculaA);
                for(int i = 0; i < capacidadeAlunoBD; i++){
                    if(Repository_BD_Aluno[i].matricula == matriculaA){
                        float nota;
                        printf("Digite a nota do aluno: %s\n",Repository_BD_Aluno[matriculaA].nome);
                        scanf("%f",&nota);
                        Repository_BD_Aluno[matriculaA].notas[i][i] = nota;
                        Repository_BD_Aluno[matriculaA].mediaFinal += Repository_BD_Aluno[matriculaA].notas[i][i]/Repository_BD_Turma[posTabela].nA;
                    }
                }
            }
}
void abrirTurma(int posTabela){
//char nomeTurma[50];


//trcpy(nomeTurma,conversorDeMaterias(codTurma));
/*printf("|\t\tTURMA:\t%s\tCODIGO DA TURMA:\t%d\tCARGA HORÁRIA:\t%d\t\t|\n",nomeTurma,Repository_BD_Turma[posTabela].codigoDaTurma,80);
printf("|\t\tPROFESSOR:\t%s\tCODIGO DA MATÉRIA:\t%d\t\t|\n",Repository_BD_Professor[posTabela].nome,Repository_BD_Turma[posTabela].codigoMateria);
printf("|\t\t----------\t---\t-----------------\t--\t\t|\n");
printf("|\t\t Alunos Da Turma:                                  \t\t|\n");
for(int i = 0; i < capacidadeAlunoBD; i++){
    for(int j = 0; j < capacidadeAlunoBD; j++){
        if(Repository_BD_Aluno[posTabela].matricula == Repository_BD_Turma[i].listaDeAlunosInscritos[j]){
            printf("|\t\t%s\t\t\t\t\\t\n",Repository_BD_Aluno[i].nome);
        }
    }
}
printf("|\t\t                                                   \t\t|\n");*/
int op;
do{
    printf("1 - Definir Avaliações\n2- Lançar as Notas\n3 - Mostrar Boletim Inividual\n4 - Mostrar Boletim Geral\n5- Relatório Geral do Aluno");
    scanf("%d",&op);
    
    switch(op){
        case 1:
            printf("Quantas avaliações compõem o semestre:");
            scanf("%d",&Repository_BD_Turma[posTabela].nA);
            printf("possui peso?\n(0 - sim 1 - Não)");
            scanf("%d",&Repository_BD_Turma[posTabela].nP);
            definirMetodoDeAvaliacao(posTabela);
          
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("ERRO DE LEITURA");
            break;
    }   
}while(op != 5);

}
int criarTurma(Professor p){
    int i;
    for(i = 0; i < capacidadeDeTurmas; i++){
        
        printf("O código na lista é: %d",Repository_BD_Turma[i].codigoDaTurma);
        if(Repository_BD_Turma[i].codigoDaTurma == 0){
            int val;
            printf("Digite o numero de alunos inicialmente:\n");
            scanf("%d",&val);
            for(int j = 0; j < val; j++){
                int codAluno;
                printf("Digite o numero de matricula de cada aluno:\n");
                scanf("%d",&codAluno);
                Repository_BD_Turma[i].listaDeAlunosInscritos[j] = codAluno;

                if(Repository_BD_Aluno[i].turmasInscritos[j] == 0){
                    Repository_BD_Aluno[i].turmasInscritos[j] = Repository_BD_Turma[i].codigoDaTurma;
                }else{
                    printf("Erro");
                }
                

            }
            Repository_BD_Turma[i].codigoDaTurma = codrefT;
            for(int j = 0; j < capacidadeProfBD; j++){
                if(Repository_BD_Professor[i].codTurmas[j] == 0){
                Repository_BD_Professor[i].codTurmas[j] = Repository_BD_Turma[i].codigoDaTurma;
                }
            }
            
            
            
            Repository_BD_Turma[i].idprof = p.id;
            
            codrefT++;
            break;
        }else{
            printf("A posição %d a lista de turmas esta ocupada", i);
        }
      

    }
    
    printf("Turma com o cod: %d foi criada",Repository_BD_Turma[i].codigoDaTurma);
    return i;
}
