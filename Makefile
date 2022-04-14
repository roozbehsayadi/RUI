.PHONY: all run clean lines

all: build/main.o build/RUI.o build/GeneralPage.o build/RuiMonitor.o build/BaseLayout.o build/ColumnLayout.o build/Container.o build/LeafLayout.o build/RowLayout.o build/Color.o build/Rect.o build/Geometry.o build/BaseWidget.o build/ButtonWidget.o build/ImageWidget.o
	g++ -Ibuild build/*.o -o build/RUI.out -Wall -g -O2 -std=c++2a -lSDL2 -lSDL2_ttf -lSDL2_image
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
build/BaseLayout.o: layout/BaseLayout.h layout/BaseLayout.cpp
	g++ -c -I. -o build/BaseLayout.o layout/BaseLayout.cpp
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
build/Geometry.o: utils/Geometry.h utils/Geometry.cpp
	g++ -c -I. -o build/Geometry.o utils/Geometry.cpp
build/BaseWidget.o: widgets/BaseWidget.h widgets/BaseWidget.cpp
	g++ -c -I. -o build/BaseWidget.o widgets/BaseWidget.cpp
build/ButtonWidget.o: widgets/ButtonWidget.h widgets/ButtonWidget.cpp
	g++ -c -I. -o build/ButtonWidget.o widgets/ButtonWidget.cpp
build/ImageWidget.o: widgets/ImageWidget.h widgets/ImageWidget.cpp
	g++ -c -I. -o build/ImageWidget.o widgets/ImageWidget.cpp
clean:
	rm -rf build/*.o build/*.gch build/*.out
lines:
	find . -type f -name "*.cpp" -o -name "*.h" -o -name "Makefile" | xargs wc -l
