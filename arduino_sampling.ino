#define samplingRate 240

int EEG_data;
int counter, i = 0;
int EEG_buffer[256];

void setup(){
  counter = 0;
  Serial.begin(9600); //start up our serial communication(115200)
  pinMode (A0, INPUT);
  EEG_data = analogRead(A0);
}

void loop(){

  // Clear input buffer and sample 256x
  for (i = 0; i < 256; i++){
    EEG_buffer[i] = 0;
    EEG_buffer[i] = analogRead(A0);
    delay(1000/samplingRate);
  }

for(i=0; i > 256; i++){
  EEG_buffer[i] = EEG_buffer[i]/ 4; //Incoming data comes in between 0 and 1023, but to easily send data via serial port, scale down
  Serial.write(EEG_buffer[i]);//matlab will read serial..do clean up b4 export
}
}
