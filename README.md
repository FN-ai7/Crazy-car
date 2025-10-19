# Crazy Car Project 🚗

Dieses Projekt wurde im Rahmen des ECE-Labors mit dem **MSP430** erstellt.

## 📂 Projektstruktur
- **HAL/** – Hardware Abstraction Layer (Timer, UCS, GPIO usw.)
- **main.c** – Hauptprogramm
- **targetConfigs/** – Gerätekonfigurationen
- **Debug/** – Build-Ordner (wird lokal generiert)
- **.project / .cproject** – Code Composer Studio Metadaten

## ⚙️ Funktion
Das Programm steuert die Hintergrundbeleuchtung und andere Komponenten über den MSP430-Timer.
TimerB0 sorgt z. B. dafür, dass die LCD-Hintergrundbeleuchtung mit 2 Hz blinkt.

## 🧠 Tools
- **IDE:** Code Composer Studio  
- **Microcontroller:** MSP430F5335  
- **Sprache:** C  

---

✳️ Entwickelt von **Farzaneh Niazi (FN-ai7)**  
Version: 1.0
