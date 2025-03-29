# Oficina IoT - Telemetria
Repositório de código para oficina de IoT para cursos EAD Unisantos

Essa oficina tem como objetivo demonstrar a criação de um protótipo de telemetria utilizando como microcontrolador o ESP32, enviando dados a plataforma ThingSpeak através de consumo de uma API da própria plataforma.

# O circuito
Para a montagem do circuito será utilizada a lista de componentes abaixo
- 1 Resistor de 10K
- 1 sensor LDR analógico
- 1 microcontrolador Nodemcu ESP32-WROOM-32

As conexões do circuito segue conforme imagem abaixo:
![Texto Alternativo](URL_da_imagem)

# Plataforma ThingSpeak
- Necessário logar, ou criar uma conta caso não tenha, no site ThingSpeak (https://thingspeak.mathworks.com/)
- Após logar é necessário criar um canal, clicar no menu "Channel", opção "My Channels"
  - Clicar no botão "New Channel"
  - Preencher os campos "Name" e "Description" (Sugestão: "Name= Luminosidade" e "Description= Teste de luminosidade")
  - Preecnher o campo "Field 1" (Sugestão: "Field 1= Sensor LDR")
- Após criar o canal, entrar no canal e anotar o ID do canal, conforme imagem abaixo
  ![Texto Alternativo](URL_da_imagem)
- Clicar na aba "API Keys" e copiar a chave de escrita "Write API Key"

# Código-fonte
O código-fonte está representado no arquivo ldr_thinkspeak.ino, algumas adaptações talvez tenham que ser realizadas conforme o caso
- Conexão Wifi
  

