import serial
import pyautogui
import time

PORTA = 'COM13'
BAUDRATE = 9600

# 📌 TAG : TECLA
tags = {
    #ANIMAIS
    "C3 4C EE FD": "1",     #LEAO = 4260252867
    "43 66 F8 EB": "2",     #TUBARAO = 3958924867
    "F3 1B D3 07": "3",     #TIGRE = 0131275763
    "B3 98 B1 07": "4",     #GORILA = 0129079475
    #PODERES
    "A3 F8 C7 FD": "7",     #GELO = 4257740963
    "F3 92 BD 07": "8",     #ESCUDO = 0129864435
    "43 20 D1 07": "9",     #VENENO = 0131145795
    "03 89 DB FD": "0",     #MORDIDA = 4259023107
    #EASTER EGG
    "11 DE FF 66": "space", #CARLOS = CRACHÁ
    #BOTOES
    "AZUL": "h",
    "VERDE": "j",
    "AMARELO": "k",
    "VERMELHO": "l"
}

while True:
    try:
        print("Conectando ao Arduino...")

        arduino = serial.Serial(PORTA, BAUDRATE, timeout=0.1)

        time.sleep(2)

        print("Conectado!")

        ultima_tag = ""

        while True:

            if arduino.in_waiting:

                tag = arduino.readline().decode(errors='ignore').strip().upper()

                if tag:

                    print("Lido:", tag)

                    # evita spam da mesma tag
                    if tag != ultima_tag:

                        if tag in tags:

                            tecla = tags[tag]

                            pyautogui.press(tecla)

                            print(f"Tecla '{tecla}' pressionada!")

                        else:
                            print("Tag não cadastrada.")

                        ultima_tag = tag

            else:
                # permite reler a mesma tag depois
                ultima_tag = ""

    except Exception as erro:

        print("Erro:", erro)

        print("Tentando reconectar em 3 segundos...")

        time.sleep(3)