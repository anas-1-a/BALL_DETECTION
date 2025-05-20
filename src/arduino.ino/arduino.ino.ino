int led_v = 13;
int led_r = 4;
int led = 2;
int mf = 5;
int mb = 6;
void setup() {
  Serial.begin(9600);
  pinMode(mf , OUTPUT);
  pinMode(mb , OUTPUT);
  pinMode(led_v , OUTPUT);
}
void clear_buffer() {
  while (Serial.available() > 0) {
    Serial.read();
  }
}
void loop() {
  if (Serial.available() > 0) {
    String str_distance = Serial.readStringUntil('\n');
    int distance = str_distance.toInt();
    int vit = map(diff, 30 , 60, 255, 0);
    
    if (-67<diff>67) {
      analogWrite(led_v , vit);
    }
    if (320 > diff  ) {
      analogWrite(mf, vit);
    }
    else if (320 < diff) {
      analogWrite(mb, vit);
    }
    clear_buffer();
  }
}