all: objects archive Main24.exe

CC        = g++
CCFLAGS   = -Wall -Werror -g
LINKER    = g++
ARCH      = ar
ARCHFLAGS = cr
RANLIB    = ranlib

# Compiling statements.

%.o: %.cc
	$(CC) $(CCFLAGS) $<

OBJECTS = BSModel01.o Options.o BSEq.o FDMethod.o ExplicitMethod.o

objects: $(OBJECTS)

archive: $(OBJECTS)
	$(ARCH) $(ARCHFLAGS) objects.a $(OBJECTS)
	$(RANLIB) ./objects.a

# Driver.

Main24.exe: Main24.cpp Main24.o
	$(LINKER) Main24.o objects.a -o Main24.exe

Main24.o: Main24.cpp objects.a
	$(CC) -c Main24.cpp $(CCFLAGS) -o Main24.o

clean:
	rm -f *~ *.o *.tex *.exe *.a
