#include "contbg.h"
#include "usefrt.h"

bool exesim(std::string name, Scorekeep& n, std::mt19937& mt) {
	if(name == "bin") {
		std::cout << "Would you like to throw something away? You have the wrong command.\n";
	}
	else if(name == "hide.exe") {
		std::string t;
		t = io("What would you like to hide?\n>");
		if(t == "shovel" && n.hasShovel) {
			std::cout << "Shovel has been hidden.\n";
			n.hasShovel = false;
			n.shovelHidden = true;
		}
	}
	else if(name == "bazaar.exe") {
		std::string t;
		t = io("What are you looking for?\n>");
		if(t == "key") {
			t = io("I have several keys. Do you want a big key or a small one?\n>");
			t = t.substr(0,1);
			if(t == "b" || t == "B") {
				std::cout << "Ah, the big key. That costs a golden peach pit, a shovel, three points, and two small keys.\n";
				if(n.score >= 3 && n.keys >= 2 && n.hasShovel && n.hasGoldPit) {
					t = io("Are you sure you want it?\n>").substr(0,1);
					if(t == "y" || t == "Y") {
						std::cout << "Okay, here you go.\n";
						n.score -= 3;
						n.keys -= 2;
						n.hasShovel = false;
						n.hasGoldPit = false;
					}
				}
				else {
					std::cout << "You don't have the required items.\n";
				}
			}
			else if(t == "s" || t == "S") {
				std::cout << "I'll sell you a small key for only one point.\n";
				if(n.score >= 1) {
					t = io("Are you sure you want it?\n>");
					if(t == "y" || t == "Y") {
						std::cout << "Here you go.\n";
						n.score -= 1;
						n.keys += 1;
					}
				}
				else {
					std::cout << "You can't afford this.\n";
				}
			}
		}
		else {
			std::cout << "I don't have that.\n";
		}
	}
	else if(name == "door.exe") {
		if(n.finalKey) {
			std::cout << "Congratulations: You won! \n";
		}
		else {
			std::cout << "You don't have permisson to run this.\n";
		}
	}
	else if(name == "bonus.exe") {
		if(n.gotBonus) {
			std::cout << "You've already got a bonus.\n";
		}
		else if(n.polite) {
			std::cout << "You've been nice to me, so I'll give you some points.\n";
			n.score += 2;
			n.gotBonus = true;
		}
		else {
			std::cout << "If you are looking for points, you need to be more nice.\n";
		}
	}
	else if(name == "clear") {

	}
	else if(name == "ackbar.exe") {
		std::string in;
		in = io("You are in front of a big door. Do you go in?\n>");
		if(in.substr(0,1) == "y") {
			std::cout << "IT'S A TRAP!!!!!!!\n";
			std::cout << "You've been eaten by a grue.\n";
		}
		else {
			std::cout << "Good call. You survive.\n";
			std::cout << "You find a common key on the ground.\n";
			n.keys++;
			n.score++;
		}
	}
	else if(name == "llave.exe") {
		if(n.gotLlave) {
			std::cout << "You already got this.\n";
		}
		else if(n.score >= 3 && !n.gotLlave) {
			std::cout << "You have at least 3 points, so here is a key.\n";
			n.gotLlave = true;
		}
		else if(n.polite && !n.gotLlave) {
			n.gotLlave = true;
			std::cout << "You asked nicely, so here is a key. Your politeness has worn off.\n";
			n.polite = false;
		}
	}
	else if(name == "t4.exe") {
		std::cout << "You found a T4 bacteriophage.\n";
		if(n.ecoli && !n.virus) {
			std::cout << "You've been infected.\n";
		}
		else if(!n.ecoli) {
			std::cout << "You aren't e coli, so you weren't infected.\n";
		}
	}
	else if(name == "calculus") {

	}
	else if(name == "xkcd.exe") {

	}
	else if(name == ".secrets") {

	}
	else if(name == "system32") {

	}
	else if(name == "notavirus.exe") {
		n.virus = true;
		std::cout << "Sorry, this was a misnomer. You've been infected.\n";
	}
	else if(name == "homeofclippy.exe") {

	}
	else if(name == "ADVENT.EXE") {

	}
	else if(name == "cheese.png") {
		std::cout <<"      CHEESE        \n" <<
					"                ,;  \n" <<
					"             ,.`|'  \n" <<
					"          ,.`O  /   \n" <<
					"       ,.`     |'   \n" <<
					"    ,.`   o  @ /    \n" <<
					" ,.` o @      |'    \n" <<
					"  `-_    O   /      \n" <<
					"     `-__   *|'     \n" <<
					"         `-__/      \n";
	}
	else if(name.substr(name.find(".")+1) == "png") {
		std::string nfname = "assets/"+name;
		img2asciiart(nfname);
	}
	else {
		return false;
	}
	return true;
}
