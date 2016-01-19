import processing.serial.*;
Serial myPort;        // The serial port
float xPos = 0;             // horizontal position of the graph
int max = 200;
int per_param = 0;
char inByte; 
int recval;
void setup () {
   // List all the available serial ports
  println(Serial.list());
 
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
 
}

 
void draw() {
  // get the byte:
       myPort.clear();
     delay(10);

   if (myPort.available() > 0) {

  inByte = myPort.readChar();
  // print it:
    println("recv:" + (int)inByte);
    recval = (int)inByte;
    recval = constrain(recval, 55, 200);


    }
  if(recval > max){
    max =  recval;}
 
 
  per_param = (max-recval)*100/max;
  println(per_param + "%");
  String[] params = {"C:/Users/asahoo264/Desktop/Courses/ECE516/ScreenBrightness.exe",str(per_param) + "%", "quit"};
  exec(params);
  
 
  delay(5000);
  
}