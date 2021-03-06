# EPTA ( Joao Barboza Rodrigues )
 Program designed to recreate the trajectory of a rocket for the Propulsion and Aeronautical Technology Team and all the codes researched and developed during my trainee project.
 
# Algorithm ( trajectory reconstitution )

To achieve the program goal , first the data is treated and converted to the csv format, then , using the csv library , the data is processed into a dictionary ignoring the empty lines. After beeing stores in the dictionary the data is read and inserted into lists , wich enables the library mathplotlib to read it (Dictionary are used just to simplify the coding if another function needs to be added ). Finally , the matplolib library plots a 3d graph with the rocket trajectory and 2d graphs with a vision from each axes , it also plots a graph of accelleration , ground speed and verticle speed x time. 

# Trainee Research

Basically my project, as a trainee, was to research about ESP32, the LoRa and NRF25L01 radio modules, SD CARD modules and de accelerometer module MPU9250. The texts will be displayed in portuguese for now, because the priority is to display accessible information to all EPTA members, even if the don´t know English very well. In the future the descriptions will be displayed in the two languages.

# Esp32

![alt text](https://www.curtocircuito.com.br/pub/media/catalog/product/cache/8550e88b3e2f562f4a5046962e3b9f42/p/l/placa_doit_esp32_-_esp-wroom-32_-_wifi_bluetooth.jpg)

 O ESP32 é um microcontrolador desenvolvido pela empresa eespressif, sendo um dispositivo com alta confiabilidade, podendo se adaptar facilmente a condições adversa, tendo uma margem de operação de -40°C à 125°C. Desenvolvido principalmente para dispositivos móveis e apliações de IOT (Internet Of Things) o ESP32 tem um baixissimo consumo de energia e diversos modos de operação.
 
 
 O dispositivo possui alto grau de integração, oferecendo módulo que já integram emissores e receptores de rádio, amplificadores, filtros e módulos de ajuste de potência por um preço aceessivel. Também é interessante ressaltar que o ESP32 possui chips wi-fi e bluetooth já integrados, oferecendo alto nível de integração.
 
 
 Com relação a especificações técnicas, o microcontrolador emprega o microprocessador Tensilica Xtensa LX6, em variações com um ou dois núcleos, operando entre 160 e 240MHz. Possui 520KB de SRAM. A programação direcionada para o ESP32 funciona em diversos frameworks, citando especialmente, arduino IDE e Espressif IoT Development Framework, framework da própria Espressif.
 
# Rádio LoRa

![alt text](https://uploads.filipeflop.com/2019/02/6WL84-5.jpg)


A tecnologia LoRa é uma tecnologia que visa permitir comunicações a longas distâncias com o mínimo de consumo de energia, ideal para aplicações utilizando o ESP32, que também 
visa o mínimo consumo de energia. Basicamente se baseia em uma rede com topolia estrela e utiliza gateways específicos para enviar e receber dados.


Em geral, emissores que utilizam a tecnologia LoRa podem chegar a ter um alcance de até 12Km em zonas rurais, alcance que é reduzido em áreas urbanas devido a obstáculos como prédios. A tecnologia LoRa é baseada em uma técnica conhecida como “Chirp spread spectrum modulation“, utilizada a muito tempo por sistemas mais complexos, mas que sempre esteve caminhando junto com altos custos. A tecnologia LoRa foi a primeira capaz de implementar a técnica com componentes de custo reduzido e para uso comercial.


Sistemas de comunicação LoRa utilizam o protocolo LoRaWAN, que inplementa detalhes realtivos ao funcionamento do sistema e otimiza tudo relativo a comunicação. O protocolo pode ser dividido em 4 camadas, snedo elas os servidores das aplicações, os servidores de rede, os gateways utilizados que já foram citados anteriormente e os módulos (end-points). Nas américas a frequência de operação LoRa está entre 902MHz e 928MHz.


# Rádio NRF24L01

![alt text](https://5.imimg.com/data5/LN/GP/YG/SELLER-27298097/nrf24l01-module-with-antenna-500x500.jpg)


 Diferente do rádio LoRa, desenvolvido para aplicações que devem ter grande alcance, os módulos de rádio NRF24L01 possuem um alcance muitoo reduzido e operam com tecnologias diferentes. É pela Nordic e pode ser utilizado para operações que necessitam de comunicação entra dispositivos como ESP32 e Arduino. Seu alcance pode chegar a 50 metros em ambientes rurais (Algumas fontes afirmam que módulos mais recentes e com mais tecnologia embarcada podem atingir 100m).


 O módulo faz pequenas conexões do circuito integrado utilizando capacitores, resistores e um cristal de 16MHz, simplificando muito a ligação com um microcontrolador. Basicamente opera entre 2.4GHz e 2.525GHz, totalizando 125 canais de comunicação diferentes, o que permite configurar sistemas com diversos módulos operando ao mesmo tempo sem relação ou diversos módulos conectados à um mesmo ponto. O tamanho máximo do pacote enviado ou recebido pelo módulo é de 32bytes e opera com velocidade de comunicação de 1 ou 2 Mbps.


 O uso de antenas apropriadas pode aumentar significativamente o alcance do módulo, que possui o alcance aumentado quando opera na máxima potência de transmissão (0dBm) e menor velocidade de comunicação (1Mbps).
 
 
# Módulo Cartão SD

![alt text](https://uploads.filipeflop.com/2015/07/Modulo_Cartao_SD.jpg)


 O módulo de cartão SD é um módulo que permite fazer a conexâo entre um cartão SD e um microcontrolador, sendo o ESP32 ou Arduino. O módulo aceita cartões formatados em FAT16 ou FAT32 e são uma ótima opção para salvar dados obtidos durante a operação do microcontrolador. Em geral utilizam comunicação por meio da interface SPI utilizando os pinos MOSI, SCK, MISO E CS.


 O módulo opera com tensões de 3.3V, dessa maneira, em geral é necessário implementar divisores de tensão para fornecer a tensão ideal de funcionamento para o módulo. Os módulos geralmente se conectam ao microcontroladores por meio de diversas bibliotecas que variam de dispositivo para dispositivo e tem seus dados gravados, normalmente, em formato txt.

# Acelerômetro MPU9250

![alt text](https://cdn.awsli.com.br/1000x1000/945/945993/produto/36996713/d4657819ae.jpg)


 Apesar de ser chamado apenas de acelerômetro, o módulo MPU9250 é muito mais do que apenas isso, ele é um dispositivo integrado por um acelerômetro de três eixos, um giroscópio de 3 eixos , um magnetômetro de 3 eixos e um sensor de pressão BMP80 em algumas variações de mercado do dispositivo. Dessa maneira o módulo se classifica como um dispositivo Motion Tracking de 9 eixos.
	
 
 Possui rápido processamento, grande precisão e baixo consumo de energia, sendo ideal para aplicações que necessitem de rápidas medições e não possam consumir muita energia.
 
# Sistema de telemetria

 Um sistema de telemetria consiste basicamente em uma tecnologia que permite a medição remota de grandezas e a comunicação entre sistemas através de dispositivos sem fio. A telemetria é a base da internet das coisas e dessa maneira é parte fundamental de qualquer sistema que se baseie em sensoriamento. 


 Sabendo disso, podemos desenvolver o sistema de telemetria requisitado em duas partes separadas, a primeira, localizada no foguete, será responsável por coletar dados utilizando-se de sensores e transmitir esses dados por meio do rádio LoRa, também é necessário que esse sistema armazene os dados coletados em um cartão de memória ou outro dispositivo de memória consistente.


 A segunda parte se trata do sistema localizado em solo, ele será responsável por receber os sinais de rádio emitido pelo sistema em voo, e disponibilizar gráficos produzidos com os dados de voo em um servidor web, disponibilizado pelo próprio microcontrolador, possibilitando que os gráficos sejam visualizados em diversos dispositivos ao mesmo tempo.


Sendo assim, os materiais necessários para o sistema inteiro seriam dois microcontroladores ESP32 com rádio LoRa, dois módulo de cartão SD, dois cartões SD, sensores ( podem variar de acordo com as informações desejadas , logo o espectro de preço pode variar muito) e os dispositivos que irão acessar o servidor WEB hospedado pelo microcontrolador. 
 
 
  O código do sistema se baseia nos códigos anteriormente desenvolvidos responsáveis por coletar dados dos sensores, armazenar dados no módulo SD, transmissão e recepção por meio do protocolo LoRaWAN e o código responsável por hospedar um servidor WEB localmente.




