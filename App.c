#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"

int menu(){
    int op = 0;
 /*  do
  {
    code 
  } while ();*/
    
}
int main(){
    cadastrarAluno();
    listarAlunos();
    int matricula = 0;
    scanf("%d",&matricula);
    deletarAlunoPorMatricula(matricula);
    listarAlunos();

    cadastroDeProfessor();

    listarProfessores();
    return 0;
}
