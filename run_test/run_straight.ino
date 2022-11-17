// trace straight line

#define L_WHEEL 0
#define R_WHEEL 1
#define UNDEFINED_WHEEL -1

const int moter_r1 = 2;
const int moter_r2 = 3;

const int moter_l1 = 4;
const int moter_l2 = 5;

const int pwm_moter_r = 10;
const int pwm_moter_l = 11;

// 速度記憶用変数
int l_speed = 0;   // 左
int r_speed = 0;   // 右

int get_pwm(int wheel_key) {
    switch(wheel_key) {
        case L_WHEEL:
            return pwm_moter_l;
        case R_WHEEL:
            return pwm_moter_r;
        default:
            return UNDEFINED_WHEEL;
    }
}

int get_moter_pin_1(int wheel_key) {
    switch(wheel_key) {
        case L_WHEEL:
            return moter_l1;
        case R_WHEEL:
            return moter_r1;
        default:
            return UNDEFINED_WHEEL;
    }
}

int get_moter_pin_2(int wheel_key) {
    switch(wheel_key) {
        case L_WHEEL:
            return moter_l2;
        case R_WHEEL:
            return moter_r2;
        default:
            return UNDEFINED_WHEEL;
    }
}

// 車輪のスピード制御
void update_wheel_speed(int wheel_key, long speed) {
    int moter_1 = get_moter_pin_1(wheel_key);
    int moter_2 = get_moter_pin_2(wheel_key);
    int pwm = get_pwm(wheel_key);
    if (speed >= 0) {
        digitalWrite(moter_1, HIGH);
        digitalWrite(moter_2, LOW);
    } else {
        digitalWrite(moter_1, LOW);
        digitalWrite(moter_2, HIGH);
    }
    analogWrite(pwm, (speed >= 0) ? speed : -speed);
}

void setup() {

    pinMode(moter_r1, OUTPUT);
    pinMode(moter_r2, OUTPUT);
    pinMode(moter_l1, OUTPUT);
    pinMode(moter_l2, OUTPUT);
    pinMode(pwm_moter_r, OUTPUT);
    pinMode(pwm_moter_l, OUTPUT);

    Serial.begin(9600);
    
}

void loop() {

}

