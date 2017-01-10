AVLNode.o : AVLNode.h AVLNode.cpp AVLTreeBase.h
	g++ -c AVLNode.cpp
AVLForest.o : AVLForest.h AVLForest.cpp
	g++ -c AVLForest.cpp
Driver.o : Driver.cpp
	g++ -c Driver.cpp
Driver : Driver.o AVLForest.o AVLNode.o
	g++ -o Driver Driver.o AVLForest.o AVLNode.o
run : Driver
	./Driver $(INPUT) $(RANGE)
clean : 
	rm -f Driver.o AVLNode.o AVLForest.o 