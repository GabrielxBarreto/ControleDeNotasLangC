
#ifndef TURMA_H
#define TURMA_H
#define capacidadeDeTurmas 10
#include "aluno.h"
#include "professor.h"
#define escala  10
typedef struct 
{
    int codigoDaTurma;
    int codigoMateria;
    int cargaHoraria;
    int nA;//numero de Avalia��es
    int nP;//possui peso?
    //Relacionamento do BD
    char nomeDaTurma[50];
    int idprof;
    int listaDeAlunosInscritos[capacidadeAlunoBD];
    
}Turma;



Turma Repository_BD_Turma[capacidadeDeTurmas]; 


static int codrefT = 369;
void cadastroDeNotas(int posTabela){
    int somaDosPesos = 0; 
      if(Repository_BD_Turma[posTabela].nP == 0){
                int matriculaA = 0;
                
                printf("Digite o codigo de Matricula do aluno:");
                scanf("%d",&matriculaA);

                for(int i = 0; i < capacidadeAlunoBD; i++){
                    if( matriculaA == Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i]){
                        
                        float nota;
                        int peso;
                        for(int j = 0; j < Repository_BD_Turma[posTabela].nA; j++){
                            printf("Digite a nota do aluno:\n");
                            scanf("%f",&nota);
                            printf("Digite o peso da nota do aluno: \n");
                            scanf("%d",&peso);
                            somaDosPesos += peso;
                            Repository_BD_Aluno[i].notas[i][0] = Repository_BD_Turma[posTabela].codigoDaTurma;
                            Repository_BD_Aluno[i].notas[i][j+1] = (nota*escala)/peso;
                            Repository_BD_Aluno[i].mediaFinal +=  Repository_BD_Aluno[i].notas[i][j+1] /somaDosPesos;
                             printf("At� aqui foi 2!!");
                        }
                       
                    }else{
                        printf("Matricula n�o encontrada!");
                    }
                }
                
                
                
                
            }else if(Repository_BD_Turma[posTabela].nP == 1){
                int matriculaA;
                printf("Digite o codigo de Matricula do aluno:");
                scanf("%d",&matriculaA);
                for(int i = 0; i < capacidadeAlunoBD; i++){
                    if(matriculaA == Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i]){
                        for(int j = 0; j < Repository_BD_Turma[posTabela].nA; j++){
                            float nota;
                            printf("Digite a nota do aluno:\n");
                            scanf("%f",&nota);
                            Repository_BD_Aluno[i].notas[i][0] = Repository_BD_Turma[posTabela].codigoDaTurma;
                           
                            Repository_BD_Aluno[i].notas[i][j+1] = nota;
                            
                            Repository_BD_Aluno[i].mediaFinal +=  Repository_BD_Aluno[i].notas[i][j+1] /Repository_BD_Turma[posTabela].nA;
                        }
                    }else{
                        printf("Matricula n�o encontrada!");
                    }
                }
                
            }
}
int listarAlunosDaTurma(int posTabela){
    printf("\n---------LISTA DE ALUNOS----------\n");
    for(int i = 0;i < capacidadeAlunoBD;i++){
        
        if(Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i] != 0){
            if(Repository_BD_Aluno[i].matricula == Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i] ){
                  printf("Matr�cula %d | Nome : %s |", Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i] , Repository_BD_Aluno[i].nome);
            }
          
       
                /*for(int j=0;j < quantMaterias; j++){
                    if (Repository_BD_Aluno[i].materias[j] != 0){
                        printf("%d|", Repository_BD_Aluno[i].materias[j]);
                    }
                }*/
                printf("\n");
        }
    }
    return 0;
 }
void abrirTurma(int posTabela, Professor professorLogado) {
    int op;

    do {
        
        printf("\n---------------------------- Menu da Turma [%d] -----------------------------------\n", Repository_BD_Turma[posTabela].codigoDaTurma);
        printf("Nome:%s\t\tN�mero de Avalia��es:%d\n",Repository_BD_Turma[posTabela].nomeDaTurma,Repository_BD_Turma[posTabela].nA);
        //listarAlunosDaTurma(posTabela);
        printf("1 - Visualizar Soma Total das Notas da Turma      5 - Gerar Relat�rio Geral do Aluno\n");
        printf("2 - Visualizar Soma das Notas por Aluno           6 - Definir N�mero de Avalia��es\n");
        printf("3 - Mostrar Boletim Individual                    7 - Lan�ar Notas\n");
        printf("4 - Visualizar Soma das Notas por Avalia��o     8 - Sair da Turma\n");
        
        
        
        printf("Escolha uma op��o: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                system("cls");
                somaTotalNotas(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 2:
                system("cls");
                somaNotasPorAluno(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 3: {
                system("cls");
                int matricula, encontrado = 0;
                printf("Digite a matr�cula do aluno: ");
                scanf("%d", &matricula);
                for (int i = 0; i < capacidadeAlunoBD; i++) {
                    if (Repository_BD_Aluno[i].matricula == matricula) {
                        mostrarBoletimIndividual(Repository_BD_Aluno[i],
                                                 Repository_BD_Turma[posTabela].codigoDaTurma,
                                                 Repository_BD_Turma[posTabela].nA);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado)
                    printf("Aluno com matr�cula %d n�o encontrado!\n", matricula);
                break;
            }

            case 4:
            system("cls");
                somaNotasPorAvaliacao(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 5: {
    system("cls");
    int matricula, encontrado = 0;
    printf("Digite a matr�cula do aluno: ");
    scanf("%d", &matricula);

    for (int i = 0; i < capacidadeAlunoBD; i++) {
        if (Repository_BD_Aluno[i].matricula == matricula) {

            // VERIFICA se o aluno pertence � turma
            int alunoNaTurma = 0;
            for (int t = 0; t < 40; t++) {
                if (Repository_BD_Turma[posTabela].listaDeAlunosInscritos[t] == matricula) {
                    alunoNaTurma = 1;
                    break;
                }
            }

            if (!alunoNaTurma) {
                printf("Este aluno n�o pertence � turma %d!\n", Repository_BD_Turma[posTabela].codigoDaTurma);
                break;
            }

            gerarRelatorioGeralDoAluno(
                Repository_BD_Aluno[i],
                Repository_BD_Turma,
                capacidadeDeTurmas,
                professorLogado.id
            );
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Aluno com matr�cula %d n�o encontrado!\n", matricula);
    break;
}

            case 6:
            system("cls");
                printf("Digite a quantidade de avalia��es da turma: ");
                scanf("%d", &Repository_BD_Turma[posTabela].nA);
                printf("N�mero de avalia��es definido como %d\n", Repository_BD_Turma[posTabela].nA);
                break;

            case 7: {
                system("cls");
                int nAvaliacoes = Repository_BD_Turma[posTabela].nA;
                if (nAvaliacoes <= 0) {
                    printf("Defina o n�mero de avalia��es primeiro (op��o 6).\n");
                    break;
                }

                for (int i = 0; i < 40; i++) {
                    int matricula = Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i];
                    if (matricula == 0) continue;

                    for (int j = 0; j < capacidadeAlunoBD; j++) {
                        if (Repository_BD_Aluno[j].matricula == matricula) {
                            printf("Lan�ando notas para: %s (Matr�cula %d)\n", Repository_BD_Aluno[j].nome, matricula);

                            int slot = -1;
                            for (int n = 0; n < 10; n++) {
                                if ((int)Repository_BD_Aluno[j].notas[n][0] == Repository_BD_Turma[posTabela].codigoDaTurma) {
                                    slot = n;
                                    break;
                                } else if (Repository_BD_Aluno[j].notas[n][0] == 0.0 && slot == -1) {
                                    slot = n;
                                }
                            }

                            Repository_BD_Aluno[j].notas[slot][0] = Repository_BD_Turma[posTabela].codigoDaTurma;
                            float soma = 0;

                            for (int k = 1; k <= nAvaliacoes; k++) {
                                printf("Nota da Avalia��o %d: ", k);
                                scanf("%f", &Repository_BD_Aluno[j].notas[slot][k]);
                                soma += Repository_BD_Aluno[j].notas[slot][k];
                            }

                            Repository_BD_Aluno[j].mediaFinal = soma / nAvaliacoes;
                            break;
                        }
                    }
                }
                printf("Notas lan�adas com sucesso.\n");
                break;
            }

            case 8:
                printf("Saindo da turma...\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
        }

    } while (op != 8);
}
int criarTurma(Professor p){
    int i;
    
    for(i = 0; i < capacidadeDeTurmas; i++){
        
        if(Repository_BD_Turma[i].codigoDaTurma == 0){
            int val;
            
            printf("Digite o Nome Da Mat�ria:\n");
            scanf(" %[^\n]",Repository_BD_Turma[i].nomeDaTurma);
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
        }
      

    }
    
    printf("Turma com o cod: %d foi criada",Repository_BD_Turma[i].codigoDaTurma);
    return i;
}
#endif