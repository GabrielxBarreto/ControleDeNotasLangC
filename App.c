#include <stdio.h>
#include <locale.h>
#include <string.h>
#define  capacidadeProfBD 20
#define  quantMaterias 10
#define  capacidadeAlunoBD 40
typedef struct{
    int matricula;
    char nome[50];
    int materias[qtdmaterias];

} Aluno;

Aluno Repository_BD_Aluno[capacidadeAlunoBD];

//Função para o cadastro dos alunos
int cadastrarAluno(){
    Aluno aluno;
    int n;
    static int matricularef = 1000 ;

    printf("Digite o nome do aluno : \n");
    gets(aluno.nome);
    printf("Digite o número de matérias que o aluno cursa : \n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("DIgite o código da matéria :");
        scanf("%d", &aluno.materias[i]);



    }
    for(int i=0;i<capacidadeAlunoBD;i++){
        if(Repository_BD_Aluno[i].matricula == 0){
            aluno.matricula = matriculaRef;
            Repository_BD_Aluno[i] = aluno;
            matricularef++;
            printf("Aluno cadastrado com matrícula : %d", aluno.matricula);
            break;
        }


    }

    return 0;

}
//Função para a listagem dos alunos

 int listarAlunos(){
    printf("---------LISTA DE ALUNOS----------");
    for(int i=0;i < capacidadeAlunoBD;i++);{
        if(Repository_BD_Aluno[i].matricula != 0){
            printf("Matrícula %d | Nome : %d | Matérias: ", 
                Repository_BD_Aluno[i].matricula, Repository_BD_Aluno[i].nome);
       
                for(int j=0;j < quantMaterias; j++){
                    if (Repository_BD_Aluno[i].materias[j] != 0)
                    printf("%d", Repository_BD_Aluno[i].materias[j]);
                }
                printf("\n");
            }
    }
    return 0;
 }

 //Função para deletar o aluno através da matrícula

    int deletarAlunoPorMatricula(){
        for (int i = 0; i < capacidadeAlunoBD; i++){
            if (Repository_BD_Aluno[i].matricula == matricula){
                Repository_BD_Aluno[i].matricula = 0 ;
                Repository_BD_Aluno[i].nome = '\0';
                for (int j = 0; j < capacidadeAlunoBD ; j++)
                {
                    Repository_BD_Aluno[i].materias[j] = 0;
                }
                printf("Aluno com a matrícula %d deletado com sucesso !", matricula)
                break ;
                 }
            
            
               }  
               return 0;
            }
        
    }
typedef struct {
    int id; 
    char nome[20];
    char cpf[20];
    int materias[quantMaterias];

}Professor;

Professor Repository_BD_Professor[capacidadeProfBD]; 

int cadastroDeProfessor(){
    Professor professor;
    int n = 0;
    int static idRef = 100; 
    
    printf("Digite o nome do professor que Deseja cadastrar:\n");
    scanf(" %[^\n]", professor.nome);
    printf("Digite o CPF do professor que Deseja cadastrar:\n");
    scanf(" %[^\n]", professor.cpf);
    printf("Digite o número de trumas que o professor %s deve assumir assumir:\n",professor.nome);
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Digite o cóigo da turma:\n");
        scanf("%d",&professor.materias[i]);
    }

    for (int i = 0; i < capacidadeProfBD; i++){

        if(Repository_BD_Professor[i].cpf[0] == 0){
            professor.id = idRef;
            Repository_BD_Professor[i].id = professor.id; 
            strcpy(Repository_BD_Professor[i].nome,professor.nome);
            strcpy(Repository_BD_Professor[i].cpf,professor.cpf);

            for (int j = 0; j < n; j++){
                Repository_BD_Professor[i].materias[j] =professor.materias[j];
            }
            idRef++;
            break;
        }
    }
    
    return 0;
}
int listarProfessores(){
    
    for (int i = 0; i < capacidadeProfBD; i++){
        printf("ID:%d   |NOME:%s  |CPF:%s  |Código de Matérias:",Repository_BD_Professor[i].id,
        Repository_BD_Professor[i].nome,
        Repository_BD_Professor[i].cpf);
        for(int j = 0; j < capacidadeProfBD; j++){
             printf("%d|",Repository_BD_Professor[i].materias[j]);
        }
       printf("\n");
    }
    return 0;
}
int deletePorID(int id){
    
        for (int i = 0; i < capacidadeProfBD; i++){
            
            if(Repository_BD_Professor[i].id == id){
               
                Repository_BD_Professor[i].id = 0;
               
                for (int j = 0; j < quantMaterias; j++){
                    Repository_BD_Professor[i].materias[j] = 0;
                }
                
                Repository_BD_Professor[i].nome[0] = '\0';
                Repository_BD_Professor[i].cpf[0] = '\0';
                
            }
        
        

    }
    
    return 0;
}
int menu(){
    int op = 0;
 /*  do
  {
    code 
  } while ();*/
    
}
int main(){
    
    return 0;
}
