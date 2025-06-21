

#ifndef REQUISITOS_FUNCIONAIS_H
#define REQUISITOS_FUNCIONAIS_H

#include<stdio.h>
#include "aluno.h"
#include "professor.h"
#include "turma.h"
       

//Função que soma todas as notas da turma
//Requisito funcional 1 : Permitir a soma total das notas de todos os alunos da turma
void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos){
    float soma = 0;
    for(int i = 0; i< 40;i++){
        int matricula = turma->listaDeAlunosInscritos[i];
        if(matricula==0)continue;

        for(int j=0;j<totalAlunos;j++){
            if (alunos[j].matricula == matricula) {
             for (int k = 0; k < turma->nA; k++) {
                    soma += alunos[j].notas[k];
                }
            break;
        }

    }
    
 }
    printf("Soma total dos alunos da turma : %.2f \n", soma);
}

//Função que soma a nota que cada aluno individualmente
//Requisito funcional 2 : Permitir a visualização da soma de notas por aluno
void somaNotasPorAluno(Turma *turma, Aluno alunos[], int totalAlunos){
    for(int i=0;i<40; i++){
        int matricula = turma->listaDeAlunosInscritos[i];
        if(matricula == 0) continue;

        for (int j = 0; j < totalAlunos; j++) {
            if(alunos[j].matricula == matricula){
                float soma = 0;
                for(int k = 0; k< turma->nA; k++){
                    soma += alunos[j].notas[k];

                }
                printf("Aluno: %s | Matrícula: %d | Soma das notas: %.2f\n",alunos[j].nome, alunos[j].matricula , soma);
                break ;
            }
          
        }
        
    }

}

//Função que soma as notas por avaliação (coluna da matriz de notas) 
//Requisito Funcional 3 : Calcular a soma das notas por avaliaçao aplicada
void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos){
    for(int a=0; a <turma->nA ; a++){
        float soma  = 0;
        for (int i = 0; i<40;i++){
            int matricula = turma->listaDeAlunosInscritos[i];
            if(matricula == 0)continue;

            for(int j = 0; j< totalAlunos; j++){
                if(alunos[j].matricula == matricula){
                    soma += alunos[j].notas[a];
                    break;
                }
            }
        }
        printf("Avaliação %d - Soma das notas : %.2f \n", a+1, soma);
    }
}

//Função que gera um relatório geral do aluno
//Requisito funcional 5 : Gerar um relatório geral de cada aluno
void gerarRelatorioGeralDoAluno(Aluno aluno){
    printf("Relatório do aluno : %s (Matricula : %d)\n", aluno.nome , aluno.matricula);
    printf("Notas : ");
    for(int i=0; i<10; i++){
        if(aluno.notas[i] == 0.0)break ;
        printf("%2.f", aluno.notas[i]);

    }
    printf("Média Final : %2.f \n", aluno.mediaFinal);
}
//Função que exibe o boletim individual do aluno 
//Requisito funcional 4 : Exibir o boletim invidualmente do aluno
void mostrarBoletimIndividual(Aluno aluno, int nAvaliacoes){
    printf("Boletim do aluno : %s (Matricula %d)\n", aluno.nome, aluno.matricula);
    for(int i = 0 ; i< nAvaliacoes ; i++){
        printf("Avaliação %d : %2.f \n", i+1 , aluno.notas[i];)
    }
    printf("Média Final : %2.f \n", aluno.mediaFinal);
}

#endif