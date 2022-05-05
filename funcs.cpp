#include "cipstr.h"
#include "contbg.h"
#include <ctime>
extern "C" {
	#define STB_IMAGE_IMPLEMENTATION
	#include "stb_image.h"
}
bool img2asciiart(std::string filename, int width, int height) {
	int w, h;
	std::vector<unsigned char> image;
	if(!load_image(image, filename, w, h)) {
		return false;
	}
	//transform image size to output size -- i'm not entirely sure how to do this
	
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			size_t index = 3 * (i * w + j);
			std::cout << pix2ascii(image[index],image[index+1],image[index+2]);
		}
		std::cout << '\n';
	}
	return true;
}
bool img2asciiart(std::string filename) { //overload for using images as default size
	int w, h;
	std::vector<unsigned char> image;
	if(!load_image(image, filename, w, h)) {
		return false;
	}
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			size_t index = 3 * (i * w + j);
			std::cout << pix2ascii(image[index],image[index+1],image[index+2]);
		}
		std::cout << '\n';
	}
	return true;
}
char pix2ascii(int r, int g, int b) {
	int grey = 0.299*r + 0.587*g + 0.114*b;
	std::string map=" `.':;ox$%#@";
	return map[(255-grey)*(map.length())/256];
}
bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int&y) {
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 3);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 3);
    }
    stbi_image_free(data);
    return (data != nullptr);
}
bool coinFlip(std::mt19937& mt) {
	std::uniform_int_distribution<int> dieroll(1,2);
	return dieroll(mt);
}
void chooseRands(std::map<std::string, std::string>& main, std::map<std::string, std::string>& out, std::mt19937& mt, float p) {
	std::uniform_real_distribution<float> r(0,1);
	for(auto x : main) {
		if(r(mt) >= p)
			out.insert(x);
	}
}
void init(std::map<std::string, std::string>& m, std::mt19937& mt) { //make sure none of these are required 
	m.insert(std::pair("bin", "\0"));
	m.insert(std::pair("files", "\0"));
	m.insert(std::pair(".hint.txt", "To leave, you need to find a big key to unlock the door."));
	m.insert(std::pair("ackbar.exe", "\0"));
	m.insert(std::pair("t4.exe", "\0"));
	m.insert(std::pair("fuigiufj", "ghrusioghegnvujhalgjrfnqnrfvusehrldf"));
	m.insert(std::pair("e-coli.txt", "I didn't like my E.coli infection, but then it grew on me..."));
	m.insert(std::pair("calculus", "\0"));
	m.insert(std::pair("notes.txt", "Notes: watch out for pits. They can be dangerous"));
	m.insert(std::pair("xkcd.exe", "\0"));
	m.insert(std::pair(".secrets", "\0"));
	m.insert(std::pair("[REDACTED]", "[REDACTED]"));
	m.insert(std::pair("system32", "\0"));
	m.insert(std::pair("notavirus.exe", "\0"));
	m.insert(std::pair("homeofclippy.exe", "\0"));
	m.insert(std::pair("bottle.txt", "You find a bottle that contains a message that says: Hello, there"));
	m.insert(std::pair("Adminpassword.txt", "There is no password"));
	m.insert(std::pair("help.txt", "Want some help? Try typing help"));
	m.insert(std::pair("doc1.docx", "Error: filetype not supported."));
	m.insert(std::pair("doc2.odt", "I see you are a user of open-source software. Cool"));
	m.insert(std::pair("list.txt", "Don't get lost in the maze"));
	m.insert(std::pair("cheese.png", "\0"));
	m.insert(std::pair("ADVENT.EXE", "\0"));
	m.insert(std::pair("descript.ion", "This is a console-based game. To win, successfully run door.exe"));
	m.insert(std::pair(".random", "stuff"));
	m.insert(std::pair("bonus.exe", "\0"));
	m.insert(std::pair("tmp.txt", "829032178bcd3ab078aeb78ab0bf8073abc0")); //maybe make andom
	m.insert(std::pair("llave.exe", "\0"));
	m.emplace("lock.png","\0");
	m.emplace("player.png","\0");
	m.emplace("board.png","\0");
	//create some random files:
	m.insert(std::pair(pad("n",8), "This was procedurally generated. Cool, right?"));
	m.insert(std::pair(pad("q",9)+pad(".",4), "Randomfuhreuiohuriohruehgulslsj"));
	m.insert(std::pair(pad("e",9)+pad(".",4), "YIGHT!!!!!!!!!!!!!!!!!!!!!!"));
	m.insert(std::pair(pad("f",9)+pad(".",4), "don't run notavirus.exe"));
	m.insert(std::pair(pad("j",9)+pad(".",4), "don't delete system32"));
	//create some pseudorandom files:
	m.emplace(nvp(mt)+randExt(mt), "This is a random filename.");
	m.emplace(nvp(mt)+randExt(mt), "You shouldn't delete system32.\n");
}
