#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "turma.h"

// Apenas os protótipos:
void mostrarBoletimIndividual(Aluno aluno, int codigoTurma, int nAvaliacoes);
void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos);
void somaNotasPorAluno(Turma *turma, Aluno alunos[], int totalAlunos);
void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos);
void gerarRelatorioGeralDoAluno(Aluno aluno);


#endif  // FUNCOES_H

// ========================= IMPLEMENTAÇÕES =============================

void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos){
    float soma = 0;
    for(int i = 0; i < 40; i++){
        int matricula = turma->listaDeAlunosInscritos[i];
        if(matricula == 0) continue;

        for(int j = 0; j < totalAlunos; j++){
            if (alunos[j].matricula == matricula) {
                for (int k = 0; k < turma->nA; k++) {
                    for (int l = 0; l < 10; l++) {
                        if ((int)alunos[j].notas[l][0] == turma->codigoDaTurma) {
                            soma += alunos[j].notas[l][k+1];
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    printf("Soma total dos alunos da turma: %.2f\n", soma);
}

void somaNotasPorAluno(Turma *turma, Aluno alunos[], int totalAlunos){
    for(int i = 0; i < 40; i++){
        int matricula = turma->listaDeAlunosInscritos[i];
        if(matricula == 0) continue;

        for (int j = 0; j < totalAlunos; j++) {
            if(alunos[j].matricula == matricula){
                float soma = 0;
                for(int l = 0; l < 10; l++) {
                    if ((int)alunos[j].notas[l][0] == turma->codigoDaTurma) {
                        for(int k = 1; k <= turma->nA; k++){
                            soma += alunos[j].notas[l][k];
                        }
                        break;
                    }
                }
                
                printf("Aluno: %s | Matrícula: %d | Soma das notas: %.2f\n", alunos[j].nome, alunos[j].matricula, soma);
                break;
            }
        }
    }
}

void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos){
    for(int a = 0; a < turma->nA; a++){
        float soma = 0;
        for(int i = 0; i < 40; i++){
            int matricula = turma->listaDeAlunosInscritos[i];
            if(matricula == 0) continue;

            for(int j = 0; j < totalAlunos; j++){
                if(alunos[j].matricula == matricula){
                    for(int l = 0; l < 10; l++) {
                        if ((int)alunos[j].notas[l][0] == turma->codigoDaTurma) {
                            soma += alunos[j].notas[l][a+1];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        printf("Avaliação %d - Soma das notas: %.2f\n", a+1, soma);
    }
}

void gerarRelatorioGeralDoAluno(Aluno aluno){
   
    printf("Relatório do aluno: %s (Matrícula: %d)\n", aluno.nome, aluno.matricula);
    for(int i = 0; i < 10; i++){
        if (aluno.notas[i][0] == 0) continue;

        printf("Turma %d - Notas: ", (int)aluno.notas[i][0]);
        for(int j = 1; j < 10; j++){
            if (aluno.notas[i][j] == 0.0) break;
            printf("%.2f ", aluno.notas[i][j]);
        }
        printf("\n");
    }
    printf("Média Final: %.2f\n", aluno.mediaFinal);
}

void mostrarBoletimIndividual(Aluno aluno, int codigoTurma, int nAvaliacoes){
    
    int indiceNota = -1;

    for (int i = 0; i < 10; i++) {
        if ((int)aluno.notas[i][0] == codigoTurma) {
            indiceNota = i;
            break;
        }
    }

    if (indiceNota == -1) {
        printf("Nenhuma nota encontrada para a turma %d do aluno %s.\n", codigoTurma, aluno.nome);
        return;
    }

    printf("Boletim do aluno: %s (Matrícula: %d)\n", aluno.nome, aluno.matricula);
    for (int i = 1; i <= nAvaliacoes; i++) {
        printf("Avaliação %d: %.2f\n", i, aluno.notas[indiceNota][i]);
    }
    printf("Média Final: %.2f\n", aluno.mediaFinal);
}