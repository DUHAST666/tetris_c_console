#include "main.h"

int main()
{
    init_map_static();
    spawn_fig();
    print_console();
    while(1){
        /* check_pressed_key();
        run_action();
        fall_fig();
        check_line_complite(); */
        next_posRot_fig();
        getch();
    }


    return 0;
}

void init_map_static()
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
 
char random_num(char max_val)
{
    char num;
    srand((unsigned int) time(NULL));          // #include <stdlib.h> and <time.h>
    num = (char) rand() % max_val+1;
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
            case LEFT:  spawn_fig();//move_left_fig();
                        break;
            case RIGHT: move_right_fig();
                        break;
            case DOWN:  speed_fall_fig();
                        break;
            case SPACE: next_posRot_fig();
                        break;
        }
        pressed_key = NONE;
        print_console();
    }  
}

void array_update()
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
                if (posRot == 0)
                    Map_dynamic[i][n] = figure[i_fig][n_fig];
                else if (posRot == 1)
                    Map_dynamic[i][n] = figure[n_fig][i_fig];
                n_fig++;
            }
            //printf("%d", Map_dynamic[i][n]);
        } 
        if (i >= posY && i < posY + SZ_FIG)
            i_fig++;
    }
}

void spawn_fig()
{
    char posRot = random_num(3);
    posX = FIG_SPWN_POS_X0;

    switch(random_num(6)){
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
    rotation_fig(posRot);
    array_update();
} 

void speed_fall_fig()
{

}

void move_left_fig()
{
    posX--;
    array_update();
}

void move_right_fig()
{
    posX++;
    array_update();
}

void rotation_fig(char countRot)
{
    char figure_temp[SZ_FIG][SZ_FIG];
    
    // вращаем count_rot раз 
    while(countRot != 0){
        countRot--;
        system("cls");
        // заполняем временый массив перевернутыми данными
        for (char i = 0; i < SZ_FIG; i++)
        { 
            for (char n = 0; n < SZ_FIG; n++)
            {
                figure_temp[i][n] = figure[n][SZ_FIG-1-i];
            }
        }
        // переносим из временного массива в текущий
        for (char i = 0; i < SZ_FIG; i++)
        { 
            printf("\n");
            for (char n = 0; n < SZ_FIG; n++)
            {
                figure[i][n] = figure_temp[i][n];
                printf("%d", figure[i][n]);
            }
        }
        printf("\n");
    }

}

void next_posRot_fig()
{
    if (posRot < 3) posRot++;
    else posRot = 0;
    rotation_fig(posRot);
    array_update();
}

void fall_fig()
{

}

void check_line_complite()
{

}

void print_console()
{
    system("cls");
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