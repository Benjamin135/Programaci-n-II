// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Numeros.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// Algoritmo que duvuelve la suma de los digitos de un n�mero
// Ejemplo:  SumaDigitos(x = 12345) ==> 15

byte SumaDigitos(Cardinal x) {
	byte suma;
	if (x < 10) {
		suma = x;
	} else {
		suma = SumaDigitos(x / 10);
		suma = suma + x % 10;
	}
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve el mayor de los d�gitos de un n�mero
// Ejemplo:  Mayor(x = 1825) ==> 8

byte Mayor(Cardinal x) {
	byte mayor;
	if (x < 10) {
		mayor = x;
	} else {
		mayor = Mayor(x / 10);
		if (x % 10 > mayor) {
			mayor = x % 10;
		}
	}
	return mayor;
}
// ---------------------------------------------------------------------------
// Algoritmo para eliminar el d�gito Z de un n�mero
// Ejemplo:  EliminarZ(x = 42872981, z = 2) ==> x = 487981;

void EliminarZ(Cardinal &x, byte z) {
	if (x < 10) {
		if (x == z) {
			x = 0;
		}
	} else {
		byte dig = x % 10;
		x = x / 10;
		EliminarZ(x, z);
		if (dig != z) {
			x = x * 10 + dig;
		}
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve una cadena a partir de un numero:
// Ejemplo:  Literal(x = 132) ==> "133322"

AnsiString RepetirDigito(Cardinal x, Cardinal v) {
	AnsiString resultado;
	if (x == 0) {
		resultado = "";
	} else {
		resultado = RepetirDigito(x - 1, v) + String(v);
	}
	return resultado;
}

AnsiString Literal(Cardinal x) {
	AnsiString resultado;
	if (x < 10) {
		resultado = RepetirDigito(x, x);
	} else {
		byte digito = x % 10;
		resultado = Literal(x / 10);
		resultado = resultado + RepetirDigito(digito, digito);
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Algoritmo para rotar de un n�mero un digito a la izquierda
// Ejemplo:  Rotar(x = 12345) ==> 23451

Cardinal Rotar(Cardinal x) {
	Cardinal resultado;
	if (x < 10) {
		resultado = x;
	} else if (x < 100) {
		byte dig_1 = x / 10;
		byte dig_2 = x % 10;
		resultado = dig_2 * 10 + dig_1;
	} else {
		resultado = Rotar(x / 10);
		byte dig_3 = x % 10;
		resultado = (resultado / 10 * 10 + dig_3) * 10 + resultado % 10;
	}
	return resultado;
}

void Rotar_2(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else if (x < 100) {
		byte dig_1 = x / 10;
		byte dig_2 = x % 10;
		x = dig_2 * 10 + dig_1;
	} else {
		byte dig_3 = x % 10;
		x = x / 10;
		Rotar_2(x);
		x = (x / 10 * 10 + dig_3) * 10 + x % 10;
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que verifica si un n�mero esta ordenado ascendentemente
// Ejemplo: OrdenadoAsc(x = 1234) ==> true
// 			OrdenadoAsc(x = 1324) ==> false

bool OrdenadoAsc(Cardinal x) {
	bool resultado;
	if (x < 10) {
		resultado = true;
	}else {
		byte dig = x % 10;
		x = x / 10;
		resultado = OrdenadoAsc(x);
		if (x % 10 > dig) {
			resultado = false;
		}
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Algoritmo que verifica si un n�mero esta ordenado descendentemente
// Ejemplo: OrdenadoDesc(x = 1234) ==> true
// 			OrdenadoDesc(x = 1324) ==> false

bool OrdenadoDesc(Cardinal x) {
	bool resultado;
	if (x < 10) {
		resultado = true;
	}else {
		byte dig = x % 10;
		x = x / 10;
		resultado = OrdenadoDesc(x);
		if (x % 10 < dig) {
			resultado = false;
		}
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve un numero separado en pares e impares
// Ejemplo: Separar(x = 12345, x, y) ==> x = 135, y = 24

void Separar(Cardinal n, Cardinal &x, Cardinal &y) {
	if (n < 10) {
		if (n % 2 == 0) {
			x = n;
		} else {
			y = n;
        }
	} else {
		byte dig = n % 10;
		n = n / 10;
		Separar(n, x, y);
		if (dig % 2 == 0) {
			x = x * 10 + dig;
		} else {
			y = y * 10 + dig;
        }
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que elimina los digitos pares de un numero
// Ejemplo: EliminarPar(x = 12345) ==> 135

void EliminarPar(Cardinal &x) {
	if (x < 10) {
		if (x % 2 == 0) {
			x = 0;
		}
	} else {
		byte dig = x % 10;
		x = x / 10;
		EliminarPar(x);
		if (dig % 2 == 1) {
			x = x * 10 + dig;
		}
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que elimina los digitos primos de un numero
// Ejemplo: EliminarPrimos(x = 1345247) ==> x = 144

bool EsPrimo(Cardinal x) {
	String primos = "2357";
	return primos.Pos(String(x)) > 0;
}

void EliminarPrimos(Cardinal &x) {
	String primos = "2357";
	if (x < 10) {
		if (EsPrimo(x)) {
			x = 0;
		}
	} else {
		byte dig = x % 10;
		x = x / 10;
		EliminarPrimos(x);
		if (!EsPrimo(dig)) {
			x = x * 10 + dig;
        }
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que invierte un numero
// Ejemplo: Invertir(x = 12345) ==> x = 54321

byte Cantidad_Digitos(Cardinal x) {
	byte cantidad;
	if (x == 0) {
		cantidad = 1;
	} else {
		cantidad = (int)log10(10 * x);
	}
	return cantidad;
}

void Invertir(Cardinal &x) {
	if (x > 9) {
		byte dig = x % 10;
		x = x / 10;
		Invertir(x);
		x = dig * (int)pow(10, Cantidad_Digitos(x)) + x;
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que lleva el mayor de los digitos al final de un numero
// Ejemplo: MoverMayor(x = 15832) ==> x = 15328

void MoverMayor(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else {
		byte dig = x % 10;
		x = x / 10;
		MoverMayor(x);
		if (x % 10 > dig) {
			x = (x / 10) * 100 + dig * 10 + x % 10;
		} else {
			x = x * 10 + dig;
        }
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de d�gitos pares que est�n antes de un impar
// Ejemplo: CantidadPares(x = 23415) ==> 2

byte CantidadPares(Cardinal x) {
	byte cantidad;
	if (x < 10) {
		cantidad = 0;
	} else {
		byte dig = x % 10;
		cantidad = CantidadPares(x / 10);
		if ((dig % 2 != 0) && ((x / 10) % 2 == 0)) {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de digitos de un numero
// Ejemplo: CantidadDigitos(x = 15234) ==> 5

byte CantidadDigitos(Cardinal x) {
	byte cantidad;
	if (x < 10) {
		cantidad = 1;
	} else {
		cantidad = CantidadDigitos(x / 10);
		cantidad++;
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de Digitos pares
// Ejemplo: Cantidad_Pares(x = 16743) ==> 2

byte Cantidad_Pares(Cardinal x) {
	byte cantidad = 0;
	if (x < 10) {
		if (x % 2 == 0) {
			cantidad = 1;
		}
	} else {
		byte dig = x % 10;
		cantidad = Cantidad_Pares(x / 10);
		if (dig % 2 == 0) {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de Digitos impares
// Ejemplo: Cantidad_Pares(x = 16743) ==> 2

byte Cantidad_Impares(Cardinal x) {
	byte cantidad = 0;
	if (x < 10) {
		if (x % 2 != 0) {
			cantidad = 1;
		}
	} else {
		byte dig = x % 10;
		cantidad = Cantidad_Impares(x / 10);
		if (dig % 2 != 0) {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que ordena un numero ascendentemente
// Ejemplo: OrdenarAsc(x = 53124) ==> x = 12345

void Mover_Mayor(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else {
		byte dig = x % 10;
		x = x / 10;
		Mover_Mayor(x);
		if (dig < x % 10) {
			x = (x / 10) * 100 + dig * 10 + x % 10;
		} else {
			x = x * 10 + dig;
        }
	}
}

void OrdenarAsc(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else {
		Mover_Mayor(x);
		byte dig = x % 10;
		x = x / 10;
		OrdenarAsc(x);
		x = x * 10 + dig;
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que ordena un numero descendentemente
// Ejemplo: OrdenarDesc(x = 53124) ==> x = 54321

void Mover_Menor(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else {
		byte dig = x % 10;
		x = x / 10;
		Mover_Menor(x);
		if (dig > x % 10) {
			x = (x / 10) * 100 + dig * 10 + x % 10;
		} else {
			x = x * 10 + dig;
        }
	}
}

void OrdenarDesc(Cardinal &x) {
	if (x < 10) {
		x = x;
	} else {
		Mover_Menor(x);
		byte dig = x % 10;
		x = x / 10;
		OrdenarDesc(x);
		x = x * 10 + dig;
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve el digito menor y mayor de un numero
// Ejemplo: MenorMayor(x = 57134) ==> 17

byte MenorMayor(Cardinal x) {
	byte resultado;
	if (x < 10) {
		resultado = x * 11;
	} else {
		byte dig = x % 10;
		resultado = MenorMayor(x / 10);
		if (dig > resultado % 10) {
			resultado = (resultado / 10) * 10 + dig;
		}
		if (dig < resultado / 10) {
			resultado = dig * 10 + resultado % 10;
		}
    }
	return resultado;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de los digitos pares
// Ejemplo: SumaPares(x = 12345) ==> 6

byte SumaPares(Cardinal x) {
	byte suma = 0;
	if (x < 10) {
		if (x % 2 == 0) {
			suma = x;
		}
	} else {
		byte dig = x % 10;
		suma = SumaPares(x / 10);
		if (dig % 2 == 0) {
			suma = suma + dig;
		}
	}
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de los digitos impares
// Ejemplo: SumaImpares(x = 12345) ==> 9

byte SumaImpares(Cardinal x) {
	byte suma = 0;
	if (x < 10) {
		if (x % 2 != 0) {
			suma = x;
		}
	} else {
		byte dig = x % 10;
		suma = SumaImpares(x / 10);
		if (dig % 2 != 0) {
			suma = suma + dig;
		}
	}
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de digitos primos de un nummero
// Ejemplo: Cantidad_Primos(x = 123457) ==> 4

byte Cantidad_Primos(Cardinal x) {
	byte cantidad = 0;
	if (x < 10) {
		if (EsPrimo(x)) {
			cantidad = 1;
        }
	} else {
		byte dig = x % 10;
		cantidad = Cantidad_Primos(x / 10);
		if (EsPrimo(dig)) {
			cantidad++;
        }
    }
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de digitos primos de un numero
// Ejemplo: SumaPrimos(x = 12345) ==> 10

byte SumaPrimos(Cardinal x) {
	byte suma = 0;
	if (x < 10) {
		if (EsPrimo(x)) {
			suma = x;
		}
	} else {
		byte dig = x % 10;
		suma = SumaPrimos(x / 10);
		if (EsPrimo(dig)) {
			suma = suma + dig;
        }
    }
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la diferencia entre digitos pares e impares
// Ejemplo: Diferencia(x = 123456) ==> 3

short int Diferencia(Cardinal x) {
	short int resultado;
	if (x < 10) {
		if (x % 2 == 0) {
			resultado = x;
		} else {
			resultado = - x;
		}
	} else {
		byte dig = x % 10;
		resultado = Diferencia(x / 10);
		if (dig % 2 == 0) {
			resultado = resultado + dig;
		} else {
			resultado = resultado - dig;
		}
    }
	return resultado;
}
// ---------------------------------------------------------------------------
// Algoritmo que inserta un digito en una posicion de un numero
// Ejemplo: Insertar(x = 12345, pos = 2, dig = 6) ==> x = 126345

void Insertar(Cardinal &x, byte pos, Word dig) {
	byte cant = CantidadDigitos(dig);
	if (x < 10) {
		if (pos == 0) {
			x = (x / 10) * 100 + dig * 10 + x % 10;
		}
		if (pos == 1) {
			x = x * pow(10, cant) + dig;
		}
	} else {
		byte digito = x % 10;
		x = x / 10;
		byte posi = CantidadDigitos(x);
		Insertar(x, pos, dig);
		if ((posi > 1) && (posi == pos)) {
			x = x * pow(10, cant + 1) + dig * 10 + digito;
		} else {
			x = x * 10 + digito;
		}
//		if ((posi > 1) && (posi == pos)) {
//			x = x * 100 + dig * 10 + digito;
//		} else {
//			x = x * 10 + digito;
//		}
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que cambia un digito de un numero por otro digito
// Ejemplo: CambiarDigito(x = 12345, d = 2, n = 7) ==> x = 17345

void CambiarDigito(Cardinal &x, byte digActual, byte digNuevo) {
	if (x < 10) {
		if (x == digActual) {
			x = digNuevo;
		}
	} else {
		byte dig = x % 10;
		x = x / 10;
		CambiarDigito(x, digActual, digNuevo);
		if (dig == digActual) {
			x = x * 10 + digNuevo;
		} else {
			x = x * 10 +dig;
		}
	}
}

void CambiarDigitos(Cardinal &x, Word digActual, Word digNuevo) {
	if (x < 10) {
		if (x == digActual) {
			x = digNuevo;
		}
	} else {
		byte cant = CantidadDigitos(digActual);
		byte cant_2 = CantidadDigitos(digNuevo);
		Word dig = x % (int)pow(10, cant);
		x = x / pow(10, cant);
		CambiarDigitos(x, digActual, digNuevo);
		if (dig == digActual) {
			x = x * pow(10, cant_2) + digNuevo;
		} else {
			x = x * pow(10, cant) + dig;
		}
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la posicion de un digito de un numero
// Ejemplo: Posicion(x = 45736, dig = 7) ==> 3

byte Posicion(Cardinal x, byte digito) {
	byte posicion = 0;
	if (x < 10) {
		if (digito == x) {
			posicion = 1;
        }
	} else {
		byte dig = x % 10;
		posicion = Posicion(x / 10, digito);
		if (dig == digito) {
			posicion = CantidadDigitos(x);
        }
	}
	return posicion;
}
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
