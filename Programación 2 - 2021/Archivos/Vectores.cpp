//---------------------------------------------------------------------------

#pragma hdrstop

#include "Vectores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Algoritmo que devuelve la suma de los elementos de un vector
// Ejemplo: v[1,2,3,4,5] ==> 15

Cardinal Suma(TStringGrid *v, Word n) {
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else {
		suma = Suma(v, n - 1);
		suma = suma + StrToInt(v->Cells[n - 1][0]);
    }
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de los elementos pares de un vector
// Ejemplo: v[1,2,3,4,5] ==> 6

Cardinal SumaPares(TStringGrid *v, Word n){
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else if (n == 1) {
		byte num = StrToInt(v->Cells[0][0]);
		if (num % 2 == 0) {
			suma = num;
		} else {
			suma = 0;
        }
	} else {
		suma = SumaPares(v, n - 1);
		byte ult = StrToInt(v->Cells[n - 1][0]);
		if (ult % 2 == 0) {
			suma = suma + ult;
		}
    }
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de los elementos impares de un vector
// Ejemplo: v[1,2,3,4,5] ==> 9

Cardinal SumaImpares(TStringGrid *v, Word n) {
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else if (n == 1) {
		suma = StrToInt(v->Cells[0][0]);
		if (suma % 2 == 0) {
			suma = 0;
		}
	} else {
		suma = SumaImpares(v, n - 1);
		byte ult = StrToInt(v->Cells[n - 1][0]);
		if (ult % 2 != 0) {
			suma = suma + ult;
        }
    }
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que verifica si un elemento esta en el vector
// Ejemplo: v[2, 21, 34, 55, 8]; x = 34 ==> true

bool ExisteElemento(TStringGrid *v, Word a, Word b, Word elemento) {
	bool result;
	Word n = b - a + 1;
	if (n == 0) {
		result = false;
	} else if (n == 1) {
		Word num = StrToInt(v->Cells[a][0]);
		if (num == elemento) {
			result = true;
		} else {
			result = false;
        }
	} else {
		result = ExisteElemento(v, a, b - 1,elemento);
		Word ult = StrToInt(v->Cells[b - 1][0]);
		if (ult == elemento) {
			result = true;
        }
    }
	return result;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve un vector cargado con las vocales de
// cada palabra de una cadena
// Ejemplo: x = "Buenos dias a todos" ==> v[ueo, ia, a, oo,]

AnsiString Vocales(AnsiString cadena) {
	AnsiString vocales;
	AnsiString alf = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		vocales = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		byte pos = alf.Pos(z);
		vocales = Vocales(cadena);
		if (pos > 0) {
			vocales = AnsiString(z) + vocales;
        }
    }
	return vocales;
}

void CargarVocales(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString vocales = Vocales(palabra);
		if (!vocales.IsEmpty()) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = vocales;
			v->ColCount++;
		}
		CargarVocales(v, cadena);
	}
}

void CargarVocales_2(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		cadena = cadena.Trim();
		byte len = cadena.Length();
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, len - pos);
		cadena.SetLength(pos - 1);
		AnsiString vocales = Vocales(palabra);
		CargarVocales_2(v, cadena);
		if (!vocales.IsEmpty()) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = vocales;
			v->ColCount++;
		}
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve una cadena con el ultimo caracter de cada palabra del vector
// Ejemplo: v[hola,como,estas,hoy,dia] ==> aosya

AnsiString UltimasLetras(TStringGrid *v, Word n) {
	AnsiString resultado;
	AnsiString palabra;
	byte len;
	if (n == 0) {
		resultado = "";
	} else if (n == 1) {
		palabra = v->Cells[0][0];
		palabra = palabra.Trim();
		if (palabra != "" && palabra != " ") {
			len = palabra.Length();
			resultado = palabra[len];
		}
	} else {
		palabra = v->Cells[n - 1][0];
		palabra = palabra.Trim();
		if (palabra != "" && palabra != " ") {
			len = palabra.Length();
			resultado = UltimasLetras(v, n - 1);
			resultado = resultado + palabra[len];
		} else {
			resultado = resultado + UltimasLetras(v, n - 1);
        }
	}
	return resultado;
}
// ---------------------------------------------------------------------------
/* Algoritmo que carga un vector con las palabrs de una cadena
   donde la primera letra de cada palabra este en Mayuscula */
// Ejemplo: x = "buenos dias a todos" => v[Buenos, Dias, A, Todos]

AnsiString LetraMayuscula(AnsiString cadena) {
	AnsiString palabra;
	if (cadena.IsEmpty()) {
		palabra = "";
	} else {
		char z = toupper(cadena[1]);
		cadena.Delete(1, 1);
		palabra = LetraMayuscula(cadena);
		palabra = AnsiString(z) + cadena;
	}
	return palabra;
}

void CargarPalabras(TStringGrid *v, AnsiString cadena) {
	if(cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString newPalabra = LetraMayuscula(palabra);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = newPalabra;
		v->ColCount++;
		CargarPalabras(v, cadena);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo para cargar un vector con las palabras de una cadena
// Ejemplo: x = "Hola a todos" ==> v[Hola, a, todos]

void CargarPalabra(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		CargarPalabra(v, cadena);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = palabra;
		v->ColCount++;
    }
}
// ---------------------------------------------------------------------------
/* Algoritmo que devuelve una cadena con las primeras letras
   de las palabras de un vector */
// Ejemplo: v[Feliz, navidad, a, todos] ==> Fnat

AnsiString PrimerasLetras(TStringGrid *v, Word n) {
	AnsiString cad;
	if (n == 0) {
		cad = "";
	} else {
		AnsiString palabra = v->Cells[n - 1][0];
		palabra = palabra.Trim();
		if (palabra !="" && palabra != " ") {
			cad = PrimerasLetras(v, n - 1);
			cad = cad + palabra[1];
		} else {
			cad = PrimerasLetras(v, n - 1);
        }
    }
	return cad;
}
// ---------------------------------------------------------------------------
// Algoritmo que carga un vector con las vocales de una cadena
// Ejemplo: x = "hola mundo genial" ==> v[o, a, u, o, e, i, a]

void Cargar_Vocales(TStringGrid *v, AnsiString cadena) {
	AnsiString vocales = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		if (vocales.Pos(z) > 0) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = AnsiString(z);
			v->ColCount++;
		}
		Cargar_Vocales(v, cadena);
	}
}
// ---------------------------------------------------------------------------
/* Algoritmo que carga un vector con palabras invertidas de una
   cadena letra por letra */
// Ejemplo: x = "Hola mundo" ==> v[o, d, n, u, , m, a, l, o, H]

void CargarCadenaInvertida(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte len = cadena.Length();
		char z = cadena[len];
		cadena.SetLength(len - 1);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = AnsiString(z);
		v->ColCount++;
		CargarCadenaInvertida(v, cadena);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que carga las palabras de una cadena sin vocales
// Ejemplo: x = "el mundo es grande" ==> v[l, mnd, s, grnd]

AnsiString SinVocales(AnsiString cadena) {
	AnsiString palabra;
	AnsiString vocales = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		palabra = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		palabra = SinVocales(cadena);
		if (vocales.Pos(z) == 0) {
			palabra = AnsiString(z) + palabra;
        }
    }
	return palabra;
}

void CargarSinVocales(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		cadena = cadena.Trim();
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString newPalabra = SinVocales(palabra);
		if (newPalabra != "") {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = newPalabra;
			v->ColCount++;
		}
		CargarSinVocales(v, cadena);
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve un numero con los elementos de un vector
// Ejemplo: v[10, 2, 30, 65, 9] ==> 96530210

void GenerarNumeros(TStringGrid *v, Word n, unsigned long long &num) {
	byte cantidad;
	if (n == 0) {
		throw new Exception("Error: Vector vacio");
	} else if (n == 1) {
		num = StrToInt(v->Cells[0][0]);
	} else {
		GenerarNumeros(v, n - 1, num);
		Cardinal numero = StrToInt(v->Cells[n - 1][0]);
		cantidad = String(num).Length();
		num = numero * pow(10, cantidad) + num;
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que ordena un vector en orden ascendente
// Ejemplo: v[95, 21,67, 3, 78] ==> v[3, 21, 67, 78, 95]

void MayorAlFinal(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlFinal(v, n - 1);
		String x = v->Cells[n - 1][0];
		String y = v->Cells[n - 2][0];
		if (StrToInt(x) < StrToInt(y)) {
			v->Cells[n - 1][0] = v->Cells[n - 2][0];
			v->Cells[n - 2][0] = x;
		}
	}
}

void OrdenarAsc(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlFinal(v, n);
		OrdenarAsc(v, n - 1);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que ordena un vector en orden Descendente
// Ejemplo: v[95, 21,67, 3, 78] ==> v[5, 78, 67, 21, 3]

void MayorAlInicio(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlInicio(v, n - 1);
		String x = v->Cells[n - 1][0];
		String y = v->Cells[n - 2][0];
		if (StrToInt(x) > StrToInt(y)) {
			v->Cells[n - 1][0] = v->Cells[n - 2][0];
			v->Cells[n - 2][0] = x;
		}
	}
}

void OrdenarDesc(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlInicio(v, n);
		OrdenarDesc(v, n - 1);
	}
}
// ---------------------------------------------------------------------------
// Ordenar un vector en forma Ascendente en un segmento (a, b)
// Ejemplo: v[10, 2, 45, 31, 7, 18]   a = 2, b = 5
//          v[10, 2, 7, 31, 45, 18]

void MayorAlFinalSeg(TStringGrid *v, Word a, Word b) {
	Word n = b - a + 1;
	if (n > 1) {
		MayorAlFinalSeg(v, a, b - 1);
		String x = v->Cells[b - 1][0];
		String y = v->Cells[b - 2][0];
		if (StrToInt(x) < StrToInt(y)) {
		   v->Cells[b - 1][0] = v->Cells[b - 2][0];
		   v->Cells[b - 2][0] = x;
        }
    }
}

void OrdenarSegmentoAsc(TStringGrid *v, Word a, Word b) {
 	Word n = b - a + 1;
	if (n > 1) {
		MayorAlFinalSeg(v, a, b);
		OrdenarSegmentoAsc(v, a, b - 1);
    }
}
// ---------------------------------------------------------------------------
// Algoitmo que invierte un vector en segmento (a, b)
// Ejemplo: v[1, 2, 3, 4, 5, 6] ==> v[1, 5, 4, 3, 2, 6]

void InvertirSegmento(TStringGrid *v, Word a, Word b) {
	byte n = b - a + 1;
	if (n > 1) {
		InvertirSegmento(v, a + 1, b - 1);
		String x = v->Cells[b - 1][0];
		v->Cells[b - 1][0] = v->Cells[a - 1][0];
		v->Cells[a - 1][0] = x;
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que elimina un elemento de un vector
// Ejemplo: v[1, 2, 3, 4, 5] x = 2  ==> v[1, 3, 4, 5]

void Eliminar(TStringGrid* v, Cardinal pos) {
	if (pos < v->ColCount) {
		v->Cells[pos][0] = v->Cells[pos + 1][0];
		Eliminar(v, pos + 1);
	}
}

void EliminarElemento(TStringGrid *v, Word n, Word elemento) {
	if (n >= 1) {
		Word num = StrToInt(v->Cells[n - 1][0]);
		if (num == elemento) {
			Eliminar(v, n - 1);
			v->ColCount--;
			EliminarElemento(v, n - 1, elemento);
		} else {
			EliminarElemento(v, n - 1, elemento);
		}
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que elimina los elementos de un segmento del vector
// Ejemplo: v[1, 2, 3, 4, 5] a = 2, b = 4  ==> v[1, 5]

void EliminarElementos(TStringGrid *v, byte a, byte b){
	byte n = b - a + 1;
	if (n >= 1) {
		if (b > b - 1) {
			Eliminar(v, b - 1);
			v->ColCount--;
		}
		EliminarElementos(v, a, b - 1);
	}
}
// ---------------------------------------------------------------------------

byte CantidadVocales(AnsiString cadena) {
	AnsiString vocales = "aeiouAEIOU������������";
	byte cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadVocales(cadena);
		if (vocales.Pos(z) > 0) {
			cantidad++;
        }
	}
	return cantidad;
}

Cardinal Cantidad_Vocales(TStringGrid *v, Word n) {
	Cardinal cantidad = 0;
	if (n == 0) {
		cantidad = 0;
	} else {
		AnsiString palabra = v->Cells[n - 1][0];
		byte num = CantidadVocales(palabra);
		cantidad = Cantidad_Vocales(v, n - 1);
		cantidad = cantidad + num;
	}
	return cantidad;
}
// ---------------------------------------------------------------------------

byte CantidadPrimos(Cardinal x) {
	String primos = "12357";
	byte cantidad = 0;
	if (x < 10) {
		if (primos.Pos(String(x)) > 0) {
			cantidad = 1;
		}
	} else {
		byte dig = x % 10;
		cantidad = CantidadPrimos(x / 10);
		if (primos.Pos(String(dig)) > 0) {
			cantidad++;
		}
	}
	return cantidad;
}

Cardinal Cantidad_Primos(TStringGrid *v, Word n) {
	Cardinal cantidad;
	if (n == 0) {
		cantidad = 0;
	} else {
		Cardinal numero = StrToInt(v->Cells[n - 1][0]);
		byte num = CantidadPrimos(numero);
		cantidad = Cantidad_Primos(v, n - 1);
		cantidad = cantidad + num;
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Suma de los elementos pares de un vector en iterativo

byte SumaParesIterativo(TStringGrid *v, Word n) {
	byte suma, i, col;
	suma = 0, i = 0, col = n - 1;
	while (i < n) {
		if (StrToInt(v->Cells[col][0]) % 2 == 0) {
			suma = suma + StrToInt(v->Cells[col][0]);
		}
		col--;
		i++;
	}
	return suma;
}
// ---------------------------------------------------------------------------
// Suma de los elementos pares de un vector en recursivo

byte SumaParesRecursivo(TStringGrid *v, Word n) {
	byte suma;
	if (n == 0) {
		suma = 0;
	} else {
		byte num = StrToInt(v->Cells[n - 1][0]);
		suma = SumaParesRecursivo(v, n - 1);
		if (num % 2 == 0) {
			suma = suma + num;
		}
	}
	return suma;
}
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
