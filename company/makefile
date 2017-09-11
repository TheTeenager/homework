FINAL:=main
OBJECT:=main.o Employee.o TecPartTime.o TecManager.o SelPartTime.o SelManager.o Boss.o DataSet.o FileOpe.o Company.o
OPTIONS:=-g -Wall
CC:=g++

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)

%.o:%.cpp
	$(CC) -c $< -o $@ $(OPTIONS)
clean:
	rm -rvf $(OBJECT) $(FINAL) 
cleant:
	rm -rvf *.txt
built:
	touch student.txt teacher.txt
