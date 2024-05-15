tumislemler: derleme baglama calistir

derleme:
	g++ -c -I "./include/" ./src/main.cpp -o ./lip/main.o
	g++ -c -I "./include/" ./src/Basamak.cpp -o ./lip/Basamak.o
	g++ -c -I "./include/" ./src/sayi.cpp -o ./lip/sayi.o
	g++ -c -I "./include/" ./src/Dugum.cpp -o ./lip/Dugum.o
	g++ -c -I "./include/" ./src/Sayilarlistesi.cpp -o ./lip/Sayilarlistesi.o
	
baglama:
	g++ ./lip/main.o ./lip/Basamak.o ./lip/sayi.o ./lip/Dugum.o ./lip/Sayilarlistesi.o -o ./bin/program.exe

calistir:
	./bin/program.exe
