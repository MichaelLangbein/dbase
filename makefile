# Compilation
#
# Schritt 1: Preprocessor: auslesen der #include directives, nachschlagen der included'ten *.h files
# 			in den -I dirs, alles zusammen in eine große Datei verbinden.
# Schritt 2: Compiler: erzeugen der *.o object files
# schritt 3: Linker:  verbinden der object files.
#
#
# Includes sind header files
# Option -I(dirname): hinzufügen dir zu Suchpfad für *.h files.
# Im Gegensatz zu libs kann man bei incls nur dirs spezifizieren, nicht einzelne files.Dafür
# gibt es ja schon die #include direktive.
#
# Libs sind die den header files zu Grunde liegenden so files
# Option -L(dirname): hinzufügen dir zu Suchpfad für *.so files
# 	-l(libname): mit Einbinden einer lib
# 	-pthread: eine besondere Option; steht für -lpthread + definiere ein paar extra macros
#
# Jansson ist ein externes Programm. Es muss erst ge-make-t werden (oder ge apt-get-tet),
# danach finden wir header per default in /usr/local/include und libs in /usr/local/lib


INCLUDES = 
LIBS =
WARNINGS = -Wall -Wextra

# Compilen
# 	-c: compile
# 	-g: für debugger

bintree.o: bintree.c bintree.h
	gcc -g -c $(WARNINGS) $(INCLUDES) bintree.c

hash.o: hash.c hash.h 
	gcc -g -c $(WARNINGS) $(INCLUDES) hash.c

# Linken
# 	-o: name der fertigen binary
# 	-g: für debugger

main: bintree.o hash.o
	gcc -g -o main bintree.o hash.o $(LIBS)

all: main

