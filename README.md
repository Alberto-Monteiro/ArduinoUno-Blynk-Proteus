# Arduino Uno + Blynk + Proteus

Esse projeto tem a intenção de ensinar como usar IoT dentro de um ambiente virtual como o Proteus.

## O que precisar ter instalado

* PlatformIO IDE - https://platformio.org/platformio-ide
* Proteus - https://www.labcenter.com/
* VIRTUAL SERIAL PORTS EMULATOR - http://www.eterlogic.com/Downloads.html

## Como usar

* Após instalar o PlatformIO IDE você deve abrir esse projeto e fazer o build para gerar os arquivos ".pio\build\uno\firmware.hex" e ".pio\libdeps\uno\Blynk\scripts\blynk-ser.bat".

* Depois de fazer o download e instalar o 'VIRTUAL SERIAL PORTS EMULATOR' Você precisa configurá-lo.
<p align="center">
    * * Create new device... * *
</p>
<p align="center">
    <img src="doc\2021-03-25 (1).png" width="400" />
</p>

<p align="center">
    * * Device type -> Pair -> Avançar * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (2).png" width="400" />
</p>

<p align="center">
    * * Virtual serial port 1 -> COM1 <<|>> Virtual serial port 2 -> COM2 -> Concluir * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (3).png" width="400" />
</p>

<p align="center">
    * * E para finalizar clique em Start emulation * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (8).png" width="400" />
</p>

* Agora você precisa configurar o arquivo ".pio\libdeps\uno\Blynk\scripts\blynk-ser.bat"

<p align="center">
    * * Você deve setar o seu servidor e porta nas variáveis SERV_ADDR e SERV_PORT * *
</P>
<p align="center">
    <img src="doc\2021-03-25.png" width="400" />
</p>

<p align="center">
    * * Você tem que executar o arquivo ".pio\libdeps\uno\Blynk\scripts\blynk-ser.bat" * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (9).png" width="400" />
</p>

* No Proteus você precisa abrir o arquivo que se encontra em "src\UnoBlynkProteus.pdsprj"

<p align="center">
    <img src="doc\2021-03-25 (5).png" width="400" />
</p>

<p align="center">
    * * Clicar 2x no Arduino Uno para configurar o caminho do <br> firmware que fica em ".pio\build\uno\firmware.hex" * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (7).png" width="400" />
</p>

<p align="center">
    * * Clicar 2x no conector P1 para configurar a porta <br> fornecida pelo VIRTUAL SERIAL PORTS EMULATOR que seria a COM2 * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (6).png" width="400" />
</p>

<p align="center">
    * * Agora com tudo pronto é só clicar em "Run the simulator" que fica localizado <br> no canto esquerdo inferior * *
</P>
<p align="center">
    <img src="doc\2021-03-25 (5).png" width="400" />
</p>

