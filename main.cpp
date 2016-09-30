#include <stdio.h>
#include <allegro.h>


using namespace std;

void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}

int main()
{
    inicia_allegro(640, 480);
    install_mouse();

    BITMAP *buffer = create_bitmap(640, 480);
    BITMAP *fondo1 = load_bitmap("FONDO1.bmp", NULL);
    BITMAP *fondo2 = load_bitmap("FONDO2.bmp", NULL);
    BITMAP *fondo3 = load_bitmap("FONDO3.bmp", NULL);
    BITMAP *cursor = load_bitmap("cursor.bmp", NULL);

    bool salida = false;

    while(!salida){
        if(mouse_x > 130 && mouse_x < 510 &&
           mouse_y > 170 && mouse_y < 225){

            blit(fondo2, buffer,0,0,0,0,640,480);
            if(mouse_b & 1){
                salida = true;
            }
        }else if(mouse_x > 200 && mouse_x < 420 &&
                 mouse_y > 260 && mouse_y < 315){

                 blit(fondo3, buffer,0,0,0,0,640,480);blit(fondo3, buffer,0,0,0,0,640,480);
                 if(mouse_b & 1){
                    salida = true;
                }
        }else blit(fondo1, buffer,0,0,0,0,640,480);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen,0,0,0,0,640,480);
    }//while
    destroy_bitmap(buffer);
    return 0;
}END_OF_MAIN();
