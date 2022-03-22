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
BaseLayout.o: layout/BaseLayout.h
	g++ -c -I. layout/BaseLayout.h
ColumnLayout.o: layout/ColumnLayout.h
	g++ -c -I. layout/ColumnLayout.h
LeafLayout.o: layout/LeafLayout.h
	g++ -c -I. layout/LeafLayout.h
RowLayout.o: layout/RowLayout.h
	g++ -c -I. layout/RowLayout.h
Color.o: utils/Color.h utils/Color.cpp
	g++ -c -I. utils/Color.cpp
Rect.o: utils/Rect.h
	g++ -c -I. utils/Rect.h
BaseWidget.o: widgets/BaseWidget.h
	g++ -c -I. widgets/BaseWidget.h
ButtonWidget.o: widgets/ButtonWidget.h
	g++ -c -I. widgets/ButtonWidget.h
clean:
	rm -rf *.o *.out
	find . -type f -name "*.gch" -exec rm {} + 
