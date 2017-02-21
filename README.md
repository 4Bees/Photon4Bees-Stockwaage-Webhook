# Photon4Bees - WLAN Stockwaage - Webhook

Diese Software verwendet Particle Webhooks zur Übermittlung der Messwerte an [cloud4Bees.at](http://cloud.4bees.at)
. Dadurch ist es möglich den API_Key aus dem
Programm zu entfernen. Die Verbindung zur Cloud4Bees wird durch einen Webhook konfiguriert. Es ist damit möglich auf alle Waagen die
gleiche Firmware zu spielen. Updates der Firmware können nun problemlos Over the Air (OTA) an alle Photon4Bees - WLAN Stockwaagen
gesendet werden.


![Particle Webhook Einstellung zur Weiterleitung der Daten an Cloud4Bees](./Webhook.JPG?raw=true "Webhook Einstellungen")


![Particle Webhook Einstellungen für get_scalefactor](./get_scalefactor_Webhook.JPG?raw=true "Webhook Einstellungen")


![Particle Webhook Einstellungen für get_offset](./get_offset_Webhook.JPG?raw=true "Webhook Einstellungen")
