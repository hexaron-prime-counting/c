# Compile primes with linked_list

# Syntax is:
# ```
# <target>: <dependencies>
# 	<command: dependencies -> target>
# ```
# In make there is no difference between $(...) and ${...}

CC := gcc -O3 -Wall
INCLUDES := -I ./

BUILD_DIR := build

BINARY := ${BUILD_DIR}/primes

OBJ_DIR := ${BUILD_DIR}/objs
_OBJS := primes.o linked_list.o
# substitue % by ${OBJ_DIR}/% for each word in ${_OBJS}
OBJS := ${patsubst %,${OBJ_DIR}/%,${_OBJS}}

all: ${BINARY}

${BINARY}: ${OBJS}
	@mkdir -p ${BUILD_DIR}
	${CC} ${OBJS} -o ${BINARY}

run: ${BINARY}
	./${BINARY}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	${CC} -c $*.c -o ${OBJ_DIR}/$*.o ${INCLUDES}

clean:
	rm ${OBJS} ${BINARY}
