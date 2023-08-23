import serial
import pyautogui

COM_PORT = 'COM4' ## 장치관리자 확인

# 시리얼 포트 연결
my_serial = serial.Serial(COM_PORT, 9600)

while True:
    # 시리얼 포트에서 문자 읽기
    key = my_serial.read(1).decode('ascii')
    
    # 키보드 이벤트 발생
    pyautogui.press(key)

