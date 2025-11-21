````bash
esp32-keepalive/
│
├── keepalive.ino        # Código principal para Arduino IDE
├── README.md            # Explicação do projeto
└── LICENSE              # Opcional, me dá licença que eu quero passar
````


# ESP32 Keep-Alive para Render Free Tier

Este projeto mantém um site hospedado no Render Free Tier acordado 24/7, enviando requisições HTTP periódicas usando um ESP32.

## Requisitos

- ESP32
- IDE Arduino
- Biblioteca WiFi e HTTPClient (já inclusas na IDE do ESP32)

## Como usar

1. Abra o arquivo `keepalive.ino` na Arduino IDE.
2. Substitua `SEU_WIFI` e `SUA_SENHA` com os dados da sua rede.
3. Substitua `https://seu-site-no-render.onrender.com` pelo link do seu site.
4. Compile e envie para o ESP32.
5. Abra o Serial Monitor para ver os pings enviados a cada 10 minutos.

## Observações

- O ESP32 precisa estar sempre ligado e conectado ao Wi-Fi.
- O intervalo de ping é configurável pelo delay no código (`600000` ms = 10 minutos).
- Este script mantém sites no Render Free Tier acordados evitando que entrem em sleep.


# 💡 Observações importantes:

- Flash Frequency: 80 MHz é seguro para todos os módulos genéricos.

- Upload Speed: 115200 garante que a IDE consiga enviar o código sem erros.

- Partition Scheme: “Default 4MB with spiffs” funciona bem para projetos simples, como seu keepalive.
