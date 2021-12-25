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
	"Daihatsu Ayla \t\t", "Toyota Raize \t\t", "Nissan Livina \t\t", "Daihatsu Gran Max \t", "Toyota Land cruiser \t", "Toyota Vellfire \t", 
	"Chevrolet Colorado \t", "Toyota Veloz \t\t", "Daihatsu Sigra \t\t", "Hummer \t\t\t", "Range Rover sport \t",  "Toyota Alphard \t\t", 
	"Toyota Avanza \t\t", "Toyota Camry \t\t", "Honda CRV 1.5L Turbo \t", "Honda CRV 1.5L Turbo Prestige", "Toyota Fortuner \t",  "Toyota Hiace Premio \t", 
	"Hyundai H1 Royale \t", "Hyundai H1 XG \t\t", "Toyota Kijang Innova \t", "Toyota Kijang Innova Venturer ", "Lexus LX 570 \t\t", "Mercedes Benz C300 AMG \t", 
	"Mercedes Benz E250 \t", "Mercedes Benz E300 AMG \t", "Mercedes Benz S400 Hybrid", "Toyota Voxy \t\t", "Daihatsu Xenia \t\t", "Mitsubishi Xpander \t", 
	"Honda Brio \t\t", "Honda Jazz \t\t", "Toyota Yaris \t\t", "Nissan March \t\t", "Nissan Evalia \t\t", "Daihatsu Luxio \t\t"
};
string fuels[] =
{
	"45", "36", "55", "45", "93", "75", 
	"53", "45", "36", "6,2", "80", "75", 
	"45", "60", "58", "53", "80", "70", 
	"75", "75", "55", "55", "138", "66", 
	"66", "66", "70", "55", "43", "45",
	"35", "40", "42", "41", "55", "43"
};
string seats[] =
{
	"5", "5", "7", "8", "7", "7", 
	"7", "7", "7", "5", "5", "7", 
	"7", "5", "7", "7", "7", "16", 
	"8", "9", "7", "6", "7", "5", 
	"5", "5", "5", "7", "7", "7", 
	"5", "5", "5", "5", "7", "8"
};
string engines[] =
{
	"1000", "998", "1500", "1330", "4500", "2494", 
	"2231", "1496", "998", "6200", "3550", "2494", 
	"1329", "2494", "1498", "1498", "2393", "2755", 
	"2497", "2497", "2393", "2393", "5663", "1991", 
	"1991", "1991", "3498", "1987", "989", "1499", 
	"1199", "1497", "1496", "1198", "1498", "1495"
};
string engineTypes[] =
{
	"Otomatis", "Otomatis", "Otomatis", "Manual", "Otomatis", "Otomatis", 
	"Otomatis", "Manual", "Otomatis", "Manual", "Otomatis", "Otomatis", 
	"Manual", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual", 
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", 
	"Otomatis", "Otomatis", "Otomatis", "Otomatis", "Otomatis", "Manual", 
	"Manual", "Manual", "Manual", "Manual", "Otomatis", "Manual"
};
string haveAC[] =
{
	"Tidak", "Ya", "Ya", "Tidak", "Ya", "Tidak", 
	"Ya", "Tidak", "Ya", "Ya", "Ya", "Ya", 
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", 
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", 
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya", 
	"Ya", "Ya", "Ya", "Ya", "Ya", "Ya"
};
string fuelTypes[] =
{
	"Bensin", "Bensin", "Bensin", "Bensin", "Diesel", "Bensin", 
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Diesel", "Diesel", 
	"Diesel", "Diesel", "Diesel", "Diesel", "Bensin", "Bensin",
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin", 
	"Bensin", "Bensin", "Bensin", "Bensin", "Bensin", "Bensin"
};
int prices[] =
{
	250000, 350000, 250000, 350000, 11000000, 2500000, 
	1500000, 400000, 275000, 9500000, 5000000, 2200000,
	400000, 1300000, 1200000, 1300000, 1400000, 1450000, 
	1400000, 850000, 850000, 1000000, 11000000, 2700000,
	3000000, 3200000, 11000000, 1200000, 400000, 600000, 
	275000, 350000, 400000, 300000, 325000, 325000
};
string colors[] =
{
	"Red", "Black", "Brown", "Blue", "Silver", "Silver", "Red", "Silver", "Black", "Aqua Blue", "Black", "Graphite", "Dark Brown",
	"Burning Black", "Crystal Black Pearl", "White Orchid Pearl", "Dark Grey", "Silver", "Silver", "Silver", "Phantom Brown",
	"Silver Metalic", "White", "Polar White", "Silver", "Blue", "Bright White", "White Pearl", "Icy White", "Black", "Tafetta White",
	"Rallye Red", "Attitude Black Mica", "Ruby Red", "Grey", "Icy White",
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
	"G", "H", "K", "AB", "R", "AA", "AD", "AB", "D", "E", "AB", "F", "T", "Z", "A", "B", "L", "M",
	"N", "AB", "P", "S", "AB", "W", "AB", "AE", "AG", "AB", "DK", "AB", "AB", "AB",
};
