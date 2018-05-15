

CC=g++

OPT=DEBUG# OPT, DEBUG

IFLAGS = -I"../../" # path to support directory
CCFLAGS_BASE = -Wall $(IFLAGS)
CCFLAGS_DEBUG =
CCFLAGS_OPT = -O3 -Ofast 
#-ftree-vectorizer-verbose=2 # -Ofast

.SUFFIXES: .o .cpp .exe

CCFLAGS = $(CCFLAGS_BASE) $(CCFLAGS_$(OPT))

seq-performance-test: seq-performance-test.cpp
	$(CC) $(CCFLAGS) $< -o $@_$(OPT).exe

seq-performance-test2: seq-performance-test2.cpp
	$(CC) $(CCFLAGS) $< -o $@_$(OPT).exe

seq-performance-arithm: seq-performance-arithm.o dummy.o
	$(CC) $(CCFLAGS) $< dummy.o -o $@_$(OPT).exe

matrix-sums: matrix-sums.cpp
	$(CC) $(CCFLAGS) $< -o $@_$(OPT).exe

matrix-sums-wtime: matrix-sums-wtime.cpp
	$(CC) $(CCFLAGS) -fopenmp $< -o $@_$(OPT).exe

matrix-sums-wtime-malloc: matrix-sums-wtime-malloc.cpp
	$(CC) $(CCFLAGS) -fopenmp $< -o $@_$(OPT).exe

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

.cpp.exe:
	$(CC) $(CCFLAGS) $< -o $@_$(OPT).exe

clean:
	rm -f *.exe *.o *~
