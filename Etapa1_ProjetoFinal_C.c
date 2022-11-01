#include <stdio.h>
#include <pthread.h>

// Tipo Produto
typedef struct
{
    int id;
    char *produto;
    float preco;
} Produto;

// Tipo que eu uso como parametro pra função do Thread
typedef struct
{
    int numThread;
    int sizeofArray;
    Produto *produtos;
} t_produto_arg, *ptr_t_produto_arg;

// Soma os produtos do carrinho
float somar_produtos(Produto produtos[], int sizeofArray)
{
    float soma = 0;
    for (int index = 0; index < sizeofArray / sizeof(Produto); index++)
    {
        soma += produtos[index].preco;
    }
}

// Função que o Thread roda
void *calcular_carrinho(void *arg)
{
    ptr_t_produto_arg args = (ptr_t_produto_arg)arg;
    printf("Produtos do Thread |%d|:\n", args->numThread);

    for (int index = 0; index < args->sizeofArray / sizeof(Produto); index++)
    {
        printf("    - %s - R$ %.2f\n", args->produtos[index].produto, args->produtos[index].preco);
    }

    printf("Soma dos Preços:\n");
    float soma_precos = somar_produtos(args->produtos, args->sizeofArray);
    printf("R$ %.2f\n", soma_precos);
}

int main()
{
    // Carrinho e Args dos Threads
    Produto produtos0[] = {{1, "Kindle", 179.00f}};
    Produto produtos1[] = {{1, "Kindle", 179.00f}, {2, "IPhone", 499.00f}};
    Produto produtos2[] = {{1, "Kindle", 179.00f}, {2, "IPhone", 499.00f}, {3, "Macbook Pro", 1199.00f}};
    Produto produtos3[] = {{1, "Kindle", 179.00f}, {2, "IPhone", 499.00f}, {3, "Macbook Pro", 1199.00f}, {4, "Apple Workstation", 10000.00f}};

    t_produto_arg produtos0_arg = {1, sizeof(produtos0), produtos0};
    t_produto_arg produtos1_arg = {2, sizeof(produtos1), produtos1};
    t_produto_arg produtos2_arg = {3, sizeof(produtos2), produtos2};
    t_produto_arg produtos3_arg = {4, sizeof(produtos3), produtos3};

    // Criação dos Threads
    pthread_t t_produtos0, t_produtos1, t_produtos2, t_produtos3;
    pthread_create(&t_produtos0, NULL, calcular_carrinho, &(produtos0_arg));
    pthread_create(&t_produtos1, NULL, calcular_carrinho, &(produtos1_arg));
    pthread_create(&t_produtos2, NULL, calcular_carrinho, &(produtos2_arg));
    pthread_create(&t_produtos3, NULL, calcular_carrinho, &(produtos3_arg));

    // Join dos Threads
    pthread_join(t_produtos0, NULL);
    pthread_join(t_produtos1, NULL);
    pthread_join(t_produtos2, NULL);
    pthread_join(t_produtos3, NULL);

    return 0;
}