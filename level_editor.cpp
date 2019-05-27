#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
int SCREEN_WIDTH = 400;
int SCREEN_HEIGHT = 400;
SDL_Window* window;
SDL_Renderer* levelRenderer;

bool init(){
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout<<"unable to initialize video"<<endl;
        success = false;
    }
    else{
        window = SDL_CreateWindow("Level Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if(window == NULL){
            cout<<"Issue while creating the window"<<endl;
            success = false;
        }
        else{
            levelRenderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_PRESENTVSYNC);
            if(levelRenderer == NULL){
                cout<<"Issue in Renderer"<<endl;
                success = false;
            }
        }
    }
    return success;
}

int main(){
    if(!init()){
        cout<<"failed to initialize"<<endl;
    }
    else{
        bool quit = false;
            SDL_Event e;
            while(!quit){
                while(SDL_PollEvent(&e) != 0 ){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }
                }
            }
    }
    
    SDL_Quit();
    return 0;
}