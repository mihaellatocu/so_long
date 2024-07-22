so_long


`so_long` is a C project developed as part of the 42 curriculum. This project is a simple yet engaging game built using the MiniLibX library. In `so_long`, players navigate through a 2D maze-like map to collect items and achieve specific objectives.

## Features

- **2D Graphics**: Utilizes the MiniLibX library for rendering graphics and managing the game window.
- **Map Interaction**: Load and explore user-defined maps to experience different challenges.
- **Simple Controls**: Intuitive keyboard controls for moving the character and interacting with game elements.
- **Memory Management**: Includes practices to detect and handle memory leaks, ensuring efficient resource usage.

## Gameplay Rules

- **Objective**: Navigate through the map to collect all the collectible items (e.g. coins) and reach the exit.
- **Movement**: Use the arrow keys to move the character around the map.
- **Collectibles**: Collect items scattered throughout the map to unlock new areas or achieve objectives.
- **Exit**: Find and reach the exit point to complete the level.
- **Obstacles**: Avoid obstacles and enemies that may hinder progress. Touching an enemy will exit the game.


## Installation

1. Clone the repository:
    ```bash
    git clone git@github.com:mihaellatocu/so_long_new.git so_long
    cd so_long
    ```

2. Build the project:
    make

3. Run the game with a specified map:
    ./so_long resources/maps/map_6.ber


![Game](./game.png)