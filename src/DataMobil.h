#pragma once
#include <iostream>
using namespace std;

/*
    Keterangan nama array:
    - models[]		: adalah array yang menampung data jenis mobil
    - fuels[]		: adalah array yang menampung data kapasitas tangki BBM mobil (L)
    - seats[]		: adalah array yang menampung data kapasitas tempat duduk mobil
    - engines[]     : adalah array yang menampung data kapasitas mesin mobil (cc)
    - engineTypes[] : adalah array yang menampung data transmisi pada mobil
    - haveAC[]      : adalah array yang menampung data apakah mobil terdapat AC atau tidak
    - fuelTypes[]   : adalah array yang menampung data bahan bakar yang digunakan oleh mobil
    - colors[]      : adalah array yang menampung data warna mobil primer
	- allColors[]	: adalah array yang menampung data warna mobil sekunder
    - prices[]      : adalah array yang menampung data harga sewa mobil per hari (24 jam)
*/

string models[] =
{
	"Daihatsu Ayla", "Toyota Raize", "Nissan Livina", "Daihatsu Gran Max", "Toyota Land Cruiser", "Toyota Vellfire",
	"Chevrolet Colorado", "Toyota Veloz", "Daihatsu Sigra", "Hummer H2", "Range Rover Sport", "Toyota Alphard",
	"Toyota Avanza", "Toyota Camry", "Honda CRV 1.5L Turbo", "Honda CRV 1.5L Turbo Prestige", "Toyota Fortuner",
	"Toyota Hiace Premio", "Hyundai H1 Royale", "Hyundai H1 XG", "Toyota Kijang Innova", "Toyota Kijang Innova Venturer",
	"Lexus LX 570", "Mercedes Benz C300 AMG", "Mercedes Benz E250", "Mercedes Benz E300 AMG", "Mercedes Benz S400 Hybrid",
	"Toyota Voxy", "Daihatsu Xenia", "Mitsubishi Xpander", "Honda Brio", "Honda Jazz", "Toyota Yaris", "Nissan March",
	"Nissan Evalia", "Daihatsu Luxio", "Tesla Model 3", "Tesla Model X", "Tesla Model S", "Aston Martin Victor",
	"Rolls-Royce Cullinan", "Maserati Quattroporte", "Dodge Charger Hellcat", "Audi R8 2020", "Mustang SVT Cobra R",
	"Nissan Silvia S13", "Mazda RX-7", "McLaren P1", "Volkswagen Golf", "Mitsubishi Eclipse", "Jaguar Project 8",
	"Chevrolet Impala", "Aston Martin Vanquish", "Skyline GTR KGC10", "Volkswagen Beetle", "Maserati Levante",
	"Lamborghini Urus", "Porsche 992 Cabriolet", "Hummer H1", "Audi E-Tron 2020", "Volkswagen Type 2", "Chevrolet Suburban",
};

string fuels[] =
{
	"45 Liter", "36 Liter", "55 Liter", "45 Liter", "93 Liter", "75 Liter", "53 Liter", "45 Liter", "36 Liter",
	"62 Liter", "80 Liter", "75 Liter", "45 Liter", "60 Liter", "58 Liter", "53 Liter", "80 Liter", "70 Liter",
	"75 Liter", "75 Liter", "55 Liter", "55 Liter", "138 Liter", "66 Liter", "66 Liter", "66 Liter", "70 Liter",
	"55 Liter", "43 Liter", "45 Liter", "35 Liter", "40 Liter", "42 Liter", "41 Liter", "55 Liter", "43 Liter",
	"54 kWh", "100 kWh", "100 kWh", "N/A", "N/A", "80 Liter", "85 Liter", "83 Liter", "75 Liter", "60 Liter",
	"76 Liter", "N/A", "60 Liter", "63 Liter", "75 Liter", "85 Liter", "78 Liter", "50 Liter", "65 Liter",
	"95 Liter", "85 Liter", "64 Liter", "130 Liter", "100 kWh", "60 Liter", "60 Liter",
};
string seats[] =
{
	"5", "5", "7", "8", "7", "7", "7", "7", "7", "5", "5", "7", "7", "5",
	"7", "7", "7", "16", "8", "9", "7", "6", "7", "5", "5", "5", "5", "7",
	"7", "7", "5", "5", "5", "5", "7", "8", "5", "7", "5", "2", "6", "4",
	"6", "2", "2", "4", "4", "2", "5", "5", "4", "5", "2", "2", "4", "4",
	"6", "4", "6", "5", "5", "8",
};
string engines[] =
{
	"1000 CC", "998 CC", "1500 CC", "1330 CC", "4500 CC", "2494 CC", "2231 CC", "1496 CC", "998 CC", "6200 CC",
	"3550 CC", "2494 CC", "1329 CC", "2494 CC", "1498 CC", "1498 CC", "2393 CC", "2755 CC", "2497 CC", "2497 CC",
	"2393 CC", "2393 CC", "5663 CC", "1991 CC", "1991 CC", "1991 CC", "3498 CC", "1987 CC", "989 CC", "1499 CC",
	"1199 CC", "1497 CC", "1496 CC", "1198 CC", "1498 CC", "1495 CC", "Elektrik", "Elektrik",
	"Elektrik", "7233 CC", "6749 CC", "3799 CC", "6166 CC", "5204 CC", "5412 CC", "1998 CC", "1308 CC",
	"3799 CC", "1395 CC", "1499 CC", "5000 CC", "3599 CC", "5935 CC", "1989 CC", "2000 CC", "2993 CC", "3996 CC",
	"2981 CC", "6600 CC", "Elektrik", "1970 CC", "5328 CC",
};
string engineTypes[] =
{
	"Otomatis", "Otomatis", "Otomatis", "Manual", "Otomatis", "Otomatis",
	"Otomatis", "Manual", "Otomatis", "Manual", "Otomatis", "Otomatis",
	"Manual", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual",
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis",
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual",
	"Manual", "Manual", "Manual", "Manual", "Otomatis", "Manual", "Otomatis",
	"Otomatis", "Otomatis", "Manual", "Manual", "Otomatis", "Manual",
	"Otomatis", "Manual", "Otomatis", "Manual", "Otomatis", "Manual",
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual", "Otomatis",
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual", "Manual",
};
string haveAC[] =
{
	"Tidak", "Ya", "Ya", "Tidak", "Ya", "Tidak", "Ya", "Tidak",
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya",
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya",
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya",
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya",
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya", "Ya",
	"Ya", "Ya", "Tidak", "Ya",
};
string fuelTypes[] =
{
	"Bensin", "Bensin", "Bensin", "Bensin", "Diesel", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Diesel", "Diesel", "Diesel", "Diesel", "Diesel",
	"Diesel", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Baterai", "Baterai", "Baterai", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Baterai", "Bensin", "Diesel",
};
int prices[] =
{
	250000, 350000, 250000, 350000, 11000000, 2500000,
	1500000, 400000, 275000, 9500000, 5000000, 2200000,
	400000, 1300000, 1200000, 1300000, 1400000, 1450000,
	1400000, 850000, 850000, 1000000, 11000000, 2700000,
	3000000, 3200000, 11000000, 1200000, 400000, 600000,
	275000, 350000, 400000, 300000, 325000, 325000,
	1250000, 1250000, 1250000, 9500000, 12000000, 1275000,
	1050000, 7500000, 1000000, 650000, 550000, 15000000,
	550000, 675000, 2500000, 720000, 9000000, 378000,
	585000, 1135000, 8450000, 2525000, 2745000, 1500000,
	2500000, 685000,
};
string colors[] =
{
	"Red", "Black", "Brown", "Blue", "Silver", "Silver", "Red",
	"Silver", "Black", "Aqua Blue", "Black", "Graphite", "Dark Brown",
	"Burning Black", "Crystal Black Pearl", "White Orchid Pearl",
	"Dark Grey", "Silver", "Silver", "Silver", "Phantom Brown",
	"Silver Metalic", "White", "Polar White", "Silver", "Blue",
	"Bright White", "White Pearl", "Icy White", "Black", "Tafetta White",
	"Rallye Red", "Attitude Black Mica", "Ruby Red", "Grey", "Icy White",
	"Red", "Smoke White", "Ice White", "Ultra Black", "Metallic Gray",
	"Cyan", "Black", "Torino Red", "Formula Red", "Cream", "Metallic Orange",
	"Metallic Red", "Sky Blue", "Orange Red", "Dark Bue", "Black",
	"Formula Red", "Formula Red", "Formula Red", "Snow White", "Yellow Race",
	"Dark Blue Metallic", "Saddle Brown", "Sky Blue", "Ultra Blue", "Black",
};
string bodyTypes[] =
{
	"Compact", "SUV", "MPV", "Minivan", "SUV", "SUV", "Pickup Truck",
	"Minivan", "MPV", "Off-Road", "SUV", "Minivan", "MPV", "Sedan",
	"SUV", "SUV", "SUV", "Minibus", "Minivan", "MPV", "MPV", "MPV",
	"SUV", "Sedan", "Sedan", "Sedan", "Sedan", "Minivan", "MPV", "MPV",
	"Compact", "MPV", "Sedan", "MPV", "Minivan", "Minivan", "Sport",
	"Sport", "Sport", "Super", "SUV", "Sport", "Muscle", "Sport",
	"Muscle", "Muscle", "Muscle", "Super", "SUV", "SUV", "Sedan",
	"MPV", "Super", "Classic", "Compact", "SUV", "SUV", "Sport",
	"Off-Road", "SUV", "Classic", "SUV",
};
string manufacturers[]
{
	"Daihatsu", "Toyota", "Nissan", "Daihatsu", "Toyota", "Toyota", "Chevrolet",
	"Toyota", "Daihatsu", "Hummer", "Land Rover", "Toyota", "Toyota", "Toyota",
	"Honda", "Honda", "Toyota", "Toyota", "Hyundai", "Hyundai", "Toyota", "Toyota",
	"Lexus", "Mercedes Benz", "Mercedes Benz", "Mercedes Benz", "Mercedes Benz",
	"Toyota", "Daihatsu", "Mitsubishi", "Honda", "Honda", "Toyota", "Nissan",
	"Nissan", "Daihatsu", "Tesla", "Tesla", "Tesla", "Aston Martin", "Rolls-Royce",
	"Maserati", "Dodge", "Audi", "Ford", "Nissan", "Mazda", "McLaren", "Volkswagen",
	"Mitsubishi", "Jaguar", "Chevrolet", "Aston Martin", "Nissan", "Volkswagen",
	"Maserati", "Lamborghini", "Porsche", "Hummer", "Audi", "Volkswagen", "Chevrolet",
};
string allColors[] =
{
	"Black", "Graphite Black", "Black Steal", "Dark Silver", "Silver", "Blue Silver", "Steel Gray", "Shadow Silver", "Stone Silver",
	"Midnight Silver", "Gun Metal", "Anthracite Grey", "Gray", "Light Grey", "Black Poly", "Graphite", "Silver Grey", "Red", "Torino Red",
	"Formula Red", "Blaze Red", "Graceful Red", "Garnet Red", "Desert Red", "Cabernet Red", "Candy Red", "Sunrise Orange", "Classic Gold",
	"Orange", "Dark Red", "Yellow", "Bright Red", "Golden Red", "Dark Green", "Racing Green", "Sea Green", "Olive Green", "Green",
	"Gasoline Blue Green", "Lime Green", "Sea Wash", "Midnight Blue", "Dark Blue", "Saxony Blue", "Blue", "Mariner Blue", "Harbor Blue",
	"Diamond Blue", "Surf Blue", "Nautical Blue", "Purple Blue", "Spinnaker Blue", "Ultra Blue", "Bright Blue", "Sea Foam Blue",
	"Lightning blue", "Maui Blue Poly", "Light blue", "Taxi Yellow", "Race Yellow", "Bronze", "Yellow Bird", "Lime", "Champagne",
	"Pueblo Beige", "Dark Ivory", "Choco Brown", "Golden Brown", "Light Brown", "Straw Beige", "Moss Brown", "Biston Brown", "Beechwood",
	"Dark Beechwood", "Choco Orange", "Beach Sand", "Sun Bleeched Sand", "Cream", "Brown", "Medium Brown", "White", "Frost White", "Honey Beige",
	"Dark Brown", "Brushed Steel", "Brushed Black steel", "Brushed Aluminium", "Chrome", "Light Orange", "Securicor Green", "Olive Army Green",
	"Pure White", "Hot Pink", "Salmon pink", "Vermillion Pink", "Mettalic Black Blue", "Black Purple", "Black Red", "Hunter Green", "Purple",
	"Dark Purple", "Lava Red", "Forest Green", "Olive Drab", "Desert Brown", "Desert Tan", "Foilage Green", "Epsilon Blue",
};
string awalanPlat[] =
{
	"G", "H", "K", "AB", "R", "AA", "AD", "AB", "D", "E", "AB", "F", "T", "Z", "A", "B", "L",
	"M", "N", "AB", "P", "S", "AB", "W", "AB", "AE", "AG", "AB", "DK", "AB", "AB", "AB",
};