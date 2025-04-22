import serial
import time

# Abre a porta serial conectada ao Arduino (pode ser /dev/ttyAMA0 ou /dev/serial0)
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
time.sleep(2)  # Aguarda o Arduino resetar

try:
    while True:
        # Envia o comando 'D' para o Arduino
        arduino.write(b'D')  # b'D' é um byte, como Serial.read() espera
        print("Comando enviado: D")

        # Espera a resposta do Arduino
        resposta = arduino.readline().decode('utf-8').strip()
        if resposta:
            print("Distância recebida:", resposta, "cm")
        
        time.sleep(2)

except KeyboardInterrupt:
    print("Encerrando comunicação.")
    arduino.close()
