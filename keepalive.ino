#include <WiFi.h>
#include <HTTPClient.h>

// ===== CONFIGURAÇÃO =====
const char* ssid = "SEU_WIFI";               // coloque sua rede Wi-Fi
const char* password = "SUA_SENHA";          // coloque a senha do Wi-Fi
const char* url = "https://seu-site-no-render.onrender.com"; // seu site no Render
const unsigned long interval = 10 * 60 * 1000; // 10 minutos em milissegundos
// =========================

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  unsigned long currentMillis = millis();

  // checa se já passou o intervalo para enviar o ping
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sendPing();
  }

  // mantém conexão Wi-Fi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi desconectado, tentando reconectar...");
    connectWiFi();
  }
}

void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado ao Wi-Fi!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha ao conectar. Tentará novamente no próximo loop.");
  }
}

void sendPing() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("Ping enviado! Código HTTP: %d\n", httpCode);
    } else {
      Serial.printf("Erro no ping: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  } else {
    Serial.println("Não conectado ao Wi-Fi. Ping não enviado.");
  }
}
