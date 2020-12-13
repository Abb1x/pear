#include "../inc/renderer.hpp"
#include <iostream>

void Renderer::createWindow(const char* title, int w, int h)

{

      window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

}

void Renderer::createRenderer()

{
      
  renderer = SDL_CreateRenderer(window, -1, 0);

}

void Renderer::setRendererColor(int r,int g, int b, int a)

{
      

  SDL_SetRenderDrawColor(renderer,r,g,b,a);

}

void Renderer::clearRenderer()

{
      

  SDL_RenderClear(renderer);

}

void Renderer::renderPresent()

{
      
  SDL_RenderPresent(renderer);
}

void Renderer::destroyRenderer()

{
      
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

}

SDL_Texture* Renderer::loadTexture(const char* path)
{
      
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer,path);
  if(texture == NULL)
        
    {

      std::cout<<"Pear failed to load a texture, error: "<<SDL_GetError()<<std::endl;
    }
      
  return texture;
}

void Renderer::renderSprite(SDL_Texture* tex,int x, int y, float scale, double angle)
      
{
      
  int w, h;
  SDL_QueryTexture(tex, NULL, NULL, &w, &h);
  texr.x = x; texr.y = y; texr.w = w * scale  ; texr.h = h * scale; 
  SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
  SDL_RenderCopyEx(renderer, tex, NULL, &texr,angle,NULL,flip);
}

void Renderer::renderFont(SDL_Color color, const char* text, int size,const char* path, int x ,int y)
      
{
  
  TTF_Font * font = TTF_OpenFont(path,size);
  SDL_Surface * surface = TTF_RenderText_Solid(font,text, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = { x, y, texW, texH };
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
      
}

void Renderer::testAnimation()
      
{
      
  texr.x += 1;

}
