mkdir -p out/

clang-format -i *.c *.h

gcc *.c -Ofast -g -fuse-ld=gold -o out/mp3-player `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread && ./out/mp3-player
