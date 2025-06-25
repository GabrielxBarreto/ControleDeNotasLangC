#ifndef ALUNO_H
#define ALUNO_H

#define capacidadeDeTurmas 10

#include <stdio.h>
#include <string.h>
#define  capacidadeProfBD 20
#define  quantMaterias 10
#define  capacidadeAlunoBD 20

typedef struct{

    int matricula;
    char nome[50];
    int materias[quantMaterias];
    //a primeira coluna guarda o valor do código da turma e o resto guarda o seu conteudo de notas
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
    /*printf("Digite o número de matérias que o aluno cursa : \n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("DIgite o código da matéria :");
        scanf("%d", &aluno.materias[i]);



    }*/
    for(int i=0;i<capacidadeAlunoBD;i++){
        if(Repository_BD_Aluno[i].matricula == 0){
            aluno.matricula = matriculaRef;
            strcpy(Repository_BD_Aluno[i].nome,aluno.nome);
            Repository_BD_Aluno[i].matricula = aluno.matricula;
            matriculaRef++;
            printf("Aluno cadastrado com matrícula : %d", aluno.matricula);
            break;
        }


    }

    return 0;

}
//Função para a listagem dos alunos

 int listarAlunos(){
    printf("\n---------LISTA DE ALUNOS----------\n");
    for(int i = 0;i < capacidadeAlunoBD;i++){
        
        if(Repository_BD_Aluno[i].matricula != 0){
            printf("Matrícula %d | Nome : %s | Matérias: ", 
                Repository_BD_Aluno[i].matricula, Repository_BD_Aluno[i].nome);
       
                for(int j=0;j < quantMaterias; j++){
                    if (Repository_BD_Aluno[i].materias[j] != 0){
                        printf("%d|", Repository_BD_Aluno[i].materias[j]);
                    }
                }
                printf("\n");
        }
    }
    return 0;
 }

 //Função para deletar o aluno através da matrícula

    int deletarAlunoPorMatricula(int matricula){
        for (int i = 0; i < capacidadeAlunoBD; i++){
            if (Repository_BD_Aluno[i].matricula == matricula){
                Repository_BD_Aluno[i].matricula = 0;
                Repository_BD_Aluno[i].nome[0] = '\0';
                for (int j = 0; j < capacidadeAlunoBD ; j++){
                    Repository_BD_Aluno[i].materias[j] = 0;
                }
                printf("Aluno com a matrícula %d deletado com sucesso !", matricula);
                break ;
            }
            
            
               }  
               return 0;
            }
        #endif