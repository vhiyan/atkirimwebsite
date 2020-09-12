#include <ArduinoJson.h>
#define sim800 Serial1
//String link = "https://postb.in/b/1598889149403-2220193766988";
unsigned long currentTimeWifi[10], previousTimeWifi[10];
int state=0;
  int Timeout=0;
String sendMsg;
  String header;
  String body;
  unsigned int contentLength;
  String cmd;
  const char *msg ="";

float air_temperature,air_humidity,air_pressure,rain_gauge,wind_speed,soil_temp,soil_moist,soil_ph,soil_EC;
unsigned int wind_direction;

String host = "192.168.43.166";





void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  sim800.begin(115200);
  state=0;
  air_temperature=27.23;
  air_humidity=98.23;
  air_pressure=1100.00;
  rain_gauge = 3.23;
  wind_speed = 45.00;
  wind_direction = 180;
  soil_temp = 51.12;
  soil_moist = 81.23;
  soil_ph = 11.00;
  soil_EC = 9.00;

  init_wifi();
}

void loop() {


//send_cmd("AT+CREG?");
//
//send_cmd("AT+CGATT?");


loop_TCP();

//
//send_cmd("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
//
//send_cmd("AT+SAPBR=3,1,\"APN\",\"internet\"");
//
//send_cmd("AT+SAPBR=1,1");
//
//send_cmd("AT+SAPBR=2,1");
//
//send_cmd("AT+HTTPINIT");
//send_cmd("AT+HTTPSSL=1");
//
//send_cmd("AT+HTTPPARA =\"CID\",1");
//send_cmd("AT+HTTPPARA =\"URL\","+link);
//
//send_cmd("AT+HTTPACTION=0");
//delay(5000);
//send_cmd("AT+HTTPREAD");
//
//send_cmd("AT+HTTPTERM");
//send_cmd("AT+SAPBR=0,1");

//send_cmd("ATD+6281230192177;");

//send_cmd("AT+CBC");

}

void show_serial()
{
  while(sim800.available()!=0)
    Serial.write(char (sim800.read()));
}

void send_cmd(String cmd)
{
  sim800.println(cmd);
}

void loop_TCP()
{
//  send_cmd("AT+CGATT?");
//  send_cmd("AT+CSTT=\"internet\"");
//  send_cmd("AT+CIICR");


switch(state){
case 0:
if (timer(2,3000000)){
  send_cmd("AT+CIPSTART=\"TCP\",\"192.168.43.166\",3000");

  

  state=1;
} 
  break;
case 1:
if (timer(2,3000000)){
  
  header = createHeader(host,body.length());
  body = bodyJSON(air_temperature,air_humidity,air_pressure,rain_gauge,wind_speed,wind_direction,soil_temp,soil_moist,soil_ph,soil_EC);
  cmd = "AT+CIPSEND=";
  sendMsg =  cmd + (header.length()+body.length()+2);
  Serial.println(body.length());
    send_cmd(sendMsg);
  state=2;
} 
  
break;

case 2:

if (timer(2,1000000)){
 sim800.println(header+body);

 Serial.print(header+body);
 state=4;   
} 
break;
  case 3:
  break;

case 4:
if (timer(2,12000000)){
  send_cmd("AT+CIPCLOSE");
  state=0;
} 


break;
default:
  break;
}
}

void serialEvent1()
{
  show_serial();

//   if ((Serial1.find((char *)F("OK")) || Serial1.find((char *)F("ALREADY"))) && state==0) {
//      Serial.println("Connected");
//      state=1;
//    }
//    
//   if(Serial1.find((char *)F(">"))) {
//      
//      Serial.println("sending...");
//    };
//  if( Serial1.find((char *)F("SEND OK"))) {
//   // Serial.println("Packet sent");
//    state=4;
//  }
  
}
