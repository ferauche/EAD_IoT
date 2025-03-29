# Oficina IoT - Telemetria
Repositório de código para oficina de IoT para cursos EAD Unisantos

Essa oficina tem como objetivo demonstrar a criação de um protótipo de telemetria utilizando como microcontrolador o ESP32, enviando dados a plataforma ThingSpeak através de consumo de uma API da própria plataforma.

# O circuito
Para a montagem do circuito será utilizada a lista de componentes abaixo
- 1 Resistor de 10K
- 1 sensor LDR analógico
- 1 microcontrolador Nodemcu ESP32-WROOM-32

As conexões do circuito segue conforme imagem abaixo:
- Resistor está conectado entre o GND e um terminal do LDR
- Outro terminal do LDR está conectado ao pino 32
- O pino 33 está conectado no terminal do LDR conectado ao resistor
<br>![Circuito](https://github.com/ferauche/EAD_IoT/blob/main/circuito.png)

# Plataforma ThingSpeak
- Necessário logar, ou criar uma conta caso não tenha, no site ThingSpeak (https://thingspeak.mathworks.com/)
- Após logar é necessário criar um canal, clicar no menu "Channel", opção "My Channels"
  - Clicar no botão "New Channel"
  - Preencher os campos "Name" e "Description" (Sugestão: "Name= Luminosidade" e "Description= Teste de luminosidade")
  - Preecnher o campo "Field 1" (Sugestão: "Field 1= Sensor LDR")
- Após criar o canal, entrar no canal e anotar o ID do canal, conforme imagem abaixo
  <br>![Id Channel](https://github.com/ferauche/EAD_IoT/blob/main/channel_Id.png)
- Clicar na aba "API Keys" e copiar a chave de escrita "Write API Key"
  <br>![API Key](https://github.com/ferauche/EAD_IoT/blob/main/api_keys.png)

# Código-fonte
Para compilar o código é necessário instalar a biblioteca ThingSpeak no Arduino IDE, para realizar a instação siga os passos abaixo:
- Abrir o Arduino IDE e clicar no Menu "Ferramentas", opção "Gerenciador de Bibliotecas"
- Filtrar pelo palavra "ThingSpeak" e clicar no botão "Instalar".
  <br>![ThinkSpeak Lib](https://github.com/ferauche/EAD_IoT/blob/main/thinkspeak_lib.png) 

O código-fonte está representado no arquivo [ldr_thinkspeak.ino](https://github.com/ferauche/EAD_IoT/blob/main/ldr_thinkspeak.ino), algumas adaptações talvez tenham que ser realizadas conforme o caso.
- Conexão Wifi: SSID e Senha são configurados nas linhas 4 e 5
- Configurações do ThingSpeak: ID do canal e chave de API são configurados nas linhas 8 e 9

Basta compilar e fazer o upload do arquivo ldr_thinkspeak.ino para o ESP32, e não apresentando nenhum erro, deve-se abrir o "Serial Monitor" e verificar as mensagens de conexão Wifi, leitura de luminonisdade e envio dos dados ao ThinkgSpeak
<br>![Serial Monitor](https://github.com/ferauche/EAD_IoT/blob/main/serial_monitor.png)
  

