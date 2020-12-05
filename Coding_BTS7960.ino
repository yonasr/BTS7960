/*
Coding ini dibuat untuk tutorial Youtube: 
Dibuat oleh : Yonatan K. A. Sarumaha untuk TechnoHance
Tanggal     : 5/12/2020

Follow IG TechnoHance     : @technohance
Subscribe YT TechnoHance  : @technohance
*/

//inisialisasi pin yang digunakan oleh Arduino Nano
#define RPWM 9 // Hubungkan pin D9 dengan pin RPWM BTS7960
#define LPWM 10 // Hubungkan pin D10 dengan pin LPWM BTS7960
#define PWM 11 // Hubungkan pin D11 dengan pin R_EN and L_EN BTS7960. Harus menggunakan pin PWM dari MicroController

//Function buat motor muter ke CW
void motor_CW() {
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, HIGH);
  analogWrite (PWM,500); //Value "100" bisa diganti dengan speed yang diinginkan (0-1024), atau menggunakan input potensio, atau yang lain
  Serial.println ("Muter Kanan");
}

//Function buat motor muter ke CCW
void motor_CCW() {
  digitalWrite (LPWM, HIGH);
  digitalWrite (RPWM, LOW);
  analogWrite (PWM,500); //Value "100" bisa diganti dengan speed yang diinginkan (0-1024), atau menggunakan input potensio, atau yang lain
  Serial.println ("Muter Kiri");
}

//Function buat motor STOP
void motor_stop() {
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, LOW);
  analogWrite (PWM,0);//Value "0" harus tetap 0, karena motornya diperintahkan untuk STOP
  Serial.println ("STOP");
}

//Inisialisasi program. Dijalankan hanya 1 kali
void setup() {
  Serial.begin (9600); //Buka serial monitor untuk melihat output ini. (CTRL+SHIFT+M)
  Serial.println ("Start");
  pinMode (RPWM, OUTPUT);
  pinMode (PWM, OUTPUT);
  pinMode (LPWM, OUTPUT);
}

//Main program
void loop() { 
  motor_CW(); //Muter CW 1 detik
  delay (1000); 
  motor_stop(); //STOP 1 detik
  delay (1000);
  motor_CCW(); //Muter CCW 1 detik
  delay (1000);
  motor_stop(); //STOP 1 detik
  delay (1000);
  //Loop terus
}
