/* map file, is included by world.c */

#define WORLD_SIZE_X 20
#define WORLD_SIZE_Y 20

//
// X is wall
// $ is treasure
// 1 is starting position player 1
// 2 is starting position player 2
//
static const char *initWorld[WORLD_SIZE_Y] =
  {"XXXXXXXXXXXXXXXXXXXX",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$XXXX$$$$$$$$X",
   "X$$$$$$XXXX$$$$$$$$X",
   "X$$$$$$XXXX$$$$$$$$X",
   "X$$$$$$XXXX$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$XXXXXX$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X     XXXXXX       X",
   "X     XXXXXX       X",
   "X     XXXXXX  12   X",
   "X     XXXXXX       X",
   "X$$$$$$$$$$$$$$$$$$X",
   "X$$$$$$$$$$$$$$$$$$X",
   "XXXXXXXXXXXXXXXXXXXX"};
