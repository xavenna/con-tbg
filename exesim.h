#ifndef CONTBG_H
#define CONTBG_H

void exesim(std::string name, ) {
	if(name == "bin") {
		bin();
	}
	else if(name == "door.exe") {
		door();
	}
	else if(name == "clear") {
		clear();
	}
	else if(name == "ackbar.exe") {
		ackbarexe();
	}
	else if(name == "t4.exe") {
		t4();
	}
	else if(name == "calculus") {
		calculus();
	}
	else if(name == "xkcd.exe") {
		xkcdexe();
	}
	else if(name == ".secrets") {
		secrets();
	}
	else if(name == "system32") {
		system32();
	}
	else if(name == "notavirus.exe") {
		notavirusexe();
	}
	else if(name == "homeofclippy.exe") {
		homeofclippyexe();
	}
	else if(name == "ADVENT.EXE") {
		adventexe();
	}
}

#endif
