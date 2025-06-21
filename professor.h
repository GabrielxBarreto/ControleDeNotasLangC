#include <stdio.h>
#include <string.h>
#define  capacidadeProfBD 20
#define  capacidadeAlunoBD 20
typedef struct {
    int id; 
    char nome[50];
    char usuario[10];
    char cpf[20];
    char senha[20];
    int materias[quantMaterias];

}Professor;

Professor Repository_BD_Professor[capacidadeProfBD]; 

int cadastroDeProfessor(){
    Professor professor;
    int n = 0;
    static int idRef = 100; 
    
    printf("Digite o nome do professor que Deseja cadastrar:\n");
    scanf(" %[^\n]", professor.nome);
    printf("Digite o CPF do professor que Deseja cadastrar:\n");
    scanf(" %[^\n]", professor.cpf);
    printf("Digite seu Usuário:\n");
    scanf(" %[^\n]", professor.usuario);
     printf("Digite sua senha:\n");
    scanf(" %[^\n]", professor.senha);
    printf("\nDigite o número de trumas que o professor %s deve assumir inicialmente:\n",professor.nome);
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
            strcpy(Repository_BD_Professor[i].senha,professor.senha);
            strcpy(Repository_BD_Professor[i].usuario,professor.usuario);

            for (int j = 0; j < n; j++){
                Repository_BD_Professor[i].materias[j] = professor.materias[j];
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
int logar(char usuario[], char senha[]){
   
    int codeVerify = 0;
    for(int i = 0; i < capacidadeProfBD; i++){ 
      if((strcmp(Repository_BD_Professor[i].usuario,usuario)==0 && strcmp(Repository_BD_Professor[i].senha,senha) == 0) == 1){
        codeVerify = Repository_BD_Professor[i].id;
        break;
      }else{
        codeVerify = -1;
      }
    }
   return codeVerify;
}