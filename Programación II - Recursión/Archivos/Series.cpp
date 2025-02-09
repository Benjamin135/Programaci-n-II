// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Series.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// Serie Fibonacci

Cardinal fibonacci(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return t;
}
// ---------------------------------------------------------------------------
/* Escribir una funci�n que devuelva el n-�simo t�rmino
 de la siguiente serie: 1, 2, 3, 6, 7, 14, 15, 30, 31, ... */

Cardinal serie1(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = serie1(n - 1);
		if (n % 2 == 0) {
			t *= 2;
		}
		else {
			t++;
		}
	}
	return t;
}
// ---------------------------------------------------------------------------
// Suma de Serie: 0, 2, 4, 6, 8, 10, ...

Cardinal sumaSerie(Word n) {
	Cardinal s;
	if (n < 1) {
		s = 0;
	}
	else {
		s = sumaSerie(n - 1);
		s += 2*(n - 1);
	}
	return s;
}
// ---------------------------------------------------------------------------
// Serie: 1, 3, 7, 15, 31, 63, ...

Cardinal serie2(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = serie2(n - 1) * 2 + 1;
	}
	return t;
	// return (int)pow(2, n)-1;
}
// ---------------------------------------------------------------------------
/* Escribir una funci�n que devuelva la suma de los t�rminos
 pares de la siguiente serie: 1, 2, 4, 5, 10, 13, 26, 28, 29, ... */

Cardinal sumaSerie2(Word n, Cardinal &s) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = sumaSerie2(n - 1, s);
		if (n % 3 == 0) {
			t += 2;
		}
		else if (n % 3 == 1) {
			t++;
		}
		else {
			t *= 2;
		}

		if (t % 2 == 0) {
			s += t;
		}
	}
	return t;
}
//---------------------------------------------------------------------------
// Digito de la serie S = 2,4,6,8,10...

byte Serie(byte numero) {
	byte resultado = 2;

	if (numero == 1) {
		resultado = 2;
	} else {
		resultado = resultado + Serie(numero - 1);
	}
	return resultado;
}
// ----------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
