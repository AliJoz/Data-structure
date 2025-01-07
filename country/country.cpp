#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
using namespace std;
int Tabcounter(string S);
string splite_type(string L);
string splite_namecity(string L);
string splitePop(string L);
string splitpop2(string L);
string splitecuntpop(string L);
string SpliteNumberofCounty(string L);
string splitecunter2(string L);
int SpliteNumberofRuralDistrict(string L);
class node {
private:
	string name;//Tehran
	string city;
	int type;//0 1 2
	string pop;//poplitoin
	int numCunt; //125p
	string numberof;
	int numCunt2;//num56
	string div;
	int District;
	node* dlink;
	node* next;
public:
	node(string type, node* link) {
		this->name = " ";
		this->dlink = NULL;
		this->next = NULL;
		this->pop = " ";
		this->numCunt = 0;
		this->city = " ";
		this->type = 0;
		this->numCunt2 = 0;
		this->numberof = " ";
		this->div = "";
		this->District = 0;
	}
	node(string L) {
		string Namecity, title, pop, numcunt, numberof, numcut2;
		int type, destter;
		Namecity = splite_namecity(L);
		title = splite_type(L);
		type = Tabcounter(title);
		pop = splitePop(L);
		numcunt = splitecuntpop(L);//14033400	
		numberof = SpliteNumberofCounty(L);
		numcut2 = splitecunter2(L);
		destter = SpliteNumberofRuralDistrict(L);
		this->settitle(title); this->setcity(Namecity); this->settype(type);
		this->setpop(pop); this->setnumcount(stoi(numcunt));
		this->setnumberof(numberof); this->setnumcount2(stoi(numcut2));
		this->setdister(destter);
		settNext(NULL); setDLink(NULL);
	}
	// /// geter
	int getType() { return this->type; }//{Province: 
	string gettitle() { return this->name; }//Tehran	
	node* getDLink() { return this->dlink; }
	node* getNext() { return this->next; }
	string getcity() { return this->city; }
	string getpop() { return this->pop; }///Population 
	string getpop2() { return this->numberof; }//NumberofCounty 
	int getnumcount() { return this->numCunt; }//14033400	
	int getnumcount2() { return this->numCunt2; }//16},
	//seter
	void settype(int T) {
		this->type = T;
	}
	void settitle(string N) {
		this->name = N;
	}
	void setcity(string N) {
		this->city = N;
	}
	void setDLink(node* DL) {
		this->dlink = DL;
	}
	void settNext(node* NE) {
		this->next = NE;
	}
	void setnumcount(int C) {//14033400	
		this->numCunt = C;
	}
	void setnumcount2(int C2) {
		this->numCunt2 = C2;
	}
	void setpop(string P) {///Population 
		this->pop = P;
	}
	void setnumberof(string P) {///numberof
		this->numberof = P;
	}
	void setdister(int C2) {//numberofRuralDistrict
		this->District = C2;
	}
	void setdiv(string P) {///divvv 
		this->div = P;
	}
};
void print_console(node*);
void saveFile(node* f);
///  read
class stageC {
private:
	node* first;
public:
	stageC(node* f) {
		set(f);
	}
	void set(node* f) {
		this->first = f;
	}
	node* get() { return this->first; }


};
node* readFile() {
	ifstream txt("new.txt");
	string res;
	node* first = NULL;
	node* current = NULL;
	while (getline(txt, res, '\n'))
	{
		if (res.length() < 4)
			getline(txt, res, '\n');
		if (res == "//")
			break;
		node* D = new node(res);
		if (!first)
		{
			first = D;
			current = first;
		}
		else
		{
			current->setDLink(D);
			current = current->getDLink();
		}
	}
	txt.close();
	return first;
}
node* AddDowList(node* p, node* q)
{
	if (!q)
		return NULL;
	if (p->getType() == q->getType())
	{
		p->settNext(q);
		p->setDLink(NULL);
		q = AddDowList(q, q->getDLink());
	}
	else if (p->getType() < q->getType())
	{
		q = AddDowList(q, q->getDLink());
	}
	else
	{
		p->setDLink(NULL);
		return q;
	}
	while (q && p->getDLink() && p->getType() == q->getType())
	{
		p->settNext(q);
		q = AddDowList(q, q->getDLink());
	}
	return q;
}

void printcounterynodeback(node*);
// meno
int menoRead() {
	std::cout << "\n\n";
	std::cout << "\t\t1.)add \t\t\n" << endl;
	std::cout << "\t\t2.)print \t\t\n" << endl;
	std::cout << "\t\t3.)Delet \t\t\n" << endl;
	std::cout << "\t\t4.)exist \t\t\n" << endl;
	std::cout << "\t\t5.)change \t\t\n" << endl;
	std::cout << "\t\t6.)move \t\t\n" << endl;
	std::cout << "\t\t7.)Exit \t\t\n" << endl;
	int x;
	std::cout << "\n\n";
	std::cout << "\t\t>>";
	cin >> x;
	return x;
}

int menoPrint() {
	system("cls");
	std::cout << "\n\n\n";
	std::cout << "\t\t\t1.)print for stage \t\t" << "\n\n";
	std::cout << "\t\t\t2.)peint for city \t\t" << "\n\n";
	std::cout << "\t\t\t3.) print for ALL \t\t" << "\n\n";
	int x;
	cin >> x;
	return x;
}
int typeLevele(string x) {
	if (x.find("Province") != string::npos) {
		return 0;
	}
	else if (x.find("County") != string::npos) {
		return 1;

	}
	else if (x.find("District") != string::npos) {
		return 2;

	}
	else if (x.find("County") != string::npos) {

		return 3;
	}
	else if (x.find("City") != string::npos) {
		return 3;

	}
	else if (x.find("Rural District") != string::npos) {

		return 3;
	}
	else if (x.find("Village") != string::npos) {

		return 4;
	}
	else {
		std::cout << "\t\ttype not exist\n";
	}
}
// add//
string menoAdd() {
	int x = 0;

	system("cls");
	std::cout << "\n\t\t1)->add province ";
	std::cout << "\n\t\t2)->add county ";
	std::cout << "\n\t\t3)->add district ";
	std::cout << "\n\t\t4)->add city ";
	std::cout << "\n\t\t5)->add rural district ";
	std::cout << "\n\t\t6)->add vilage ";
	std::cout << "\n\t\t7)->Exit ";
	std::cout << "\n\n\t\twhich one?\t";
	cin >> x;
	while (true) {
		switch (x)
		{
		case 1:
			return "{Province";
		case 2:
			return "[County";
		case 3:
			return "<District";
		case 4:
			return "**City";
		case 5:
			return "**Rural District";
		case 6:
			return "#Village";

		case 7:
			break;
		}
	}
}
node* findNode(node* f, string x, bool& flag)
{
	node* r = NULL;
	if (!f)
		return NULL;
	if ((f->getcity() == ' ' + x) || (f->getcity() == x))
	{
		flag = true;
		return f;
	}
	if (!flag)
		r = findNode(f->getDLink(), x, flag);
	if (!flag)
		r = findNode(f->getNext(), x, flag);
	return r;
}
void printback(node* first, int level) {
	if (first == NULL)
		return;
	if (first->getType() == level)
		std::cout << "\n\t\t\t" << first->getcity() << first->getnumcount() << "\n\n";
	printback(first->getDLink(), level);
	printback(first->getNext(), level);
}
node* addNode(node* first, node* n)
{
	if (n->gettitle() == "Province") {
		n->settNext(first);
		first = n;
		return first;
	}
	else {
		printback(first, n->getType() - 1);
		string city;
		std::cout << "\n\t\t\t Enter Node ADD: \t";
		cin >> city;
		bool flag = false;
		node* p = findNode(first, city, flag);
		if (p->getDLink()) {
			n->settNext(p->getDLink());
			p->setDLink(n);
		}
		else {
			p->setDLink(n);
		}
		p->setnumcount(p->getnumcount() + n->getnumcount());
		n->settype(n->getType());
		std::cout << "\n\n\win\n";
		return first;
	}
}
void ADD(node* f) {
	string x = menoAdd();
	int ch = typeLevele(x);
	string city;
	string cunt;
	system("cls");
	//printback(f, ch - 1);
	std::cout << "\n\n";
	std::cout << "\t\tEnter Name Of Node :";
	cin >> city;
	bool flag = false;
	bool exist = findNode(f, city, flag);

	if (exist) {
		std::cout << "\n\n";
		std::cout << "\t\t\texist\n";
		system("pause");
	}
	else {
		std::cout << "\n\n";
		std::cout << "\t\tenter population of node :";
		cin >> cunt;
		string txt = x + ":" + city + "\t Population->" + cunt;
		system("cls");
		node* n = new node(txt);
		node* a = addNode(f, n);
		print_console(a);
		saveFile(a);
		system("pause");
		return;
	}


}
// add//
node* deleteAll(node* f) {
	if (!f) {
		return NULL;
	}
	deleteAll(f->getDLink());
	deleteAll(f->getNext());
	delete f;
	return NULL;
}
node* nextFind(node* f, node*& n, bool& flag) {
	node* p = NULL;
	if (!f)
		return NULL;
	if (f == n) {
		flag = true;

		p = n->getNext();
	}
	if (!flag && f->getDLink())
		p = nextFind(f->getDLink(), n, flag);
	if (!flag && f->getNext())
		p = nextFind(f->getNext(), n, flag);

	return p;
}
node* findparent(node* f, node*& n, bool& flag) {
	node* p = NULL;
	if (!f)
		return NULL;
	if (n->getType() == 0) {
		return NULL;
	}
	if (f == n) {
		flag = true;
	}
	if (!flag && f->getDLink()) {

		p = findparent(f->getDLink(), n, flag);
	}
	if (!flag && f->getNext())
		p = findparent(f->getNext(), n, flag);
	if (n && flag == true && (f->getType() < n->getType())) {

		n = NULL;
		p = f;
	}
	return p;
}
int meuoDEl() {
	system("cls");
	std::cout << "\t\t\t1.)All \n\n" << endl;
	std::cout << "\t\t\t2.)Province \n\n" << endl;
	std::cout << "\t\t\t3.)County \n\n" << endl;
	std::cout << "\t\t\t4.)District \n\n" << endl;
	std::cout << "\t\t\t5.)City \n\n" << endl;
	std::cout << "\t\t\t6.)Rural District \n\n" << endl;
	std::cout << "\t\t\t7.)Village \n\n" << endl;
	std::cout << "\t\t\t8.)exite \n\n" << endl;
	int x;
	cout << "\t\t\t:";
	cin >> x;
	return x;
}
node* DeleteFull(node* f) {
	if (!f)
		return NULL;
	DeleteFull(f->getDLink());
	DeleteFull(f->getNext());
	delete f;
	return NULL;
}
node* findback(node* f, node* n)
{
	node* current = f;
	node* g = NULL;
	while (current != NULL) {
		if (current->getNext() == n || current->getDLink() == n)
			return current;
		else if (current->getDLink()) {
			g = findback(current->getDLink(), n);
			if (g != NULL)
				return g;
		}
		current = current->getNext();
	}
	return NULL;
}
node* delNode(node* k, node*& r) {
	if (!k) {
		return NULL;
	}
	bool flag = false;
	node* tmp = r;
	node* back = findback(k, r);
	node* next = nextFind(k, r, flag);
	flag = false;
	node* parent = findparent(k, r, flag);
	if (parent) {
		if (back == parent) {
			parent->setDLink(tmp->getNext());
			tmp->settNext(NULL);
		}
		else {
			if (tmp->getNext() == NULL)
				back->settNext(NULL);
			else {
				back->settNext(tmp->getNext());
				tmp->settNext(NULL);
			}
		}
		parent->setnumcount(parent->getnumcount() - tmp->getnumcount());
		if (tmp->gettitle() == "Rural District")
			parent->setnumcount2(parent->getnumcount2() - 1);
		else
			parent->setnumcount2(parent->getnumcount2() - 1);

	}
	else {
		back->settNext(r->getNext());
		r->settNext(NULL);
	}
	DeleteFull(r);
	printcounterynodeback(k);
}
///delete
node* last_next(node* first) {
	if (first == NULL)
	{
		return NULL;
	}
	node* q = first;
	while (q->getNext() != NULL)
	{
		q = q->getNext();
	}
	return q;
}

string splite_namecity(string L) {
	string s;
	if (L != "") {
		return L.substr(L.find(":") + 1, (L.find("\t") - (L.find(":") + 1)));
	}
	else {
		L = "";
		return L;
	}
}
string splite_type(string L) {

	if (L != "") {

		if (L[1] == '*') {
			return L.substr((L.find("*") + 2), (L.find(":") - 2));

		}
		return L.substr((L.find("*") + 2) || (L.find("{")) || (L.find("<")) or (L.find("#")) || (L.find("[")), (L.find(":") - 1));
	}
	else {
		L = "";
		return L;
	}
}
int Tabcounter(string S)
{
	int x = -1;
	if (S.find("Rural District") != string::npos) {
		x = 3;
	}
	else if (S.find("Province") != string::npos) {
		x = 0;
	}
	else if (S.find("County") != string::npos) {
		x = 1;
	}
	else  if (S.find("District") != string::npos) {
		x = 2;
	}
	else  if (S.find("City") != string::npos) {
		x = 3;
	}
	else  if (S.find("Village") != string::npos) {
		x = 4;
	}
	return x;
}
string splitePop(string L) {
	if (L != "") {

		return "Population";
	}
	else
	{
		return L;
	}
}
string splitpop2(string L) {
	return L.substr(L.find("->") + 2, (L.find("\t") - 8));
}
string splitecuntpop(string L) {
	if (L != "") {
		int pos;
		string d = "\t";
		string token;
		int x = 0;
		string H = L;
		string numbers;
		while ((pos = L.find(d)) != std::string::npos) {
			token = L.substr(0, pos);
			L.erase(0, pos + d.length());
			x++;
		}
		if ((L.find("Population") != string::npos) && (x == 1)) {
			for (char c : L) {
				if (isdigit(c)) {
					numbers += c;
				}
			}
			return  numbers;
		}
		for (char c : token) {
			if (isdigit(c)) {
				numbers += c;
			}
		}
		return  numbers;

	}
	else
	{
		return  L;
	}
}
string SpliteNumberofCounty(string L) {//NumberofCounty -> 16}
	if (L != "") {
		int pos, x = 0;
		string d = "\t";
		string token, H;
		H = L;
		while ((pos = L.find(d)) != std::string::npos) {
			token = L.substr(0, pos);
			L.erase(0, pos + d.length());
			x++;
		}
		if (x == 1) {
			return "0";
		}
		return  L.substr(0, L.find('->') - 1);
	}
	else
	{
		return  L;
	}
}
string splitecunter2(string L) {
	string numbers;
	if (L != "") {
		int pos;
		string d = "\t";
		string token;
		int x = 0;
		while ((pos = L.find(d)) != std::string::npos) {
			token = L.substr(0, pos);
			if ((L.find("Numberof") != string::npos) && (x == 2)) {
				for (char c : token) {
					if (std::isdigit(c)) {
						numbers += c;
					}
				}
				return numbers;
			}
			x++;
			L.erase(0, pos + d.length());
		}
		if (x == 1) {
			return "0";
		}
		for (char c : L) {
			if (std::isdigit(c)) {
				numbers += c;
			}
		}
		return numbers;
		return L.substr(L.find("->") + 2, (L.length() - L.find("->") - 4));
	}
	else
	{
		L = "";
		return  L;
	}
}
int SpliteNumberofRuralDistrict(string L) {
	int H = 0;
	if (L != "") {
		int pos;
		string d = "\t";
		string token;
		int x = 0;
		while ((pos = L.find(d)) != std::string::npos) {
			token = L.substr(0, pos);
			L.erase(0, pos + d.length());
			x++;
			if (x == 3) {

				return stoi(L.substr(L.find("->") + 2, (L.length() - L.find("->") - 4)));
			}
		}
		return H;
	}
	else
	{
		return  H;
	}
}
/* print all list*/
///show symbol
string symbolF(string x) {
	if (x.find("Province") != string::npos) {
		return "{";
	}
	else if (x.find("County") != string::npos) {

		return "[";
	}
	else if (x.find("District") != string::npos) {
		return "<";
	}
	else if ((x.find("City") != string::npos) || (x.find("Rural District") != string::npos)) {

		return "**";
	}
	else if (x.find("Village") != string::npos) {
		return "#";
	}
	else {
		std::cout << "symbol not exite\n";

	}
}
string symbolL(string x) {
	if (x.find("Province") != string::npos) {
		return "}";
	}
	else if (x.find("County") != string::npos) {

		return "]";
	}
	else if (x.find("District") != string::npos) {
		return ">";
	}
	else if (x.find("City") != string::npos) {

		return "**";
	}
	else if (x.find("Rural District") != string::npos) {
		return "**";
	}
	else if (x.find("Village") != string::npos) {
		return "#";
	}
	else {
		std::cout << "symbol not exite\n";

	}
}
void print_console(node* r) {
	if (r == NULL)
		return;
	else {
		std::cout << "\t" << symbolF(r->gettitle()) + r->gettitle() << ":" << r->getcity() << "\t" << r->getpop() << ":" << r->getnumcount() << "\t" << "numberof" << ":" << r->getnumcount2() << symbolL(r->gettitle()) << endl;
		print_console(r->getDLink());
		print_console(r->getNext());
	}
}
// print  name khozesstan
node* nodecountery(node* f, string x) {


	if (!f) {
		return f;
	}
	if (f->getcity() == x) {
		return f;
	}
	f = nodecountery(f->getNext(), x);
	return f;
}
void printcountery(node* f) {
	if (f == NULL) {
		return;
	}
	std::cout << f->gettitle() << ":" << f->getcity() << endl;
	printcountery(f->getNext());
	printcountery(f->getDLink());
}
string NameCuntery(node* f) {
	node* temp = f;
	node* cu = f;
	std::cout << "\n\n\n";
	int x, i = 1;

	while (temp) {
		std::cout << "\n\n";
		std::cout << "\t\t\t" << i << ")" << temp->getcity() << "\n\n";
		i++;
		temp = temp->getNext();
	}
	if (!cu) {
		return " ";

	}
	std::cout << "\t\t\tchoice in city\t";
	cin >> x;
	string txt;
	i = 1;
	while (cu) {
		if (x == i) {
			txt = cu->getcity();
			break;
		}
		i++;
		cu = cu->getNext();
	}
	if (x == 0) {
		return "s";
	}
	return txt;
}
// print  name khozesstan

node* nodePTry(node* f, string x) {
	if (!f) {
		return f;
	}
	if (f->getcity() == x) {
		return f;
	}
	f = nodecountery(f->getNext(), x);
	return f;
}
// print dezful;
void printcounterynodeback(node* f) {
	if (f == NULL)
		return;
	else {
		std::cout << "\t" << f->getcity() << "//";
		printcounterynodeback(f->getNext());
	}
}
void printcounterynode(node* f) {
	f = nodecountery(f, NameCuntery(f));
	f = f->getDLink();
	printcounterynodeback(f);
	if (!f) {
		system("cls");
		std::cout << "\n\n";

		std::cout << "\t\t\t" << "[31m" << "NOT SRAGE\n" << "[0m";
	}
	system("pause");
}
// print dezful;

void PRcity(node* f) {
	string x, y;
	node* r = NULL;
	node* c = NULL;
	x = NameCuntery(f);
	while (f)
	{
		if (f->getcity() == x) {
			y = NameCuntery(f->getDLink());
			if (y == " ") {
				std::cout << "\t\t\t" << "[31m" << "NOT City\n" << "[0m";
				system("pause");
				return;
			}
			if (y == "s") {
				return;
			}
			c = nodePTry(f->getDLink(), y);
			system("cls");
			printcountery(c->getDLink());
		}
		f = f->getNext();
	}
}
// /// /// 
void clearFill() {

	ofstream f("new.txt");
	f.close();
}
void write_in_file(node* r) {
	ofstream f("new.txt", ios::app);
	if (r)
		f << symbolF(r->gettitle()) + r->gettitle() << ":" << r->getcity() << '\t' << r->getpop() << "->" << r->getnumcount() << '\t' << "Numberof" << "->" << r->getnumcount2() << symbolL(r->gettitle()) << endl;
	f.close();
	if (r->getDLink())
		write_in_file(r->getDLink());
	if (r->getNext())
		write_in_file(r->getNext());
}
void saveFile(node* f) {
	clearFill();
	if (!f) {
		return;
	}
	write_in_file(f);
}
// //
int menoExist() {
	std::cout << "\t\t1)EXIST or NOT EXIST\n\n";
	std::cout << "\t\t2)Route\n";
	int x;
	cout << "\n\n";
	cout << "\t\t\t:";
	cin >> x;
	return x;
}
void existeNode(node* r, string x) {

	bool fa = false;
	node* ex = findNode(r, x, fa);
	string res = ex ? "EXIST" : "NOT EXIST";
	std::cout << "\t\t\t" << res;
	cout << "\n\n\t\t\t";
	system("pause");
}
void printRoute(node* p, node* se) {
	if (se) {
		bool flag = false;
		node* s = se;
		printRoute(p, findparent(p, s, flag));
		std::cout << se->getType() << " : " << se->getcity() << endl;
	}
}
void routeNode(node* r, string x) {
	bool fg = false;
	node* self = findNode(r, x, fg);
	printRoute(r, self);
}
//////
node* movenode(node* k, node* r) {
	if (!k) {
		return NULL;
	}
	node* se = r;
	bool flag = false;
	node* back = findback(k, r);
	node* next = nextFind(k, r, flag);
	flag = false;
	node* parent = findparent(k, r, flag);

	if (parent) {
		if (back == parent) {
			parent->setDLink(se->getNext());
			se->settNext(NULL);
		}
		else {
			if (se->getNext() == NULL)
				back->settNext(NULL);
			else {
				back->settNext(se->getNext());
				se->settNext(NULL);
			}
		}
	}
	else {
		back->settNext(se->getNext());
		se->settNext(NULL);
	}
	return se;

}
//
node* move(node* r, node*& p) {
	node* tmp = movenode(r, p);
	std::cout << "wich node use\t";
	string name;
	cin >> name;
	bool flag = false;
	node* fnode = findNode(r, name, flag);
	if (fnode->getDLink()) {
		node* s = fnode->getDLink();
		fnode->setDLink(tmp);
		tmp->setDLink(s->getDLink());
	}
	else {
		fnode->setDLink(tmp);
	}
	return fnode;
}
node* change(node* p, node*& r) {
	node* h = r;
	bool flag = false;
	node* parent = findparent(p, h, flag);
	node* s = movenode(p, r);
	if (parent) {

		node* tpar = parent->getNext();
		s->settitle(parent->gettitle());
		s->settype(parent->getType());
		parent->settNext(s);
		s->settNext(tpar);
	}
	else {
		std::cout << "self root";
		system("puase");
	}
	return p;
}
node* stageMove(node* p, node* key) {
	node* h = key;
	bool fl = false;

	node* f = findparent(p, key, fl);
	node* s = movenode(p, h);
	printback(p, 0);
	string x;
	std::cout << "name stage:\t";
	cin >> x;
	fl = false;
	node* tmp = findNode(p, x, fl);
	f->setnumcount(f->getnumcount() - s->getnumcount());

	tmp->setDLink(s);
	tmp->setnumcount(tmp->getnumcount() + s->getnumcount());
	return p;
}
/////
int menoMove() {
	std::cout << "1.)move parentself \t\t" << endl;
	std::cout << "2.)move stage some satge \t\t" << endl;

	int x;
	cin >> x;
	return x;
}

node* Edite(node* r, node* key) {

	node* H = key;
	bool flag = false;
	int backcunt = H->getnumcount();
	node* parent = findparent(r, H, flag);
	string newName;
	int newcunt;
	cout << "\t\t\tnew name:";
	cin >> newName;
	cout << "\t\t\t newCunt:";
	cin >> newcunt;
	key->setcity(newName);
	key->setnumcount(newcunt);
	parent->setnumcount(parent->getnumcount() - backcunt + key->getnumcount());

	return r;
}
node* parentvilge(node* first, int level) {
	node* f;
	if (first == NULL)
		return NULL;
	if (first->getType() == level) {
		while (first) {
			if (!first->getDLink()) {
				first = first->getNext();

			}
			else if (first->getDLink()->getType() == 4) {
				node* f = first;
			}
		}
	}
	f=parentvilge(first->getDLink(), level);
	f=parentvilge(first->getNext(), level);
	return f;
}


node* por(node* f, bool& flag) {
	node*j = parentvilge(f, 3);

	return f;
}



void choceMeno(node* r) {
	int ch;
	node* k = NULL;
	string name;
	while (true)
	{
		system("cls");
		ch = menoRead();
		switch (ch)
		{
		case 1: {

			ADD(r);

			break;
		}
		case 2: {
			int ch;
			ch = menoPrint();
			system("cls");
			switch (ch)
			{
			case 1: {
				printcounterynode(r); break;
			}
			case 2: {
				PRcity(r); break;
			}
			case 3: {
				print_console(r);
				system("pause");
				break;
			}
			default:
				std::cout << "choice 1-3 for print\t"; break;
			}
			break;
		}
		case 3: {
			ch = meuoDEl();
			switch (ch)
			{
			case 1: {
				k = deleteAll(r);
				saveFile(k);
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				std::cout << "privice\n";
				printback(r, 0);
				cout << "\t\t\tname:";
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 3: {
				system("cls");
				std::cout << "countery\n";
				printback(r, 1);
				cout << "\t\t\tname:";
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 4: {
				system("cls");
				std::cout << "district\n";
				cout << "\t\t\tname:";
				printback(r, 2);
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 5: {
				system("cls");
				std::cout << "city\n";
				printback(r, 3);
				cout << "\t\t\tname:";
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 6: {
				system("cls");
				std::cout << "Rural district \n";
				printback(r, 3);
				cout << "\t\t\tname:";
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 7: {
				system("cls");
				std::cout << "vilage\n";
				printback(r, 4);
				cout << "\t\t\tname:";
				cin >> name;
				bool flag = false;
				k = findNode(r, name, flag);
				delNode(r, k);
				saveFile(r);
				break;
			}
			case 8: {
				break; }
			default:
				std::cout << "choice 1-8 for delet\t"; break;
				break;
			}
			break;
		}
		case 4: {
			system("cls");
			cout << "\n\n\n\n";
			ch = menoExist();
			std::cout << "\t\t\t\t\t\t\t\t name city:\t";
			cin >> name;
			switch (ch)
			{
			case 1: {
				existeNode(r, name);
				break;
			}
			case 2: {
				routeNode(r, name);
				break;
			}
			default: {
				std::cout << "choice 1-2 for print\t"; break;
				break;
			}
			}
			break;
		}
		case 5: {
			bool flag = false;
			int x;
			std::cout << "type:\t";
			cin >> x;
			printback(r, x);
			std::cout << "which u node:\t";
			cin >> name;
			k = findNode(r, name, flag);
			move(r, k);

			saveFile(r);
			break;
		}
		case 6: {
			int x;
			std::cout << "type:\t";
			cin >> x;
			printback(r, x);
			string name;
			std::cout << "which u node:\t";
			cin >> name;
			bool flag = false;
			k = findNode(r, name, flag);
			ch = menoMove();
			switch (ch)
			{
			case 1: {
				change(r, k);
				saveFile(r);
				break;
			}
			case 2: {
				stageMove(r, k);
				saveFile(r);
			}
			default:
				break;
			}
		}
		case 7: {
			return;
		}
		case 8: {
			int x;
			std::cout << "type:\t";
			cin >> x;
			printback(r, x);
			string name;
			std::cout << "which u node:\t";
			cin >> name;
			bool flag = false;
			k = findNode(r, name, flag);
			Edite(r, k);
			saveFile(r);
		}

		case 9: {

			bool flag = false;
			por(r, flag);


		}
		}
	}
}


int main() {
	node* r = NULL;
	node* s = NULL;
	r = readFile();
	s = AddDowList(r, r->getDLink());
	string t;
	node* e = NULL;
	//print_console(r);
	choceMeno(r);
}