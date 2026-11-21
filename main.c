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

    /* TODO: ler o nome do arquivo, carregar os dados e calcular o resumo. */
    /* TODO: implementar o menu com switch. */
    /* TODO: liberar a memoria antes de encerrar. */

    (void)ensaio;
    (void)resumo;
    return 0;
}

/* Implemente aqui as funcoes declaradas acima. */
