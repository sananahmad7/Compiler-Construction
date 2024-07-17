#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream newfile;


void openFile() {
	newfile.open("file.txt");
}


// ENUMERATION
enum Tokentype {
    IF, ELSE,WHILE, EXIT, DO, FOR, INTEGER, MAIN, IDENTIFIER, MINUS, DIVID, RIGHTBRACKET, REMAINDER,
    LEFTBRACKET, LEFTCURLYBRACKET, RIGHTCURLYBRACKET, COMMENT, ADD, EQUAL, INCREMENT,
    DECREMENT, MULTIPLY, OR, ASSIGNMENT, SHIFTRIGHT, SHIFTLEFT, LESSTHAN, LESSOREQUAL, GREATER, GREATEROREQUAL, NOTEQUAL, LOGICALAND, NOT,
    PLUSEQUAL, MINUSEQUAL, SEMICOLON, COMMA, DIGIT, ENDF, SPACE, BEGIN, END,
};

struct sanan_tokenization {
    int value = 0;
    std::string name;
    Tokentype token;
}tok_name;


sanan_tokenization currentToken;






// Lexical token function
sanan_tokenization Lexical() {
	char a;
	while (newfile.get(a)) {
		if (newfile.eof()) {
			continue;
		}
		string str = "";
		if (a == ' ' || a == '\t' || a == '\n') {
			continue;
		}
		else if (a == '_' || isalpha(a)) {
			str = "";
			do {
				str += a;
				newfile.get(a);
			} while (isalnum(a));
			if (!newfile.eof()) {
				newfile.unget();
			}

			if (str == "if") {
				tok_name.name = "if";
				tok_name.token = IF;
				return tok_name;
			}
			else if (str == "else") {
				tok_name.name = "else";
				tok_name.token = ELSE;
				return tok_name;
			}
			else if (str == "while") {
				tok_name.name = "while";
				tok_name.token = WHILE;
				return tok_name;
			}
			else if (str == "BEGIN") {
				tok_name.name = "BEGIN";
				tok_name.token = BEGIN;
				return tok_name;
			}
			else if (str == "END") {
				tok_name.name = "END";
				tok_name.token = END;
				return tok_name;
			}
			else if (str == "exit") {
				tok_name.name = "EXIT";
				tok_name.token = EXIT;
				return tok_name;
			}
			else if (str == "do") {
				tok_name.name = "DO";
				tok_name.token = DO;
				return tok_name;
			}
			else if (str == "for") {
				tok_name.name = "FOR";
				tok_name.token = FOR;
				return tok_name;
			}
			else if (str == "int") {
				tok_name.name = "INT";
				tok_name.token = INTEGER;
				return tok_name;
			}
			else if (str == "main") {
				tok_name.name = "main";
				tok_name.token = MAIN;
				return tok_name;
			}
			else {
				tok_name.name = "IDENTIFIER";
				tok_name.token = IDENTIFIER;
				return tok_name;
			}
		}
		else if (isdigit(a)) {
			str = "";
			do {
				str += a;
				newfile.get(a);
			} while (isdigit(a));
			newfile.unget();
			tok_name.name = "DIGIT";
			tok_name.token = DIGIT;
			tok_name.value = stoi(str);
			return tok_name;
		}
		else if (a == '(') {
			tok_name.name = "LEFTBRACKET";
			tok_name.token = LEFTBRACKET;
			return tok_name;
		}
		else if (a == ')') {
			tok_name.name = "RIGHTBRACKET";
			tok_name.token = RIGHTBRACKET;
			return tok_name;
		}
		else if (a == '{') {
			tok_name.name = "LEFTCURLYBRACKET";
			tok_name.token = LEFTCURLYBRACKET;
			return tok_name;
		}
		else if (a == '}') {
			tok_name.name = "RIGHTCURLYBRACKET";
			tok_name.token = RIGHTCURLYBRACKET;
			return tok_name;
		}
		else if (a == '%') {
			tok_name.name = "REMAINDER";
			tok_name.token = REMAINDER;
			return tok_name;
		}
		else if (a == '=') {
			newfile.get(a);
			if (a == '=') {
				tok_name.name = "assignment";
				tok_name.token = ASSIGNMENT;
			}
			else {
				newfile.unget();
				tok_name.name = "EQUAL";
				tok_name.token = EQUAL;
			}
			return tok_name;
		}
		else if (a == '<') {
			newfile.get(a);
			if (a == '<') {
				tok_name.name = "shiftLeft";
				tok_name.token = SHIFTLEFT;
			}
			else if (a == '=') {
				tok_name.name = "lessEqual";
				tok_name.token = LESSOREQUAL;
			}
			else {
				newfile.unget();
				tok_name.name = "less";
				tok_name.token = LESSTHAN;
			}
			return tok_name;
		}
		else if (a == '&') {
			newfile.get(a);
			if (a == '&') {
				tok_name.name = "logicalAnd";
				tok_name.token = LOGICALAND;
				return tok_name;
			}
		}
		else if (a == '!') {
			newfile.get(a);
			if (a == '=') {
				tok_name.name = "notEqual";
				tok_name.token = NOTEQUAL;
			}
			else {
				newfile.unget();
				tok_name.name = "not";
				tok_name.token = NOT;
			}

			return tok_name;
		}
		else if (a == '>') {
			newfile.get(a);
			if (a == '>') {
				tok_name.name = "shiftRight";
				tok_name.token = SHIFTRIGHT;
			}
			else if (a == '=') {
				tok_name.name = "greaterEqual";
				tok_name.token = GREATEROREQUAL;
			}
			else {
				newfile.unget();
				tok_name.name = "greater";
				tok_name.token = GREATER;
			}
			return tok_name;
		}
		else if (a == '*') {
			tok_name.name = "MULTIPLY";
			tok_name.token = MULTIPLY;
			return tok_name;
		}
		else if (a == '+') {
			newfile.get(a);
			if (a == '+') {
				tok_name.name = "INCREMENT";
				tok_name.token = INCREMENT;
				return tok_name;
			}
			else if (a == '=') {
				tok_name.name = "PLUSEQUAL";
				tok_name.token = PLUSEQUAL;
				return tok_name;
			}
			else {
				newfile.unget();
				tok_name.name = "ADD";
				tok_name.token = ADD;
				return tok_name;
			}
		}
		else if (a == '-') {
			newfile.get(a);
			if (a == '-') {
				tok_name.name = "decrement";
				tok_name.token = DECREMENT;
				return tok_name;
			}
			else if (a == '=') {
				tok_name.name = "MINUSEQUAL";
				tok_name.token = MINUSEQUAL;
				return tok_name;
			}
			else {
				newfile.unget();
				tok_name.name = "MINUS";
				tok_name.token = MINUS;
				return tok_name;
			}
		}
		else if (a == ';') {
			tok_name.name = ';';
			tok_name.token = SEMICOLON;
			return tok_name;
		}
		else if (a == '/') {
			newfile.get(a);
			if (a == '/') {
				while (newfile.get(a))
				{
					if (a == '\n') {
						tok_name.name = "comment";
						tok_name.token = COMMENT;
						return tok_name;
					}
				}
			}
			else
			{
				newfile.unget();
				tok_name.name = "DIVID";
				tok_name.token = DIVID;
				return tok_name;
			}
		}
		else if (a == ',') {
			tok_name.name = "comma";
			tok_name.token = COMMA;
			return tok_name;
		}
		else if (a == '|') {
			newfile.get(a);
			if (a == '|') {
				tok_name.name = "or";
				tok_name.token = OR;
				return tok_name;
			}
		}
	}
	tok_name.name = "";
	tok_name.token = ENDF;
	return tok_name;
}












int flag = 0;

sanan_tokenization getToken() {
	if (!flag) {
		sanan_tokenization tokVal;
		tokVal = Lexical();
		currentToken = tokVal;
		return currentToken;
	}
	else {
		flag = 0;
		return currentToken;
	}


}

void ungetToken() {
	flag = 1;
}






