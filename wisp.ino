#include <WiFi.h>
#include <WebServer.h>

const char* apName = "ESP32-Scanner";
const char* apPassword = "12345678";

WebServer server(80);

unsigned long bootTime;

struct WiFiData {

  String ssid;
  int rssi;
  int channel;
  bool open;
};

WiFiData networks[50];

int networkCount = 0;

void scanWiFi() {

  networkCount = WiFi.scanNetworks();

  for (int i = 0; i < networkCount && i < 50; i++) {

    String name = WiFi.SSID(i);

    if (name == "") {

      name = "<Hidden Network>";
    }

    networks[i].ssid = name;

    networks[i].rssi = WiFi.RSSI(i);

    networks[i].channel = WiFi.channel(i);

    networks[i].open =
      (WiFi.encryptionType(i) == WIFI_AUTH_OPEN);
  }
}

String signalBars(int rssi) {

  int width = 20;

  if (rssi >= -50) width = 100;

  else if (rssi >= -60) width = 80;

  else if (rssi >= -70) width = 60;

  else if (rssi >= -80) width = 40;

  else width = 20;

  String color = "#ff3333";

  if (rssi >= -60)
    color = "#00ff00";

  else if (rssi >= -75)
    color = "#ffff00";

  String html = "";

  html += "<div style='width:120px;";
  html += "height:12px;";
  html += "border:1px solid #00ff66;";
  html += "border-radius:10px;";
  html += "overflow:hidden;'>";

  html += "<div style='height:100%;";
  html += "width:";
  html += String(width);
  html += "%;";
  html += "background:";
  html += color;
  html += ";'></div>";

  html += "</div>";

  return html;
}

String createPage() {

  String page = "";

  page += "<!DOCTYPE html>";

  page += "<html>";

  page += "<head>";

  page += "<meta name='viewport' ";
  page += "content='width=device-width, initial-scale=1'>";

  page += "<meta http-equiv='refresh' content='5'>";

  page += "<title>ESP32 Cyber Scanner</title>";

  page += "<style>";

  page += "body{";
  page += "background:black;";
  page += "color:#00ff66;";
  page += "font-family:monospace;";
  page += "padding:15px;";
  page += "}";

  page += "h1{";
  page += "color:#00ffff;";
  page += "text-shadow:0 0 15px #00ffff;";
  page += "}";

  page += ".card{";
  page += "background:#050505;";
  page += "border:1px solid #00ff66;";
  page += "border-radius:15px;";
  page += "padding:15px;";
  page += "margin-top:15px;";
  page += "box-shadow:0 0 20px #00ff66;";
  page += "}";

  page += ".btn{";
  page += "background:#00ff66;";
  page += "color:black;";
  page += "border:none;";
  page += "padding:15px;";
  page += "font-size:18px;";
  page += "border-radius:12px;";
  page += "width:100%;";
  page += "}";

  page += ".radar{";
  page += "width:120px;";
  page += "height:120px;";
  page += "border:2px solid #00ff66;";
  page += "border-radius:50%;";
  page += "margin:auto;";
  page += "animation:spin 4s linear infinite;";
  page += "}";

  page += "@keyframes spin{";
  page += "from{transform:rotate(0deg);}";

  page += "to{transform:rotate(360deg);}";
  page += "}";

  page += "</style>";

  page += "</head>";

  page += "<body>";

  page += "<h1>SUNDAY STARTING</h1>";

  page += "<h2>Portable WiFi Scanner</h2>";

  page += "<div class='radar'></div>";

  page += "<div class='card'>";

  page += "<h3>Device Info</h3>";

  page += "IP Address: ";

  page += WiFi.softAPIP().toString();

  page += "<br><br>";

  page += "Uptime: ";

  page += String((millis() - bootTime) / 1000);

  page += " sec";

  page += "<br><br>";

  page += "Free RAM: ";

  page += String(ESP.getFreeHeap());

  page += "<br><br>";

  page += "Networks Found: ";

  page += String(networkCount);

  page += "</div>";

  page += "<div class='card'>";

  page += "<h3>WiFi Networks</h3>";

  for (int i = 0; i < networkCount; i++) {

    page += "<div class='card'>";

    page += "<b>";

    page += networks[i].ssid;

    page += "</b>";

    page += "<br><br>";

    page += "Signal Strength:<br><br>";

    page += signalBars(networks[i].rssi);

    page += "<br>";

    page += String(networks[i].rssi);

    page += " dBm";

    page += "<br><br>";

    page += "Channel: ";

    page += String(networks[i].channel);

    page += "<br><br>";

    if (networks[i].open) {

      page += "🔓 Open Network";

    } else {

      page += "🔒 Secured Network";
    }

    page += "</div>";
  }

  page += "</div>";

  page += "<div class='card'>";

  page += "<h3>Channel Analyzer</h3>";

  for (int ch = 1; ch <= 13; ch++) {

    int count = 0;

    for (int i = 0; i < networkCount; i++) {

      if (networks[i].channel == ch) {

        count++;
      }
    }

    if (count > 0) {

      page += "Channel ";

      page += String(ch);

      page += " : ";

      page += String(count);

      page += " networks";

      page += "<br>";
    }
  }

  page += "</div>";

  page += "<br>";

  page += "<form action='/scan'>";

  page += "<button class='btn'>SCAN AGAIN</button>";

  page += "</form>";

  page += "</body>";

  page += "</html>";

  return page;
}

void handleRoot() {

  server.send(200, "text/html", createPage());
}

void handleScan() {

  scanWiFi();

  server.sendHeader("Location", "/");

  server.send(303);
}

void setup() {

  Serial.begin(115200);

  bootTime = millis();

  WiFi.mode(WIFI_AP);

  WiFi.softAP(apName, apPassword);

  scanWiFi();

  Serial.println();

  Serial.println("ESP32 Cyber Scanner Started");

  Serial.print("Open Browser: ");

  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);

  server.on("/scan", handleScan);

  server.begin();
}

void loop() {

  server.handleClient();
}