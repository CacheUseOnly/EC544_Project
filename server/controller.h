/**
 * 17   27  22  selection
 * 0    0   1   M1
 * 0    1   0   M2
 * 0    1   1   M3
 * 1    0   0   M4
 * 1    0   1   M5
 * 1    1   0   M6
 *
 * 5    6   operation
 * x    0   NOP
 * 0    1   clockwise rotation (cw)
 * 1    1   counter-clockwise  (cc)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define P1 17
#define P2 27
#define P3 22
#define P4 5
#define P5 6

typedef enum _mode {
    NOP,
    CW,
    CC,
} operate_mode;

void init();
int selectMotor(int motor);
int operate(operate_mode mode);
int handleInput(char* input);
