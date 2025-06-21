#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "turma.h"

// Função que soma todas as notas da turma
// Requisito funcional 1 : Permitir a soma total das notas de todos os alunos da turma
void somaTotalNotas(Turma *turma, Aluno alunos[], int totalAlunos);

// Função que soma a nota que cada aluno tem individualmente
// Requisito funcional 2 : Permitir a visualização da soma de notas por aluno
void somaNotasPorAluno(Turma *turma, Aluno alunos[], int totalAlunos);

// Função que soma as notas por avaliação (coluna da matriz de notas) 
// Requisito Funcional 3 : Calcular a soma das notas por avaliação aplicada
void somaNotasPorAvaliacao(Turma *turma, Aluno alunos[], int totalAlunos);

// Função que gera um relatório geral do aluno
// Requisito funcional 4 : Gerar um relatório geral de cada aluno
void gerarRelatorioGeralDoAluno(Aluno aluno);

// Função que exibe o boletim individual do aluno 
// Requisito funcional 4 : Exibir o boletim individual do aluno
void mostrarBoletimIndividual(Aluno aluno, int nAvaliacoes);

#endif
