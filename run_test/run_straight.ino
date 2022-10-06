// trace straight line

#define LF_WHEEL 0
#define LB_WHEEL 1
#define RF_WHEEL 2
#define RB_WHEEL 3
#define UNDEFINED_WHEEL -1

const int moter_r1 = 2;
const int moter_r2 = 3;

const int moter_l1 = 4;
const int moter_l2 = 5;

const int pwm_moter_r = 10;
const int pwm_moter_l = 11;

// 速度記憶用変数
int lf_speed = 0;   // 左前
int lb_speed = 0;   // 左後ろ
int rf_speed = 0;   // 右前
int rb_speed = 0;   // 右後ろ

int get_pwm(int wheel_key) {
    switch(wheel_key) {
        case LF_WHEEL:
        case LB_WHEEL:
            return pwm_moter_l;
        case RF_WHEEL:
        case RB_WHEEL:
            return pwm_moter_r;
        default:
            return UNDEFINED_WHEEL;
    }
}

int get_moter_pin_1(int wheel_key) {
    switch(wheel_key) {
        case LF_WHEEL:
        case LB_WHEEL:
            return moter_l1;
        case RF_WHEEL:
        case RB_WHEEL:
            return moter_r1;
        default:
            return UNDEFINED_WHEEL;
    }
}

int get_moter_pin_2(int wheel_key) {
    switch(wheel_key) {
        case LF_WHEEL:
        case LB_WHEEL:
            return moter_l2;
        case RF_WHEEL:
        case RB_WHEEL:
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

