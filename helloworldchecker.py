# <--------------------------------------------------------->
# Programa para comprobar que tu programa hace lo que le toca
# <--------------------------------------------------------->
from time import sleep
from curses import initscr

valid_outputs: tuple[str] = ("hello,world!","helloworld!","helloworld","hello,world")

prog_output = input()
preprocessed_output = prog_output.strip().lower()
simplified_output = ''.join(preprocessed_output.split(" "))

frames: tuple[tuple[str, int]] = (
    ("Tu programa es", 1),
    ("Tu programa es.", 1),
    ("Tu programa es..", 1),
    ("Tu programa es...", 1),
    ("Tu programa es... " + 'válido :D' if simplified_output else 'inválido :(', 3)
)
TXT = 0
DELAY = 1

for frame in frames:
    print(frame[TXT])
    sleep(frame[DELAY])
