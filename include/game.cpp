

/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.hpp"

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

Game::~Game()
{
}

void Game::Init()
{
    SysInit("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
}

void Game::Update(float dt)
{
}

void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

void Game::SysInit(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    std::cout << "Initializing Subsystems..." << std::endl;
    int flags = 0;

    if (fullscreen)
        flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
    else
        flags = SDL_WINDOW_OPENGL;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        std::cout << "Subsystems initialized!" << std::endl;
    else
        std::cout << "Error initializing Subsystems. Error: " << SDL_GetError() << std::endl;

    // Request opengl 3.3 context with core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window)
        SDLDie("failed to create window ");

    maincontext = SDL_GL_CreateContext(window);

    if (!maincontext)
        SDLDie("failed to create context ");

    // INITIALIZE GLAD:
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        std::cout << "Failed to initialize GLAD" << std::endl;

    glViewport(0, 0, width, height);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.1f, 0.1f, 0.12f, 0.3f);
    isRunning = true;
    return;
}

void Game::SDLDie(const char *msg)
{
    std::cout << msg << SDL_GetError() << std::endl;
    SDL_Quit();
    exit(1);
}

void Game::Clean()
{
    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
    std::cout << "Subsystems cleaned" << std::endl;
}

void Game::UpdateFrameTiming()
{
    float currentFrame = SDL_GetTicks();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

void Game::HandleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        // LogCameraPosition();
        if (event.key.keysym.sym == SDLK_ESCAPE)
            isRunning = false;
        if (event.key.keysym.sym == SDLK_w)
        {
        }
        if (event.key.keysym.sym == SDLK_s)
        {
        }
        if (event.key.keysym.sym == SDLK_a)
        {
        }
        if (event.key.keysym.sym == SDLK_d)
        {
        }
        if (event.key.keysym.sym == SDLK_UP)
        {
            std::cout << "Pressed UP" << std::endl;
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
            std::cout << "Pressed DOWN" << std::endl;
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            std::cout << "Pressed LEFT" << std::endl;
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
            std::cout << "Pressed RIGHT" << std::endl;
        }
        break;
    default:
        break;
    }
}

void Game::Setup()
{
}