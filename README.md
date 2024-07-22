so_long


`so_long` is a C project developed as part of the 42 curriculum. This project is a simple yet engaging game built using the MiniLibX library. In `so_long`, players navigate through a 2D maze-like map to collect items to unlock the exit and quit the game.

## Features and Gameplay

- **2D Graphics**: Utilizes the MiniLibX library for rendering graphics and managing the game window.
- **User-Created Maps**: Play on various user-created maps with different challenges. The maps can be found under resources/maps.
- **Simple Controls**: The character moves using the arrow keys.
- **Collect Items**: Gather all coins to unlock the exit. 
- **Avoid Obstacles**: Dodge enemies and obstacles that try to block your path. Touching an enemy will exit the game.
- **Memory Management**: Efficient memory handling to ensure there are no memory leaks and the game runs smoothly.


## Installation

1. Clone the repository:
    ```bash
    git clone git@github.com:mihaellatocu/so_long_new.git so_long
    cd so_long
    ```

2. Build the project:
    ```bash
    make
    ```

3. Run the game with a specified map:
    ```bash
    ./so_long resources/maps/map_6.ber
    ```


![Game](./game.png)