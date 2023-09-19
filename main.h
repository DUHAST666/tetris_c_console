#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

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
} type_pressed_key;

type_pressed_key pressed_key = NONE;

char Fig_sqr[SZ_FIG][SZ_FIG]= {{0,1,1,0},
                               {0,1,1,0},
                               {0,0,0,0},
                               {0,0,0,0}};
                     
char Fig_L1[SZ_FIG][SZ_FIG] = {{0,1,1,0},
                               {0,1,0,0},
                               {0,1,0,0},
                               {0,0,0,0}};
					 
char Fig_L2[SZ_FIG][SZ_FIG] = {{0,1,1,0},
                               {0,0,1,0},
                               {0,0,1,0},
                               {0,0,0,0}};
					 
char Fig_T[SZ_FIG][SZ_FIG]  = {{0,1,1,1},
                               {0,0,1,0},
                               {0,0,0,0},
                               {0,0,0,0}};
					 
char Fig_I[SZ_FIG][SZ_FIG]  = {{0,0,1,0},
                               {0,0,1,0},
                               {0,0,1,0},
                               {0,0,1,0}};
					 
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
char PosRot = 0;
char (*figure)[SZ_FIG];
char Map_static[N_LINE][N_COL];
char Map_dynamic[N_LINE][N_COL];

void init_map_static();
char random_num_0to6();
void spawn_fig();
void speed_fall_fig();
void move_left_fig();
void move_right_fig();
void rotation_fig();
void check_pressed_key();
void run_action();
void print_console();
void fall_fig();
void check_line_complite();
void array_update(char posX, char posY);