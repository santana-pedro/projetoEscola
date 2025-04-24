#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  
#define MAX_STR 255
#define MAX 250
#define TRUE -1
#define FALSE -2

int opcaoPrincipal, opcaoSecundaria, sair = 0, indiceAluno = 0, indiceProfessor = 0, indiceDisciplina = 0;

typedef struct dma{
    int dia, mes, ano;
}Data;

typedef struct Pessoa{
    char tipo; //m = matricula ; s = sexo ; n = nome ; c = cpf ; d = dataNascimento ; e = excluir ; i = disciplina
    char nome[MAX_STR];
    char sexo[MAX_STR];
    int disciplinas[MAX];
    int qtdDisciplinas;
    int matricula;
    char cpf[MAX_STR];
    Data dataNascimento;

    int excluir;
}Pessoa;
typedef struct Disciplina{
    char tipo; //n = nomeDisciplina ; s = semestre ; p = nomeProfessor ; c = codigo ; e = excluir
    char nomeDisciplina[MAX_STR];
    int codigo;
    int semestre;
    char nomeProfessor[MAX_STR];
    int qtdAlunos;

    int excluir;
}Disciplina;

Pessoa aluno[MAX];
Pessoa professor[MAX];
Disciplina disciplina[MAX];

//VALIDACOES

int validarCpfAluno(){
    int achouProfessor = FALSE, achouAluno = FALSE;
    if(indiceProfessor > 1){
        for(int cont = 0; cont < indiceProfessor; cont++){
            if(professor[cont].tipo == 'c' && aluno[indiceAluno].tipo == 'c' && strcmp(professor[cont].cpf, aluno[indiceAluno].cpf) == 0){
                achouProfessor = TRUE;
                printf("Cpf já existente, inválido \n");
                break;
            }
        }
    }
    if(achouProfessor == FALSE && indiceAluno > 4){
        for(int cont = 0; cont < indiceAluno; cont++){
            if(aluno[cont].tipo == 'c' && aluno[indiceAluno].tipo == 'c' && strcmp(aluno[cont].cpf, aluno[indiceAluno].cpf) == 0){
                achouAluno = TRUE;
                printf("Cpf já existente, inválido \n");
                break;
            }
        }
    }
    if(achouProfessor == TRUE || achouAluno == TRUE){
        return TRUE;
    }else if(achouProfessor == FALSE && achouAluno == FALSE){
        return FALSE;
    } 
}

int validarCpfProfessor(){
    int achouProfessor = FALSE, achouAluno = FALSE;
    if(indiceProfessor > 4){
        for(int cont = 0; cont < indiceProfessor; cont++){
            if(professor[cont].tipo == 'c' && professor[indiceProfessor].tipo == 'c' && strcmp(professor[cont].cpf, professor[indiceProfessor].cpf) == 0){
                achouProfessor = TRUE;
                printf("Cpf já existente, inválido \n");
                break;
            }
        }
    }
    if(achouProfessor == FALSE && indiceAluno > 1){
        for(int cont = 0; cont < indiceAluno; cont++){
            if(aluno[cont].tipo == 'c' && professor[indiceProfessor].tipo == 'c' && strcmp(aluno[cont].cpf, professor[indiceProfessor].cpf) == 0){
                achouAluno = TRUE;
                printf("Cpf já existente, inválido \n");
                break;
            }
        }
    }
    if(achouProfessor == TRUE || achouAluno == TRUE){
        return TRUE;
    }else if(achouProfessor == FALSE && achouAluno == FALSE){
        return FALSE;
    } 
}

int validarMatriculaAluno(){
    int achouProfessor = FALSE, achouAluno = FALSE;
    if(indiceProfessor > 1){
        for(int cont = 0; cont < indiceProfessor; cont++){
            if(professor[cont].tipo == 'm' && aluno[indiceAluno].tipo == 'm' && professor[cont].matricula == aluno[indiceAluno].matricula){
                achouProfessor = TRUE;
                printf("Matrícula já existente, inválida \n");
                break;
            }
        }
    }
    if(achouProfessor == FALSE && indiceAluno > 4){
        for(int cont = 0; cont < indiceAluno; cont++){
            if(aluno[cont].tipo == 'm' && aluno[indiceAluno].tipo == 'm' && aluno[cont].matricula == aluno[indiceAluno].matricula){
                achouAluno = TRUE;
                printf("Matrícula já existente, inválida \n");
                break;
            }
        }
    }
    if(achouProfessor == TRUE || achouAluno == TRUE){
        return TRUE;
    }else if(achouProfessor == FALSE && achouAluno == FALSE){
        return FALSE;
    } 
}

int validarMatriculaProfessor(){
    int achouProfessor = FALSE, achouAluno = FALSE;
    if(indiceProfessor > 4){
        for(int cont = 0; cont < indiceProfessor; cont++){
            if(professor[cont].tipo == 'm' && professor[indiceProfessor].tipo == 'm' && professor[cont].matricula == professor[indiceProfessor].matricula){
                achouProfessor = TRUE;
                printf("Matrícula já existente, inválida \n");
                break;
            }
        }
    }
    if(achouProfessor == FALSE && indiceAluno > 1){
        for(int cont = 0; cont < indiceAluno; cont++){
            if(aluno[cont].tipo == 'm' && professor[indiceProfessor].tipo == 'm' && aluno[cont].matricula == professor[indiceProfessor].matricula){
                achouAluno = TRUE;
                printf("Matrícula já existente, inválida \n");
                break;
            }
        }
    }
    if(achouProfessor == TRUE || achouAluno == TRUE){
        return TRUE;
    }else if(achouProfessor == FALSE && achouAluno == FALSE){
        return FALSE;
    } 
}

int validarCodigoDisciplina(){
    int achouDisciplina = FALSE;
    if(indiceDisciplina > 1){
        for(int cont = 0;  cont < indiceDisciplina; cont++){
            if(disciplina[cont].tipo == 'c' && disciplina[indiceDisciplina].tipo == 'c' && disciplina[cont].codigo == disciplina[indiceDisciplina].codigo){
                achouDisciplina = TRUE;
                printf("Código já existente, inválido \n");
                break;
            }
        }
    }
    if(achouDisciplina == TRUE){
        return TRUE;
    }else if(achouDisciplina == FALSE){
        return FALSE;
    }
}

int validarNomeDisciplina(){
    int achouDisciplina = FALSE;
    if(indiceDisciplina > 2){
        for(int cont = 0; cont < indiceDisciplina; cont++){
            if(disciplina[cont].tipo == 'n' && disciplina[indiceDisciplina].tipo == 'n' && strcmp(disciplina[cont].nomeDisciplina, disciplina[indiceDisciplina].nomeDisciplina) == 0){
                achouDisciplina = TRUE;
                printf("Nome de disciplina já existente, inválido \n");
                break;
            }
        }
    }
    if(achouDisciplina == TRUE){
        return TRUE;
    }else if(achouDisciplina == FALSE){
        return FALSE;
    }
}

//TROCA SEM NOME ALUNO
void fazerTrocaAluno(int cont, int cont2){
    int trocaM;
    char trocaS[MAX_STR], trocaC[MAX_STR];
    //MATRICULA
    trocaM = aluno[cont2 - 4].matricula;
    aluno[cont2 - 4].matricula = aluno[cont - 4].matricula;
    aluno[cont - 4].matricula = trocaM;
    //CPF
    strcpy(trocaC, aluno[cont - 3].cpf);
    strcpy(aluno[cont - 3].cpf, aluno[cont2 - 3].cpf);
    strcpy(aluno[cont2 - 3].cpf, trocaC);
    //SEXO
    strcpy(trocaS, aluno[cont - 1].sexo);
    strcpy(aluno[cont - 1].sexo, aluno[cont2 - 1].sexo);
    strcpy(aluno[cont2 - 1].sexo, trocaS);
}
//TROCA SÓ DATA ALUNO
void fazerTrocaDataAluno(int cont, int cont2){
    Data trocaD;
    //DATA DIA
    trocaD.dia = aluno[cont2 - 2].dataNascimento.dia;
    aluno[cont2 - 2].dataNascimento.dia = aluno[cont - 2].dataNascimento.dia;
    aluno[cont - 2].dataNascimento.dia = trocaD.dia;
    //DATA MES
    trocaD.mes = aluno[cont2 - 2].dataNascimento.mes;
    aluno[cont2 - 2].dataNascimento.mes = aluno[cont - 2].dataNascimento.mes;
    aluno[cont - 2].dataNascimento.mes = trocaD.mes;
    //DATA ANO
    trocaD.ano = aluno[cont2 - 2].dataNascimento.ano;
    aluno[cont2 - 2].dataNascimento.ano = aluno[cont - 2].dataNascimento.ano;
    aluno[cont - 2].dataNascimento.ano = trocaD.ano;
}
//TROCA COM NOME ALUNO
void trocaNomeAluno(int cont, int  cont2){
    char trocaN[MAX_STR];
    if(aluno[cont].tipo == 's' && aluno[cont2].tipo == 'n' && strcmp(aluno[cont].nome, aluno[cont2].nome) > 0) {
        strcpy(trocaN, aluno[cont].nome);
        strcpy(aluno[cont].nome, aluno[cont2].nome);
        strcpy(aluno[cont2].nome, trocaN);
        fazerTrocaAluno(cont, cont2);
        fazerTrocaDataAluno(cont, cont2);
    }
}
//TROCA SEM NOME PROFESSOR
void fazerTrocaProfessor(int cont, int cont2){
    int trocaM;
    char trocaS[MAX_STR], trocaC[MAX_STR];
    //MATRICULA
    trocaM = professor[cont2 - 4].matricula;
    professor[cont2 - 4].matricula = professor[cont - 4].matricula;
    professor[cont - 4].matricula = trocaM;
    //CPF
    strcpy(trocaC, professor[cont - 3].cpf);
    strcpy(professor[cont - 3].cpf, professor[cont2 - 3].cpf);
    strcpy(professor[cont2 - 3].cpf, trocaC);
    //SEXO
    strcpy(trocaS, professor[cont - 1].sexo);
    strcpy(professor[cont - 1].sexo, professor[cont2 - 1].sexo);
    strcpy(professor[cont2 - 1].sexo, trocaS);
}
//TROCA SÓ DATA PROFESSOR
void fazerTrocaDataProfessor(int cont, int cont2){
    Data trocaD;
    //DATA DIA
    trocaD.dia = professor[cont2 - 2].dataNascimento.dia;
    professor[cont2 - 2].dataNascimento.dia = professor[cont - 2].dataNascimento.dia;
    professor[cont - 2].dataNascimento.dia = trocaD.dia;
    //DATA MES
    trocaD.mes = professor[cont2 - 2].dataNascimento.mes;
    professor[cont2 - 2].dataNascimento.mes = professor[cont - 2].dataNascimento.mes;
    professor[cont - 2].dataNascimento.mes = trocaD.mes;
    //DATA ANO
    trocaD.ano = professor[cont2 - 2].dataNascimento.ano;
    professor[cont2 - 2].dataNascimento.ano = professor[cont - 2].dataNascimento.ano;
    professor[cont - 2].dataNascimento.ano = trocaD.ano;
}
//TROCA COM NOME PROFESSOR
void trocaNomeProfessor(int cont, int  cont2){
    char trocaN[MAX_STR];
    if(professor[cont].tipo == 's' && professor[cont2].tipo == 'n' && strcmp(professor[cont].nome, professor[cont2].nome) > 0) {
        strcpy(trocaN, professor[cont].nome);
        strcpy(professor[cont].nome, professor[cont2].nome);
        strcpy(professor[cont2].nome, trocaN);
        fazerTrocaProfessor(cont, cont2);
        fazerTrocaDataProfessor(cont, cont2);
    }
}

void cadastroAluno(){
    printf("##CADASTRO ALUNO## \n");
    //MATRICULA
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe a matricula do aluno: ");
    scanf("%d%*c" ,&aluno[indiceAluno].matricula);
    if(aluno[indiceAluno].matricula < 0){
        printf("Matrícula inválida \n");
        return;
    }
    aluno[indiceAluno].tipo = 'm';
    if(validarMatriculaAluno() == TRUE){
        return;
    }
    indiceAluno++;
    //CPF
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe o cpf (apenas numeros) do aluno: ");
    fgets(aluno[indiceAluno].cpf, MAX_STR, stdin);
    aluno[indiceAluno].cpf[strcspn(aluno[indiceAluno].cpf, "\n")] = '\0';
    aluno[indiceAluno].tipo = 'c';
    if(validarCpfAluno() == TRUE){
        indiceAluno -= 1;
        return;
    }
    indiceAluno++;
    //DATA NASCIMENTO
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe a data de nascimento(apenas numeros espaçados: xx xx xxxx) do aluno: ");
    scanf("%d %d %d%*c" ,&aluno[indiceAluno].dataNascimento.dia ,&aluno[indiceAluno].dataNascimento.mes ,&aluno[indiceAluno].dataNascimento.ano);
    if(aluno[indiceAluno].dataNascimento.dia < 1 || aluno[indiceAluno].dataNascimento.dia > 31 || aluno[indiceAluno].dataNascimento.mes < 1 || aluno[indiceAluno].dataNascimento.mes > 12 || aluno[indiceAluno].dataNascimento.ano < 1 || aluno[indiceAluno].dataNascimento.ano > 2025){
        printf("Data de nascimento inválida \n");
        indiceAluno -= 2;
        return;
    }
    aluno[indiceAluno].tipo = 'd';
    indiceAluno++;
    //SEXO
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe o sexo do aluno: ");
    fgets(aluno[indiceAluno].sexo, MAX_STR, stdin);
    aluno[indiceAluno].sexo[strcspn(aluno[indiceAluno].sexo, "\n")] = '\0';
    if(aluno[indiceAluno].sexo[0] == 'M' || aluno[indiceAluno].sexo[0] == 'm'){
        strcpy(aluno[indiceAluno].sexo, "mulher");
        aluno[indiceAluno].tipo = 's';
        indiceAluno++;
    }
    else if(aluno[indiceAluno].sexo[0] == 'H' || aluno[indiceAluno].sexo[0] == 'h'){
        strcpy(aluno[indiceAluno].sexo, "homem");
        aluno[indiceAluno].tipo = 's';
        indiceAluno++;
    }
    else{
        printf("Sexo inválido (Homem ou Mulher) \n");
        indiceAluno -= 3;
        return;
    }
    //NOME
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe o nome do aluno: ");
    fgets(aluno[indiceAluno].nome, MAX_STR, stdin);
    aluno[indiceAluno].nome[strcspn(aluno[indiceAluno].nome, "\n")] = '\0';
    aluno[indiceAluno].tipo = 'n';
    aluno[indiceAluno - 4].qtdDisciplinas = 0;
    indiceAluno++;
    printf("##CADASTRO DE ALUNO REALIZADO!!## \n");
}

void excluirAluno(){
    int achouAluno = FALSE;
    printf("##EXCLUIR ALUNO## \n");
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para excluir \n");
        return;
    }
    printf("INDICE ALUNO: %d\n", indiceAluno);
    printf("Informe a matrícula do aluno para exclusão: ");
    scanf("%d%*c" ,&aluno[indiceAluno].excluir);
    if(aluno[indiceAluno].excluir < 0){
        printf("Matrícula inválida \n");
        return;
    }
    aluno[indiceAluno].tipo = 'e';
    indiceAluno++;
    printf("INDICE ALUNO: %d\n", indiceAluno);
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm' && aluno[cont].matricula == aluno[indiceAluno - 1].excluir){
            achouAluno = TRUE;
            for(int cont2 = cont; cont2 < indiceAluno; cont2++){
                aluno[cont2].matricula = aluno[cont2 + 5].matricula;
                strcpy(aluno[cont2 + 1].cpf, aluno[cont2 + 6].cpf);
                aluno[cont2 + 2].dataNascimento.dia = aluno[cont2 + 7].dataNascimento.dia;
                aluno[cont2 + 2].dataNascimento.mes = aluno[cont2 + 7].dataNascimento.mes;
                aluno[cont2 + 2].dataNascimento.ano = aluno[cont2 + 7].dataNascimento.ano;
                strcpy(aluno[cont2 + 3].sexo, aluno[cont2 + 8].sexo);
                strcpy(aluno[cont2 + 4].nome, aluno[cont2 + 9].nome);
                aluno[cont2 + 5].excluir = aluno[cont2 + 10].excluir;
            }
            indiceAluno -= 6;
            printf("INDICE ALUNO: %d\n", indiceAluno);
            printf("##EXCLUSÃO DE ALUNO REALIZADO!!## \n");
            break;
        }
    }
    if(achouAluno == FALSE){
        printf("Matrícula aluno inexistente \n");
        indiceAluno--;
        printf("INDICE ALUNO: %d\n", indiceAluno);
        return;
    }
}

void atualizarAluno(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para atualizar \n");
        return;
    }
    int alunoAtualizar, achouAluno = FALSE;
    printf("##ATUALIZAR ALUNO## \n");
    printf("Informe a matrícula do aluno que deseja atualizar: ");
    scanf("%d%*c" ,&alunoAtualizar);
    if(alunoAtualizar < 0){
        printf("Mátricula inválida \n");
        return;
    }
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm' && aluno[cont].matricula == alunoAtualizar){
            achouAluno = TRUE;
            printf("--CASO NÃO QUEIRA ALTERAR ALGUM DOS ITENS, BASTA REPETI-LO--\n");
            //MATRICULA
            printf("Informe a matricula: ");
            scanf("%d%*c" ,&aluno[cont].matricula);
            //CPF
            printf("Informe o cpf (apenas numeros) do aluno: ");
            fgets(aluno[cont + 1].cpf, MAX_STR, stdin);
            aluno[cont + 1].cpf[strcspn(aluno[cont + 1].cpf, "\n")] = '\0';
            //DATA DE NASCIMENTO
            printf("Informe a data de nascimento(apenas numeros espaçados: xx xx xxxx) do aluno: ");
            scanf("%d %d %d%*c" ,&aluno[cont + 2].dataNascimento.dia ,&aluno[cont + 2].dataNascimento.mes ,&aluno[cont + 2].dataNascimento.ano);
            //SEXO
            printf("Informe o sexo do aluno: ");
            fgets(aluno[cont + 3].sexo, MAX_STR, stdin);
            aluno[cont + 3].sexo[strcspn(aluno[cont + 3].sexo, "\n")] = '\0';
            //NOME
            printf("Informe o nome do aluno: ");
            fgets(aluno[cont + 4].nome, MAX_STR, stdin);
            aluno[cont + 4].nome[strcspn(aluno[cont + 4].nome, "\n")] = '\0';
            printf("##ALUNO ATUALIZADO!!## \n");
            break;
        }
    }
    if(achouAluno == FALSE){
        printf("Mátricula aluno inexistente \n");
        return;
    }
}

void listarAlunos(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para listar \n");
        return;
    }
    printf("##LISTAR ALUNOS## \n");
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm'){
            printf("Aluno: %s, matrícula: %d, cpf: %s, sexo: %s, data de nascimento: %d/%d/%d \n" ,aluno[cont + 4].nome, aluno[cont].matricula, aluno[cont + 1].cpf, aluno[cont + 3].sexo, aluno[cont + 2].dataNascimento.dia, aluno[cont + 2].dataNascimento.mes, aluno[cont + 2].dataNascimento.ano);
        }
    }
}

void listarAlunosSexo(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para listar \n");
        return;
    }
    char buscarSexo[MAX_STR], achouAluno = FALSE;
    printf("##LISTAR ALUNOS POR SEXO## \n");
    printf("Informe o sexo que deseja procurar: ");
    fgets(buscarSexo, MAX_STR, stdin);
    buscarSexo[strcspn(buscarSexo, "\n")] = '\0';
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 's' && strcmp(aluno[cont].sexo, buscarSexo) == 0){
            achouAluno = TRUE;
            printf("Aluno: %s, sexo: %s \n", aluno[cont + 1].nome, aluno[cont].sexo);
        }
    }
    if(achouAluno == FALSE){
        printf("Nenhum aluno com o sexo: %s", buscarSexo);
        return;
    }
}

void listarAlunosNome(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para listar \n");
        return;
    }
    char trocaN[MAX_STR];
    printf("##LISTAR ALUNOS ORDENADO POR NOME## \n");
    for (int cont = 0; cont < indiceAluno; cont++) {
        for (int cont2 = cont + 1; cont2 < indiceAluno; cont2++){
            if(aluno[cont].tipo == 's' && aluno[cont2].tipo == 'n' && strcmp(aluno[cont].nome, aluno[cont2].nome) > 0) {
                strcpy(trocaN, aluno[cont].nome);
                strcpy(aluno[cont].nome, aluno[cont2].nome);
                strcpy(aluno[cont2].nome, trocaN);
                fazerTrocaAluno(cont, cont2);
                fazerTrocaDataAluno(cont, cont2);
            }
        }
    }
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'n'){
            printf("Aluno: %s\n", aluno[cont].nome);
        }
    }
}

void listarAlunosDma(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para listar \n");
        return;
    }
    printf("##LISTAR ALUNOS POR DATA DE NASCIMENTO## \n");
    //ANO MAIS VELHO
    for(int cont = 0; cont < indiceAluno; cont++){
        for(int cont2 = cont + 1; cont2 < indiceAluno; cont2++){
            if(aluno[cont].tipo == 'n' && aluno[cont - 2].dataNascimento.ano > aluno[cont2 - 2].dataNascimento.ano){
                trocaNomeAluno(cont, cont2);
            }
        }
    }
    //MES MAIS VELHO
    for(int cont = 0; cont < indiceAluno; cont++){
        for(int cont2 = cont + 1; cont2 < indiceAluno; cont2++){
            if(aluno[cont].tipo == 'n' && aluno[cont - 2].dataNascimento.mes > aluno[cont2 - 2].dataNascimento.mes && aluno[cont - 2].dataNascimento.ano == aluno[cont2 - 2].dataNascimento.ano){
                trocaNomeAluno(cont, cont2);
            }
        }
    }
    //DIA MAIS VELHO
    for(int cont = 0; cont < indiceAluno; cont++){
        for(int cont2 = cont + 1; cont2 < indiceAluno; cont2++){
            if(aluno[cont].tipo == 'n' && aluno[cont - 2].dataNascimento.dia > aluno[cont2 - 2].dataNascimento.dia && aluno[cont - 2].dataNascimento.mes == aluno[cont2 - 2].dataNascimento.mes && aluno[cont - 2].dataNascimento.ano == aluno[cont2 - 2].dataNascimento.ano){
                trocaNomeAluno(cont, cont2);
            }
        }
    }
    //IMPRIMIR LISTA
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'n'){
            printf("Aluno: %s, Data de nascimento: %d/%d/%d \n", aluno[cont].nome, aluno[cont - 2].dataNascimento.dia, aluno[cont - 2].dataNascimento.mes, aluno[cont - 2].dataNascimento.ano);
        }
    }
}

void listarAlunosDisciplina(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para listar \n");
        return;
    }
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm' && aluno[cont].qtdDisciplinas < 3){
            printf("Aluno: %s, matricula: %d, matriculado em %d disciplinas \n", aluno[cont + 4].nome, aluno[cont].matricula, aluno[cont].qtdDisciplinas);
        }
    }
}
//MENU ALUNO
void menuAluno(int voltar){
    while(voltar == 0){
        printf("##MENU ALUNO## \n");
        printf("1 - Cadastrar aluno \n");
        printf("2 - Excluir aluno \n");
        printf("3 - Atualizar aluno \n");
        printf("4 - Listar alunos \n");
        printf("5 - Listar alunos por sexo \n");
        printf("6 - Listar alunos ordernados por nome \n");
        printf("7 - Listar alunos ordernados por data de nascimento \n");
        printf("8 - Listar alunos matriculados em menos de 3 disciplinas \n");
        printf("0 - Voltar \n");
        scanf("%d%*c" ,&opcaoSecundaria);
        switch(opcaoSecundaria){
            //CADASTRO ALUNO
            case 1:{
                cadastroAluno();
                break;
            }
            //EXCLUIR ALUNO
            case 2:{
                excluirAluno();
                break;
            }
            //ATUALIZAR ALUNO
            case 3:{
                atualizarAluno();
                break;
            }
            //LISTAR ALUNOS
            case 4:{
                listarAlunos();
                break;
            }  
            //LISTAR ALUNOS POR SEXO
            case 5:{
                listarAlunosSexo();
                break;
            } 
            //LISTAR ALUNOS ORDENADO POR NOME
            case 6:{
                listarAlunosNome();
                break;
            }
            //LISTAR ALUNOS ORDENADOS POR DATA DE NASCIMENTO
            case 7:{
                listarAlunosDma();
                break;
            }
            //LISTAR ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS
            case 8:{
                listarAlunosDisciplina();
                break;
            }
            //VOLTAR
            case 0:{
                printf("##VOLTANDO## \n");
                voltar = 1;
                break;
            }
        }
    }
}

void cadastroProfessor(){
    printf("##CADASTRO PROFESSOR## \n");
    //MATRICULA
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe a matricula do professor: ");
    scanf("%d%*c" ,&professor[indiceProfessor].matricula);
    if(professor[indiceProfessor].matricula < 0){
        printf("Matrícula inválida \n");
        return;
    }
    professor[indiceProfessor].tipo = 'm';
    if(validarMatriculaProfessor() == TRUE){
        return;
    }
    indiceProfessor++;
    //CPF
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe o cpf (apenas numeros) do professor: ");
    fgets(professor[indiceProfessor].cpf, MAX_STR, stdin);
    professor[indiceProfessor].cpf[strcspn(professor[indiceProfessor].cpf, "\n")] = '\0';
    professor[indiceProfessor].tipo = 'c';
    if(validarCpfProfessor() == TRUE){
        indiceProfessor -= 1;
        return;
    }
    indiceProfessor++;
    //DATA NASCIMENTO
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe a data de nascimento(apenas numeros espaçados: xx xx xxxx) do professor: ");
    scanf("%d %d %d%*c" ,&professor[indiceProfessor].dataNascimento.dia ,&professor[indiceProfessor].dataNascimento.mes ,&professor[indiceProfessor].dataNascimento.ano);
    if(professor[indiceProfessor].dataNascimento.dia < 1 || professor[indiceProfessor].dataNascimento.dia > 31 || professor[indiceProfessor].dataNascimento.mes < 1 || professor[indiceProfessor].dataNascimento.mes > 12 || professor[indiceProfessor].dataNascimento.ano < 1 || professor[indiceProfessor].dataNascimento.ano > 2025){
        printf("Data de nascimento inválida \n");
        indiceProfessor -= 2;
        return;
    }
    professor[indiceProfessor].tipo = 'd';
    indiceProfessor++;
    //SEXO
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe o sexo do professor: ");
    fgets(professor[indiceProfessor].sexo, MAX_STR, stdin);
    professor[indiceProfessor].sexo[strcspn(professor[indiceProfessor].sexo, "\n")] = '\0';
    if(professor[indiceProfessor].sexo[0] == 'M' || professor[indiceProfessor].sexo[0] == 'm'){
        strcpy(professor[indiceProfessor].sexo, "mulher");
        professor[indiceProfessor].tipo = 's';
        indiceProfessor++;
    }
    else if(professor[indiceProfessor].sexo[0] == 'H' || professor[indiceProfessor].sexo[0] == 'h'){
        strcpy(professor[indiceProfessor].sexo, "homem");
        professor[indiceProfessor].tipo = 's';
        indiceProfessor++;
    }
    else{
        printf("Sexo inválido (Homem ou Mulher) \n");
        indiceProfessor -= 3;
        return;
    }
    //NOME
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe o nome do professor: ");
    fgets(professor[indiceProfessor].nome, MAX_STR, stdin);
    professor[indiceProfessor].nome[strcspn(professor[indiceProfessor].nome, "\n")] = '\0';
    professor[indiceProfessor].tipo = 'n';
    professor[indiceProfessor - 4].qtdDisciplinas = 0;
    indiceProfessor++;
    printf("##CADASTRO DE PROFESSOR REALIZADO!!## \n");
}

void excluirProfessor(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para excluir \n");
        return;
    }
    int achouProfessor = FALSE;
    printf("##EXCLUIR PROFESSOR## \n");
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    printf("Informe a matrícula do professor para exclusão: ");
    scanf("%d%*c" ,&professor[indiceProfessor].excluir);
    if(professor[indiceProfessor].excluir < 0){
        printf("Matrícula inválida \n");
        return;
    }
    professor[indiceProfessor].tipo = 'e';
    indiceProfessor++;
    printf("INDICE PROFESSOR: %d\n", indiceProfessor);
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'm' && professor[cont].matricula == professor[indiceProfessor - 1].excluir){
            achouProfessor = TRUE;
            for(int cont2 = cont; cont2 < indiceProfessor; cont2++){
                professor[cont2].matricula = professor[cont2 + 5].matricula;
                strcpy(professor[cont2 + 1].cpf, professor[cont2 + 6].cpf);
                professor[cont2 + 2].dataNascimento.dia = professor[cont2 + 7].dataNascimento.dia;
                professor[cont2 + 2].dataNascimento.mes = professor[cont2 + 7].dataNascimento.mes;
                professor[cont2 + 2].dataNascimento.ano = professor[cont2 + 7].dataNascimento.ano;
                strcpy(professor[cont2 + 3].sexo, professor[cont2 + 8].sexo);
                strcpy(professor[cont2 + 4].nome, professor[cont2 + 9].nome);
                professor[cont2 + 5].excluir = professor[cont2 + 10].excluir;
            }
            indiceProfessor -= 6;
            printf("INDICE PROFESSOR: %d\n", indiceProfessor);
            printf("##EXCLUSÃO DE PROFESSOR REALIZADO!!## \n");
            break;
        }
    }
    if(achouProfessor == FALSE){
        printf("Matrícula professor inexistente \n");
        indiceProfessor--;
        printf("INDICE PROFESSOR: %d\n", indiceProfessor);
        return;
    }
}

void atualizarProfessor(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para atualizar \n");
        return;
    }
    int professorAtualizar, achouProfessor = FALSE;
    printf("##ATUALIZAR PROFESSOR## \n");
    printf("Informe a matrícula do professor que deseja atualizar: ");
    scanf("%d%*c" ,&professorAtualizar);
    if(professorAtualizar < 0){
        printf("Mátricula inválida \n");
        return;
    }
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'm' && professor[cont].matricula == professorAtualizar){
            achouProfessor = TRUE;
            printf("--CASO NÃO QUEIRA ALTERAR ALGUM DOS ITENS, BASTA REPETI-LO--\n");
            //MATRICULA
            printf("Informe a matricula: ");
            scanf("%d%*c" ,&professor[cont].matricula);
            //CPF
            printf("Informe o cpf (apenas numeros) do professor: ");
            fgets(professor[cont + 1].cpf, MAX_STR, stdin);
            professor[cont + 1].cpf[strcspn(professor[cont + 1].cpf, "\n")] = '\0';
            //DATA DE NASCIMENTO
            printf("Informe a data de nascimento(apenas numeros espaçados: xx xx xxxx) do professor: ");
            scanf("%d %d %d%*c" ,&professor[cont + 2].dataNascimento.dia ,&professor[cont + 2].dataNascimento.mes ,&professor[cont + 2].dataNascimento.ano);
            //SEXO
            printf("Informe o sexo do professor: ");
            fgets(professor[cont + 3].sexo, MAX_STR, stdin);
            professor[cont + 3].sexo[strcspn(professor[cont + 3].sexo, "\n")] = '\0';
            //NOME
            printf("Informe o nome do professor: ");
            fgets(professor[cont + 4].nome, MAX_STR, stdin);
            professor[cont + 4].nome[strcspn(professor[cont + 4].nome, "\n")] = '\0';
            printf("##PROFESSOR ATUALIZADO!!## \n");
            break;
        }
    }
    if(achouProfessor == FALSE){
        printf("Mátricula professor inexistente \n");
        return;
    }
}

void listarProfessor(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para listar \n");
        return;
    }
    printf("##LISTAR PROFESSOR## \n");
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'm'){
            printf("Professor: %s, matrícula: %d, cpf: %s, sexo: %s, data de nascimento: %d/%d/%d \n" ,professor[cont + 4].nome, professor[cont].matricula, professor[cont + 1].cpf, professor[cont + 3].sexo, professor[cont + 2].dataNascimento.dia, professor[cont + 2].dataNascimento.mes, professor[cont + 2].dataNascimento.ano);
        }
    }
}

void listarProfessorSexo(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para listar \n");
        return;
    }
    char buscarSexo[MAX_STR], achouProfessor = FALSE;
    printf("##LISTAR PROFESSOR POR SEXO## \n");
    printf("Informe o sexo que deseja procurar: ");
    fgets(buscarSexo, MAX_STR, stdin);
    buscarSexo[strcspn(buscarSexo, "\n")] = '\0';
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 's' && strcmp(professor[cont].sexo, buscarSexo) == 0){
            achouProfessor = TRUE;
            printf("Professor: %s, sexo: %s \n", professor[cont + 1].nome, professor[cont].sexo);
        }
    }
    if(achouProfessor == FALSE){
        printf("Nenhum professor com o sexo: %s", buscarSexo);
        return;
    }
}

void listarProfessorNome(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para listar \n");
        return;
    }
    char trocaN[MAX_STR];
    printf("##LISTAR PROFESSOR ORDENADO POR NOME## \n");
    for (int cont = 0; cont < indiceProfessor; cont++) {
        for (int cont2 = cont + 1; cont2 < indiceProfessor; cont2++){
            if(professor[cont].tipo == 's' && professor[cont2].tipo == 'n' && strcmp(professor[cont].nome, professor[cont2].nome) > 0) {
                strcpy(trocaN, professor[cont].nome);
                strcpy(professor[cont].nome, professor[cont2].nome);
                strcpy(professor[cont2].nome, trocaN);
                fazerTrocaProfessor(cont, cont2);
                fazerTrocaDataProfessor(cont, cont2);
            }
        }
    }
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'n'){
            printf("Professor: %s\n", professor[cont].nome);
        }
    }
}

void listarProfessorDma(){
    if(indiceProfessor < 1){
        printf("É necessário ao menos 1 professor para listar \n");
        return;
    }
    printf("##LISTAR PROFESSOR POR DATA DE NASCIMENTO## \n");
    //ANO MAIS VELHO
    for(int cont = 0; cont < indiceProfessor; cont++){
        for(int cont2 = cont + 1; cont2 < indiceProfessor; cont2++){
            if(professor[cont].tipo == 'n' && professor[cont - 2].dataNascimento.ano > professor[cont2 - 2].dataNascimento.ano){
                trocaNomeProfessor(cont, cont2);
            }
        }
    }
    //MES MAIS VELHO
    for(int cont = 0; cont < indiceProfessor; cont++){
        for(int cont2 = cont + 1; cont2 < indiceProfessor; cont2++){
            if(professor[cont].tipo == 'n' && professor[cont - 2].dataNascimento.mes > professor[cont2 - 2].dataNascimento.mes && professor[cont - 2].dataNascimento.ano == professor[cont2 - 2].dataNascimento.ano){
                trocaNomeProfessor(cont, cont2);
            }
        }
    }
    //DIA MAIS VELHO
    for(int cont = 0; cont < indiceProfessor; cont++){
        for(int cont2 = cont + 1; cont2 < indiceProfessor; cont2++){
            if(professor[cont].tipo == 'n' && professor[cont - 2].dataNascimento.dia > professor[cont2 - 2].dataNascimento.dia && professor[cont - 2].dataNascimento.mes == professor[cont2 - 2].dataNascimento.mes && professor[cont - 2].dataNascimento.ano == professor[cont2 - 2].dataNascimento.ano){
                trocaNomeProfessor(cont, cont2);
            }
        }
    }
    //IMPRIMIR LISTA
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'n'){
            printf("Professor: %s, Data de nascimento: %d/%d/%d \n", professor[cont].nome, professor[cont - 2].dataNascimento.dia, professor[cont - 2].dataNascimento.mes, professor[cont - 2].dataNascimento.ano);
        }
    }
}
//MENU PROFESSOR
void menuProfessor(int voltar){
    while(voltar == 0){   
        printf("##MENU PROFESSOR## \n");
        printf("1 - Cadastrar professor \n");
        printf("2 - Excluir professor \n");
        printf("3 - Atualizar professor \n");
        printf("4 - Listar professores \n");
        printf("5 - Listar professores por sexo \n");
        printf("6 - Listar professores ordernados por nome \n");
        printf("7 - Listar professores ordernados por data de nascimento \n");
        printf("0 - Voltar \n");
        scanf("%d%*c" ,&opcaoSecundaria);
        switch(opcaoSecundaria){
            //CADASTRO PROFESSOR
            case 1:{
                cadastroProfessor();
                break;
            }
            //EXCLUIR PROFESSOR
            case 2:{
                excluirProfessor();
                break;
            }
            //ATUALIZAR PROFESSOR
            case 3:{
                atualizarProfessor();
                break;
            }
            //LISTAR PROFESSORES
            case 4:{
                listarProfessor();
                break;
            }
            //LISTAR PROFESSORES POR SEXO
            case 5:{
                listarProfessorSexo();
                break;
            }
            //LISTAR PROFESSORES ORDENADO POR NOME
            case 6:{
                listarProfessorNome();
                break;
            }
            //LISTAR PROFESSORES ORDENADOS POR DATA DE NASCIMENTO
            case 7:{
                listarProfessorDma();
                break; 
            }
            //VOLTAR
            case 0:{
                printf("##VOLTANDO## \n");
                voltar = 1;
                break;
            }
        }
    }
}

void cadastrarDisciplina(){
    printf("##CADASTRO DISCIPLINA## \n");
    //CODIGO
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    printf("Informe o código da disciplina: ");
    scanf("%d%*c" ,&disciplina[indiceDisciplina].codigo);
    if(disciplina[indiceDisciplina].codigo < 0){
        printf("Código inválido \n");
        return;
    }
    if(validarCodigoDisciplina() == TRUE){
        return;
    }
    disciplina[indiceDisciplina].tipo = 'c';
    indiceDisciplina++;
    //SEMESTRE
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    printf("Informe o semestre da disciplina: ");
    scanf("%d%*c" ,&disciplina[indiceDisciplina].semestre);
    if(disciplina[indiceDisciplina].semestre < 0){
        printf("Semestre inválido \n");
        indiceDisciplina -= 1;
        return;
    }
    disciplina[indiceDisciplina].tipo = 's';
    indiceDisciplina++;
    //NOME DISCIPLINA
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    printf("Informe o nome da disciplina: ");
    fgets(disciplina[indiceDisciplina].nomeDisciplina, MAX_STR, stdin);
    disciplina[indiceDisciplina].nomeDisciplina[strcspn(disciplina[indiceDisciplina].nomeDisciplina, "\n")] = '\0';
    if(validarNomeDisciplina() == TRUE){
        indiceDisciplina -= 2;
        return;
    }
    disciplina[indiceDisciplina].tipo = 'n';
    indiceDisciplina++;
    //NOME PROFESSOR
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    printf("Informe o nome do professor da disciplina: ");
    fgets(disciplina[indiceDisciplina].nomeProfessor, MAX_STR, stdin);
    disciplina[indiceDisciplina].nomeProfessor[strcspn(disciplina[indiceDisciplina].nomeProfessor, "\n")] = '\0';
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'n' && strcmp(professor[cont].nome, disciplina[indiceDisciplina].nomeProfessor) == 0){
            professor[cont - 4].disciplinas[disciplina[indiceDisciplina - 3].codigo] = TRUE;
            disciplina[indiceDisciplina].tipo = 'p';
            disciplina[indiceDisciplina - 3].qtdAlunos = 0;
            professor[cont - 4].qtdDisciplinas++;
            indiceDisciplina++;
            printf("##CADASTRO DE DISCIPLINA REALIZADO!!## \n");
            return;
        }
    }
    printf("Professor não existente \n");
    indiceDisciplina -= 3;
}

void excluirDisciplina(){
    int achouDisciplina = FALSE;
    printf("##EXCLUIR DISCIPLINA## \n");
    if(indiceDisciplina < 1){
        printf("É necessário ao menos 1 disciplina para excluir \n");
        return;
    }
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    printf("Informe o código da disciplina para exclusão: ");
    scanf("%d%*c" ,&disciplina[indiceDisciplina].excluir);
    if(disciplina[indiceDisciplina].excluir < 0){
        printf("Código inválido \n");
        return;
    }
    disciplina[indiceDisciplina].tipo = 'e';
    indiceDisciplina++;
    printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c' && disciplina[cont].codigo == disciplina[indiceDisciplina - 1].excluir){
            achouDisciplina = TRUE;
            for(int cont2 = cont; cont2 < indiceDisciplina; cont2++){
                disciplina[cont2].codigo = disciplina[cont2 + 4].codigo;
                disciplina[cont2 + 1].semestre = disciplina[cont2 + 5].semestre;
                strcpy(disciplina[cont2 + 2].nomeDisciplina, disciplina[cont2 + 6].nomeDisciplina);
                strcpy(disciplina[cont2 + 3].nomeProfessor, disciplina[cont2 + 7].nomeProfessor);
                disciplina[cont2 + 4].excluir = disciplina[cont2 + 8].excluir;
            }
            indiceDisciplina -= 6;
            printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
            printf("##EXCLUSÃO DE DISCIPLINA REALIZADO!!## \n");
            break;
        }
    }
    if(achouDisciplina == FALSE){
        printf("Código disciplina inexistente \n");
        indiceDisciplina--;
        printf("INDICE DISCIPLINA: %d\n", indiceDisciplina);
        return;
    }
}

void atualizarDisciplina(){
    if(indiceDisciplina < 1){
        printf("É necessário ao menos 1 disciplina para atualizar \n");
        return;
    }
    int disciplinaAtualizar, achouDisciplina = FALSE;
    printf("##ATUALIZAR DISCIPLINA## \n");
    printf("Informe o código da disciplina que deseja atualizar: ");
    scanf("%d%*c" ,&disciplinaAtualizar);
    if(disciplinaAtualizar < 0){
        printf("Código inválido \n");
        return;
    }
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c' && disciplina[cont].codigo == disciplinaAtualizar){
            achouDisciplina = TRUE;
            printf("--CASO NÃO QUEIRA ALTERAR ALGUM DOS ITENS, BASTA REPETIR--\n");
            //CÓDIGO
            printf("Informe o código da disciplina: ");
            scanf("%d%*c" ,&disciplina[cont].codigo);
            //SEMESTRE
            printf("Informe o semestre da disciplina: ");
            scanf("%d%*c" ,&disciplina[cont + 1].semestre);
            //NOME DA DISCIPLINA
            printf("Informe o nome da disciplina: ");
            fgets(disciplina[cont + 2].nomeDisciplina, MAX_STR, stdin);
            disciplina[cont + 2].nomeDisciplina[strcspn(disciplina[cont + 2].nomeDisciplina, "\n")] = '\0';
            //NOME DO PROFESSOR DA DISCIPLINA
            printf("Informe o nome do professor da disciplina: ");
            fgets(disciplina[cont + 3].nomeProfessor, MAX_STR, stdin);
            disciplina[cont + 3].nomeProfessor[strcspn(disciplina[cont + 3].nomeProfessor, "\n")] = '\0';
            printf("##DISCIPLINA ATUALIZADA!!## \n");
            break;
        }
    }
    if(achouDisciplina == FALSE){
        printf("Código disciplina inexistente \n");
        return;
    }
}

void matricularAlunoDisciplina(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para matricular em uma disciplina \n");
        return;
    }
    int disciplinaMatricular, alunoMatricular, achouAluno = FALSE, achouDisciplina = TRUE;
    printf("##MATRICULAR ALUNO EM DISCIPLINA## \n");
    printf("Informe a matricula do aluno que deseja matricular: ");
    scanf("%d%*c", &alunoMatricular);
    if(alunoMatricular < 0){
        printf("Mátricula inválida \n");
        return;
    }
    printf("Informe o código da disciplina que deseja matricular: ");
    scanf("%d%*c", &disciplinaMatricular);
    if(disciplinaMatricular < 0){
        printf("Código inválido \n");
        return;
    }
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm' && aluno[cont].matricula == alunoMatricular){
            achouAluno = TRUE;
            for(int cont2 = 0; cont2 < indiceDisciplina; cont2++){
                if(disciplina[cont2].tipo == 'c' && disciplina[cont2].codigo == disciplinaMatricular){
                    achouDisciplina = TRUE;
                    disciplina[cont2].qtdAlunos++;
                    aluno[cont].disciplinas[disciplinaMatricular] = TRUE;
                    aluno[cont].qtdDisciplinas++;
                    break;
                }
            }
            break;
        }
    }
    if(achouAluno == FALSE){
        printf("Mátricula de aluno inexistente \n");
        return;
    }
    if(achouDisciplina == FALSE){
        printf("Código de disciplina inexistente \n");
        return;
    }
    printf("##ALUNO MATRICULADO## \n");
}

void excluirAlunoDisciplina(){
    if(indiceAluno < 1){
        printf("É necessário ao menos 1 aluno para excluir de uma disciplina \n");
        return;
    }
    int disciplinaExcluir, alunoExcluir, achouAluno = FALSE, achouDisciplina = TRUE;
    printf("##EXCLUIR ALUNO DE DISCIPLINA## \n");
    printf("Informe a matricula do aluno que deseja excluir: ");
    scanf("%d%*c", &alunoExcluir);
    if(alunoExcluir < 0){
        printf("Mátricula inválida \n");
        return;
    }
    printf("Informe o código da disciplina que deseja excluir aluno: ");
    scanf("%d%*c", &disciplinaExcluir);
    if(disciplinaExcluir < 0){
        printf("Código inválido \n");
        return;
    }
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm' && aluno[cont].matricula == alunoExcluir){
            achouAluno = TRUE;
            for(int cont2 = 0; cont2 < indiceDisciplina; cont2++){
                if(disciplina[cont2].tipo == 'c' && disciplina[cont2].codigo == disciplinaExcluir && aluno[cont].disciplinas[disciplinaExcluir] == TRUE){
                    achouDisciplina = TRUE;
                    disciplina[cont2].qtdAlunos--;
                    aluno[cont].disciplinas[disciplinaExcluir] = FALSE;
                    aluno[cont].qtdDisciplinas--;
                    break;
                }
            }
            break;
        }
    }
    if(achouAluno == FALSE){
        printf("Mátricula de aluno inexistente \n");
        return;
    }
    if(achouDisciplina == FALSE){
        printf("Código de disciplina inexistente \n");
        return;
    }
    printf("##ALUNO EXCLUIDO DA DISCIPLINA## \n");
}

void listarDisciplina(){
    if(indiceDisciplina < 1){
        printf("É necessário ao menos uma disciplina para listar \n");
        return;
    }
    printf("##LISTAR DISCIPLINAS## \n");
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c'){
            printf("Disciplina: %s, codigo: %d, semestre: %d, professor: %s \n", disciplina[cont + 2].nomeDisciplina, disciplina[cont].codigo, disciplina[cont + 1].semestre, disciplina[cont + 3].nomeProfessor);
        }
    }
}

void listarDisciplinaVagas(){
    if(indiceDisciplina < 1){
        printf("É necessário ao menos 1 disciplina para listar \n");
        return;
    }
    printf("##LISTAR DISCIPLINAS QUE EXTRAPOLAM 40 VAGAS## \n");
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c' && disciplina[cont].qtdAlunos > 40){
            printf("Disciplina: %s, professor: %s, n° de vagas: %d \n", disciplina[cont + 2].nomeDisciplina, disciplina[cont + 3].nomeProfessor, disciplina[cont].qtdAlunos);
        }
    }
}

void listarUmaDisciplina(){
    if(indiceDisciplina < 1){
        printf("É necessário ao menos uma disciplina para listar \n");
        return;
    }
    int listarDisciplina, achouDisciplina = FALSE;
    printf("##LISTAR UMA DISCIPLINA## \n");
    printf("Informe o código da disciplina que deseja listar: ");
    scanf("%d%*c", &listarDisciplina);
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c' && disciplina[cont].codigo == listarDisciplina){
            achouDisciplina = TRUE;
            printf("Disciplina: %s, codigo: %d, semestre: %d, professor: %s \n", disciplina[cont + 2].nomeDisciplina, disciplina[cont].codigo, disciplina[cont + 1].semestre, disciplina[cont + 3].nomeProfessor);
            printf("Alunos: ");
            for(int cont2 = 0; cont2 < indiceAluno; cont2++){
                if(aluno[cont2].tipo == 'm' && aluno[cont2].disciplinas[disciplina[cont].codigo] == TRUE){
                    printf("%s ", aluno[cont2 + 4].nome);
                }
            }
            break;
        }
    }
    if(achouDisciplina == FALSE){
        printf("Código de disciplina inexistente \n");
    }
}
//MENU DISCIPLINA
void menuDisciplina(int voltar){   
    printf("##MENU DISCPLINA## \n");
    printf("1 - Cadastrar disciplina \n");
    printf("2 - Excluir disciplina \n");
    printf("3 - Atualizar disciplina \n");
    printf("4 - Matricular aluno em alguma disciplina \n");
    printf("5 - Excluir aluno de alguma disciplina \n");
    printf("6 - Listar disciplinas \n");
    printf("7 - Listar disciplinas, com nome do professor, que extrapolam 40 vagas \n");
    printf("8 - Listar uma disciplina \n");
    printf("0 - Voltar \n");
    scanf("%d%*c" ,&opcaoSecundaria);
    switch(opcaoSecundaria){
        //CADASTRAR DISCIPLINA
        case 1:{
            cadastrarDisciplina();
            break;
        }
        //EXCLUIR DISCIPLINA
        case 2:{
            excluirDisciplina();
            break;
        }
        //ATUALIZAR DISCIPLINA
        case 3:{
            atualizarDisciplina();
            break;
        }
        //MATRICULAR ALUNO EM ALGUMA DISCIPLINA
        case 4:{
            matricularAlunoDisciplina();
            break;
        }
        //EXCLUIR ALUNO DE ALGUMA DISCIPLINA
        case 5:{
            excluirAlunoDisciplina();
            break;
        }
        //LISTAR DISCIPLINAS
        case 6:{
            listarDisciplina();
            break;
        }
        //LISTAR DISCIPLINAS COM NOME PROFESSOR QUE EXTRAPOLAM 40 VAGAS
        case 7:{
            listarDisciplinaVagas();
            break;
        }
        //LISTAR UMA DISCIPLINA
        case 8:{
            listarUmaDisciplina();
            break;
        }
        //VOLTAR
        case 0:{
            printf("##VOLTANDO## \n");
            voltar = 1;
            break;
        }
    }
}

void buscarPessoa(){
    if(indiceAluno < 1 && indiceProfessor < 1){
        printf("É necessário ao menos 1 pessoa para realizar uma busca \n");
        return;
    }
    char buscaPessoa[MAX_STR];
    int achouAluno = FALSE, achouProfessor = FALSE;
    printf("##BUSCAR PESSOAS## \n");
    printf("Informe ao menos 3 letras para realizar uma busca: ");
    fgets(buscaPessoa, MAX_STR, stdin);
    buscaPessoa[strcspn(buscaPessoa, "\n")] = '\0';
    //ALUNOS
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'n' && strstr(buscaPessoa, aluno[cont].nome)){
            achouAluno = TRUE;
            printf("Aluno: %s ",aluno[cont].nome);
        }
    }
    if(achouAluno == FALSE){
        printf("Nenhum aluno encontrado");
    }
    printf("\n");
    //PROFESSORES
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'n' && strstr(buscaPessoa, professor[cont].nome)){
            achouProfessor = TRUE;
            printf("Professor: %s ",professor[cont].nome);
        }
    }
    if(achouProfessor == FALSE){
        printf("Nenhum professor encontrado");
    }
    printf("\n");
}

void aniversariantes(){
    if(indiceAluno < 1 && indiceProfessor < 1){
        printf("É necessário ao menos 1 pessoa para listar os aniversariantes do mês \n");
        return;
    }
    char meses[12][30] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    char mesString[MAX_STR];
    int mesNum, achouProfessor = FALSE, achouAluno = FALSE, achouMes = FALSE;
    printf("##ANIVERSARIANTES## \n");
    printf("Informe o mês para saber os aniversariantes: ");
    fgets(mesString, MAX_STR, stdin);
    mesString[strcspn(mesString, "\n")] = '\0';
    for(int cont = 0; cont < 12; cont++){
        if(strcmp(mesString, meses[cont]) == 0){
            achouMes = TRUE;
            mesNum = cont + 1;
            printf("%d \n", mesNum);
            break;
        }
    }
    if(achouMes == FALSE){
        mesNum = atoi(mesString);
        printf("%d \n", mesNum);
        if(mesNum < 1 || mesNum > 12){
            printf("Mês inválido \n");
            return;
        }
    }
    //ALUNO
    printf("Alunos que fazem aniversário nesse mes: ");
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'd' && aluno[cont].dataNascimento.mes == mesNum){
            achouAluno = TRUE;
            printf("%s ",aluno[cont + 2].nome);
        }
    }
    if(achouAluno == FALSE){
        printf("Nenhum aluno faz aniversário nesse mês");
    }
    printf("\n");
    //PROFESSORES
    printf("Professores que fazem aniversário nesse mes: ");
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'd' && professor[cont].dataNascimento.mes == mesNum){
            achouProfessor = TRUE;
            printf("%s ",professor[cont + 2].nome);
        }
    }
    if(achouProfessor == FALSE){
        printf("Nenhum professor faz aniversário nesse mês");
    }
    printf("\n");
}

void listarTudo(){
    if(indiceAluno < 1 && indiceDisciplina < 1 && indiceProfessor < 1){
        printf("Não há nada para listar \n");
        return;
    }
    printf("##LISTAR TUDO## \n");
    int achouAluno = FALSE, achouProfessor = FALSE, achouDisciplina = FALSE;
    printf("------ALUNOS-----\n");
    for(int cont = 0; cont < indiceAluno; cont++){
        if(aluno[cont].tipo == 'm'){
            achouAluno = TRUE;
            printf("Aluno: %s, matrícula: %d, cpf: %s, sexo: %s, data de nascimento: %d/%d/%d \n" ,aluno[cont + 4].nome, aluno[cont].matricula, aluno[cont + 1].cpf, aluno[cont + 3].sexo, aluno[cont + 2].dataNascimento.dia, aluno[cont + 2].dataNascimento.mes, aluno[cont + 2].dataNascimento.ano);
        }
    }
    if(achouAluno == FALSE){
        printf("Não há alunos \n");
    }
    printf("------PROFESSORES-----\n");
    for(int cont = 0; cont < indiceProfessor; cont++){
        if(professor[cont].tipo == 'm'){
            achouProfessor = TRUE;
            printf("Professor: %s, matrícula: %d, cpf: %s, sexo: %s, data de nascimento: %d/%d/%d \n" ,professor[cont + 4].nome, professor[cont].matricula, professor[cont + 1].cpf, professor[cont + 3].sexo, professor[cont + 2].dataNascimento.dia, professor[cont + 2].dataNascimento.mes, professor[cont + 2].dataNascimento.ano);
        }
    }
    if(achouProfessor == FALSE){
        printf("Não há professores \n");
    }
    printf("------DISCIPLINAS-----\n");
    for(int cont = 0; cont < indiceDisciplina; cont++){
        if(disciplina[cont].tipo == 'c'){
            achouDisciplina = TRUE;
            printf("Disciplina: %s, codigo: %d, semestre: %d, professor: %s, quantidade de alunos: %d \n", disciplina[cont + 2].nomeDisciplina, disciplina[cont].codigo, disciplina[cont + 1].semestre, disciplina[cont + 3].nomeProfessor, disciplina[cont].qtdAlunos);
        }
    }
    if(achouDisciplina == FALSE){
        printf("Não há disciplinas \n");
    }
    printf("##LISTA COMPLETADA## \n");
}

void menu(){
    while(sair == 0){
        int voltar = 0;
        printf("##MENU PRINCIPAL## \n");
        printf("1 - Alunos \n");
        printf("2 - Professores \n");
        printf("3 - Disciplinas \n");
        printf("4 - Buscar pessoa(min. 3 letras) \n");
        printf("5 - Listar aniversariantes do mês \n");
        printf("6 - Listar tudo (disciplinas, professores e alunos) \n");
        printf("0 - Sair \n");
        scanf("%d%*c" ,&opcaoPrincipal);
        switch(opcaoPrincipal){
            //ALUNO
            case 1:{
                //MENU ALUNO
                menuAluno(voltar);
                break;
            }
            //PROFESSOR
            case 2:{
                //MENU PROFESSOR
                menuProfessor(voltar);
                break;
            }
            //DISCIPLINA
            case 3:{
                //MENU DISCIPLINA
                menuDisciplina(voltar);
                break;
            }
            //BUSCA DE PESSOA
            case 4:{
                buscarPessoa();
                break;
            }
            //ANIVERSARIANTES
            case 5:{
                aniversariantes();
                break;
            }
            //LISTAR TUDO
            case 6:{
                listarTudo();
                break;
            }
            //SAIR
            case 0:{
                printf("##SAINDO## \n");
                sair = 1;
                break;
            }
        }
    }
}

int main(){
    menu();
    return 0;
}
