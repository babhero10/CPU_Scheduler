main:
	gcc -o main.exe *.c models/*.c models/*.h

clean:
	rm -f main.exe