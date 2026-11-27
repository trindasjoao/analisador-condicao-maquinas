#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_NOME 60
#define NORMAL 0
#define ATENCAO 1
#define CRITICA 2

typedef struct {
    float tempo;
    float rpm;
    float temperatura;
    float vibracao;
} Amostra;

typedef struct {
    char maquina[TAM_NOME];
    float rpmNominal;
    float tempLimite;
    float vibLimite;
    int quantidade;
    Amostra *amostras;
} Ensaio;

typedef struct {
    float medias[3];
    float extremos[3][2];
    int contagem[3];
} Resumo;

int carregarEnsaio(const char *nomeArquivo, Ensaio *ensaio);
int classificarAmostra(const Amostra *a, const Ensaio *ensaio);
void calcularResumo(const Ensaio *ensaio, Resumo *resumo);
void mostrarResumo(const Ensaio *ensaio, const Resumo *resumo);
void listarAmostrasPorEstado(const Ensaio *ensaio, int estado);
int gerarRelatorio(const char *nomeArquivo, const Ensaio *ensaio,
                   const Resumo *resumo);
void liberarEnsaio(Ensaio *ensaio);

int main(void) {
    Ensaio ensaio = {0};
    Resumo resumo = {0};

    char nome_arquivo[TAM_NOME] = "maquina.txt"; 

    carregarEnsaio(nome_arquivo, &ensaio);


    /* TODO: ler o nome do arquivo, carregar os dados e calcular o resumo. */
    /* TODO: implementar o menu com switch. */
    /* TODO: liberar a memoria antes de encerrar. */

    (void)ensaio;
    (void)resumo;
    return 0;
}

int carregarEnsaio(const char *nomeArquivo, Ensaio *ensaio){
    //abertura arquivo
    FILE *arquivo;

    arquivo = fopen (nomeArquivo, "r");

    if (arquivo == NULL){
        return 0;    
    }
    
    //faz leitura dos dados somente do ensaio
    if (fscanf(arquivo, "%s %f %f %f %d", 
        ensaio->maquina,
        &ensaio->rpmNominal, 
        &ensaio->tempLimite, 
        &ensaio->vibLimite,
        &ensaio->quantidade) != 5 || ensaio->quantidade <= 0) {
        ensaio->quantidade = 0;
        fclose(arquivo);
        return 0;
    }
    //uso malloc para criar vetor com número de quantidade das amostras
    ensaio->amostras = malloc((size_t)ensaio->quantidade * sizeof(Amostra));

    if (ensaio->amostras == NULL){
        fclose(arquivo);
        return 0; 
    }
    //leitura de todos os campos da amostra
    for (int i = 0; i < ensaio->quantidade; i++) {
        if (fscanf(arquivo, "%f %f %f %f", 
            &ensaio->amostras[i].tempo,
            &ensaio->amostras[i].rpm,
            &ensaio->amostras[i].temperatura,
            &ensaio->amostras[i].vibracao) != 4) {
                free(ensaio->amostras); //se der erro na leitura, ele libera memória
                ensaio->amostras = NULL; //não aponta para nada, por segurança
                ensaio->quantidade = 0; //zera quantidade, pq a leitura foi "apagada"
                fclose(arquivo);
                return 0;
            }
        
    }

    fclose(arquivo);
    return 1;

}
