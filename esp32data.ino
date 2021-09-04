#include <WiFi.h>
#include <HTTPClient.h>
const char *ssid = "ASUSX555Q";  //Nama Wifi
const char *password = "welcomestark"; // pass wifi
bool Parsing = false;
String command;
int trig, cp1, cp2, cp3, cp4, cp5, cp6, cp7, cp8, cp9, cp10;

void setup() {
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}
void loop() {
  while (Serial.available()) {
    char dataParsing = Serial.read();
    if (dataParsing == '\n') {
      parseCommand(command);
      command = "";
    }
    else {
      command += dataParsing;
    }
  }
  Serial.println(trig);
  if (trig == 1) {
    String url = (String)"cp1=" + cp1 + "&cp2=" + cp2 + "&cp3=" + cp3 + "&cp4=" + cp4 + "&cp5=" + cp5 + "&cp6=" + cp6 + "&cp7=" + cp7 + "&cp8=" + cp8 + "&cp9=" + cp9 + "&cp10=" + cp10;
    kirim_data(url);
  }else{
    cp1 = 0;
    cp2 = 0;
    cp3 = 0;
    cp4 = 0;
    cp5 = 0;
    cp6 = 0;
    cp7 = 0;
    cp8 = 0;
    cp9 = 0;
    cp10 = 0;
  }
  delay(1000);
}

void kirim_data(String url) {
  HTTPClient http;
  http.begin("http://footwork.promonissanbogor.com/tambah-proses.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  auto httpCode = http.POST(url);
  String payload = http.getString();
  Serial.println(url);
  Serial.println(payload);
  http.end();
}

void parseCommand(String com) {
  String part1;
  String part2;
  part1 = com.substring(0, com.indexOf(" "));
  part2 = com.substring(com.indexOf(" ") + 1);
  if (part1.equalsIgnoreCase("trig")) {
    trig = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp1")) {
    cp1 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp2")) {
    cp2 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp3")) {
    cp3 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp4")) {
    cp4 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp5")) {
    cp5 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp6")) {
    cp6 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp7")) {
    cp7 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp8")) {
    cp8 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp9")) {
    cp9 = part2.toInt();
  }
  if (part1.equalsIgnoreCase("cp10")) {
    cp10 = part2.toInt();
  }
}
