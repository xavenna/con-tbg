#ifndef CONTBG_H
#define CONTBG_H
#include <map>
#include <string>
#include <random>
#include <iostream>
#include "usefrt.h"



class Scorekeep {
public:
	int score;
	int keys;
	bool literal;
	bool polite;
	bool hasWon;
	bool stuck;
	bool hasGoldPit;
	bool hasShovel;
	bool gotBonus;
	bool finalKey;
	bool virus;
	bool ecoli;
	bool shovelHidden;
	bool gotLlave;
	Scorekeep() {
		score=0;
		keys=0;
		literal=false;
		hasWon=false;
		stuck=false;
		hasGoldPit=false;
		hasShovel=false;
		gotBonus=false;
		polite=false;
		finalKey=false;
		virus=false;
		ecoli=false;
		shovelHidden=false;
	}
};
void console();
bool coinFlip();
void chooseRands(std::map<std::string, std::string>&, std::map<std::string, std::string>&, float p = .5);
void init(std::map<std::string, std::string>&);
bool exesim(std::string, Scorekeep&);
bool picdisp(std::string);
char pix2ascii(int, int, int);
bool img2asciiart(std::string, int, int);
bool load_image(std::vector<unsigned char>&, const std::string&, int&, int&);
std::string randNoun();
std::string randVerb();
std::string nvp();
std::string randExt();

void init(std::map<std::string, std::string>&);
#endif
