
// g++ -o main ./src/main.cpp ./src/glad.c ./include/texture.cpp ./include/resourceman.cpp ./include/game.cpp ./include/shader.cpp ./include/stb_image.cpp -w -lSDL2
/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "../include/game.hpp"

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int, char **)
{
    Breakout.Setup();
    Breakout.Init();

    while (Breakout.Running())
    {
        Breakout.UpdateFrameTiming();
        Breakout.HandleEvents();
        Breakout.Update(Breakout.deltaTime);
        Breakout.Render();
    }
    Breakout.Clean();
    return 0;
}
