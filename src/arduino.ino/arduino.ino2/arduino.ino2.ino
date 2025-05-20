int MRF = 5;
int MLF = 9;
int MRB = 6;
int MLB = 10;
void setup() {
  Serial.begin(9600);
  pinMode(MRF, OUTPUT);
  pinMode(MLF, OUTPUT);
  pinMode(MRB, OUTPUT);
  pinMode(MLB, OUTPUT);
}
void clear_buffer() {
  while (Serial.available() > 0) {
    Serial.read();
  }
}
void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    if (commaIndex > 0) {
      int difference_x = input.substring(0, commaIndex).toInt();
      int rayon = input.substring(commaIndex + 1).toInt();
      int vit_f = map(rayon, 30, 60, 255, 0);
      int vit_l = map(rayon, 30, 290, 255, 0);
      int vit_r = map(rayon, 350, 610, 255, 0);
      if (difference_x > 290 && difference_x < 350) {
        analogWrite(MRF, vit);
        analogWrite(MLB, vit);
      } else if (difference_x < 290) {
        analogWrite(MLF, vit_l);
        analogWrite(MRB, vit_l);
      } else if (difference_x > 350) {
        analogWrite(MRF, vit_r);
        analogWrite(MLB, vit_r);
      }
      clear_buffer();
    }
  }
}
