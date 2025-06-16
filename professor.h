#include <stdio.h>
#include <string.h>
#define  capacidadeProfBD 20
#define  quantMaterias 10
#define  capacidadeAlunoBD 20
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
    if(Repository_BD_Professor[i].id != 0){
        printf("ID:%d   |NOME:%s  |CPF:%s  |Código de Matérias:",Repository_BD_Professor[i].id,
        Repository_BD_Professor[i].nome,
        Repository_BD_Professor[i].cpf);
        for(int j = 0; j < capacidadeProfBD; j++){
             printf("%d|",Repository_BD_Professor[i].materias[j]);
        }
       printf("\n");
    }
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