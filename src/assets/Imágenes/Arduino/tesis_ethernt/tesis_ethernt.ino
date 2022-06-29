#include <EtherCard.h>
#define STATIC 0 // set to 1 to disable DHCP (adjust myip/gwip values below)

// mac address
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
// ethernet interface ip address
static byte myip[] = { 192,168,0,10 };
// gateway ip address
static byte gwip[] = { 192,168,0,1 };

// pines de control
int centuria = 8; //pin para la puerta de centuria
int s1 = 7;  //pin para el aula 1
int s2 = 6;  //pin para el aula 2
int tiempo_abierta=3000;

byte Ethernet::buffer[700];

char const page[] PROGMEM =
"HTTP/1.0 503 Service Unavailable\r\n"
"Content-Type: text/html\r\n"
"Retry-After: 600\r\n"
"\r\n"
"<html>"
"<head><title>"
"Service Temporarily Unavailable"
"</title></head>"
"<body>"
"<h3>This page is used behind the scene</h3>"
"<p><em>"
"Commands to control LED are transferred to Arduino.<br />"
"The syntax: http://192.168.0.XX/?LED10=OFF or ON"
"</em></p>"
"</body>"
"</html>"
;

void setup () {
pinMode(centuria, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
//digitalWrite(ledPin10,HIGH);
//digitalWrite(s1,HIGH);
//digitalWrite(s2,HIGH);

Serial.begin(9600);
Serial.println("Trying to get an IP...");

Serial.print("MAC: ");
for (byte i = 0; i < 6; ++i) {
Serial.print(mymac[i], HEX);
if (i < 5)
Serial.print(':');
}
Serial.println();

if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
{
Serial.println( "Failed to access Ethernet controller");
}
else
{
Serial.println("Ethernet controller access: OK");
}
;

#if STATIC
Serial.println( "Getting static IP.");
if (!ether.staticSetup(myip, gwip)){
Serial.println( "could not get a static IP");
blinkLed(); // blink forever to indicate a problem
}
#else

Serial.println("Setting up DHCP");
if (!ether.dhcpSetup()){
Serial.println( "DHCP failed");
blinkLed(); // blink forever to indicate a problem
}
#endif

ether.printIp("My IP: ", ether.myip);
ether.printIp("Netmask: ", ether.netmask);
ether.printIp("GW IP: ", ether.gwip);
ether.printIp("DNS IP: ", ether.dnsip);
}

void loop () {
word len = ether.packetReceive();
word pos = ether.packetLoop(len);
    
// Puerta principal abierta durante un tiempo n
if(strstr((char *)Ethernet::buffer + pos, "GET /?P_PRINCIPAL=ON ") != 0) {
Serial.println("Principal puerta abierta");
digitalWrite(centuria, HIGH);
delay(tiempo_abierta);
digitalWrite(centuria, LOW);
}
// Salon 101-1
if(strstr((char *)Ethernet::buffer + pos, "GET /?S_101_1=ON") != 0) {
digitalWrite(s1,HIGH);
delay(tiempo_abierta);
digitalWrite(s1, LOW);
}
// Salon 101-2
if(strstr((char *)Ethernet::buffer + pos, "GET /?S_101_2=ON") != 0) {
digitalWrite(s2, HIGH);
delay(tiempo_abierta);
digitalWrite(s2, LOW);
}
// show some data to the user
memcpy_P(ether.tcpOffset(), page, sizeof page);
ether.httpServerReply(sizeof page - 1);
delay(50);
}

void blinkLed(){
while(true){
digitalWrite(centuria, HIGH);
delay(500);
digitalWrite(centuria, LOW);
delay(500);
}
}
