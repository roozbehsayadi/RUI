.PHONY: all run clean lines

all: build/main.o build/RUI.o build/GeneralPage.o build/RuiMonitor.o build/BaseLayout.gch build/ColumnLayout.o build/Container.o build/LeafLayout.o build/RowLayout.o build/Color.o build/Rect.o build/BaseWidget.gch build/ButtonWidget.o
	g++ -Ibuild build/*.o -o build/RUI.out -Wall -g -O2 -std=c++2a -lSDL2 -lSDL2_ttf
run:
	./build/RUI.out
build/main.o: main.cpp
	g++ -c -I. -o build/main.o main.cpp
build/RUI.o: RUI.h RUI.cpp
	g++ -c -I. -o build/RUI.o RUI.cpp
build/GeneralPage.o: window/GeneralPage.h window/GeneralPage.cpp
	g++ -c -I. -o build/GeneralPage.o window/GeneralPage.cpp
build/RuiMonitor.o: monitor/RuiMonitor.h monitor/RuiMonitor.cpp
	g++ -c -I. -o build/RuiMonitor.o monitor/RuiMonitor.cpp
build/BaseLayout.gch: layout/BaseLayout.h
	g++ -c -I. -o build/BaseLayout.gch layout/BaseLayout.h
build/ColumnLayout.o: layout/ColumnLayout.h layout/ColumnLayout.cpp
	g++ -c -I. -o build/ColumnLayout.o layout/ColumnLayout.cpp
build/Container.o: layout/Container.h layout/Container.cpp
	g++ -c -I. -o build/Container.o layout/Container.cpp
build/LeafLayout.o: layout/LeafLayout.h layout/LeafLayout.cpp
	g++ -c -I. -o build/LeafLayout.o layout/LeafLayout.cpp
build/RowLayout.o: layout/RowLayout.h layout/RowLayout.cpp
	g++ -c -I. -o build/RowLayout.o layout/RowLayout.cpp
build/Color.o: utils/Color.h utils/Color.cpp
	g++ -c -I. -o build/Color.o utils/Color.cpp
build/Rect.o: utils/Rect.h utils/Rect.cpp
	g++ -c -I. -o build/Rect.o utils/Rect.cpp
build/BaseWidget.gch: widgets/BaseWidget.h
	g++ -c -I. -o build/BaseWidget.gch widgets/BaseWidget.h
build/ButtonWidget.o: widgets/ButtonWidget.h widgets/ButtonWidget.cpp
	g++ -c -I. -o build/ButtonWidget.o widgets/ButtonWidget.cpp
clean:
	rm -rf build/*.o build/*.gch build/*.out
lines:
	find . -type f -name "*.cpp" -o -name "*.h" -o -name "Makefile" | xargs wc -l
