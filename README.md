# Instalação
* Primeiramente, baixe o arquivo .zip daqui do github
* Então, no arduino IDE, vá em **Sketch > Incluir biblioteca > Adicionar biblioteca .ZIP**
* Isso abrirá uma tela para selecionar um arquivo, vá até a pasta em que baixou essa biblioteca e clique duas vezes.
* Enfim, no topo do seu código, copie essa linha `#include <autocalibralib.h>`

(Alternativamente, você pode extrair o .zip e colocar a pasta "autocalibralib" dentro do diretório libraries do arduino) 

# FUNÇÕES 

## Construtor
Define um sensor e um LED (opcional), para calibração e inicia os pinos.

`LineSensor [nome]([pino do sensor], [pino do LED])`
## calibrate
calibra o sensor, lendo o sensor em certo momento e interpretando o valor lido como valor limiar (_threshold), para identificar se os valores lidos posteriormente representam a cor preta ou branca. Indicado por LED.

`[nome].calibrate()`
## isBlack
lê o sensor e baseia-se no valor _threshold (margem, ou valor limiar) definido com `setThreshold()` para deduzir se o valor lido representa ou não a cor preta. Retorna 1 (preto) ou 0 (branco). 

`[var] = [nome].isBlack()`
## read
Apenas lê o sensor e retorna o valor bruto.

`[var] = [nome].read()`
## setThreshold
Define o _threshold (margem ou valor limiar) para deduzir se o valor lido representa ou não a cor preta de maneira manual.

`[nome].setThreshold([valor])`
## getThreshold
Retorna o valor _threshold

`[var] = [nome].getThreshold()`
## blinkLED
Usada internamente, pisca o LED posto no construtor um número [times] de vezes

`[nome].blinkLED([times])`

# EXEMPLOS

## Exemplo 1

calibra o sensor e guarda o valor limiar na placa, então começa a ler valores e deduzir se são pretos ou não, baseado em tal valor

## Exemplo 2

Utiliza do valor armazenado na placa para deduzir a cor da linha

## Exemplo 3

Assume um valor limiar e o usa para deduzir a cor da linha
