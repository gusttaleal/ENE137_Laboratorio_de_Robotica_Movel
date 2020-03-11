/*
%##########################################################################
%#               UNIVERSIDADE FEDERAL DE JUIZ DE FORA                     #
%#              GUSTAVO LEAL SILVA E SOUZA - 201469055B                   #
%##########################################################################
*/
int PWMA = 5, AIN1 = 6, AIN2 = 7, STBY = 8, BIN1 = 9, BIN2 = 10, PWMB = 11;
int MTA = 0, MTB = 0;

void setup() {

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  analogWrite(PWMA, MTA);
  analogWrite(PWMB, MTB);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  Serial.begin(9600);

}

void loop() {

  if (Serial.available() > 0) {
    char SerialData = Serial.read();
    switch (SerialData) {
      case 'a':
        digitalWrite(AIN1, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(AIN2, LOW);
        digitalWrite(BIN2, LOW);
        MTA = 120;
        MTB = 120;
        break;
      case 'b':
        digitalWrite(AIN1, LOW);
        digitalWrite(BIN1, LOW);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN2, HIGH);
        MTA = 120;
        MTB = 120;
        break;
      case 'c':
      //Não inércia
        digitalWrite(AIN1, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN2, HIGH);
        MTA = 0;
        MTB = 0;
        break;
      case 'd':
      //Inércia
        digitalWrite(AIN1, LOW);
        digitalWrite(BIN1, LOW);
        digitalWrite(AIN2, LOW);
        digitalWrite(BIN2, LOW);
        //Fazer o teste com PWM 0
        MTA = 120;
        MTB = 120;
        break;
      default:
        Serial.println("Default");
        break;
    }
  }
  analogWrite(PWMA, MTA);
  analogWrite(PWMB, MTB);
}
