#Makefile for employees
# Author: Elise Lightner
# File: Makefile
# Last Modified: 10/17
# Purpose: A Makefile to compile and link the Employee project, including Employee, Officer, and Supervisor classes.


CC = g++
TARGET = employee  
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o Employee.o Officer.o Supervisor.o
	$(CC) main.o Employee.o Officer.o Supervisor.o -o $(TARGET)

main.o: main.cpp Employee.h Officer.h Supervisor.h
	$(CC) $(CFLAGS) main.cpp

Employee.o: Employee.cpp Employee.h
	$(CC) $(CFLAGS) Employee.cpp

Officer.o: Officer.cpp Officer.h
	$(CC) $(CFLAGS) Officer.cpp

Supervisor.o: Supervisor.cpp Supervisor.h
	$(CC) $(CFLAGS) Supervisor.cpp

clean:
	rm -f *.o $(TARGET) *~
