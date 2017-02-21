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

* Erstellen Sie ein Konto bei [Particle](https://particle.io)
* Loggen Sie sich in die Console ein
* Wählen Sie den Menüpunkt **Integrations**
* Klicken Sie auf **New Integration**

![Particle Integration](./New Integration.JPG?raw=true "Particle New Integration")


* Füllen Sie das Formular wie in der folgenden Abbildung angeben aus. Ersetzen Sie dabei XXXXXXXXXXXX mit Ihrem gültigen API_key
  den Sie zuvor auf [cloud.4bees.at](http://cloud.4bees.at) angelegt haben* Klicken Sie auf Create Webhook


![Particle Webhook Einstellung zur Weiterleitung der Daten an Cloud4Bees](./Webhook.JPG?raw=true "Webhook Einstellungen")


![Particle Webhook Einstellungen für get_scalefactor](./get_scalefactor_Webhook.JPG?raw=true "Webhook Einstellungen")


![Particle Webhook Einstellungen für get_offset](./get_offset_Webhook.JPG?raw=true "Webhook Einstellungen")
