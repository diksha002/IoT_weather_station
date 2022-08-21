# iot_weather_station
Le mini centre station météorologique créer par des capteurs, l'arduino, et raspberry pi

## Comment installer le projet

> ETAPES

Copier le lien du projet et cloner le via votre terminal ou logiciel
```
  - git clone https://github.com/diksha002/iot_weather_station.git
```

Veuiller avoir les logiciel suivant pour pouvoir executer les fichers:
 - arduino IDE
 - PUTTY
 
 apres avoir cloner le projet, dans le dossier iot_weather_station, il y aura 4 dossiers:

- Sensors_test: contient les fichers pour tester les capteurs donc le barometre, photoresisteur, le capteur d'humidité et temperature et le fichier pour afficher les données sur le terminal.
 
- code to display data from arduino to terminal of raspberry: ce dossier contient le fichier python pour afficher les données depuis l'arduino jusqu'à le raspberry pi
 
 - code to send data from raspberry to db: ce dossier contient les fichiers qui consiste à envoyer les données de raspberry jusqu'àu base de donnée. 
 
 - final circuit arduino: le code final avec tous les capteurs.


