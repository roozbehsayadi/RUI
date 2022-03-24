.PHONY: all run clean lines

all: build/main.o build/GeneralPage.o build/RuiMonitor.o build/BaseLayout.o build/ColumnLayout.o build/LeafLayout.gch build/RowLayout.o build/Color.o build/Rect.o build/BaseWidget.gch build/ButtonWidget.gch
	g++ build/*.o -o build/RUI.out -Wall -g -O2 -std=c++2a -lSDL2
run:
	./build/RUI.out
build/main.o: main.cpp
	g++ -c -I. -o build/main.o main.cpp
build/GeneralPage.o: GeneralPage.h GeneralPage.cpp
	g++ -c -I. -o build/GeneralPage.o GeneralPage.cpp
build/RuiMonitor.o: monitor/RuiMonitor.h monitor/RuiMonitor.cpp
	g++ -c -I. -o build/RuiMonitor.o monitor/RuiMonitor.cpp
build/BaseLayout.o: layout/BaseLayout.h layout/BaseLayout.cpp
	g++ -c -I. -o build/BaseLayout.o layout/BaseLayout.cpp
build/ColumnLayout.o: layout/ColumnLayout.h layout/ColumnLayout.cpp
	g++ -c -I. -o build/ColumnLayout.o layout/ColumnLayout.cpp
build/LeafLayout.gch: layout/LeafLayout.h
	g++ -c -I. -o build/LeafLayout.gch layout/LeafLayout.h
build/RowLayout.o: layout/RowLayout.h layout/RowLayout.cpp
	g++ -c -I. -o build/RowLayout.o layout/RowLayout.cpp
build/Color.o: utils/Color.h utils/Color.cpp
	g++ -c -I. -o build/Color.o utils/Color.cpp
build/Rect.o: utils/Rect.h utils/Rect.cpp
	g++ -c -I. -o build/Rect.o utils/Rect.cpp
build/BaseWidget.gch: widgets/BaseWidget.h
	g++ -c -I. -o build/BaseWidget.gch widgets/BaseWidget.h
build/ButtonWidget.gch: widgets/ButtonWidget.h
	g++ -c -I. -o build/ButtonWidget.gch widgets/ButtonWidget.h
clean:
	rm -rf build/*.o build/*.gch build/*.out
lines:
	find . -type f -name "*.cpp" -o -name "*.h" -o -name "Makefile" | xargs wc -l
