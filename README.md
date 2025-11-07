🚀 Torre de Resgate – Free Fire em C
Este projeto simula a montagem estratégica da torre de resgate no jogo Free Fire, utilizando algoritmos clássicos de ordenação e busca binária. Desenvolvido em linguagem C, o sistema permite ao jogador organizar componentes essenciais, escolher a melhor estratégia de ordenação e localizar o item-chave para ativar a torre.

🎯 Objetivo
Consolidar conhecimentos de estrutura de dados e algoritmos em C por meio de um desafio gamificado. O jogador deve montar a torre de resgate escolhendo critérios de ordenação e realizando buscas eficientes, com feedback sobre desempenho e comparações.

🛠️ Tecnologias Utilizadas
- Linguagem: C
- Bibliotecas: stdio.h, stdlib.h, string.h, time.h
- Ferramentas: compilador GCC ou qualquer ambiente C compatível

🧱 Estrutura do Código
O projeto é modularizado em funções específicas para facilitar manutenção e comparação de desempenho:
|  |  | 
| main() |  | 
| bubbleSortNome() |  | 
| insertionSortTipo() |  | 
| selectionSortPrioridade() |  | 
| buscaBinariaPorNome() |  | 
| medirTempo() |  | 
| mostrarComponentes() |  | 



📦 Componentes da Torre
Cada componente é representado por uma struct com os seguintes campos:
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;


O jogador pode cadastrar até 20 componentes, informando nome, tipo (ex: “controle”, “suporte”, “propulsão”) e prioridade (1 a 10).

🔍 Funcionalidades
- Cadastro de componentes
- Ordenação por nome, tipo ou prioridade
- Busca binária por nome (após ordenação)
- Medição de tempo de execução com clock()
- Contagem de comparações realizadas
- Interface interativa com menu de escolha
- Exibição formatada dos componentes ordenados

🧪 Como Executar
- Clone o repositório:
git clone https://github.com/seu-usuario/freefire-torre-resgate.git
cd freefire-torre-resgate
- Compile o código:
gcc torre.c -o torre
- Execute o jogo:
./torre



📚 Aprendizado
Este projeto reforça conceitos fundamentais como:
- Implementação de algoritmos de ordenação
- Busca binária otimizada
- Análise de desempenho em tempo real
- Modularização e clareza de código
- Manipulação de structs e strings em C

📄 Licença
Este projeto está licenciado sob a MIT License.
