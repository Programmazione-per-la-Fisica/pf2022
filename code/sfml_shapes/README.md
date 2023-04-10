# Esempio di polimorfismo dinamico con SFML

Questo esempio è una semplice dimostrazione dell'uso del polimorfismo dinamico
(noto anche come programmazione *object-oriented*) applicato alla manipolazione
di figure geometriche sul piano. Nel nostro caso, vengono costruiti un cerchio e
un rettangolo, che vengono poi fatti muovere dall'angolo in alto a sinistra
all'angolo in basso a destra. Notare come le figure vengono create sullo *heap*
e gestite con `unique_ptr<Shape>` in un vettore.

Con l'occasione si mostra anche la tipica struttura di un programma di
visualizzazione grafica, caratterizzato dalla presenza del cosiddetto *game
loop*

```c++
while (window.isOpen()) {
  // ...
}
```

il cui corpo gestisce un singolo *frame* temporale. Nel caso specifico, il
*frame rate* viene impostato a 60 frame al secondo (*frames per second*, FPS),
ognuno dei quali dura quindi circa 15 millisecondi.

All'interno del game loop si evidenziano cinque fasi significative:

1. la gestione degli eventi nel cosiddetto *event loop*. Nell'esempio viene
   gestito solo l'evento di chiusura della finestra
2. l'evoluzione della scena. Nell'esempio il cerchio e il rettangolo vengono
   spostati lungo la diagonale della finestra, in modo tale che ci mettano circa
   5 secondi a percorrerla
3. la finestra viene pulita
4. le figure vengono disegnate sulla finestra
5. la finestra viene visualizzata

Il codice usa `CMake` e la libreria grafica `SFML`, installabili su Ubuntu con
`sudo apt install cmake libsfml-dev`.

Per compilare il codice

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug # o Release
```

seguito da

```sh
cmake --build build
```

Per eseguire:

```sh
build/sfmlplay
```
