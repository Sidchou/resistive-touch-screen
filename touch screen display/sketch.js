
var serial; // variable to hold an instance of the serialport library
var fromSerial = 0; //variable to hold the data
var posX = 0,
  posY = 0,
  step = 10;


function setup() {
  createCanvas(400, 400);
  serial = new p5.SerialPort(); // make a new instance of  serialport librar
  serial.on('list', printList); // callback function for serialport list event
  serial.on('data', serialEvent); // callback for new data coming in
  serial.list(); // list the serial ports
  serial.open("/dev/cu.SLAB_USBtoUART"); // open a port

}

function draw() {
  background(100);
  if (fromSerial == 1) {
    //swip up
    beginShape();
    vertex(190, 190);
    vertex(170, 190);
    vertex(170, 210);
    vertex(190, 210);
    vertex(190, 230);
    vertex(210, 230);
    vertex(210, 210);
    vertex(230, 210);
     vertex(230, 190);
    vertex(210, 190);
    vertex(210, 170);
    vertex(190, 170);
    endShape(CLOSE);
  } else if (fromSerial == 2) {
        rect(170,190,60,20)
    //swip down
  } else if (fromSerial == 3) {
    //swip right
    triangle(210, 200, 170, 180, 170, 220);
    triangle(235, 200, 195, 180, 195, 220);

  } else if (fromSerial == 4) {
    //swip left
    triangle(190, 200, 230, 180, 230, 220);
    triangle(165, 200, 205, 180, 205, 220);
  }
}

// get the list of ports:
function printList(portList) {
  for (var i = 0; i < portList.length; i++) {
    // Display the list the console:
    println(i + " " + portList[i]);
  }
}

function serialEvent() {
  // this is called when data is recieved, data will then live in fromSerial
  fromSerial = serial.read();
}

/*
// Arduino Code
void setup() {
  Serial.begin(9600);
}
void loop() {
  int analogValue = analogRead(A0);
  byte byteToSend = map (analogValue, 0, 1023, 0, 255);
  Serial.write(byteToSend);
  delay(50);
}
*/
