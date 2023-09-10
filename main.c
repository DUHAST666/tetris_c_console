#include "main.h"

int main()
{
    char Map_static[N_LINE][N_COL];
    char Map_dynamic[N_LINE][N_COL];

    init_map_static(Map_static);
   
    
    while(1){
        spawn_fig(Map_static, Map_dynamic);
        print_console(Map_dynamic);
        check_pressed_key();
        run_action();
        fall_fig();
        check_line_complite();
        getch(); 
    }


    return 0;
}

void init_map_static(char (*Map_static)[N_COL])
{
    char i, n;

    for (i = 0; i < N_LINE; i++){
        //printf("\n");
        for (n = 0; n < N_COL; n++) {
            if (i != N_LINE - 1) 
                Map_static[i][n] = Map_static_part1[n];
            else Map_static[i][n] = Map_static_part2[n];
           //printf("%d", Map_static[i][n]);
        }
    }
}
 
char random_num_0to6()
{
    char num;
    srand((unsigned int) time(NULL));          // #include <stdlib.h> and <time.h>
    num = (char) rand() % 7;
    if (num < 0)
        num *= -1;
    return num;
}

void check_pressed_key()
{
   int code_key;

    if (kbhit()) {
        code_key = getch();
        if (code_key == FIRST_CODE_KEY_MOVE){
            switch(getch()){
                case KEY_LEFT:  pressed_key = LEFT;
                                break;
                case KEY_RIGHT: pressed_key = RIGHT;
                                break;
                case KEY_DOWN:  pressed_key = DOWN;
                                break;
            }
        }
        else if (code_key == KEY_SPACE)
            pressed_key = SPACE;
    } 
}

void run_action()
{
    if (pressed_key != NONE) {
        switch(pressed_key){
            case LEFT:  move_left_fig();
                        break;
            case RIGHT: move_right_fig();
                        break;
            case DOWN:  speed_fall_fig();
                        break;
            case SPACE: rotation_fig();
                        break;
        }
        pressed_key = NONE;
    }  
}

void array_update(char (*Map_static)[N_COL], char (*Map_dynamic)[N_COL], char (*figure)[SZ_FIG], char posX, char posY, char posRot)
{
    char n_fig = 0;
    char i_fig = 0;

    for (char i = 0; i < N_LINE; i++) {
       // printf("\n");
        n_fig = 0;

        for (char n = 0; n < N_COL; n++){
            Map_dynamic[i][n] = Map_static[i][n];
            if (n >= posX && n < posX + SZ_FIG &&
                i >= posY && i < posY + SZ_FIG) 
            {
                Map_dynamic[i][n] = figure[i_fig][n_fig];
                n_fig++;
            }
            //printf("%d", Map_dynamic[i][n]);
        } 
        if (i >= posY && i < posY + SZ_FIG)
            i_fig++;
    }
}

void spawn_fig(char (*Map_static)[N_COL], char (*Map_dynamic)[N_COL])
{
    char (*figure)[SZ_FIG];

    switch(random_num_0to6()){
        case 0: figure = Fig_sqr;
                break;
        case 1: figure = Fig_L1;
                break;
        case 2: figure = Fig_L2;
                break;
        case 3: figure = Fig_T;
                break;
        case 4: figure = Fig_I;
                break;
        case 5: figure = Fig_Z1;
                break;
        case 6: figure = Fig_Z2;
                break;
    }
        array_update(Map_static, Map_dynamic, figure, FIG_SPWN_POS_X0, 0, 0);
} 

void speed_fall_fig()
{

}

void move_left_fig()
{

}

void move_right_fig()
{

}

void rotation_fig()
{

}

void fall_fig()
{

}

void check_line_complite()
{

}

void print_console(char (*Map_dynamic)[N_COL])
{
    for (char i = 0; i < N_LINE; i++) {
        printf("\n");
        for (char n = 0; n < N_COL; n++){
            if (Map_dynamic[i][n] == 1) 
                printf("#");
            else printf(" ");
        }
    }
    printf("\n");
}