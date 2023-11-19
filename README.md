![🚨_Flasher](https://github.com/NathZenh/flasher/assets/46894591/47b0e913-9aa0-418c-8fc6-5f75ae9fc884)

# Flasher, PRGC-Projekt

## Discription
Es wird durch betätigen von zwei Knöpfen die Blinkrate einer LED beschleunigt oder verlangsamt werden. 

## Visualisierung
![flasher](https://github.com/NathZenh/flasher/assets/46894591/8df8ec2b-9aca-48b7-b047-f20f51c4d291)

<details>
  <summary>Video</summary>
  

https://github.com/NathZenh/flasher/assets/46894591/957d2bc8-cf1c-4746-a953-76dc0f71e906


</details>

## Installation
- Lade die Dateien herunter und füge Sie im "Source" Ordner deines PRGC-Board Projektes hinen. Achte darauf das die Startdatei sw09-solution.c ist.
- Anschliessend führe das Programm auf deinem PRGC-Board mit JLink aus.

- Verbinde deinen TinyK22 mit der Printbuchse wie im unteren Bild mit Rot angegeben ist, dabei Spielt es beim Output keine Rolle ob Sie sich für LD10G oder ein anderes LD' entscheiden das selbe bei LD0 und LD1.


![prgc-board-pinout-1](https://github.com/NathZenh/flasher/assets/46894591/a4fbf7af-c993-4ef4-856c-da209bb832d6)


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
