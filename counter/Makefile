TARGET=counter
SRC=${TARGET}.v
STIMULUS=sim_main.cpp
VLIBS='-lsmurf -lsmurfemulator'
VARGS=--cc --exe --build -Wall -LDFLAGS ${VLIBS} -CFLAGS -g
OBJ=./obj_dir/

all: build

build: ${SRC} ${STIMULUS}
	verilator ${VARGS} ${STIMULUS} ${SRC}

run: build
	make -C ${OBJ} -f V${TARGET}.mk
	./obj_dir/V${TARGET}

clean:
	rm -rf obj_dir *~ tags 

rebuild: clean build

indent:
	indent *.cpp
