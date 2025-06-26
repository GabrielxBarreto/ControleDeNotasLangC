
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
    int nA;//numero de Avaliações
    int nP;//possui peso?
    //Relacionamento do BD
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
                             printf("Até aqui foi 2!!");
                        }
                       
                    }else{
                        printf("Matricula não encontrada!");
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
                        printf("Matricula não encontrada!");
                    }
                }
                
            }
}
void abrirTurma(int posTabela) {
    int op;

    do {
        printf("\n------ Menu da Turma [%d] ------\n", Repository_BD_Turma[posTabela].codigoDaTurma);
        printf("1 - Visualizar Soma Total das Notas da Turma\n");
        printf("2 - Visualizar Soma das Notas por Aluno\n");
        printf("3 - Mostrar Boletim Individual\n");
        printf("4 - Visualizar Soma das Notas por Avaliação\n");
        printf("5 - Gerar Relatório Geral do Aluno\n");
        printf("6 - Definir Número de Avaliações\n");
        printf("7 - Lançar Notas\n");
        printf("8 - Sair da Turma\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                somaTotalNotas(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 2:
                somaNotasPorAluno(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 3: {
                int matricula, encontrado = 0;
                printf("Digite a matrícula do aluno: ");
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
                    printf("Aluno com matrícula %d não encontrado!\n", matricula);
                break;
            }

            case 4:
                somaNotasPorAvaliacao(&Repository_BD_Turma[posTabela], Repository_BD_Aluno, capacidadeAlunoBD);
                break;

            case 5: {
                int matricula, encontrado = 0;
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                for (int i = 0; i < capacidadeAlunoBD; i++) {
                    if (Repository_BD_Aluno[i].matricula == matricula) {
                        gerarRelatorioGeralDoAluno(Repository_BD_Aluno[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado)
                    printf("Aluno com matrícula %d não encontrado!\n", matricula);
                break;
            }

            case 6:
                printf("Digite a quantidade de avaliações da turma: ");
                scanf("%d", &Repository_BD_Turma[posTabela].nA);
                printf("Número de avaliações definido como %d\n", Repository_BD_Turma[posTabela].nA);
                break;

            case 7: {
                int nAvaliacoes = Repository_BD_Turma[posTabela].nA;
                if (nAvaliacoes <= 0) {
                    printf("Defina o número de avaliações primeiro (opção 6).\n");
                    break;
                }

                for (int i = 0; i < 40; i++) {
                    int matricula = Repository_BD_Turma[posTabela].listaDeAlunosInscritos[i];
                    if (matricula == 0) continue;

                    for (int j = 0; j < capacidadeAlunoBD; j++) {
                        if (Repository_BD_Aluno[j].matricula == matricula) {
                            printf("Lançando notas para: %s (Matrícula %d)\n", Repository_BD_Aluno[j].nome, matricula);

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
                                printf("Nota da Avaliação %d: ", k);
                                scanf("%f", &Repository_BD_Aluno[j].notas[slot][k]);
                                soma += Repository_BD_Aluno[j].notas[slot][k];
                            }

                            Repository_BD_Aluno[j].mediaFinal = soma / nAvaliacoes;
                            break;
                        }
                    }
                }
                printf("Notas lançadas com sucesso.\n");
                break;
            }

            case 8:
                printf("Saindo da turma...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
<<<<<<< Updated upstream
=======
    }
}
printf("|\t\t                                                   \t\t|\n");*/
int op;
do{
    printf("1 - Definir Avaliações\n2- Lançar as Notas\n3 - Mostrar Boletim Inividual\n4 - Mostrar Boletim Geral\n5- Relatório Geral do Aluno\n6 - Voltar");
    scanf("%d",&op);
    
    switch(op){
        case 1:
            printf("Quantas avaliações compõem o semestre:");
            scanf("%d",&Repository_BD_Turma[posTabela].nA);
            printf("possui peso?\n(0 - sim 1 - Não)");
            scanf("%d",&Repository_BD_Turma[posTabela].nP);
            
          
            break;
        case 2:
            cadastroDeNotas(posTabela);
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
}while(op != 6);
>>>>>>> Stashed changes

    } while (op != 8);
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
#endif