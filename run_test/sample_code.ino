// sample_code

const int moter_r1 = 2;
const int moter_r2 = 3;

const int moter_l1 = 4;
const int moter_l2 = 5;

const int pwm_moter_r = 10;
const int pwm_moter_l = 11;

const int sensor = A3;

int val = 0;

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
    val = analogRead(sensor);

    Serial.print(val);

    digitalWrite(moter_l1, HIGH);
    digitalWrite(moter_l2, LOW);
    analogWrite(pwm_moter_l, 150);

    digitalWrite(moter_r1, HIGH);
    digitalWrite(moter_r2, LOW);
    analogWrite(pwm_moter_r, 150);

    delay(20);
}

