#include <fstream>
#include <deque>
#include <ctime>
#include "usefrt.h"
#include "cipstr.h"
#include "randword.h"
#include "contbg.h"


/*   this is a text-based adventure game inspired by the console
 *   TODO:
 *   add error messages to commands
 *   organize includes
 *   work on story
 */
int main() {
	std::cout << "Console game: created by xavenna. Have fun.\n";

	std::map<std::string, std::string> mli; //master list
	init(mli);  //initializes master list with potential links
	std::map<std::string, std::string> list;
	list.insert(std::pair("door.exe", "\0")); //these will be added every time
	list.insert(std::pair("cheats.exe", "\0"));
	list.insert(std::pair("hide.exe", "\0"));
	list.insert(std::pair("bazaar.exe", "\0"));
	chooseRands(mli, list, 0.4f);  //adds some of the random files to the utilized files list
	std::mt19937 eng(time(NULL));  //I have had problems with std::random_device not being random...maybe replace
	std::uniform_int_distribution<int> dieroll(1,6);
	Scorekeep score;
	bool run = true;
	std::string pin;
	std::string spin;
	std::string temp;
	do {
		pin = io("$ ");
		if(pin.substr(0,6) == "please") {
			if(pin.size() >= 8) {
				if(pin.substr(7) == "help") {
					std::cout << "I'll help if you say the magic word.\n>";
					std::getline(std::cin, spin);
					if(spin == "the magic word") {
						std::cout << "I see you are a literal one.\n";
						score.literal=true;
					}
					else if(spin == "alohomora") { //make sure spelled right
						std::cout << "Okay, I guess I'll need to give you a hint...\n";
						std::cout << "Here are some commands: tell, hide, look, pit, pizza.\n";
					}
					else if(spin == "alohamora") {
						std::cout << "aloha to you too, my friend. Although my name isn't Mora...\n";
					}
					else if(spin == "please") {
						std::cout << "Sorry, that isn't right. Nice try, though.\n";
						score.polite=true;
					}
					else {
						std::cout << "That isn't right.\n";
					}
				}
				else if(pin.substr(7) == "show") {
					for(auto x : list)
						std::cout << x.first << '\n';
				}
			}
			else {
				std::cout << "No.\n";
			}
		}
		else if(pin == "help") {
			std::cout << "Sorry, I can't help you. You'll have to figure out what to do.\n";
			std::cout << "Actually, if you ask nicely, I might help.\n";
		}
		else if(pin == "exit") {
			std::cout << "Are you sure you want to exit?\n>";
			std::getline(std::cin, spin);
			if(spin.substr(0,1) == "y" || spin.substr(0,1) == "Y")
				run = false;
		}
		else if(pin.substr(0,4) == "tell") {
			if(pin.size() >= 6) {
				try {
					if(list.at(pin.substr(5)) != "\0") {
						//output contents of the file
						std::cout << list.at(pin.substr(5)) << '\n';
					}
					else {
						std::cout << "This file can't be read out.\n";
					}
				}
				catch (...) {
					std::cout << "Error: object doesn't exist.\n";
				}
			}
			else {
				std::cout << "What should I tell you?\n";
			}
		}
		else if(pin == "hide") {
			std::cout << "Would you like to hide something?\n";
			std::cout << "Try using hide.exe.\n";
		}
		else if(pin == "look") {
			//look for something that is hidden
		}
		else if(pin == "show") {
			//show list of files that are in current directory
			for(auto x : list) {
				if(x.first.substr(0,1) != ".")
					std::cout << x.first << '\n';
			}
		}
		else if(pin == "ls") {
			std::cout << "/usr/share/Adobe/doc/example/android_vm/root/sbin/ls.jar: Error: Device is not responding.\n";
		}
		else if(pin == "cat") {
			std::cout << "meow\n";
		}
		else if(pin == "dir") {
			std::cout << "Do you need directions? Too bad. I can't help you.\n";
		}
		else if(pin == "score") {
			std::cout << "Your score is " << score.score << ".\n";
			std::cout << "You have " << score.keys << " keys.\n";
		}
		else if(pin == "pit") {
			int n = dieroll(eng);
			if(n == 1) {
				std::cout << "You have been trapped in a pit. ha\n";
				score.stuck=true;
			}
			else if(n == 6) {
				std::cout << "You found a golden peach pit.\n";
				score.hasGoldPit=true;
			}
			else if(n == 5) {
				std::cout << "You find a shovel next to a pit.\n";
				score.hasShovel=true;
			}
			else {
				std::cout << "You are correct, there is a pit.\nHow insightful\n";
			}
		}
		else if(pin == "pizza") {
			std::cout << "Do you like pizza?\n>";
			std::getline(std::cin, spin);
			temp = spin.substr(0,1);
			if(temp == "y" || temp == "Y") {
				std::cout << "That is good.\n";
				score.score++;
			}
			else {
				std::cout << "You don't like pizza?!\nHuh.";
			}
		}
		else {
			if(list.count(pin) == 1) {
				if(!exesim(pin, score))
					std::cout << "That isn't a valid command.\n";
			}
		}
	}while(run);
}