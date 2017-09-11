FINAL:=main
OBJECT:=main.o system.o admin.o book.o database.o member.o
OPTIONS:=-g -Wall -lmysqlclient
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
