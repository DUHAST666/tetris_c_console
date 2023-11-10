#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define N_LINE 21
#define N_COL 15
#define SZ_FIG 4
#define FIG_SPWN_POS_X0 6
#define FIRST_CODE_KEY_MOVE 224
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
#define KEY_DOWN 80

typedef enum KEY {
    NONE,
    LEFT,
    RIGHT,
    DOWN,
    SPACE
} pressed_key_t;

pressed_key_t pressed_key = NONE;

typedef enum ERR_MSG {
    L_WALL,
    R_WALL,
    OK
} err_msg_t;

err_msg_t err_msg;

char Fig_sqr[SZ_FIG][SZ_FIG]= {{0,0,0,0},
                               {0,1,1,0},
                               {0,1,1,0},
                               {0,0,0,0}};
                     
char Fig_L1[SZ_FIG][SZ_FIG] = {{1,1,0,0},
                               {1,0,0,0},
                               {1,0,0,0},
                               {0,0,0,0}};
					 
char Fig_L2[SZ_FIG][SZ_FIG] = {{1,1,0,0},
                               {0,1,0,0},
                               {0,1,0,0},
                               {0,0,0,0}};
					 
char Fig_T[SZ_FIG][SZ_FIG]  = {{1,1,1,0},
                               {0,1,0,0},
                               {0,0,0,0},
                               {0,0,0,0}};
					 
char Fig_I[SZ_FIG][SZ_FIG]  = {{0,1,0,0},
                               {0,1,0,0},
                               {0,1,0,0},
                               {0,1,0,0}};
					 
char Fig_Z1[SZ_FIG][SZ_FIG] = {{0,1,1,0},
                               {1,1,0,0},
                               {0,0,0,0},
                               {0,0,0,0}};	

char Fig_Z2[SZ_FIG][SZ_FIG] = {{1,1,0,0},
                               {0,1,1,0},
                               {0,0,0,0},
                               {0,0,0,0}};	
					 
char Map_static_part1[N_COL] = {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0};
char Map_static_part2[N_COL] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0};
char posX;                          // начальная позиция фигуры по оси X
char posY;                          // начальная позиция фигуры по оси Y
char (*figure)[SZ_FIG];             // указатель на двумерный массив текущей фигуры
char Map_static[N_LINE][N_COL];     // карта с неподвижными объектами
char Map_dynamic[N_LINE][N_COL];    // карта для вывода движущейся фигуры

void init_map_static();
char random_num(char max_val);
void spawn_fig();
void speed_fall_fig();
void move_left_fig();
void move_right_fig();
void next_posRot_fig();
void rotation_fig(char countRot);
void write_temp_in_figure(char (*figure_temp)[SZ_FIG]);
void align_fig();
void check_pressed_key();
void run_action();
void print_console();
void fall_fig();
void check_line_complite();
void array_update();