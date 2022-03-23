all: main.o GeneralPage.o RuiMonitor.o BaseLayout.o ColumnLayout.o LeafLayout.o RowLayout.o Color.o Rect.o BaseWidget.o ButtonWidget.o
	g++ *.o -o RUI.out -Wall -g -O2 -std=c++2a -lSDL2
run:
	./RUI.out
main.o: main.cpp
	g++ -c -I. main.cpp
GeneralPage.o: GeneralPage.h GeneralPage.cpp
	g++ -c -I. GeneralPage.cpp
RuiMonitor.o: monitor/RuiMonitor.h monitor/RuiMonitor.cpp
	g++ -c -I. monitor/RuiMonitor.cpp
BaseLayout.o: layout/BaseLayout.h layout/BaseLayout.cpp
	g++ -c -I. layout/BaseLayout.cpp
ColumnLayout.o: layout/ColumnLayout.h layout/ColumnLayout.cpp
	g++ -c -I. layout/ColumnLayout.cpp
LeafLayout.o: layout/LeafLayout.h
	g++ -c -I. layout/LeafLayout.h
RowLayout.o: layout/RowLayout.h layout/RowLayout.cpp
	g++ -c -I. layout/RowLayout.cpp
Color.o: utils/Color.h utils/Color.cpp
	g++ -c -I. utils/Color.cpp
Rect.o: utils/Rect.h utils/Rect.cpp
	g++ -c -I. utils/Rect.cpp
BaseWidget.o: widgets/BaseWidget.h
	g++ -c -I. widgets/BaseWidget.h
ButtonWidget.o: widgets/ButtonWidget.h
	g++ -c -I. widgets/ButtonWidget.h
clean:
	rm -rf *.o *.out
	find . -type f -name "*.gch" -exec rm {} + 
