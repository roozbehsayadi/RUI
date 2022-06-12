.PHONY: all run clean lines

all: build/main.o build/RUI.o build/GeneralPage.o build/RuiMonitor.o build/BaseLayout.o build/ColumnLayout.o build/Container.o build/LeafLayout.o build/RowLayout.o build/Color.o build/Rect.o build/Geometry.o build/BaseWidget.o build/ButtonWidget.o build/ImageWidget.o build/CheckboxWidget.o build/RadioButtonWidget.o build/TextInputWidget.o build/ScreenWidget.o build/ScreenObject.o
	g++ -Ibuild build/*.o -o build/RUI.out -Wall -g -O2 -std=c++2a -lSDL2 -lSDL2_ttf -lSDL2_image
run:
	./build/RUI.out
build/main.o: main.cpp
	g++ -std=c++2a -c -I. -o build/main.o main.cpp
build/RUI.o: RUI.h RUI.cpp
	g++ -std=c++2a -c -I. -o build/RUI.o RUI.cpp
build/GeneralPage.o: window/GeneralPage.h window/GeneralPage.cpp
	g++ -std=c++2a -c -I. -o build/GeneralPage.o window/GeneralPage.cpp
build/RuiMonitor.o: monitor/RuiMonitor.h monitor/RuiMonitor.cpp
	g++ -std=c++2a -c -I. -o build/RuiMonitor.o monitor/RuiMonitor.cpp
build/BaseLayout.o: layout/BaseLayout.h layout/BaseLayout.cpp
	g++ -std=c++2a -c -I. -o build/BaseLayout.o layout/BaseLayout.cpp
build/ColumnLayout.o: layout/ColumnLayout.h layout/ColumnLayout.cpp
	g++ -std=c++2a -c -I. -o build/ColumnLayout.o layout/ColumnLayout.cpp
build/Container.o: layout/Container.h layout/Container.cpp
	g++ -std=c++2a -c -I. -o build/Container.o layout/Container.cpp
build/LeafLayout.o: layout/LeafLayout.h layout/LeafLayout.cpp
	g++ -std=c++2a -c -I. -o build/LeafLayout.o layout/LeafLayout.cpp
build/RowLayout.o: layout/RowLayout.h layout/RowLayout.cpp
	g++ -std=c++2a -c -I. -o build/RowLayout.o layout/RowLayout.cpp
build/Color.o: utils/Color.h utils/Color.cpp
	g++ -std=c++2a -c -I. -o build/Color.o utils/Color.cpp
build/Rect.o: utils/Rect.h utils/Rect.cpp
	g++ -std=c++2a -c -I. -o build/Rect.o utils/Rect.cpp
build/Geometry.o: utils/Geometry.h utils/Geometry.cpp
	g++ -std=c++2a -c -I. -o build/Geometry.o utils/Geometry.cpp
build/BaseWidget.o: widgets/BaseWidget.h widgets/BaseWidget.cpp
	g++ -std=c++2a -c -I. -o build/BaseWidget.o widgets/BaseWidget.cpp
build/ButtonWidget.o: widgets/ButtonWidget.h widgets/ButtonWidget.cpp
	g++ -std=c++2a -c -I. -o build/ButtonWidget.o widgets/ButtonWidget.cpp
build/ImageWidget.o: widgets/ImageWidget.h widgets/ImageWidget.cpp
	g++ -std=c++2a -c -I. -o build/ImageWidget.o widgets/ImageWidget.cpp
build/CheckboxWidget.o: widgets/CheckboxWidget.h widgets/CheckboxWidget.cpp
	g++ -std=c++2a -c -I. -o build/CheckboxWidget.o widgets/CheckboxWidget.cpp 
build/RadioButtonWidget.o: widgets/RadioButtonWidget.h widgets/RadioButtonWidget.cpp
	g++ -std=c++2a -c -I. -o build/RadioButtonWidget.o widgets/RadioButtonWidget.cpp
build/TextInputWidget.o: widgets/TextInputWidget.h widgets/TextInputWidget.cpp
	g++ -std=c++2a -c -I. -o build/TextInputWidget.o widgets/TextInputWidget.cpp
build/ScreenWidget.o: widgets/ScreenWidget.h widgets/ScreenWidget.cpp
	g++ -std=c++2a -c -I. -o build/ScreenWidget.o widgets/ScreenWidget.cpp
build/ScreenObject.o: widgets/elements/ScreenObject.h widgets/elements/ScreenObject.cpp
	g++ -std=c++2a -c -I. -o build/ScreenObject.o widgets/elements/ScreenObject.cpp
clean:
	rm -rf build/*.o build/*.gch build/*.out
lines:
	find . -type f -name "*.cpp" -o -name "*.h" -o -name "Makefile" | xargs wc -l
