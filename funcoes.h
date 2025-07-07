#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "turma.h"

// Apenas os prot�tipos:
void mostrarBoletimIndividual(Aluno aluno, int codigoTurma, int nAvaliacoes);
void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos);
void somaNotasPorAluno(Turma *turma, Aluno alunos[], int totalAlunos);
void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos);
void gerarRelatorioGeralDoAluno(Aluno aluno);


#endif  // FUNCOES_H

// ========================= IMPLEMENTA��ES =============================

void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos){
    float soma = 0;
    int totalNotas = 0;
    float media =0;
    for(int i = 0; i < 40; i++){
        int matricula = turma->listaDeAlunosInscritos[i];
        if(matricula == 0) continue;

        for(int j = 0; j < totalAlunos; j++){
            if (alunos[j].matricula == matricula) {
                for (int k = 0; k < turma->nA; k++) {
                    for (int l = 0; l < 10; l++) {
                        if ((int)alunos[j].notas[l][0] == turma->codigoDaTurma) {
                            soma += alunos[j].notas[l][k+1];
                            totalNotas++;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
     if(totalNotas > 0){
        media = soma / totalNotas;
        printf("Soma total das notas da turma: %.2f\n", soma);
        printf("A m�dia total de todos os alunos da turma �: %.2f\n", media);
        
        if (media >= 6){
            printf("\033[0;32mA m�dia da turma � de aprovados!\033[0m\n");
        }
        else {
            printf("\033[0;31mA m�dia da turma � de reprovados!\033[0m\n");
        }
    } else {
        printf("\033[0;31mNenhuma nota encontrada para calcular!!!!\033[0m\n");
    }
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
                float media = 0.00;
                media += soma / turma->nA;
                printf("Aluno:\t%s\t | Matr�cula:\t%d | Soma das notas:\t%.2f | M�dia :\t%.2f | Situa��o:\t%s \n", 
                    alunos[j].nome,
                    alunos[j].matricula,
                    soma,
                    media,
                (media>=6 ? "\033[0;32mAprovado\033[0m" : "\033[0;31mReprovado\033[0m"));
                break;
            }
        }
    }
}

void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos){
    for(int a = 0; a < turma->nA; a++){
        float soma = 0;
        int totalNotas = 0;

        for(int i = 0; i < 40; i++){
            int matricula = turma->listaDeAlunosInscritos[i];
            if(matricula == 0) continue;

            for(int j = 0; j < totalAlunos; j++){
                if(alunos[j].matricula == matricula){
                    for(int l = 0; l < 10; l++) {
                        if ((int)alunos[j].notas[l][0] == turma->codigoDaTurma) {
                            soma += alunos[j].notas[l][a+1];
                            totalNotas++;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        if(totalNotas == 0){
            printf("Avalia��o %d - Nenhuma nota dispon�vel.\n", a+1);
            continue;
        }

        float media = soma / totalNotas;

        int acimaOuIgual =0;
        int abaixo = 0 ;
        
        for(int i =0;i<40; i++){
            int matricula = turma->listaDeAlunosInscritos[i];
            if( matricula == 0) continue;

            for (int j = 0;j< totalAlunos;j++){
                if(alunos[j].matricula == matricula){
                    for(int l= 0;l<10;l++){
                        if((int)alunos[j].notas[l][0]== turma->codigoDaTurma){
                            float nota = alunos[j].notas[l][a+1];
                            if(nota >= media) acimaOuIgual++;
                            else abaixo++;
                            break;
                        }
                    }
                    break;
                }
            }
            }
            printf("Avalia��o %d - Soma das notas: %.2f | M�dia: %.2f \n",a+1, soma, media ); 
        if(acimaOuIgual > abaixo){
             printf("\033[0;32mA maioria da turma est� na m�dia !\033[0m\n");
        }else if (abaixo>acimaOuIgual){
            printf("\033[0;31mA maioria da turma est� abaixo da m�dia.\033[0m\n");
        }
           
        }
        
        
    }


void gerarRelatorioGeralDoAluno(Aluno aluno){
   
    printf("Relat�rio do aluno: %s (Matr�cula: %d)\n", aluno.nome, aluno.matricula);
    for(int i = 0; i < 10; i++){
        if (aluno.notas[i][0] == 0) continue;

        printf("Turma %d - Notas: ", (int)aluno.notas[i][0]);
        for(int j = 1; j < 10; j++){
            if (aluno.notas[i][j] == 0.0) break;
            printf("%.2f ", aluno.notas[i][j]);
        }
        printf("\n");
    }
    printf("M�dia Final: %.2f\n", aluno.mediaFinal);
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
        printf(printf("\033[0;31mNenhuma nota encontrada para a turma %d do aluno %s \033[0m\n"), codigoTurma, aluno.nome);
        return;
    }

    printf("Boletim do aluno: %s (Matr�cula: %d)\n", aluno.nome, aluno.matricula);
    for (int i = 1; i <= nAvaliacoes; i++) {
        printf("Avalia��o %d: %.2f\n", i, aluno.notas[indiceNota][i]);
    }
    printf("M�dia Final: %.2f\n", aluno.mediaFinal);
}