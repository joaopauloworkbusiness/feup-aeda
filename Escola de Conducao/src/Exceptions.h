/*
 * Exceptions.h
 *
 *  Created on: Nov 6, 2013
 *      Author: henrique
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>
#include <string>
#include "Utilities.h"
using namespace std;

class MatriculaInvalida: public exception {
	string *m;
public:
	MatriculaInvalida(string &matricula): m(&matricula) {}
	virtual ~MatriculaInvalida() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << "Erro:\tMatricula Invalida." << endl;
		cout << "\tFormato esperado: \"xx-xx-xx\"." << endl;
		cout << "\tUma matricula tem que conter 2 letras e" << endl;
		cout << "\t4 numeros separados por um \'-\'" << endl;
		cout << "\t---------------------------------------" << endl;

		return "";
	}
};

class HoraInvalida: public exception {
	int *hora;
public:
	HoraInvalida(int &Hora): hora(&Hora) {}
	virtual ~HoraInvalida() throw() {}

	virtual const char *what () const throw() {
		cout << endl;
		cout << "Erro:\tHora Invalida." << endl;
		cout << "\tA hora tem que pertencer ao intervalo: [0, 23]" << endl;
		cout << "\t----------------------------------------------" << endl;

		return "";
	}
};

class InputEsperadoEraInt: public exception {
	int num;
	int start, end;
public:
	InputEsperadoEraInt(int Numero, int Start, int End): num(Numero), start(Start), end(End) {}
	virtual ~InputEsperadoEraInt() throw() {}

	virtual const char *what () const throw() {
		cout << endl;
		cout << "Erro:\tInput Invalido: \'int\' type era esperado." << endl;
		cout << "\tInput tambem tem que pertencer ao intervalo: [" << start << ", " << end << "]" << endl;
		cout << "\t----------------------------------------------------" << endl;

		return "";
	}
};

class InputEsperadoEraString: public exception {
	string *str;
public:
	InputEsperadoEraString(string &String): str(&String) {}
	virtual ~InputEsperadoEraString() throw() {}

	virtual const char *what () const throw() {
		cout << endl;
		cout << "Erro:\tInput Invalido: \'string\' type era esperado." << endl;
		cout << "\t-------------------------------------------" << endl;

		return "";
	}
};

class ColecaoVazia: public exception {
	string name;
public:
	ColecaoVazia(string Nome): name(Nome) {}
	virtual ~ColecaoVazia() throw() {}

	virtual const char *what () const throw() {
		cout << endl;
		cout << "Erro:\tA colecao de nome " << name << " encontra-se vazia." << endl;
		cout << "\t------------------------------------------------" << endl;
		cout << "Pressione enter para continuar... ";
		cin.get();

		return "";
	}
};

#endif /* EXCEPTIONS_H_ */
