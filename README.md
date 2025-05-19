# so_long

A nice little mini-mini-game using MinilibX! It was fun developing it, for sure. As a gamer, anything related to games is a win in my book. So, for this one, MinilibX is a pre-made library to create windows and print sprites on it. It was a bit of a challenge to work with it, considering I had to learn a whole new library of functions, but that's ok, it's for the greater good.

## Overview

- **Map:** The map is comprised of `0`s (empty spaces), `1`s (walls), `C`s (the collectibles), `E` (the exit), and `P` (the player character). No other characters are allowed, so the first validator checks for this.
- **Validation:** Only one `P` and one `E` are allowed. There must be at least one `C`, and all collectibles must be accessible by the player.
- **Flood Fill:** To ensure all collectibles and the exit are reachable, a flood fill algorithm starts from the player and marks all accessible spaces. If any `C` or `E` is unreachable, the map is invalid.
- **Rendering:** Sprites are hard-coded at 32x32 pixels and rendered according to the map size. Assets are in the `assets/` folder and can be replaced if desired.
- **Movement:** Player movement is handled using MinilibX events. The window re-renders the player in the new position to simulate movement.
- **Exit:** The game ends when all collectibles are gathered and the player enters the exit. If the player tries to exit early, the game displays how many collectibles are left.

## How to Play

1. **Build the project:**
   ```
   make
   ```

2. **Run the game:**
   ```
   ./so_long <map_file.ber>
   ```

3. **Controls:**
   - Move with `WASD` or arrow keys.
   - Press `ESC` to exit.

4. **Objective:**
   - Collect all collectibles (`C`) and reach the exit (`E`).

## Map Format

- Only the following characters are allowed: `0`, `1`, `C`, `E`, `P`.
- The map must have exactly one player (`P`) and one exit (`E`).
- At least one collectible (`C`) is required.
- All collectibles and the exit must be reachable from the player's starting position.

## Assets

- Sprites are located in the [`assets/`](so_long_deliver/assets/) folder.
- You can replace the `.xpm` files with your own 32x32 sprites.

## Project Structure

- [`ft_so_long_main.c`](so_long_deliver/ft_so_long_main.c): Entry point and main loop.
- [`ft_so_long_map.c`](so_long_deliver/ft_so_long_map.c): Map reading and validation.
- [`ft_so_long_flood_fill.c`](so_long_deliver/ft_so_long_flood_fill.c): Flood fill algorithm for path validation.
- [`ft_so_long_render.c`](so_long_deliver/ft_so_long_render.c): Rendering logic.
- [`ft_so_long_movement.c`](so_long_deliver/ft_so_long_movement.c): Player movement and controls.
- [`assets/`](so_long_deliver/assets/): Sprite images.

## Notes

- No bonus: The character is not animated and does not turn.
- If you try to exit without collecting everything, the game will tell you how many are missing.

Enjoy!
