#pragma once

#include "token.h"



bool E_sanan();
bool T_sanan();
bool E_sanan();
bool U_sanan();
bool V_sanan();
bool W_sanan();
bool X_sanan();
bool Y_sanan();
bool Z_sanan();
bool statement_list();



bool Z_sanan() {

	nkt = getToken();
	if (nkt.token == DIGIT)
	{
		return true;
	}
	else if (nkt.token == IDENTIFIER)
	{
		return true;
	}
	else if (nkt.token == LEFTBRACKET)
	{
		if (E_sanan())
		{
			nkt = getToken();
			if (nkt.token == RIGHTBRACKET)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

bool Y_sanan() {

	do {
		if (Z_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == MULTIPLY || nkt.token == DIVID || nkt.token == REMAINDER);
	ungetToken();
	return true;
}

bool X_sanan() {

	do {
		if (Y_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == ADD || nkt.token == MINUS);
	ungetToken();
	return true;
}

bool W_sanan() {

	do {
		if (X_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == SHIFTLEFT || nkt.token == SHIFTRIGHT);
	ungetToken();
	return true;
}

bool V_sanan() {

	do {
		if (W_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == LESSTHAN || nkt.token == LESSOREQUAL || nkt.token == GREATER || nkt.token == GREATEROREQUAL);
	ungetToken();
	return true;
}

bool U_sanan() {

	do {
		if (V_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == ASSIGNMENT || nkt.token == NOTEQUAL);
	ungetToken();
	return true;
}

bool T_sanan() {

	do {
		if (U_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == LOGICALAND);
	ungetToken();
	return true;
}

bool E_sanan() {

	do {
		if (T_sanan()) {
			nkt = getToken();
		}
		else {
			return false;
		}

	} while (nkt.token == OR);
	ungetToken();
	return true;
}





bool assignment() {
	nkt = getToken();
	if (nkt.token == IDENTIFIER) {
		nkt = getToken();
		if (nkt.token == EQUAL || nkt.token == PLUSEQUAL || nkt.token == MINUSEQUAL || nkt.token == MINUS || nkt.token == ADD) {
			if (E_sanan()) {
				nkt = getToken();
				if (nkt.token == SEMICOLON) {
					return true;
				}

			}
		}
	}
	else if (nkt.token == IF) {
		nkt = getToken();
		if (nkt.token == LEFTBRACKET) {
			if (E_sanan()) {
				nkt = getToken();
				if (nkt.token == RIGHTBRACKET) {
					nkt = getToken();
					if (nkt.token == LEFTCURLYBRACKET) {
						if (statement_list()) {
							nkt = getToken();
							if (nkt.token == RIGHTCURLYBRACKET) {
								nkt = getToken();
								if (nkt.token != ELSE) {
									ungetToken();
									return true;
								}
								else {
									nkt = getToken();
									if (nkt.token == LEFTCURLYBRACKET) {
										if (statement_list()) {
											nkt = getToken();
											if (nkt.token == RIGHTCURLYBRACKET) {
												return true;
											}
										}
									}
								}
							}
						}
						else {
							nkt = getToken();
							if (nkt.token == RIGHTCURLYBRACKET) {
								nkt = getToken();
								if (nkt.token != ELSE) {
									ungetToken();
									return true;
								}
								else {
									nkt = getToken();
									if (nkt.token == LEFTCURLYBRACKET) {
										if (statement_list()) {
											nkt = getToken();
											if (nkt.token == RIGHTCURLYBRACKET) {
												return true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (nkt.token == DO) {
		nkt = getToken();
		if (nkt.token == LEFTCURLYBRACKET) {
			if (statement_list()) {
				nkt = getToken();
				if (nkt.token == RIGHTCURLYBRACKET) {
					nkt = getToken();
					if (nkt.token == WHILE) {
						nkt = getToken();
						if (nkt.token == LEFTBRACKET) {
							if (E_sanan()) {
								nkt = getToken();
								if (nkt.token == RIGHTBRACKET) {
									nkt = getToken();
									if (nkt.token == SEMICOLON) {
										return true;
									}
								}
							}
						}
					}
				}
			}
			else {
				nkt = getToken();
				if (nkt.token == RIGHTCURLYBRACKET) {
					nkt = getToken();
					if (nkt.token == WHILE) {
						nkt = getToken();
						if (nkt.token == LEFTBRACKET) {
							if (E_sanan()) {
								nkt = getToken();
								if (nkt.token == RIGHTBRACKET) {
									nkt = getToken();
									if (nkt.token == SEMICOLON) {
										return true;
									}
								}
							}
						}
					}
				}

			}
		}
	}
	else {
		if (nkt.token == WHILE) {
			nkt = getToken();
			if (nkt.token == LEFTBRACKET) {
				if (E_sanan()) {
					nkt = getToken();
					if (nkt.token == RIGHTBRACKET) {
						nkt = getToken();
						if (nkt.token == LEFTCURLYBRACKET) {
							if (statement_list()) {
								nkt = getToken();
								if (nkt.token == RIGHTCURLYBRACKET) {
									return true;
								}
							}
							else {
								nkt = getToken();
								if (nkt.token == RIGHTBRACKET) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}


bool statement() {
	if (assignment()) {
		return true;
	}

	return false;
}



bool statement_list()  // statement list 
{

	if (statement())
	{
		do
		{
			nkt = getToken();
			if (nkt.token == IF || nkt.token == DO || nkt.token == IDENTIFIER)
			{
				ungetToken();
				if (!statement())
					return false;
			}
			else
			{
				ungetToken();
				break;
			}

		} while (1);
		return true;
	}
	return false;

}




bool program() {
	nkt = getToken();
	if (nkt.token == BEGIN) {
		if (statement_list()) {
			nkt = getToken();
			if (nkt.token == END) {
				return true;
			}
		}
	}
	else {
		ungetToken();
		return false;
	}
}



