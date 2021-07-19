all: NSP

NSP: NSP.o
	gcc -Wall -o NSP NSP.o
NSP.o: NSP.c
	gcc -Wall -c NSP.c
clean:
	rm *.o NSP

# NSP: NSP.o functions.o
# 	gcc -Wall -o NSP NSP.o functions.o

# NSP.o: NSP.c functions.h
# 	gcc -Wall -c NSP.c
# functions.o: functions.c
# 	gcc -Wall -c functions.c
# clean:
# 	rm *.o NSP