// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Vectores.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

/* Escribir un proceso para invertir una parte de un vector
 (la parte comprendida entre a y b)

 Ej. v[2,5,65,23,45,2,13,45]
 Invetir (v, 2, 6)  ==>     v[2,5, 13, 2, 45, 23, 65, 45] */

void Invertir_Vector(TStringGrid *v, Word a, Word b) {
	Word n;
	String x;
	n = b - a + 1;
	if (n > 1) {
		Invertir_Vector(v, a + 1, b - 1);
		x = v->Cells[b][0];
		v->Cells[b][0] = v->Cells[a][0];
		v->Cells[a][0] = x;
	}
}
// ----------------------------------------------------------------------------

void invertir(TStringGrid *v, byte a, byte b) {
	byte n = b - a + 1;
	if (n > 1) {
		String va = v->Cells[a][0];
		String vb = v->Cells[b][0];
		v->Cells[a][0] = vb;
		v->Cells[b][0] = va;
		invertir(v, a + 1, b - 1);
	}
}
// ---------------------------------------------------------------------------
// Escribir un proceso para ordenar un vector. Con el algoritmo InsertionSort

void auxInsertionSort(TStringGrid* v, Cardinal j) {
	if (j <= 0) {

	}
	else {
		Cardinal vj = StrToInt(v->Cells[j][0]);
		Cardinal vj1 = StrToInt(v->Cells[j - 1][0]);
		if (vj < vj1) { // (vj > vj1)
			String aux = v->Cells[j][0];
			v->Cells[j][0] = v->Cells[j - 1][0];
			v->Cells[j - 1][0] = aux;
			auxInsertionSort(v, j - 1);
		}
	}
}

void InsertionSort(TStringGrid* v, Cardinal i) {
	Byte n = v->ColCount;
	if (i >= n) {

	}
	else {
		Byte j = i;
		auxInsertionSort(v, j);
		InsertionSort(v, i + 1);
	}
}
// ---------------------------------------------------------------------------
// Escribir un proceso para ordenar un vector. Con el algoritmo QuickSort

void intercambiar(TStringGrid *A, int a, int b) {
	String aux = A->Cells[a][0];
	A->Cells[a][0] = A->Cells[b][0];
	A->Cells[b][0] = aux;
}

int pivotear(TStringGrid *A, int a, int b, bool sentido) {
	if (a == b) {
		return a;
	}
	else {
		if (StrToInt(A->Cells[a][0]) > StrToInt(A->Cells[b][0])) {
			intercambiar(A, a, b);
			sentido != sentido;
		}
		if (sentido) {
			a++;
		}
		else {
			b--;
		}
		return pivotear(A, a, b, sentido);
	}
}

void quickSort(TStringGrid *A, int a, int b) {
	if (a < b) {
		int p = pivotear(A, a, b, true);
		quickSort(A, a, p - 1);
		quickSort(A, p + 1, b);
	}
}

// ---------------------------------------------------------------------------
/*
 Cardinal auxSerie1(TStringGrid* v, Cardinal n) {
 Cardinal t;
 if (n == 1)
 t = 2;
 else {
 if (n % 2 == 0)
 t = auxSerie1(v, n - 1) + ((n - 1) * 2);
 else
 t = auxSerie1(v, n - 1) * ((n - 1) * 2);
 }
 v->Cells[n - 1][0] = t;
 return t;
 }

 void cargarSerie1(TStringGrid* v, int n) {
 auxSerie1(v, n);
 } */

// Cargar la siguiente Serie: 2, 4, 16, 22, 176, 186, ...

Cardinal auxSerie1(Cardinal n) {
	Cardinal t;
	if (n == 1)
		t = 2;
	else {
		if (n % 2 == 0)
			t = auxSerie1(n - 1) + ((n - 1) * 2);
		else
			t = auxSerie1(n - 1) * ((n - 1) * 2);
	}
	return t;
}

void cargarSerie1(TStringGrid* v, int n) {
	if (n == 1) {
		Cardinal termino = auxSerie1(1);
		v->Cells[0][0] = termino;
	}
	else {
		Cardinal termino = auxSerie1(n);
		v->Cells[n - 1][0] = termino;
		cargarSerie1(v, n - 1);
	}
}

// ---------------------------------------------------------------------------
// Verificar si un vector esta ordenado ascendentemente

bool Verificar_Orden(TStringGrid* v, int n) {
	bool x;
	if (n == 1) {
		x = true;
	}
	else {
		String sa = v->Cells[n - 2][0];
		String sb = v->Cells[n - 1][0];
		Cardinal a = StrToInt(sa);
		Cardinal b = StrToInt(sb);
		if (a > b)
			x = false;
		else
			x = Verificar_Orden(v, n - 1);
	}
	return x;
}

// ---------------------------------------------------------------------------
// Sumar los digitos de un vector (no importa si es cadena)

Cardinal auxSumaDigitos(String cad) {
	Cardinal s = 0;
	if (cad.Length() > 0) {
		char c = cad[1];
		if (c >= '0' && c <= '9') {
			s += (c - 48);
		}
		cad.Delete(1, 1);
		s += auxSumaDigitos(cad);
	}
	return s;
}

Cardinal sumaDigitos(TStringGrid* v, Byte n) {
	Cardinal s = 0;
	if (n > 0) {
		String cad = v->Cells[n - 1][0];
		s = auxSumaDigitos(cad);
		s += sumaDigitos(v, n - 1);
	}
	return s;
}

// ---------------------------------------------------------------------------
// Cargar en orden los caracteres de una cadena

Cardinal posMayor(String cad) {
	Cardinal p;
	Word n = cad.Length();
	if (n == 1) {
		p = 1;
	}
	else {
		char c = cad[n];
		cad.Delete(n, 1);
		p = posMayor(cad);
		if (c > cad[p])
			p = n;
	}
	return p;
}

void cargarOrdAsc(TStringGrid* v, String cad) {
	if (cad.Length() > 0) {
		Cardinal posMay = posMayor(cad);
		char c = cad[posMay];
		v->Cells[cad.Length() - 1][0] = c;
		cad.Delete(posMay, 1);
		cargarOrdAsc(v, cad);
	}
}

// ---------------------------------------------------------------------------
// Ordenar un vector por el m�todo de la burbuja
// Forma Descendente

void burbujear(TStringGrid* v, Byte n) {
	if (n > 1) {
		burbujear(v, n - 1);
		Cardinal izq = StrToInt(v->Cells[n - 2][0]);
		Cardinal der = StrToInt(v->Cells[n - 1][0]);
		if (izq < der) {
			v->Cells[n - 2][0] = der;
			v->Cells[n - 1][0] = izq;
		}
	}
}

void ord_burbuja(TStringGrid* v, Byte n) {
	if (n > 0) {
		burbujear(v, n);
		ord_burbuja(v, n - 1);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo de ordenamiento BubbleSort
// Forma Ascendente

void Burbujear(TStringGrid *v, Word n) {
	if (n > 1) {
		Burbujear(v, n - 1);
		if (StrToInt(v->Cells[n - 1][0]) < StrToInt(v->Cells[n - 2][0])) {
			String x = v->Cells[n - 1][0];
			v->Cells[n - 1][0] = v->Cells[n - 2][0];
			v->Cells[n - 2][0] = x;
		}
	}
}

void BubbleSort(TStringGrid *v, Word n) {
	if (n > 1) {
		Burbujear(v, n);
		BubbleSort(v, n - 1);
	}
}
// ---------------------------------------------------------------------------
// Forma Ascendente

void swap(TStringGrid *SG, int a, int b) {
	String aux = SG->Cells[a][0];
	SG->Cells[a][0] = SG->Cells[b][0];
	SG->Cells[b][0] = aux;
}

void burbujear1(TStringGrid *SG, int n) {
	if (n > 1) {
		burbujear1(SG, n - 1);
		if (StrToInt(SG->Cells[n - 2][0]) > StrToInt(SG->Cells[n - 1][0])) {
			swap(SG, n - 2, n - 1);
		}
	}
}

void bubbleSort(TStringGrid *SG, int n) {
	if (n > 1) {
		burbujear1(SG, n);
		bubbleSort(SG, n - 1);
	}
}

// ---------------------------------------------------------------------------
/* Insertar un vector2 dentro de otro vector1

 v1 -> 1, 2, 3, 4, 5
 v2 -> 6, 7
 pos -> 2

 v1 -> 1, 2, 6, 7, 3, 4, 5
 */

void recorrer(TStringGrid* v, Byte p, Byte n) {
	if (p < n) {
		v->Cells[n][0] = v->Cells[n - 1][0];
		recorrer(v, p, n - 1);
	}
}

void insertar_aux(TStringGrid* v2, TStringGrid* v1, Byte p, Byte i) {
	if (i < v2->ColCount) {
		v1->ColCount = v1->ColCount + 1;
		recorrer(v1, p, v1->ColCount);
		v1->Cells[p][0] = v2->Cells[i][0];
		insertar_aux(v2, v1, p + 1, i + 1);
	}
}

void insertar(TStringGrid* v2, TStringGrid* v1, Byte p) {
	insertar_aux(v2, v1, p, 0);
}
// ---------------------------------------------------------------------------
// Cargar palabras de una cadena en un vector

void cargar_frase(String cad, TStringGrid* v) {
	if (cad.Length() > 0) {
		Byte pos = cad.Pos(" ");
		if (pos == 0)
			pos = cad.Length() + 1;
		String pal = cad.SubString(1, pos - 1);
		cad.Delete(1, pos);
		Cardinal n = v->ColCount;
		v->Cells[n - 1][0] = pal;
		v->ColCount += 1;
		cargar_frase(cad, v);
	}
}
// ---------------------------------------------------------------------------

void cargarVectorCadena(TStringGrid *v, byte n, String x) {
	byte nx = x.Length();
	if (n > 0) {
		int p = x.LastDelimiter(" ");
		String pal = x.SubString(p + 1, nx - p);
		x.SetLength(p - 1);
		v->Cells[n - 1][0] = pal;
		cargarVectorCadena(v, n - 1, x);
	}
}
// ---------------------------------------------------------------------------
// Eliminar un elemento de un vector

void eliminar(TStringGrid* v, Cardinal p) {
	if (p < v->ColCount) {
		v->Cells[p][0] = v->Cells[p + 1][0];
		eliminar(v, p + 1);
	}
}

void eliminar_elemento(TStringGrid* v, Cardinal z, Cardinal n) {
	if (n > 0) {
		Cardinal num = StrToInt(v->Cells[n - 1][0]);
		if (num == z) {
			eliminar(v, n - 1);
			v->ColCount -= 1;
		}
		else {
			eliminar_elemento(v, z, n - 1);
		}
	}
}
// ---------------------------------------------------------------------------
// Cargar las vocales de una cadena en un vector

String vocales(String cad) {
	String r;
	if (cad.Length() == 0)
		r = "";
	else {
		String alf = "aeiouAEIOU";
		char c = cad[1];
		cad.Delete(1, 1);
		Byte pos = alf.Pos(c);
		if (pos > 0)
			r = c;
		r += vocales(cad);
	}
	return r;
}

void cargar_vocales(String cad, TStringGrid* v) {
	if (cad.Length() == 0)
		v->ColCount--;
	else {
		Byte pos = cad.Pos(" ");
		if (pos == 0)
			pos = cad.Length() + 1;
		String pal = cad.SubString(0, pos - 1);
		cad.Delete(1, pos);
		String voc = vocales(pal);
		Cardinal n = v->ColCount;
		v->Cells[n - 1][0] = voc;
		v->ColCount++;
		cargar_vocales(cad, v);
	}
}
// ---------------------------------------------------------------------------
// Cargar vector y su frecuencia

Cardinal frec(String cad, char c) {
	Cardinal f;
	if (cad.Length() == 0)
		f = 0;
	else {
		char x = cad[1];
		cad.Delete(1, 1);
		if (x == c)
			f = 1 + frec(cad, c);
		else
			f = frec(cad, c);
	}
	return f;
}

void cargar_frec(String cad, TStringGrid* vc, TStringGrid* vf, Cardinal n) {
	if (n > 0) {
		char c = cad[n];
		Cardinal f = frec(cad, c);
		vc->Cells[n - 1][0] = c;
		vf->Cells[n - 1][0] = f;
		cargar_frec(cad, vc, vf, n - 1);
	}
}
// ---------------------------------------------------------------------------
// Suma de elementos pares en un vector

Cardinal sumaPares(TStringGrid *v, byte n) {
	Cardinal s;
	if (n == 1) {
		s = StrToInt(v->Cells[0][0]);
		if (s % 2 == 1) {
			s = 0;
		}
	}
	else {
		s = sumaPares(v, n - 1);
		byte k = StrToInt(v->Cells[n - 1][0]);
		if (k % 2 == 0) {
			s += k;
		}
	}
	return s;
}
// ---------------------------------------------------------------------------
// Cargar un vector con los digitos menores a 100 de un n�mero

void cargarVector100(TStringGrid *v, byte n, Cardinal x) {
	if (n > 0) {
		v->Cells[n - 1][0] = x % 100;
		cargarVector100(v, n - 1, x / 100);
	}
}
// ---------------------------------------------------------------------------
// Devolver una cadena con los n�meros invertidos de un vector

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

String generarCadenaNroInv(TStringGrid *v, byte n) {
	String s;
	if (n > 0) {
		String e = v->Cells[n - 1][0];
		Invertir(e);
		s = generarCadenaNroInv(v, n - 1) + e;
	}
	return s;
}
// ---------------------------------------------------------------------------

String GenerarCadenaNroInv(TStringGrid *v, byte a, byte b) {
	String x;
	byte n = b - a + 1;
	if (n < 1) {
		x = "";
	}
	else {
		x = v->Cells[a][0];
		Invertir(x);
		x = x + GenerarCadenaNroInv(v, a + 1, b);
	}
	return x;
}
// ---------------------------------------------------------------------------
// Cargar la siguiente serie en un vector: 2, 4, 16, 22, 176, 186, ...

Cardinal CargarSerie(TStringGrid *v, byte n) {
	Cardinal t;
	if (n < 2) {
		t = n * 2;
	}
	else {
		t = CargarSerie(v, n - 1);
		if (n % 2 == 0) {
			t += (n - 1)*2;
		}
		else {
			t *= (n - 1)*2;
		}
	}

	if (n > 0) {
		v->Cells[n - 1][0] = t;
	}
	return t;
}
// ---------------------------------------------------------------------------
// Cargar la siguiente serie en un vector: 0, 1, 2, 3, 6, 7, 14, 15, 30, 31, ...

void cargarSerie(TStringGrid *A, int n) {
	if (n < 3) {
		A->Cells[0][0] = 0;
		if (n == 2) {
			A->Cells[1][0] = 1;
		}
	}
	else {
		cargarSerie(A, n - 1);
		if (n % 2 == 0) {
			A->Cells[n - 1][0] = StrToInt(A->Cells[n - 2][0]) + 1;
		}
		else {
			A->Cells[n - 1][0] = StrToInt(A->Cells[n - 2][0]) * 2;
		}
	}
}

// ---------------------------------------------------------------------------
// Suma de los elementos de un vector

Cardinal suma(TStringGrid *v, byte n) {
	Cardinal s = 0;
	if (n > 0) {
		s = StrToInt(v->Cells[n - 1][0]);
		s += suma(v, n - 1);
	}
	return s;
}
// ---------------------------------------------------------------------------

Word Sumar_Vectores(TStringGrid *v, Word n) {
	Word resultado;
	if (n == 0) {
		resultado = 0;
	}
	else {
		resultado = Sumar_Vectores(v, n - 1);
		resultado = resultado + StrToInt(v->Cells[n - 1][0]);
	}
	return resultado;
}

// ---------------------------------------------------------------------------
// Cargar caracteres de una cadena en un vector

void Cargar_Cadena(TStringGrid *v, byte n, String cad) {
	if (n > 0) {
		v->Cells[n - 1][0] = cad[n];
		Cargar_Cadena(v, n - 1, cad);
	}
}
// ---------------------------------------------------------------------------

void cargarConCadena(String cadena, TStringGrid *SG) {
	if (cadena != "") {
		String recortado = cadena.SubString(1, cadena.Length() - 1);
		cargarConCadena(recortado, SG);
		SG->Cells[cadena.Length() - 1][0] = String(cadena[cadena.Length()]);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo de busqueda binaria  (hip+otesis k=n/2)
// Algo falla

bool Busqueda_Binaria(TStringGrid *v, int x, Word a, Word b) {
	bool resultado;
	Word n = b - a + 1;
	if (n == 0) { // primer caso base
		resultado = false;
	}
	else if (n == 1) { // segundo caso base
		if (x == StrToInt(v->Cells[a][0])) {
			resultado = true;
		}
		else {
			resultado = false;
		}
	}
	else { // caso general
		byte c = (a + b) / 2; // calculamos la posici�n de la casilla c
		if (StrToInt(v->Cells[c][0]) == x) {
			resultado = true;
		}
		else if (x < StrToInt(v->Cells[c][0])) {
			resultado = Busqueda_Binaria(v, x, a, c - 1);
			// busca en la mitad izquierda
		}
		else {
			resultado = Busqueda_Binaria(v, x, c + 1, b);
			// busca en la mitad derecha
		}
	}
	return resultado;
}

// ---------------------------------------------------------------------------
/* Escribir un proceso que cargue un vector con los digitos de un n�mero,
 pero que quede ordenado. (ojo, no debe ordenar el vector)

 Ej: CargarOrden(82731, v, n);
 v[1, 2, 3, 7, 8], n = 5
 */
void Insertar(TStringGrid *v, byte &n, byte x) {
	if (n == 0) {
		v->Cells[0][0] = x;
		n = 1;
	}
	else {
		if (x >= v->Cells[n - 1][0]) {
			v->Cells[n][0] = x;
			n++;
		}
		else {
			String z = v->Cells[n - 1][0];
			n--;
			Insertar(v, n, x);
			v->Cells[n][0] = z;
			n++;
		}
	}
}

void CargarOrden(Cardinal x, TStringGrid *v, byte &n) {
	if (x < 10) {
		v->Cells[0][0] = x;
		n = 1;
	}
	else {
		CargarOrden(x / 10, v, n);
		Insertar(v, n, x % 10);
	}
}
// ---------------------------------------------------------------------------
// Eliminar vocales de una palabra y cargarlas en un vector

bool esVocal(wchar_t z) {
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

void cargar_palabras_sin_vocales(TStringGrid *v, String cad) {
	String pal;
	byte p, col, len;
	cad = cad.Trim();
	len = cad.Length();
	if (len > 1) {
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p + 1, len - p);
		cad.Delete(p + 1, len - p);
		cargar_palabras_sin_vocales(v, cad);
		eliminarVocales(pal);
		if (pal != "") {
			col = v->ColCount;
			v->Cells[col - 1][0] = pal;
			v->ColCount++;
		}
	}
	else {
		if (len == 1 && !esVocal(cad[1])) {
			v->Cells[0][0] = cad;
			v->ColCount++;
		}
	}
}
// ---------------------------------------------------------------------------
// Sumar los digitos de una cadena y cargarlos en un vector

Cardinal cargar_numero_retornar_suma(TStringGrid *v, String cad) {
	String pal;
	byte p, len, col;
	Cardinal sum;
	cad = cad.Trim();
	len = cad.Length();
	if (len > 1) {
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p + 1, len - p);
		cad.Delete(p + 1, len - p);
		sum = cargar_numero_retornar_suma(v, cad);
		sum = sum + StrToInt(pal);

		col = v->ColCount;
		v->Cells[col - 1][0] = pal;
		v->ColCount++;
	}
	else {
		if (len == 1) {
			sum = StrToInt(cad);
			v->Cells[0][0] = cad;
		}
		else {
			sum = 0;
		}
	}
	return sum;
}
// ---------------------------------------------------------------------------
// Construir una cadena con la ultima letras de cada palabra cargada en un vector

String construir_con_ultima_letra(TStringGrid *v, int dim) {
	String pal, cad;
	byte len_pal;
	if (dim > 1) {
		pal = v->Cells[dim - 1][0];
		len_pal = pal.Length();

		cad = construir_con_ultima_letra(v, dim - 1);
		cad = cad + pal[len_pal];
	}
	else {
		pal = v->Cells[0][0];
		len_pal = pal.Length();
		cad = pal[len_pal];
	}
	return cad;
}
// ---------------------------------------------------------------------------
// Cargar palabra de manera invertida al vector

bool EsLetra(char z) {
	AnsiString letras =
		"abcdefghijklmn�opqrstuvwxyzABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	return letras.Pos(z) > 0;
}

void cargar_inverso_con_letras(TStringGrid *v, String cad) {
	char caracter;
	int len;
	byte col;
	len = cad.Length();
	if (len > 1) {
		caracter = cad[len];
		cad.Delete(len, 1);
		col = v->ColCount;
		if (EsLetra(caracter) > 0) {
			v->Cells[col - 1][0] = caracter;
			v->ColCount++;
		}
		cargar_inverso_con_letras(v, cad);
	}
	else {
		col = v->ColCount;
		if (EsLetra(cad[1]) > 0) {
			v->Cells[col - 1][0] = cad;
		}
		else {
			v->ColCount--;
		}
	}
}
// ---------------------------------------------------------------------------

long generar_num(TStringGrid *v, byte n) {
	long x;
	if (n == 1) {
		x = StrToInt(v->Cells[n - 1][0]);
	}
	else {
		long num = StrToInt(v->Cells[n - 1][0]);
		long len;
		if (num == 0) {
			len = 1;
		}
		else {
			len = log10(num) + 1;
		}
		x = generar_num(v, n - 1);
		x = x * pow(10, len) + num;
	}
	return x;
}

// ---------------------------------------------------------------------------

void eliminar2(TStringGrid* v, byte m, Cardinal p) {
	if (p < v->ColCount) {
		v->Cells[p][0] = v->Cells[p + m][0];
		eliminar2(v, m, p + 1);
	}
}

void eliminar_elemento2(TStringGrid* v, Cardinal z, Cardinal n) {
	if (n > 0) {
		Cardinal num = StrToInt(v->Cells[n - 1][0]);
		if (num == z) {
			// eliminar2(v, n - 1);
			v->ColCount -= 1;
		}
		else {
			eliminar_elemento2(v, z, n - 1);
		}
	}
}
// ---------------------------------------------------------------------------

Cardinal Suma_Pares(TStringGrid* v, byte n) {
	Cardinal suma = 0;
	byte i = 0;
	while (i < n) {
		Cardinal digito = StrToInt(v->Cells[i][0]);
		if (digito % 2 == 0) {
			suma = suma + digito;
		}
		i++;
	}
	return suma;
}

// ---------------------------------------------------------------------------

Cardinal Suma_Pares2(TStringGrid* v, byte n) {
	Cardinal suma = 0;
	if (n > 0) {
		suma = suma + Suma_Pares2(v, n - 1);
		Cardinal digito = StrToInt(v->Cells[n - 1][0]);
		if (digito % 2 == 0) {
			suma = suma + digito;
		}
	}
	return suma;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void InsertionSort2(TStringGrid* v, byte n) {
	byte i,j;
	i = 0;
	while (i < n) {
		j = 1;
		byte a = StrToInt(v->Cells[j][0]);
		byte b = StrToInt(v->Cells[j - 1][0]);
		while (a < b){
			String aux = v->Cells[j][0];
			v->Cells[j][0] = v->Cells[j - 1][0];
			v->Cells[j - 1][0] = aux;
			j--;
		}
		i++;
	}

}

// ---------------------------------------------------------------------------
