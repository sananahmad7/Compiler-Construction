#pragma once

#include "token.h"


sanan_tokenization nkt;

sanan_tokenization Lexical();

typedef enum { opk, constk, idk } nodekind;

struct treenode
{
	nodekind kind;
	int value;
	std::string name;
	Tokentype opr;
	treenode* leftchild;
	treenode* rightchild;
};



treenode* Xp_sanan();
treenode* Yp_sanan();



treenode* factor();

treenode* factor() {
	treenode* t = NULL;
	nkt = getToken();
	switch (nkt.token) {
	case DIGIT:
		t = new treenode();
		t->kind = constk;
		t->value = nkt.value;
		t->name = nkt.name;
		t->leftchild = NULL;
		t->rightchild = NULL;
		return(t);
		break;
	case IDENTIFIER:
		t = new treenode();
		t->kind = idk;
		t->name = nkt.name;
		t->leftchild = NULL;
		t->rightchild = NULL;
		return t;
		break;
	case LEFTBRACKET:
		t = Xp_sanan();
		nkt = getToken();
		if (nkt.token == RIGHTBRACKET) {
			return t;
		}
		break;
	}
}











treenode* Yp_sanan() {

	treenode* t = NULL;
	treenode* p = NULL;
	int flag2 = 0;
	do {

		t = factor();
		if (flag2) {
			p->rightchild = t;
			flag2 = 0;
			t = p;
		}
		nkt = getToken();
		if (nkt.token == MULTIPLY || nkt.token == DIVID)
		{
			p = new treenode();
			p->kind = opk;
			p->opr = nkt.token;
			p->leftchild = t;
			flag2 = 1;
		}

	} while (nkt.token == MULTIPLY || nkt.token == DIVID || nkt.token == REMAINDER);
	ungetToken();
	return (t);
}

treenode* Xp_sanan() {

	treenode* t = NULL;
	treenode* p = NULL;
	int flag2 = 0;
	do {
		t = Yp_sanan();
		if (flag2) {
			p->rightchild = t;
			flag2 = 0;
			t = p;
		}
		nkt = getToken();
		if (nkt.token == ADD || nkt.token == MINUS)
		{
			p = new treenode();
			p->kind = opk;
			p->opr = nkt.token;
			p->leftchild = t;
			flag2 = 1;
		}
	} while (nkt.token == ADD || nkt.token == MINUS);
	ungetToken();
	return (t);
}





string displayTree(treenode* node)
{
	string value;
	if (node == NULL)
	{
		return value;
	}
	value += "\nNODE: ";
	if (node->kind == constk)
	{
		value += "CONSTANT ";
		value += "\nVALUE: ";
		value += node->value;
	}
	else if (node->kind == idk)
	{
		value += node->name;
	}
	else if (node->kind == opk)
	{
		if (node->opr == ADD)
		{
			value += "+";
		}
		else if (node->opr == MINUS)
		{
			value += "-";
		}
		else if (node->opr == MULTIPLY)
		{
			value += "*";
		}
		else if (node->opr == DIVID)
		{
			value += "/";
		}
	}

	value += "\nLEFT CHILD: ";
	if (node->leftchild != nullptr)
	{
		value += node->leftchild->name;
	}
	else
		value += "NULL";
	value += "\nRIGHT CHILD : ";
	if (node->rightchild != nullptr)
	{
		value += node->rightchild->name;
		value += "\n";
	}
	else
		value += "NULL\n";

	value += displayTree(node->leftchild);
	value += displayTree(node->rightchild);

	return value;
}

