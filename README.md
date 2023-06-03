# Raygame

This is an attempt to making a game and game engine for that game (LOL) using C language (Raylib)

## Architecture
I love this arch I came up with :D

### State manager
It's a crucial part of any game engine. It's simply means what user sees and interacts to. Play state, Menu state, Pause state, etc. State manager handles all this states and transitions between them.

Because I wrote this game/game engine using C language, I have to forget about OOP. So I managed to handle states and they behaviors separately in a neat way, using making advantage of how structures and function pointers stores in RAM (and a bit of MACRO magic :D ).

### ECS
It's the main architecture of data flow and behavior management of game engine. **Entity-Component-System** is an architectural pattern that is very suitable (I mean that) for game engines. 