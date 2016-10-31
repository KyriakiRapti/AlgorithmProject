# In  order  to  execute  this  "Makefile " just  type  "make "
OBJS     = test.o bankAccount.o graph.o hashtable.o List.o Node.o edge.o
SOURCE   = test.cpp bankAccount.cpp graph.cpp hashtable.cpp List.cpp Node.cpp edge.cpp
HEADER   = bankAccount.h graph.h hashtable.h List.h Node.h edge.h
OUT      = elegxos
CC       = g++
FLAGS    = -g -c
# -g  option  enables  debugging  mode
# -c flag  generates  object  code  for  separate  files
all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
#  create/ compile  the  individual  files  >> separately <<

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp

bankAccount.o: bankAccount.cpp bankAccount.h
	$(CC) $(FLAGS) bankAccount.cpp

graph.o: graph.cpp graph.h
	$(CC) $(FLAGS) graph.cpp

hashtable.o: hashtable.cpp hashtable.h
	$(CC) $(FLAGS) hashtable.cpp

List.o: List.cpp List.h
	$(CC) $(FLAGS) List.cpp

Node.o: Node.cpp Node.h
	$(CC) $(FLAGS) Node.cpp

edge.o: edge.cpp edge.h
	$(CC) $(FLAGS) edge.cpp

#  clean  house
clean :
	rm -f $(OBJS) $(OUT)
