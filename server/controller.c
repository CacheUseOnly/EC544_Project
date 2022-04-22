#include "controller.h"

/* init wiringPi */
void init() {
    wiringPiSetup();

    // init motor selection pins
    pinMode(P1, OUTPUT);
    pinMode(P2, OUTPUT);
    pinMode(P3, OUTPUT);

    // init operation pins
    pinMode(P4, OUTPUT);
    pinMode(P5, OUTPUT);
}

/* select motor */
int selectMotor(int motor) {
    switch (motor) {
        case 1:
            printf("select motor 1\n");
            digitalWrite(P1, LOW);
            digitalWrite(P2, LOW);
            digitalWrite(P3, HIGH);
            break;
        case 2:
            printf("select motor 2\n");
            digitalWrite(P1, LOW);
            digitalWrite(P2, HIGH);
            digitalWrite(P3, LOW);
            break;
        case 3:
            printf("select motor 3\n");
            digitalWrite(P1, LOW);
            digitalWrite(P2, HIGH);
            digitalWrite(P3, HIGH);
            break;
        case 4:
            printf("select motor 4\n");
            digitalWrite(P1, HIGH);
            digitalWrite(P2, LOW);
            digitalWrite(P3, LOW);
            break;
        case 5:
            printf("select motor 5\n");
            digitalWrite(P1, HIGH);
            digitalWrite(P2, LOW);
            digitalWrite(P3, HIGH);
            break;
        case 6:
            printf("select motor 6\n");
            digitalWrite(P1, HIGH);
            digitalWrite(P2, HIGH);
            digitalWrite(P3, LOW);
            break;
        default:
            perror("invalid motor number\n");
            return -1;
    }

    return 0;
}

int operate(operate_mode mode) {
    switch (mode) {
        case NOP:
            printf("NOP\n");
            digitalWrite(P4, LOW);
            digitalWrite(P5, LOW);
            break;
        case CW:
            printf("Rotate clockwise\n");
            digitalWrite(P4, LOW);
            digitalWrite(P5, HIGH);
            digitalWrite(P5, LOW);  // activate
            break;
        case CC:
            printf("Rotate counter-clockwise\n");
            digitalWrite(P4, HIGH);
            digitalWrite(P5, HIGH);
            digitalWrite(P5, LOW);  // activate
            break;
        default:
            perror("invalid mode\n");
            return -1;
    }

    return 0;
}

int handleInput(char* input) {
    int motor;
    char* mode;
    operate_mode op_mode;

    motor = input[3] - '0';
    if (motor < 1 || motor > 6) {
        perror("motor number\n");
        return -1;
    }

    mode = strtok(input, "-");
    if (strncmp("CC", mode, 2) == 0) {
        op_mode = CC;
    } else if (strncmp("CW", mode, 2) == 0) {
        op_mode = CW;
    } else {
        perror("operation mode\n");
        return -1;
    }

    selectMotor(motor);
    operate(op_mode);

    return 0;
}