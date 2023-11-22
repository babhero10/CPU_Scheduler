main:
	gcc -o main.exe *.c models/*.c models/*.h controller/*.c controller/*.h

clean:
	rm -f main.exe