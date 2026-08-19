# Technical Overview — My_game_2D / so_long

## Purpose

This project implements a small 2D game in C using MiniLibX. Its main technical value is the integration of file parsing, map validation, rendering, event handling and resource management inside a low-level graphical program.

## Runtime flow

```text
.ber map
   ↓
read / parse
   ↓
validate dimensions and required elements
   ↓
validate reachable game state
   ↓
initialize MiniLibX
   ↓
load sprites
   ↓
render map
   ↓
keyboard events → movement → render/update
```

## Main responsibilities

### Map loading
The `.ber` file is transformed into an in-memory matrix representing walls, floor, collectibles, exit and player position.

### Validation
The program should reject malformed maps before opening the game. Useful validation dimensions include rectangular shape, closed walls, valid character set, required entity counts and reachability of collectibles/exit.

### Rendering
Tiles and sprites are drawn according to the matrix representation. Keeping game state separate from rendering makes movement and validation easier to reason about.

### Input and movement
Keyboard events update the player position only when the target tile is valid. Collectibles and exit conditions modify state rather than only graphics.

### Cleanup
MiniLibX resources, map allocations and textures/images need deterministic cleanup on both normal exit and error paths.

## Testing ideas

- valid minimal map;
- non-rectangular map;
- open wall boundary;
- missing player/exit/collectible;
- duplicate player/exit when invalid;
- unreachable collectible;
- unreachable exit;
- invalid character;
- repeated movement against walls;
- closing the window through the window manager.

## Portfolio value

The project demonstrates how parsing, state modelling, graphics and event-driven code fit together in C without relying on a game engine.
