#-------------------------
# File: Makefile <for building the linkedList project>
# <To compile inddividual target use the make command as follows >
#				make <target> eg. if you make changes to the list.c file:
#				make list.o
# Author: Hrishikesh Adigal
# email: hadigal@sdsu.edu
# Date: 08/10/2018
#-------------------------

TARGET = solution.out

OBJ = list.o linkedList.o

$(TARGET):$(OBJ)
	cc -o $(TARGET) $(OBJ)

start:
	@echo "building linkedlist project using make..."

list.o:list.c
	cc -c list.c

linkedList.o:linkedList.c
	cc -c linkedList.c

cleanAll:
	rm -rf *.o *.out
