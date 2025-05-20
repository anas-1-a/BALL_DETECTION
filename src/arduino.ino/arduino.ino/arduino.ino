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
    String message = Serial.readStringUntil('\n');
    message.trim();
    int parti_lowla = message.indexOf(',');
    int parti_thenia = message.indexOf(',', parti_lowla + 1);
    if (parti_lowla > 0 && parti_thenia > parti_lowla) {
      int direction = message.substring(0, parti_lowla).toInt();
      int distance = message.substring(parti_lowla + 1, parti_thenia).toInt();
      int rotate = message.substring(parti_thenia + 1).toInt();
      int vit_f = map(distance, 30, 60, 255, 0);  
      int vit_l = map(direction, 30, 300, 255, 0);  
      int vit_r = map(direction, 350, 610, 0, 255);  
      if (rotate == 1) {
        if (direction > 290 && direction < 350) {
          analogWrite(MRF, vit_f);
          analogWrite(MLF, vit_f);
        } else if (direction < 290) {
          analogWrite(MLF, vit_l);
          analogWrite(MRB, vit_l);
        } else if (direction > 350) {
          analogWrite(MRF, vit_r);
          analogWrite(MLB, vit_r);
        }
      } else {
        analogWrite(MLF, 100);
        analogWrite(MRB, 100);
      }
      clear_buffer();
    }
  }
}
