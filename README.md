![Roll_the_Dice_banner](https://nathzenh.ch/prgc/Roll_The_Dice.png "🎲 Roll The Dice")

# Roll The Dice, PRGC-Projekt

## Discription
Es wird durch betätigen eines Knopfes auf dem Seven-segment display eine Zahl von 1-6 gewürfelt

## Visualisierung
![Roll_the_Dice_GIF](https://github.com/NathZenh/roll-the-dice/assets/46894591/07bb8a0e-74ce-453c-b156-b380280f5086)
<details>
  <summary>Video</summary>
  

https://github.com/NathZenh/roll-the-dice/assets/46894591/62857a1d-f3aa-4d4c-8a3c-752251f1ff68



</details>

## Installation
- Lade die Dateien herunter und füge Sie im "Source" Ordner deines PRGC-Board Projektes hinen. Achte darauf das die Startdatei erstes_programm.c ist.
- Anschliessend führe das Programm auf deinem PRGC-Board mit JLink aus.

- Verbinde deinen TinyK22 mit der Printbuchse wie im unteren Bild mit Rot angegeben ist, dabei Spielt es beim Output keine Rolle ob Sie sich für LD10G oder ein anderes LD' entscheiden das selbe bei LD0 und LD1.


![prgc-board pinout](https://github.com/NathZenh/roll-the-dice/assets/46894591/4c0d730a-859f-4aed-9463-fe5686a1b0d2)

## Documentation
Im Projekt ist eine Dateien enthalten, die Programme:
- sw09-solution.c

### sw09-solution.c
Dies ist das Hauptprogramm des Projektes, es beinhalten die main Funktion und führt dadurch das gesammte Programm aus.
1. Werden alle benötigten Imports eingefügt
2. Öffnet sich die main() Funktion
3. Wird die init() Funktion zur Initialisierung aufgerufen
4. Werden in einer Endlosschleife die Funktionen: user_interface_run() flasher_run(period) und supervisor_run() aufgerufen.
5. Mit der Funktion user_interface_run( wird auf die Eingabe des Benutzers die Periodenrate verändert.
6. MIt der Funktion flasher_run(period) wird die LED mit der Periode zum Blicken gebracht.

Wenn ein Knopf gedürckt wird, wird die Periodenrate verändert. Das heisst die LED blinkt schneller oder langsamer.

![flasher_run](https://github.com/NathZenh/flasher/assets/46894591/955be009-443a-4bdc-afd8-9683274c21e3)
![user_interface_run](https://github.com/NathZenh/flasher/assets/46894591/042dd688-8ec6-4f7a-9afe-a74aef3f6538)


## Lizenz
[MIT](https://choosealicense.com/licenses/mit/)
