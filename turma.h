
#define capacidadeDeTurmas 10
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

printf("|    TURMA:    %d             CODIGO DA TURMA: %d             CARGA HORÁRIA:    %d                                                      |");
printf("|    PROFESSOR: %s            CODIGO DA MATÉRIA: %d                                                                                     |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
printf("|                                                                                                                                       |");
int op;
do{
    printf("1- Lançar as Notas\n2 - Mostrar Boletim Inividual\n3 - Mostrar Boletim Geral\n4- Relatório Geral do Aluno");
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
