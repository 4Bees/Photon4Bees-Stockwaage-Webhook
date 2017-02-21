# Photon4Bees - WLAN Stockwaage - Webhook

Diese Software verwendet Particle Webhooks zur Übermittlung der Messwerte an [cloud4Bees.at](http://cloud.4bees.at)
. Dadurch ist es möglich den API_Key aus dem
Programm zu entfernen. Die Verbindung zur Cloud4Bees wird durch einen Webhook konfiguriert. Es ist damit möglich auf alle Waagen die
gleiche Firmware zu spielen. Updates der Firmware können nun problemlos Over the Air (OTA) an alle Photon4Bees - WLAN Stockwaagen
gesendet werden.


## Verbindung mit Cloud4Bees

Die Messwerte der [Photon4Bees WLAN-Stockwaage](http://www.4bees.at/wiki/-/wiki/Main/Photon4Bees+-+Die+WLAN+Stockwaage) werden auf
[cloud.4bees.at](http://cloud.4bees.at) gespeichert und können dann im Webbrowser graphisch dargestellt werden.
Die Verbindung zum Datenserver wird mittels Webhooks in der [Particle Console] (https://console.particle.io/integrations) hergestellt.

1. Erstellen Sie ein Konto bei [Particle](https://particle.io)
2. Loggen Sie sich in die Console ein
3. Wählen Sie den Menüpunkt **Integrations**
4. Klicken Sie auf **New Integration** ![Particle Integration](./New Integration.JPG?raw=true "Particle New Integration")
5. Füllen Sie das Formular wie in der folgenden Abbildung angeben aus. Ersetzen Sie dabei XXXXXXXXXXXX mit Ihrem gültigen API_key
   den Sie zuvor auf [cloud.4bees.at](http://cloud.4bees.at) angelegt haben* Klicken Sie auf Create Webhook


![Particle Webhook Einstellung zur Weiterleitung der Daten an Cloud4Bees](./Webhook.JPG?raw=true "Webhook Einstellungen")



## Kalibrierung der Stockwaage

Um die Stockwaage zu kalibrieren müssen zunächst der **Scalefactor** und der **Offset** ermittelt werden. Diese beiden Werte werden
dann in den Feldern 7 und 8 des Cloud4bees Kanals gespeichert. Über Webhooks wird dann die Verbindung mit der Firmware der Waage 
hergestellt. Im Setup des Programms, d. h. bei jedem Neustart der Waage werden die beiden Werte dann ausgelesen und die Waage damit
kalibriert. 

1. Webhook für den Scalefactor erstellen:

![Particle Webhook Einstellungen für get_scalefactor](./get_scalefactor_Webhook.JPG?raw=true "Webhook Einstellungen")


2. Webhook für den Offset erstellen:

![Particle Webhook Einstellungen für get_offset](./get_offset_Webhook.JPG?raw=true "Webhook Einstellungen")


3. Der Scalefactor wird auf 1 gesetzt und der Offset auf 0; Der beiden Werten werden mittels HTTP Get Request in den Feldern 7 
   (Scalefactor) und Feld 8 (Offset) gespeichert: http://cloud.4bees.at/update?api_key=xxxxxxxxxx&field7=1&field8=0
   **Wichtig: Der Kanal muss dafür öffentlich gemacht werden**
4. Die Waage wird jetzt eingeschaltet und nach einigen Sekunden kann der Wert auf [cloud.4bees.at](http://cloud.4bees.at)
   -> Kanal ausgelesen werden; Dieser Wert notiert man sich auf einem Notizblock
5. Jetzt wird die Waage mit einem bekannten Gewicht x (bsp. 10 kg) belastet und der Wert wird wider auf cloud.4bees.at ausgelesen
   und notiert.
6. Den **Scalefactor** erhält man über folgenden Formel: **Scalefactor = (Wert_x - Wert_0) / x**
7. Der **Offset** ergibt sich aus: **Offset = Wert_0 / Scalefactor
8. Beide Werte werden jetzt im Feld 7 und Feld 8 des entsprechenden Kanals gespeichert:
   http://cloud.4bees.at/update?api_key=xxxxxxxxxxx&field7=Scalefactor&field8=Offeset
9. Die Waage muss jetzt neu gestartet werden

