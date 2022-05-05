//cipstr.cpp
#include <string>
#include <random>

int rind(std::string n) {
	std::string lt[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	for(int i=0;i<26;i++) {
		if(n==lt[i])
			return i+1;
	}
	return -1;
}
int rind(char n) {
	char lt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i=0;i<26;i++) {
		if(n==lt[i])
			return i+1;
	}
	return -1;
}
std::string ind(int n) {
	std::string lt[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	n=n%26;
	n=(n==0?26:n);
	return lt[n-1];
}
char toChar(int n) {
	char lt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	return lt[n-1];
}
char randChar() {
	std::random_device rd;
	static std::mt19937 eng(rd());
	std::uniform_int_distribution<int> dist(1, 26);
	return toChar(dist(eng));
}
std::string pad(std::string in, int c) {
	std::string out(in);
	for(size_t i=0; i<(4-(in.size() % c));i++)
		out += randChar();
	return out;
}
void appRand(std::string& in) {
	in += randChar();
}

