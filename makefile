Tum: derleme baglama calistirma

derleme:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/DosyaOku.cpp -o ./lib/DosyaOku.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/SatirListesiDugum.cpp -o ./lib/SatirListesiDugum.o
	g++ -c -I "./include" ./src/YoneticiListesiDugum.cpp -o ./lib/YoneticiListesiDugum.o
baglama:
	g++  ./lib/DosyaOku.o ./lib/main.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/SatirListesiDugum.o ./lib/YoneticiListesiDugum.o -o ./bin/program
calistirma:
	./bin/program