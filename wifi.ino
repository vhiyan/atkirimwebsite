String ssid="Wifihp";
String password="thetering1234";
String cmdconnect="";

void init_wifi()
{
  Serial1.println("AT+RST");
  delay(4000);
  show_serial();
  Serial1.println("AT+CIPMUX=0");  
  delay(4000);
  show_serial();
  cmdconnect = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";
  Serial1.println(cmdconnect);
  delay(3000);
   show_serial();
  Serial1.println("AT+CWMODE=1");
  delay(5000);
 show_serial();
  Serial1.println("AT+CWMODE=1");
  delay(5000);
 show_serial();
  Serial1.println("AT+CIPCLOSE");
  delay(5000);
  show_serial();
  send_cmd("AT+CIFSR");
  delay(5000);
  show_serial();

}
