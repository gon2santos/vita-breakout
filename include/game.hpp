/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/

#ifndef GAME_H
#define GAME_H

#include "glad.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "resourceman.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Represents the current state of the game
enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
public:
    // game state
    GameState State;
    bool Keys[1024];
    unsigned int Width, Height;
    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void Update(float dt);
    void Render();
    void SysInit(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void SDLDie(const char *msg);
    void Setup();
    bool Running() { return isRunning; };
    void UpdateFrameTiming();
    void HandleEvents();
    void Clean();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_GLContext maincontext;
    SDL_Event event;
};

#endif