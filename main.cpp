// Simple scenario of Python Turtle using C++
// Abthahi Ahmed Rifat - https://facebook.com/IAmAbthahi

#include <iostream>
#include <ctime>
#include <vector>
#include <SDL2/SDL.h>

using namespace std;

SDL_Window *win = SDL_CreateWindow("Basic Python Turtle | Abthahi Ahmed Rifat", 100, 100, 400, 400, SDL_WINDOW_SHOWN);
SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
bool isRunning  = true;
SDL_Event event;
// Function for generate random numbers
int random(int a, int b){
    return a + (rand() / (RAND_MAX / (b - a)));
}

int main (int arc, char *argc[]){
	
	int width, height; 
	SDL_GetRendererOutputSize(ren, &width, &height); // Getting Window Size

    struct node{
        int x;
        int y;
        SDL_Color color = {0,0,0,0};
    };
    
    
    vector<node> nodes;
    
    // Inserting points for circle
    for (int i = 0; i < 50; i++){
        
        int a = width / 2 + 100 * cos(i);
        int b = height / 2 + 100 * sin(i);
        
        SDL_Color c = {(Uint8)random(100, 255), (Uint8)random(100, 255), (Uint8)random(100, 255)};
        
        nodes.push_back({a, b, c});
        
    }
    // Inserting points for ring
    for (int i = 0; i < 50; i++){
        
        int a = width / 2 + 200 * cos(i);
        int b = height / 2 + 40 * sin(i);
        
        SDL_Color c = {(Uint8)random(100, 255), (Uint8)random(100, 255), (Uint8)random(100, 255)};
        
        nodes.push_back({a, b, c});
        
    }    
    
    // Initilizing
    int index = 0;
    int x = nodes[index].x, y = nodes[index].y;
    int px = nodes[index].x, py = nodes[index].y;
    int tx = nodes[index + 1].x, ty = nodes[index + 1].y;
    
	while(isRunning){
		SDL_PollEvent(&event);
    
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);		
		
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        
        // Drawn Image
        if (index > 0){
            for (int i = 1; i <= index; i++){
//                cout<<nodes[i].x<<" "<<nodes[i].y<<endl;
                if (nodes[i].x != -1){
                    SDL_SetRenderDrawColor(ren, nodes[i].color.r, nodes[i].color.g, nodes[i].color.b, 255);
                    SDL_RenderDrawLine(ren, nodes[i - 1].x, nodes[i - 1].y, nodes[i].x, nodes[i].y);
                } 
            }
        }
        
        if (nodes[index].x != -1){
            SDL_RenderDrawLine(ren, px, py, x, y);
        }
        
        SDL_Rect indic = {x - 5, y - 5, 10, 10};
        SDL_RenderDrawRect(ren, &indic);
        
        // Login for drawing
        if (index < (int)nodes.size() - 1){
            if (x < tx) x++;
            if (x > tx) x--;
            if (y < ty) y++;
            if (y > ty) y--;
            
            if (x == tx && y == ty){   
                
                index++;
                
                px = nodes[index].x, py = nodes[index].y;
                x = nodes[index].x, y = nodes[index].y;
                tx = nodes[index + 1].x, ty = nodes[index + 1].y;
            }
        }
        
        // FPS
        SDL_Delay(1000/260);
		SDL_RenderPresent(ren);
		if (event.type == SDL_QUIT){
			isRunning = false;
		}		
	}
	
}