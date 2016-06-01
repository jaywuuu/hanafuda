#include <SDL.h>

#ifdef __cplusplus
    extern "C"
#endif

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return -1;
    }

    SDL_Quit();
    return 0;
}