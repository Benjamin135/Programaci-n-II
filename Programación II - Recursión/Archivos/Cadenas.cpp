// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Cadenas.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

/* Escribir un proceso para eliminar la primer letra de cada palabra�
 Ej. x=�esta es una prueba m�s�;

 EliminaPrim (x);
 x ==> �sta s na rueba �s� */

void Eliminar_Primera_Letra(AnsiString &cadena) {
	if (cadena == "") {

	}
	else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		Eliminar_Primera_Letra(cadena);
		palabra.Delete(1, 1);
		cadena = palabra + " " + cadena;
	}
}
// ---------------------------------------------------------------------------

void eliminarPrimerLetra(String &x) {
	byte n = x.Length();
	if (x != "") {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		eliminarPrimerLetra(x);
		if (w != "") {
			w.Delete(1, 1);
		}
		x = x + " " + w;
	}
}
// ---------------------------------------------------------------------------

void EliminarPrimeraLetra(AnsiString &cadena) {
	/* AnsiString resultado, aux;
	 cadena = cadena.Trim();
	 int n = cadena.Length();
	 cadena = cadena + ' ';
	 if (n == 0) {
	 resultado = "";
	 } else  {
	 int pos = cadena.Pos(' ');
	 aux = cadena.SubString(1, pos - 1);
	 cadena.Delete(1,pos);
	 resultado = EliminarPrimeraLetra(cadena);
	 if (aux.Length() != 0) {
	 resultado = aux.Delete(1,1) + ' ' + resultado;
	 }
	 }
	 return resultado; */

	AnsiString aux;
	cadena = cadena.Trim();
	byte n = cadena.Length();
	cadena = cadena + ' ';
	if (n == 0) {
		cadena = "";
	}
	else {
		byte pos = cadena.Pos(' ');
		aux = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		EliminarPrimeraLetra(cadena);
		if (aux.Length() > 0) {
			cadena = aux.Delete(1, 1) + " " + cadena;
		}
	}
}

// ---------------------------------------------------------------------------
// Verificar si un caracter pertenece a un conjunto o cadena

bool perteneceConjunto(String conjunto, char c) {
	bool res;
	if (conjunto == "")
		res = false;
	else {
		Cardinal len = conjunto.Length();
		char x = conjunto[len];
		if (c == x)
			res = true;
		else {
			conjunto.Delete(len, 1);
			res = perteneceConjunto(conjunto, c);
		}
	}
	return res;
}

String leerConjunto(String conjunto) {
	String r;
	String s = InputBox("Titulo", "Caracter:", "");
	char c = s[1];
	bool pertenece = perteneceConjunto(conjunto, c);
	if (pertenece == false) {
		ShowMessage("No");
		r = "";
	}
	else {
		ShowMessage("Si");
		r += String(c) + leerConjunto(conjunto);
	}
	return r;
}
// ---------------------------------------------------------------------------
// Verificar si una palabra es palindrome

bool esPalindrome(String cad) {
	bool res;
	Cardinal len = cad.Length();
	if (len <= 1)
		res = true;
	else {
		char izq = cad[1];
		char der = cad[len];
		if (izq != der)
			res = false;
		else {
			String nueva = cad.SubString(2, len - 2);
			// cad.Delete(len,1);
			// cad.Delete(1, 1);
			res = esPalindrome(nueva);
			// res = esPalindrome(cad);
		}
	}
	return res;
}
// ---------------------------------------------------------------------------

/* Cardinal auxSumatoria(String cad) {
 Cardinal s;
 if (cad == "") {
 s = 0;
 } else {
 Cardinal pos = posNum(cad);
 cad.Delete(1, pos);
 Cardinal posL = posLetra(cad);
 if (posL == 0)
 posL = cad.Length();
 String num = cad.SubString(1, posL);
 s = StrToInt(num);
 cad.Delete(1, posL);
 s += auxSumatoria(cad);
 }
 return s;
 }

 Cardinal sumatoriaNumeros(String cad) {
 Cardinal s;
 if (cad == "") {
 s = 0;
 } else {
 Cardinal pos = cad.Pos(" ");
 if (pos == 0)
 pos = cad.Length();
 String pal = cad.SubString(1, pos - 1);
 String otra = cad.SubString(pos + 1, cad.Length() - pal.Length() - 1);
 s = sumatoriaNumeros(otra) + auxSumatoria(pal);
 }
 return s;
 } */

// ---------------------------------------------------------------------------
/* Escribir un funcion que devuelva el n�mero mayor contenido
 en una cadena. (Si la cadena no tiene n�meros debe devolver 0)

 Ej: cadena = "hola104 mundo54 como1 estan"
 resultado = 104 */

Cardinal posNum(String cad, bool num) {
	Cardinal pos;
	if (cad.Length() == 0)
		pos = 0;
	else {
		char c = cad[cad.Length()];
		cad.Delete(cad.Length(), 1);
		pos = posNum(cad, num);
		if (pos == 0) {
			if (num) {
				if (c >= '0' && c <= '9')
					pos = cad.Length() + 1;
			}
			else {
				if (!(c >= '0' && c <= '9'))
					pos = cad.Length() + 1;
			}
		}
	}
	return pos;
}

Cardinal mayor(String cad) {
	Cardinal may;
	if (cad.Length() == 0)
		may = 0;
	else {
		Cardinal posA = posNum(cad, true);
		Cardinal num;
		if (posA > 0) {
			cad.Delete(1, posA - 1);
			Cardinal posB = posNum(cad, false);
			if (posB == 0)
				posB = cad.Length() + 1;
			num = StrToInt(cad.SubString(1, posB - 1));
			cad.Delete(1, posB - 1);
		}
		else {
			num = 0;
			cad = "";
		}
		may = mayor(cad);
		if (num > may)
			may = num;
	}
	return may;
}

Cardinal numMayor(String cad) {
	Cardinal may;
	if (cad.Length() == 0)
		may = 0;
	else {
		Cardinal pos = cad.Pos(" ");
		if (pos == 0)
			pos = cad.Length() + 1;
		String pal = cad.SubString(1, pos - 1);
		cad.Delete(1, pos);
		may = numMayor(cad);
		Cardinal num = mayor(pal);
		if (num > may)
			may = num;
	}
	return may;
}
// ---------------------------------------------------------------------------

bool EsDigito(char z) {
	return (z >= '0') && (z <= '9');
}

String PrimerNumero(String x) {
	String num;
	if (x == "") {
		num = "";
	}
	else {
		char aux = x[1];
		x.Delete(1, 1);
		if (!EsDigito(aux)) {
			num = PrimerNumero(x);
		}
		else {
			if ((x != "") && (EsDigito(x[1]))) {
				num = String(aux) + PrimerNumero(x);
			}
			else {
				num = String(aux);
			}
		}
	}
	return num;
}

Cardinal NumeroMayor(String x) {
	Cardinal num;
	if (x == "") {
		num = 0;
	}
	else {
		String aux = PrimerNumero(x);
		if (aux != "") {
			x.Delete(1, x.Pos(aux) + aux.Length() - 1);
			num = NumeroMayor(x);
			if (StrToInt(aux) > num) {
				num = StrToInt(aux);
			}
		}
		else {
			num = 0;
		}
	}
	return num;
}

// ---------------------------------------------------------------------------
// Invertir una Cadena
// Ej: "Anita lava la tina"
// resultado = "anit al aval atina"

void Invertir(String &x) {
	int n = x.Length();
	if (x != "") {
		if (n > 1) {
			wchar_t a = x[1];
			wchar_t b = x[n];
			x.Delete(n, 1);
			x.Delete(1, 1);
			Invertir(x);
			x = String(b) + x + a;
		}
	}
}
// ---------------------------------------------------------------------------

AnsiString Invertir_Cadena(AnsiString x) {
	AnsiString resultado;
	if (x == "") {
		resultado = "";
	}
	else {
		char z = x[1]; // z="a"
		x.Delete(1, 1); // x="nita lava la tina"
		resultado = Invertir_Cadena(x); // resultado="anit al aval atin"
		resultado = resultado + z; // resultado="anit al aval atina"
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Invertir una cadena utilizando la hip�tesis k = n-2

AnsiString Invertir_Cadena2(AnsiString x) {
	AnsiString resultado;
	if (x.Length() <= 1) {
		resultado = x;
	}
	else {
		byte n = x.Length();
		AnsiString z = x.SubString(n - 1, 2); // z="na"
		x.Delete(n - 1, 2); // x="Anita lava la ti"
		resultado = Invertir_Cadena2(x); // resultado="it al aval atinA"
		resultado = AnsiString(z[2]) + z[1] + resultado;
		// resultado="anit al aval atinA"
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Invertir una cadena utilizando la hip�tesis k = n/2

AnsiString Invertir_Cadena3(AnsiString x) {
	AnsiString resultado;
	if (x.Length() <= 1) {
		resultado = x;
	}
	else {
		byte n = x.Length();
		AnsiString z = x.SubString(1, n / 2); // z = "Anita lav"
		x.Delete(1, n / 2); // x = "a la tina"
		z = Invertir_Cadena3(z); // z = "val atinA"
		x = Invertir_Cadena3(x); // x = "anit al a"
		resultado = x + z;
	}
	return resultado;
}
// ---------------------------------------------------------------------------

String invertirN2(String cadena) {
	if (cadena.Length() <= 1) {
		return cadena;
	}
	if (cadena.Length() == 2) {
		return String(cadena[2]) + String(cadena[1]);
	}
	else {
		int n = cadena.Length();
		String priMitad = cadena.SubString(1, n / 2);
		String segMitad;
		if (n % 2 == 0) {
			segMitad = cadena.SubString((n / 2) + 1, n / 2);
		}
		else {
			segMitad = cadena.SubString((n / 2) + 1, (n / 2) + 1);
		}
		String priMiInv = invertirN2(priMitad);
		String segMiInv = invertirN2(segMitad);
		return segMiInv + priMiInv;
	}
}

// ----------------------------------------------------------------------------
/* Invertir cada palabra de una cadena
 Ej. x=�esta es una prueba m�s�;

 InvertirPal (x);
 x ==> � atse se anu abeurp s�m� */

void invertirPalabras(String &x) {
	byte n = x.Length();
	if (n > 0) {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		invertirPalabras(x);
		Invertir(w);
		x = x + " " + w;
	}
}
// ---------------------------------------------------------------------------

AnsiString InvertirPalabra(AnsiString palabra) {
	AnsiString resultado;
	if (palabra == "") {
		resultado = "";
	}
	else {
		char aux = palabra[1];
		palabra.Delete(1, 1);
		resultado = InvertirPalabra(palabra);
		resultado = resultado + aux;
	}
	return resultado;
}

void Invertir_Cada_Palabra(AnsiString &cadena) {
	// AnsiString aux;
	/* cadena = cadena.TrimLeft();
	 byte n = cadena.Length();
	 cadena = cadena + ' ';
	 if (n == 0) {
	 cadena = "";
	 } else {
	 byte pos = cadena.Pos(' ');
	 AnsiString aux = cadena.SubString(1, pos - 1);
	 cadena.Delete(1, pos);
	 char z = aux[1];
	 aux.Delete(1,1);
	 Invertir_Palabra(aux);
	 Invertir_Palabra(cadena);
	 cadena = aux + z + cadena;
	 } */

	cadena = cadena.Trim();
	byte n = cadena.Length();
	cadena = cadena + ' ';
	if (n == 0) {
		cadena = "";
	}
	else {
		byte pos = cadena.Pos(' ');
		AnsiString aux = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		aux = InvertirPalabra(aux);
		Invertir_Cada_Palabra(cadena);
		cadena = aux + " " + cadena;
	}
}

// ---------------------------------------------------------------------------
// Eliminar vocales de un cadena

bool esVocal(wchar_t z) {
	/*
	 z = m   >> w.Pos(z) = 0
	 z = p   >> w.Pos(z) = 0
	 z = A   >> w.Pos(z) = 6
	 z = a   >> w.Pos(z) = 1
	 */
	String w = "aeiouAEIOU";
	return w.Pos(z) > 0;
}

void eliminarVocales(String &x) {
	if (x != "") {
		wchar_t z = x[1];
		x.Delete(1, 1);
		eliminarVocales(x);
		if (!esVocal(z)) {
			x = String(z) + x;
		}
	}
}
// ---------------------------------------------------------------------------
// Palabra m�s larga de una cadena
// Ej. CadenaMasLarga(�esta es una prueba m�s�) ==> �prueba�

String palabraMasLarga(String x) {
	byte n = x.Length();
	String palMax = "";
	if (n > 0) {
		byte p = x.LastDelimiter(" ");
		String pal = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		palMax = palabraMasLarga(x);
		if (pal.Length() > palMax.Length()) {
			palMax = pal;
		}
	}
	return palMax;
}
// ---------------------------------------------------------------------------

AnsiString Palabra_Larga(AnsiString cadena) {
	AnsiString resultado, aux;
	cadena = cadena.Trim();
	byte n = cadena.Length();
	cadena = cadena + ' ';
	if (n == 0) {
		resultado = "";
	}
	else {
		byte pos = cadena.Pos(' '); // pos = 5
		aux = cadena.SubString(1, pos - 1); // aux = "esta"
		cadena.Delete(1, pos); // cadena = "es una prueba m�s"
		resultado = Palabra_Larga(cadena); // resultado = "prueba"
		if (aux.Length() >= resultado.Length()) {
			resultado = aux;
		}
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Contar palabras de una cadena

byte contarPalabras(String x) {
	byte c;
	if (x == "") {
		c = 0;
	}
	else if (x.Length() == 1) {
		c = 0;
		if (x[1] != ' ') {
			c++;
		}
	}
	else {
		c = 0;
		if (x[1] != ' ' && x[2] == ' ') {
			c++;
		}
		x.Delete(1, 1);
		c += contarPalabras(x);
	}
	return c;
}
// ---------------------------------------------------------------------------

byte contar_palabras(String cad) {
	byte contador, len, p;
	String pal;
	cad = cad.Trim();
	len = cad.Length();
	if (len > 1) {
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p + 1, len - p);
		cad.Delete(p + 1, len - p);
		cad = cad.Trim();
		contador = contar_palabras(cad);
		contador++;
	}
	else {
		/* if (len == 1 && cad[1] == ' ' || len == 0) {
		 contador = 0;
		 }
		 else { */
		if (len == 1) {
			contador = 1;
		}
		else {
			contador = 0;
		}
	}
	return contador;

}

// ---------------------------------------------------------------------------
// Contar espacios en una cadena
// Ej: "Hola a todos " => 3

byte Cantidad_Espacios(AnsiString x) {
	byte cantidad;
	if (x == "") {
		cantidad = 0;
	}
	else {
		char z = x[x.Length()];
		x.Delete(x.Length(), 1);
		cantidad = Cantidad_Espacios(x);
		if (z == ' ') {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo para contar las vocales de una cadena
// Ej: "Hola a todos, como est�n" ==> 9

bool Es_Vocal(char z) {
	AnsiString vocales = "aeiouAEIOU������������";
	return vocales.Pos(z) > 0;
}

byte Contar_Vocales(AnsiString x) {
	byte contador;
	if (x == "") {
		contador = 0;
	}
	else {
		char z = x[1];
		x.Delete(1, 1);
		contador = Contar_Vocales(x);
		if (Es_Vocal(z)) {
			contador++;
		}
	}
	return contador;
}
// ---------------------------------------------------------------------------
// Suma de digitos de una cadena

byte suma_digitos_cadena(String cad) {
	char letra;
	byte sum, len;
	len = cad.Length();
	if (len > 1) {
		letra = cad[len];
		cad.Delete(len, 1);
		sum = suma_digitos_cadena(cad);
		if (EsDigito(letra) > 0) {
			sum = sum + StrToInt(letra);
		}
	}
	else {
		if (EsDigito(cad[1]) > 0) {
			sum = StrToInt(cad);
		}
		else {
			sum = 0;
		}

	}
	return sum;
}
// ---------------------------------------------------------------------------
// Construir cadena con los digitos

void construir_cadena_digitos(String &cad) {
	byte len;
	char letra;
	len = cad.Length();
	if (len > 1) {
		letra = cad[len];
		cad.Delete(len, 1);
		construir_cadena_digitos(cad);
		if (EsDigito(letra) > 0) {
			cad = cad + letra;
		}
		else {
			cad = cad + " ";
		}
	}
	else {
		if (!EsDigito(cad[1]) > 0) {
			cad = " ";
		}
	}
}
// ---------------------------------------------------------------------------
// Contar letras de una cadena

bool EsLetra(char z) {
	AnsiString letras =
		"abcdefghijklmn�opqrstuvwxyzABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	return letras.Pos(z) > 0;
}

int contar_letras(String cad) {
	char letra;
	int L, contador;
	L = cad.Length();
	if (L > 1) {
		letra = cad[L];
		cad.Delete(L, 1);
		contador = contar_letras(cad);
		if (EsLetra(letra) > 0) {
			contador = contador + 1;
		}
	}
	else {
		if (EsLetra(cad[1])) {
			contador = 1;
		}
		else {
			contador = 0;
		}
	}
	return contador;
}
// ---------------------------------------------------------------------------
/* Escriba un proceso que invierta el orden de las palabras de una cadena:
 cad = �esta es una prueba�
 invertir_frase(cad) -> cad: �prueba una es esta� */

void invertir_frase(String &cadena) {
	byte n = cadena.Length();
	if (n > 0) {
		byte pos = cadena.Pos(' ');
		String palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		Invertir(palabra);
		invertir_frase(cadena);
		cadena = cadena + palabra;
	}
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
