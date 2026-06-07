# My_game_2D

Implementação do projeto `so_long`, um jogo 2D em C desenvolvido como parte da formação da 42 Rio.

O projeto usa a MiniLibX para renderizar uma janela gráfica, carregar sprites, ler mapas no formato `.ber` e controlar a movimentação do jogador em um mapa baseado em matriz.

## Objetivo

Criar um jogo 2D simples, mas completo, aplicando conceitos de renderização, eventos, validação de mapa, colisão e organização de código em C.

## Tecnologias e conceitos utilizados

- C
- Makefile
- MiniLibX
- X11
- Renderização 2D
- Sprites
- Eventos de teclado
- Validação de mapas `.ber`
- Estrutura de mapa em matriz
- Gerenciamento manual de memória

## Funcionamento geral

O jogador precisa navegar pelo mapa, coletar todos os itens e chegar até a saída.

Regras principais:

- o mapa é carregado a partir de um arquivo `.ber`;
- paredes bloqueiam o movimento;
- os coletáveis devem ser obtidos antes da saída;
- cada movimento do jogador é contabilizado;
- o jogo usa eventos de teclado para movimentação.

## Como compilar e executar

Pré-requisitos:

- ambiente Linux;
- `make`;
- compilador C;
- dependências da MiniLibX/X11 instaladas.

```sh
git clone https://github.com/vinionix/My_game_2D.git
cd My_game_2D
make
./so_long maps/map.ber
```

Alvos disponíveis:

```sh
make
make clean
make fclean
make re
```

## Estrutura geral

Estrutura simplificada do projeto:

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

## Status atual

Projeto implementado com leitura de mapa, validação, renderização, movimentação e controle básico de jogo.

O repositório não informa testes automatizados ou resultado de avaliação. A documentação foi escrita com base nos arquivos disponíveis no projeto.

## Evolução do projeto

- Criação da estrutura base em C com MiniLibX.
- Implementação da leitura de mapas `.ber`.
- Validação das regras do mapa.
- Carregamento de assets e renderização do cenário.
- Implementação da movimentação do jogador e colisões.
- Fase atual: projeto documentado para consulta e portfólio.

## Aprendizados principais

- Como criar uma janela gráfica com MiniLibX.
- Como carregar e renderizar sprites.
- Como representar um mapa 2D usando matriz.
- Como validar arquivos de mapa antes de executar o jogo.
- Como tratar eventos de teclado.
- Como organizar um projeto gráfico em C.

## Autor

Desenvolvido por [vinionix](https://github.com/vinionix) durante a formação na 42 Rio.
