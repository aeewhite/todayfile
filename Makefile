todayfile: todayfile.o
	gcc  todayfile.o -o todayfile
todayfile.o:todayfile.c
	gcc  -Wall -c todayfile.c

install: todayfile
	mv todayfile /usr/local/bin/

.PHONY: clean
clean:
	rm -f *.o
	rm -f todayfile