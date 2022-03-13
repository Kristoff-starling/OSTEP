
FLAGS = -Wall -pthread -g

all: main-race main-deadlock main-deadlock-global main-signal main-signal-cv main-norace

clean:
	rm -f main-race main-deadlock main-deadlock-global main-signal main-signal-cv main-norace

main-race: main-race.c common_threads.h
	gcc -o main-race main-race.c $(FLAGS)

main-deadlock: main-deadlock.c common_threads.h
	gcc -o main-deadlock main-deadlock.c $(FLAGS)

main-deadlock-global: main-deadlock-global.c common_threads.h
	gcc -o main-deadlock-global main-deadlock-global.c $(FLAGS)

main-signal: main-signal.c common_threads.h
	gcc -o main-signal main-signal.c $(FLAGS)

main-signal-cv: main-signal-cv.c common_threads.h
	gcc -o main-signal-cv main-signal-cv.c $(FLAGS)

main-norace: main-norace.c common_threads.h
	gcc -o main-norace main-norace.c $(FLAGS)


