# My_game_2D — so_long

Jogo 2D em C desenvolvido durante a formação da 42 Rio usando MiniLibX.

O projeto transforma um mapa `.ber` em um ambiente gráfico navegável e conecta várias responsabilidades normalmente separadas: leitura de arquivo, validação, estado do jogo, renderização de sprites, eventos de teclado, colisão e cleanup de recursos.

## Objetivo

Criar um jogo simples em que o jogador percorre o mapa, coleta todos os itens e alcança a saída, respeitando paredes e as regras definidas pelo arquivo de mapa.

## Fluxo técnico

```text
arquivo .ber
    ↓
leitura / parsing
    ↓
validação do mapa
    ↓
inicialização MiniLibX
    ↓
carregamento de sprites
    ↓
renderização
    ↓
eventos de teclado
    ↓
atualização do estado
    ↓
nova renderização
```

## Tecnologias e conceitos

- C
- Makefile
- MiniLibX
- X11
- sprites
- renderização 2D
- event loop
- parsing de arquivos `.ber`
- matriz 2D
- validação de mapas
- colisão
- gerenciamento manual de memória

## Regras principais

- o mapa é carregado de um arquivo `.ber`;
- paredes bloqueiam movimento;
- coletáveis precisam ser obtidos antes da conclusão;
- a saída faz parte da condição de vitória;
- movimentos do jogador são contabilizados;
- eventos de teclado controlam a movimentação.

## Estrutura

```text
My_game_2D/
├── gnl/
├── lib/
├── maps/
├── minilibx-linux/
├── main.c
├── parsing.c
├── ft_render_map.c
├── ft_move_player.c
└── Makefile
```

## Validação de mapa

Antes de iniciar a janela, um mapa deve ser tratado como dado não confiável. Casos que merecem validação incluem:

- formato retangular;
- paredes fechando o perímetro;
- caracteres permitidos;
- presença das entidades obrigatórias;
- quantidade válida de player/saída;
- caminho possível até coletáveis;
- caminho possível até a saída.

Separar essa validação da renderização impede que uma entrada inválida seja descoberta apenas depois de inicializar recursos gráficos.

## Como compilar e executar

Pré-requisitos:

- Linux;
- compilador C;
- `make`;
- dependências da MiniLibX/X11.

```bash
git clone https://github.com/vinionix/My_game_2D.git
cd My_game_2D
make
./so_long maps/map.ber
```

## Casos de teste

- mapa válido pequeno;
- mapa não retangular;
- parede externa aberta;
- player ausente;
- saída ausente;
- coletável ausente;
- caractere inválido;
- coletável inacessível;
- saída inacessível;
- movimento repetido contra parede;
- fechamento da janela pelo sistema.

## Status

O repositório contém leitura e validação de mapa, renderização, movimentação e controle básico do jogo. Não há afirmação de suíte automatizada ou nota oficial da 42 sem evidência no próprio repositório.

## O que este projeto demonstra

- programação gráfica em C;
- event-driven programming;
- parsing e validação de arquivos;
- modelagem de estado com matriz;
- separação entre lógica e renderização;
- gerenciamento de recursos gráficos e memória.

## Documentação

- [Technical Overview](docs/TECHNICAL_OVERVIEW.md) — fluxo do jogo, responsabilidades, validação e estratégia de testes.

## Autor

Desenvolvido por [Vinícius Fidelis](https://github.com/vinionix) durante a formação na 42 Rio.
