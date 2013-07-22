SRC := snescpu.c main.c
TGT := snesasm.html

CC := emcc
CCFLAGS := -O2

all : $(TGT)

clean :
	rm -rf $(TGT) $(TGT).map

$(TGT) : $(SRC)
	emcc $^ -o $@ -O1
