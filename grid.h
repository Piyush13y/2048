//#define size 8
typedef struct grid{
	int a[8][8] ;//[size][size];
	int i;
	int size;
}grid;
void initial(grid *g);
void move_left(grid *g, int *flag1, int *score);
void print_board(grid *g, int score);
void acw_rotate(grid *g);
void move_right(grid *g, int *flag1, int * score);
void move_up(grid *g, int *flag1, int * score);
void move_down(grid *g, int * flag1, int * score);

