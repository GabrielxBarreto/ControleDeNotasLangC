
#define capacidadeDeTurmas 2
typedef struct 
{
    int codigoDaTurma;
    int  Idprof;
    int listaDeAlunosInscritos[40];
    int codigoMateria;
    int cargaHoraria;
    
}Turma;


Turma Repository_BD_Turma[capacidadeDeTurmas]; 
static int codrefH = 456;
static int codrefT = 369;

int  abrirTurma(int id){

printf("|\t\tTURMA:\t%dCODIGO DA TURMA: %d\tCARGA HORÁRIA:    %d\t\t|\n");
printf("|\t\tPROFESSOR:\t%sCODIGO DA MATÉRIA: %d\t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
printf("|\t\t                                                   \t\t|\n");
int op;
do{
    printf("1- Lançar as Notas\n2 - Mostrar Boletim Inividual\n3 - Mostrar Boletim Geral\n4- Relatório Geral do Aluno");
    scanf("%d",&op);
    switch(op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("ERRO DE LEITURA");
            break;
    }   
}while(op);
}
int criarTurma(Professor p){
    
    for(int i = 0; i < capacidadeDeTurmas; i++){
        printf("Digite o numero de matricula de cada aluno:\n");
        scanf("%d",&Repository_BD_Turma[i].listaDeAlunosInscritos[i]);
        Repository_BD_Turma[i].codigoDaTurma = codrefT;
        Repository_BD_Turma[i].Idprof = p.id;

    }
    codrefT++;
    return 0;
}
