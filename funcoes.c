

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