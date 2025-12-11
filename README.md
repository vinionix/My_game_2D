So_long — Meu Primeiro Jogo 2D com MLX

O so_long foi meu primeiro contato real com desenvolvimento de jogos em C. Aqui eu aprendi a usar a MLX, trabalhar com renderização 2D, lidar com sprites, colisões e toda a lógica básica de um game simples, mas completo.

🚀 Sobre o Jogo

Você controla um personagem que precisa atravessar o mapa coletando itens e alcançando a saída.
O desafio está em navegar pelo labirinto, evitar paredes e planejar a rota ideal.

🧩 Principais Aprendizados

Como funciona a renderização 2D na MLX

Carregamento de imagens e manipulação de sprites

Sistema de movimentação + colisão

Estruturação de um loop de jogo (update + render)

Tratamento de eventos do teclado

Leitura e validação do mapa via arquivo .ber

🔧 Ferramentas e Soluções

C

MiniLibX (MLX)

Sistema de mapa em matriz

Controle de eventos via hooks da MLX

Organização do código em módulos (janela, mapa, player, render…)

🎮 Como Jogar

Compile o projeto:

make


Rode passando o mapa:

./so_long maps/map.ber


Use as teclas W A S D para mover.

🗺️ Regras do Jogo

Pegue todos os colecionáveis

Evite paredes

Alcance a saída quando todos os itens forem coletados

Cada movimento conta!

📁 Estrutura Simplificada
so_long/
├── src/
│   ├── main.c
│   ├── render/
│   ├── player/
│   ├── map/
│   └── utils/
├── maps/
├── assets/
└── Makefile

⚠️ Desafios do Projeto

Aprender a usar a MLX do zero

Entender como funcionam imagens e buffers na prática

Garantir que o mapa fosse válido, jogável e sem bugs

Lidar com eventos sem travar o jogo

🏁 Status

Projeto finalizado, estável e funcionando com diferentes mapas.
