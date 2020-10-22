 const int CLK_PIN = 9;  // to Clk on encoder
 const int DT_PIN = 8;  // to DT on encoder
 const int SW_PIN = 7;  // to Btn on encoder
 
 const int LedSwitcherPin = 5; // Pin 5 to Transistor PWM

 int clk, prevClk;
 int value = 120;
 
 void setup() { 
   pinMode (LED_BUILTIN, OUTPUT);
   pinMode (CLK_PIN, INPUT);
   pinMode (DT_PIN, INPUT);
   pinMode (LedSwitcherPin, OUTPUT);
   analogWrite(LedSwitcherPin, value);
   prevClk = digitalRead(CLK_PIN);
   signOk();
 } 

 void loop() {
   clk = digitalRead(CLK_PIN);
   if (clk != prevClk) { changeState(); };
   prevClk = clk;
   delay(1);
 } 

 void changeState () {
   int data = digitalRead(DT_PIN);
   boolean movingUp = data != clk;

   if (movingUp) {
     if (value < 250) value += 10;
   } else {
     if (value > 0) value -= 10;
     
   }

   digitalWrite(LED_BUILTIN, value == 250);
   analogWrite(LedSwitcherPin, value);
 }

 void signOk () {
   for (int i = 1; i < 4; i++) {
     digitalWrite(13, HIGH);
     delay(200);
     digitalWrite(13, LOW);
     delay(200);
   }
 }
