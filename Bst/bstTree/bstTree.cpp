#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
int SpliteY(string L);
int SpliteX(string L);
class node
{
private:
	int x;
	int y;
	int type;
	node* left;
	node* rghit;
	node* parent;
public:
	node() {
		this->x = 0;
		this->y = 0;
	}
	node(string L) {
		int x, y, t;
		x = SpliteX(L);
		y = SpliteY(L);
		this->setX(x);
		this->setY(y);
		this->setLeft(NULL);
		this->setRghit(NULL);
		this->setparent(NULL);
	}
	void setX(int z) { x = z; }
	void setY(int z) { y = z; }
	void settype(int z) { type = z; }
	void setLeft(node* L) { this->left = L; }
	void setRghit(node* R) { this->rghit = R; }
	void setparent(node* P) { this->parent = P; }
	int getX() { return this->x; }
	int getY() { return this->y; }
	int gettype() { return this->type; }
	node* getLeft() { return this->left; }
	node* getRghit() { return this->rghit; }
	node* getParent() { return this->parent; }
};
class point {
private:
	node* first;
public:
	point(node* f) {
		setfirst(f);
	}
	void setfirst(node* f) {
		this->first = f;
	}
	node* getfirst() { return this->first; }
};
node* createNode(node* first, node* current, bool flg, node* D) {
	while (true) {
		if (flg) {
			current = first;
		}
		if (current->gettype() % 2 == 0) {
			if (D->getX() < current->getX()) {
				if (current->getLeft() == NULL) {
					D->settype(current->gettype() + 1);
					D->setparent(current);
					current->setLeft(D);
					flg = true;
					break;
				}
				else {
					current = current->getLeft();
					flg = false;
				}
			}
			else {
				if (current->getRghit() == NULL) {
					D->settype(current->gettype() + 1);
					D->setparent(current);
					current->setRghit(D);
					flg = true;
					break;
				}
				else {
					current = current->getRghit(); flg = false;
				}
			}
		}
		if (current->gettype() % 2 == 1) {
			if (D->getY() < current->getY()) {
				if (current->getLeft() == NULL) {
					D->settype(current->gettype() + 1);
					D->setparent(current);
					current->setLeft(D);
					flg = true;
					break;
				}
				else {
					current = current->getLeft();
					flg = false;
				}
			}
			else {
				if (current->getRghit() == NULL) {
					D->settype(current->gettype() + 1);
					D->setparent(current);
					current->setRghit(D);
					flg = true;
					break;
				}
				else {
					current = current->getRghit(); flg = false;
				}
			}
		}
	}
	return first;
}
node* readFile() {
	ifstream txt("data.txt");
	string res;
	node* first = NULL;
	node* current = NULL;
	bool flg = false;
	while (getline(txt, res, '\n')) {
		node* D = new node(res);
		if (!first) {
			first = D;
			current = first;
		}
		else {
			node* f = createNode(first, current, flg, D);
		}
	}
	txt.close();
	return first;
}
void clearFill() {
	ofstream f("data.txt");
	f.close();
}
void write_in_file(node* r) {
	ofstream f("data.txt", ios::app);
	if (r)
		f << r->getX() << "\t" << r->getY() << endl;
	f.close();
	if (r->getLeft())
		write_in_file(r->getLeft());
	if (r->getRghit())
		write_in_file(r->getRghit());
}
void saveFile(node* f) {
	clearFill();
	if (!f) {
		return;
	}
	write_in_file(f);
}
node* searchBst(node* E, node* n, bool& flg) {
	node* r = E;
	if (!r) {
		return E;
	}
	if ((r->getX() == n->getX() && (r->getY() == n->getY()))) {
		flg = true;
		return r;
	}
	else
	{
		if (!flg) {
			if (!r) {
				r = E;
			}
			r = searchBst(r->getLeft(), n, flg);
		}
		if (!flg) {
			if (!r) {
				r = E;
			}
			r = searchBst(r->getRghit(), n, flg);
		}
	}
	return r;
}
void ADD(node* r, node* tree, bool& fg) {
	if (r == NULL) {
		return;
	}
	else {
		if (r->getRghit() == NULL) {
			fg = false;
		}
		if (r->gettype() % 2 == 0) {
			if (r->getX() > tree->getX()) {
				ADD(r->getLeft(), tree, fg);
				if (!fg) {
					r->setLeft(tree);
					fg = true;
				}
			}
			else {
				ADD(r->getRghit(), tree, fg);
				if (!fg) {
					r->setRghit(tree);
					fg = true;
				}
			}
		}
		else if (r->gettype() % 2 == 1) {
			if (r->getY() > tree->getY()) {
				ADD(r->getLeft(), tree, fg);
				if (!fg) {
					r->setLeft(tree);
					fg = true;
				}
			}
			else {
				ADD(r->getRghit(), tree, fg);
				if (!fg) {
					r->setRghit(tree);
					fg = true;
				}
			}
		}
	}
}
node* cheek() {
	string x, y;
	cout << "\n\n";
	cout << "\t\t\tx:"; cin >> x;
	cout << "\t\t\ty:";	cin >> y;
	string res = x + '\t' + y;
	node* Tree = new node(res);
	return Tree;
}
void addTree(node* r) {
	node* Tree = cheek();
	bool flg = false;
	bool D = searchBst(r, Tree, flg);
	if ((D)) {
		cout << "TEkkraryyyyyyy";
		system("pause");
	}
	else {
		ADD(r, Tree, flg);
		saveFile(r);
	}
}
int SpliteX(string L) {
	if (L != " ") {
		return stoi(L.substr(0, '\t'));
	}
	else {
		return 0;
	}
}
int SpliteY(string L) {
	if (L != " ") {
		return stoi(L.substr(L.find('\t'), L.length() - L.find('\t')));
	}
	else {
		return 0;
	}
}
#define count 10
void printTree(node* r, int space)
{
	if (r == NULL)
		return;
	else {
		space += count;
		printTree(r->getRghit(), space);
		for (int i = count; i < space; i++)
			cout << " ";
		cout << +"(" << r->getX() << "," << r->getY() << ")" << "\n";
		printTree(r->getLeft(), space);
	}
}
void print(node* r) {
	cout << "( " << r->getX() << "," << r->getY() << " )";
}
void path(node* r) {
	if (r == NULL) {
		return;
	}
	path(r->getParent());
	cout << "\n\t\t\t";
	cout << " --> ";
	print(r);
	cout << "\n\n";

}
void changeType(node* d, node* key) {
	if (d == NULL) {
		return;
	}
	if (d->gettype() % 2 == 0) {

	}
}
void deleteNode(node* r, node* n) {
	bool flg = false;
	node* d = searchBst(r, n, flg);
	node* LeftT, * RhiteT;
	if (d) {
		if ((d->getX() == n->getX()) && (d->getY() == n->getY())) {
			LeftT = d->getLeft();
			RhiteT = d->getRghit();
			if (d->getParent()->getLeft() == d) {
				d->getParent()->setLeft(NULL);
			}
			else  if (d->getParent()->getRghit() == d) {

				d->getParent()->setRghit(NULL);
			}
			//d->setparent(NULL);
			if (!d->getLeft() && !d->getRghit()) {
				return;
			}
			if (d->gettype() % 2 == 0) {
				flg = false;
				if (!RhiteT) {
					ADD(r, LeftT, flg);
					LeftT->setparent(d->getParent());
				}
				if (!LeftT) {
					ADD(r, RhiteT, flg);
					RhiteT->setparent(d->getParent());
				}
				else {
					if (RhiteT->getX() > LeftT->getX()) {
						LeftT->gettype() - 1;
						LeftT->setparent(d->getParent());
						ADD(r, LeftT, flg);
						flg = false;
						ADD(r, RhiteT, flg);
					}
					else if (RhiteT->getX() < LeftT->getX()) {
						RhiteT->settype(RhiteT->gettype() - 1);
						RhiteT->setparent(d->getParent());
						ADD(r, RhiteT, flg);
						flg = false;
						ADD(r, LeftT, flg);
					}
				}
			}
			else if (d->gettype() % 2 == 1)
			{
				flg = false;
				if (!RhiteT) {
					ADD(r, LeftT, flg);
					LeftT->setparent(d->getParent());
				}
				if (!LeftT) {
					ADD(r, RhiteT, flg);
					RhiteT->setparent(d->getParent());
				}
				else {
					if (RhiteT->getX() > LeftT->getX()) {
						LeftT->gettype() - 1;
						LeftT->setparent(d->getParent());
						ADD(r, LeftT, flg);
						flg = false;
						ADD(r, RhiteT, flg);
					}
					else if (RhiteT->getX() < LeftT->getX()) {
						RhiteT->settype(RhiteT->gettype() - 1);
						RhiteT->setparent(d->getParent());
						ADD(r, RhiteT, flg);
						flg = false;
						ADD(r, LeftT, flg);
					}
				}
			}
		}
	}
	else {
		cout << "\t\t\t not point\n\n";
		system("pause");
		return;
	}

	delete(d);
}
void grafic(node* r) {
	if (r == NULL) {
		return;
	}
	node* prnt = r->getParent();
	if (r->gettype() % 2 == 0) {
		if (!r->getParent()) {
			line(r->getX() * 12, 10, r->getX() * 12, 445);
		}
		else {
			node* prnt2 = prnt->getParent();
			node* prnt3 = NULL;
			if (prnt2)
				prnt3 = prnt2->getParent();
			if (prnt3) {
				if (r == prnt->getLeft()) {
					line(r->getX() * 12, 445 - prnt->getY() * 12, r->getX() * 12, 445 - prnt3->getY()*12);
				}
				else {
					line(r->getX() * 12, 445 - prnt->getY() * 12, r->getX() * 12, 445 - prnt3->getY()*12);
				}
			}
			else {
				if (r == prnt->getLeft()) {
					line(r->getX() * 12, 445 - prnt->getY() * 12, r->getX() * 12, 445);
				}
				else {
					line(r->getX() * 12, 445 - prnt->getY() * 12, r->getX() * 12, 10);
				}
			}

		}
	}
	else {
		node* prnt2 = prnt->getParent();
		node* prnt3 = NULL;
		if (prnt2)
			prnt3 = prnt2->getParent();
		if (prnt3)
			if (r == prnt->getLeft()) {
				line(prnt3->getX() * 12, 445 - r->getY() * 12, prnt->getX() * 12, 445 - r->getY() * 12);
			}
			else {
				line(prnt->getX() * 12, 445 - r->getY() * 12, 445, 445 - r->getY() * 12);
			}

		else {
			if (r == prnt->getLeft()) {
				line(10, 445 - r->getY() * 12, prnt->getX() * 12, 445 - r->getY() * 12);
			}
			else {
				line(prnt->getX() * 12, 445 - r->getY() * 12, 445, 445 - r->getY() * 12);
			}
		}
	}
	grafic(r->getLeft());
	grafic(r->getRghit());
}
void show(node* r) {
	initwindow(450, 450);
	grafic(r);
	getch();
	closegraph();

}
int menoRead() {
	std::cout << "\n\n";
	std::cout << "\t\t1.)add \t\t\n" << endl;
	std::cout << "\t\t2.)Delet \t\t\n" << endl;
	std::cout << "\t\t3.)Print \t\t\n" << endl;
	std::cout << "\t\t4.)path \t\t\n" << endl;
	std::cout << "\t\t5.)Grafic \t\t\n" << endl;
	std::cout << "\t\t6.)Exit \t\t\n" << endl;
	int x;
	std::cout << "\n\n";
	std::cout << "\t\t>>";
	cin >> x;
	return x;
}
int menosearch() {
	std::cout << "\n\n";
	std::cout << "\t\t1.)cheack And path \t\t\n" << endl;
	std::cout << "\t\t2.)exite \t\t\n" << endl;
	int x;
	std::cout << "\n\n";
	std::cout << "\t\t>>";
	cin >> x;
	return x;
}
void choiceMeno(node* r) {
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
			addTree(r); break;
		}
		case 2: {
			node* Tree = cheek();
			deleteNode(r, Tree);
			saveFile(r);
			break;
		}
		case 3: {
			ch = menosearch();
				node* Tree = cheek();
				system("cls");
				bool flg = false;
				bool D = searchBst(r, Tree, flg);
				flg = false;
				node* Dd = searchBst(r, Tree, flg);
			switch (ch) {
					case 1: {
				if (D) {
					path(Dd);
					system("pause");
					break;
				}
				else {
					cout << "\t\t\tnis\n\n";
					system("pause");
					break;
				}
				break;
			}

			case 2: {
				if (D) {
					cout << "\t\t\tYES\n\n";
					system("pause");
				}

				else {
					cout << "n\n\n\n\t\t\t\tNOOO EXIET\n\n";

				}
			}
			}
				break;
		}
		case 4: {
			system("cls");
			printTree(r, 0);
			system("pause");
			break;
		}
		case 5: {
			show(r);
			break;
		}
		case 6:return;
		default:
			cout << "PLS NUM 1-6";			break;
		}
	}
}


int main() {
	node* r = NULL;
	r = readFile();
	choiceMeno(r);
}