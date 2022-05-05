#ifndef RANDWORD_H_
#define RANDWORD_H_
#include <random>
#include <vector>
#include <ctime>
std::string randNoun(std::mt19937& mt) {
	std::uniform_int_distribution<int> gen(0,191);
	std::vector<std::string> nl{"rake","club","pollution","cabbage","ball","pencil","plantation","morning","example","bite","clam","pail","snow","credit","stocking","rat","unit","anger","feeling","direction","fork","pear","squirrel","soda","quicksand","love","land","smile","plastic","thread","books","flower","drop","ship","berry","day","camp","snakes","wren","skirt","guide","twist","system","rest","crown","poison","meeting","slope","nut","vest","pickle","island","magic","knot","lamp","window","mist","border","stream","ticket","visitor","rabbit","move","stage","floor","actor","boundary","noise","control","crowd","line","history","icicle","meal","robin","team","pigs","degree","rule","crook","teaching","wind","afternoon","anger","shape","letter","rail","toothpaste","doll","knee","pig","mailbox","scent","sister","road","badge","line","pear","yak","wash","flesh","yam","minute","amusement","month","men","wool","doll","van","company","writer","bee","silver","seat","afterthought","flame","giants","toys","vein","sister","sun","reason","star","nation","grape","war","fruit","cable","motion","dime","limit","competition","potato","sweater","thrill","box","jewel","grade","receipt","prose","attraction","trick","cream","duck","bubble","business","toe","sweater","motion","skin","carpenter","base","vegetable","sister","believe","curve","juice","suit","cook","board","insect","cream","grade","van","friction","coil","authority","cast","idea","blade","fact","language","carriage","trouble","sand","morning","walk","limit","wilderness","flower","join","bath","library","books","hill","pleasure","sneeze","wood","cows","word","bird","pancake"};
	return nl[gen(mt)];
}
std::string randVerb(std::mt19937& mt) {
	std::uniform_int_distribution<int> gen(0,191);
	std::vector<std::string> vl{"true","lewd","eatable","brash","dizzy","wiry","motionless","torpid","useless","real","fluffy","modern","melted","shy","tense","sneaky","ubiquitous","unwritten","petite","crooked","calculating","furry","faithful","feigned","soft","general","abusive","ajar","lazy","lowly","splendid","massive","goofy","separate","tremendous","slow","clean","last","weak","aberrant","idiotic","embarrassed","melodic","periodic","hulking","square","shaggy","secretive","laughable","insidious","malicious","marked","optimal","internal","obscene","wry","shocking","tacit","sparkling","toothsome","uttermost","blue-eyed","material","lopsided","wrong","ablaze","decisive","quixotic","ratty","disgusting","possible","poor","painful","possessive","questionable","jumpy","neighborly","stingy","panicky","uppity","damaged","tricky","protective","flowery","absurd","depressed","brawny","present","wakeful","zealous","volatile","plant","abortive","crabby","anxious","plucky","spiky","statuesque","abrasive","rabid","slimy","horrible","electric","whimsical","tearful","chubby","talented","instinctive","prickly","decorous","drab","closed","ill-informed","shaky","brave","accidental","acid","confused","rapid","nice","awful","functional","maddening","pushy","cooperative","amazing","clammy","threatening","previous","used","cold","yielding","hurt","distinct","hungry","somber","jolly","full","military","second-hand","kaput","nondescript","cynical","subsequent","curly","knowledgeable","unwieldy","tightfisted","weary","fancy","imminent","uninterested","gaping","evasive","various","craven","hot","forgetful","dramatic","envious","pathetic","tame","cool","big","famous","incredible","chivalrous","perfect","silent","pale","beneficial","receptive","accurate","ahead","royal","entertaining","ruthless","cloudy","snobbish","few","rotten","stale","demonic","invincible","well-made","lethal","imaginary","aboard","long-term","thoughtless","spiritual","caring"};
	return vl[gen(mt)];
}
std::string randExt(std::mt19937& mt) {
	std::vector<std::string> el{".txt",".md",".pdf",".png",".txt",".txt",".c",".cpp",".js",".java",".zsf",".zcm",".hx",".sh",".S",".lnk"};
	std::uniform_int_distribution<int> gen(0,(int)el.size());
	return el[gen(mt)];
}
std::string nvp(std::mt19937& mt) {
	return randVerb(mt) + randNoun(mt);
}
#endif
