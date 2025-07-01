#ifndef ALUNO_H
#define ALUNO_H

#define capacidadeDeTurmas 10

#include <stdio.h>
#include <string.h>
#define  capacidadeProfBD 20
#define  quantMaterias 5
#define  capacidadeAlunoBD 20

typedef struct{

    int matricula;
    char nome[50];
    int materias[quantMaterias];
    //a primeira coluna guarda o valor do c�digo da turma e o resto guarda o seu conteudo de notas
    float notas[10][10];
    float mediaFinal;
    //Relacionamento com o BD
    int turmasInscritos[capacidadeDeTurmas];

} Aluno;

Aluno Repository_BD_Aluno[capacidadeAlunoBD];

int cadastrarAluno(){
    Aluno aluno;
    //int n;
    static int  matriculaRef = 1000 ;

    printf("Digite o nome do aluno : \n");
    scanf(" %[^\n]", aluno.nome);
    /*printf("Digite o n�mero de mat�rias que o aluno cursa : \n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("DIgite o c�digo da mat�ria :");
        scanf("%d", &aluno.materias[i]);



    }*/
    for(int i=0;i<capacidadeAlunoBD;i++){
        if(Repository_BD_Aluno[i].matricula == 0){
            aluno.matricula = matriculaRef;
            strcpy(Repository_BD_Aluno[i].nome,aluno.nome);
            Repository_BD_Aluno[i].matricula = aluno.matricula;
            matriculaRef++;
            printf("Aluno cadastrado com matr�cula : %d", aluno.matricula);
            break;
        }


    }

    return 0;

}
//Fun��o para a listagem dos alunos

 int listarAlunos(){
    printf("\n---------LISTA DE ALUNOS CADASTRADOS NO SISTEMA----------\n");
    for(int i = 0;i < capacidadeAlunoBD;i++){
        
        if(Repository_BD_Aluno[i].matricula != 0){
            printf("Matr�cula %d | Nome : %s", 
                Repository_BD_Aluno[i].matricula, Repository_BD_Aluno[i].nome);
                printf("\n");
        }
    }
    return 0;
 }

 //Fun��o para deletar o aluno atrav�s da matr�cula

    int deletarAlunoPorMatricula(int matricula){
        for (int i = 0; i < capacidadeAlunoBD; i++){
            if (Repository_BD_Aluno[i].matricula == matricula){
                Repository_BD_Aluno[i].matricula = 0;
                Repository_BD_Aluno[i].nome[0] = '\0';
                for (int j = 0; j < capacidadeAlunoBD ; j++){
                    Repository_BD_Aluno[i].materias[j] = 0;
                }
                printf("Aluno com a matr�cula %d deletado com sucesso !", matricula);
                break ;
            }
            
            
               }  
               return 0;
            }
        #endif