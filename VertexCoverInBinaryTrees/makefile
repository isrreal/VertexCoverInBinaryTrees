CPPFLAGS=-std=c++17
IPATH=-Iinc/
SRC=src/
OBJ=obj/

all: app

app: main.gch BinarySearchTree.gch
	g++ $(OBJ)main.gch $(OBJ)BinarySearchTree.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch
                                        
BinarySearchTree.gch: $(SRC)BinarySearchTree.cpp                         
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)BinarySearchTree.cpp -o $(OBJ)gerar.gch

clean:
	rm -rf $(OBJ)*.gch

