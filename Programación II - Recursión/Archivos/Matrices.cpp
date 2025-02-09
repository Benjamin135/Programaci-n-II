// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Matrices.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
/* Algoritmo para cargar una matriz por filas m*n   (hip�tesis n-1)

 1   2   3   4
 5   6   7   8
 9   10  11  12
 13  14  15  16
 */

void Llenar_Fila(TStringGrid *A, Word f, Word n, Word k) {
	if (n > 0) {
		Llenar_Fila(A, f, n - 1, k - 1);
		A->Cells[n - 1][f] = k;
	}
}

void Cargar_Matriz(TStringGrid *A, Word m, Word n) {
	if (m > 0) {
		Cargar_Matriz(A, m - 1, n);
		Llenar_Fila(A, m - 1, n, m*n);
	}
}
// ---------------------------------------------------------------------------
/* Algoritmo para cargar una matriz m*n   (hip�tesis m-1, n-1)

 1  2  3  4
 2  2  3  4
 3  3  3  4
 4  4  4  4
 */

void Llenar_FilaColumna(TStringGrid *A, Word f, Word n) {
	if (n > 0) { // caso general
		Llenar_FilaColumna(A, f, n - 1);
		A->Cells[n - 1][f] = f + 1;
		A->Cells[f][n - 1] = f + 1;
	}
}

void Cargar_Matriz2(TStringGrid *A, Word m, Word n) {
	if (m > 0) { // caso general
		Cargar_Matriz2(A, m - 1, n - 1);
		Llenar_FilaColumna(A, m - 1, n);
	}
}

// ---------------------------------------------------------------------------
/* Cargar una matriz por filas

 16  15  14  13
 12  11  10   9
 8   7   6   5
 4   3   2   1
 */

void cargarCol(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		m->Cells[c - 1][f - 1] = v;
		v++;
		cargarCol(m, f, c - 1, v);
	}
}

void cargarTodoFila(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		cargarCol(m, f, c, v);
		cargarTodoFila(m, f - 1, c, v);
	}
}

// ---------------------------------------------------------------------------
/* Cargar una matriz por columnas

 16  12  8  4
 15  11  7  3
 14  10  6  2
 13   9  5  1
 */

void cargarFil(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		m->Cells[c - 1][f - 1] = v;
		v++;
		cargarFil(m, f - 1, c, v);
	}
}

void cargarTodoCol(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		cargarFil(m, f, c, v);
		cargarTodoCol(m, f, c - 1, v);
	}
}

// ---------------------------------------------------------------------------
/* Cargar diagonal secundaria inferior de una matriz

 0  0  0  10
 0  0  9  8
 0  7  6  5
 4  3  2  1
 */

void aux_sec_inf(TStringGrid* m, Byte f, Byte lc, Byte c, Cardinal &v) {
	if (c > lc) {
		Byte fil = f - 1;
		Byte col = c - 1;
		m->Cells[col][fil] = v;
		v++;
		aux_sec_inf(m, f, lc, c - 1, v);
	}
}

void diag_sec_inf(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		Byte lc = c - f;
		aux_sec_inf(m, f, lc, c, v);
		diag_sec_inf(m, f - 1, c, v);
	}
}

// ---------------------------------------------------------------------------
/* Cargar el exterior de una matriz

 1  2  3  4
 5  0  0  5
 4  0  0  6
 3  2  1  7
 */

void ext_fila(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube) {
	if (sube) {
		if (c <= m->ColCount) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_fila(m, f, c + 1, v, sube);
		}
	}
	else {
		if (c > 0) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_fila(m, f, c - 1, v, sube);
		}
	}
}

void ext_col(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube) {
	if (sube) {
		if (f <= m->RowCount) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_col(m, f + 1, c, v, sube);
		}
	}
	else {
		if (f > 1) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_col(m, f - 1, c, v, sube);
		}
	}
}

void cargar_exterior(TStringGrid* m, int f, int c) {
	if (f != -1) {
		Byte i = m->RowCount;
		Byte j = m->ColCount;
		bool subeFila = f == 1;
		bool subeCol = c == 1;
		Cardinal v = 1;
		Byte proxFil, proxCol;
		if (f == 1)
			proxFil = f + 1;
		else
			proxFil = f - 1;
		if (c == 1)
			proxCol = j;
		else
			proxCol = 1;
		ext_fila(m, f, c, v, subeFila);
		ext_col(m, proxFil, proxCol, v, subeCol);
		if (f == m->RowCount)
			cargar_exterior(m, -1, -1);
		else
			cargar_exterior(m, i, j - 1);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz diagonal inferior A(n)

 0  0   0   1
 0  0   3   5
 0  7   9  11
 13 15  17  19
 */

void aux_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		Byte fil = m->RowCount - f;
		Byte col = m->ColCount - c;
		m->Cells[col][fil] = v;
		v += 2;
		aux_matriz1(m, f, c - 1, v);
	}
}

void cargar_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		Byte col = m->ColCount - c + 1;
		aux_matriz1(m, f, col, v);
		cargar_matriz1(m, f - 1, c - 1, v);
	}
}
// ---------------------------------------------------------------------------

void colTriangular2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][fa] = 2 * k++ - 1;
		colTriangular2(v, fa, fb, ca + 1, cb, k);
	}
}

void filaTriangular2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		colTriangular2(v, fa, fb, ca, cb, k);
		filaTriangular2(v, fa + 1, fb, ca - 1, cb, k);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz diagonal superior A(n)

 1  1  2  3
 0  1  2  3
 0  0  1  3
 0  0  0  1
 */

void aux_matriz2(TStringGrid* m, Byte f, Byte c, Byte lim) {
	if (c > lim) {
		Byte fil = m->RowCount - f;
		if (c == lim + 1)
			m->Cells[c - 1][fil] = 1;
		else
			m->Cells[c - 1][fil] = (c - 1);
		aux_matriz2(m, f, c - 1, lim);
	}
}

void cargar_matriz2(TStringGrid* m, Byte f, Byte c) {
	if (f > 0) {
		Byte lim = m->ColCount - c;
		aux_matriz2(m, f, m->ColCount, lim);
		cargar_matriz2(m, f - 1, c - 1);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz caracol A(m*n)

 1    2    3  4
 12   13   14  5
 11   16   15  6
 10    9    8  7
 */

void arriba(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[ca - 1][f - 1] = v;
		v++;
		arriba(m, f, ca + 1, cb, v);
	}
}

void derecha(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fb - 1] = v;
		v++;
		derecha(m, fa, fb - 1, c, v);
	}
}

void abajo(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[cb - 1][f - 1] = v;
		v++;
		abajo(m, f, ca, cb - 1, v);
	}
}

void izquierda(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fa - 1] = v;
		v++;
		izquierda(m, fa + 1, fb, c, v);
	}
}

void caracol(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v) {
	if (fa <= fb && ca <= cb) {
		if (fa == fb && ca == cb)
			m->Cells[fa - 1][ca - 1] = v;
		else {
			arriba(m, fa, ca, cb, v);
			izquierda(m, fa, fb, cb, v);
			abajo(m, fb, ca, cb, v);
			derecha(m, fa, fb, ca, v);
		}
		caracol(m, fa + 1, fb - 1, ca + 1, cb - 1, v);
	}
}
// ---------------------------------------------------------------------------
// Matriz caracol

void anillo(TStringGrid *SG, int a, int b, int n, int prim) {
	if (n > 0) {
		anillo(SG, a, b, n - 1, prim);
		SG->Cells[a + n - 1][a] = prim + n - 1;
		SG->Cells[b][a + n - 1] = prim + (b - a) + n - 1;
		SG->Cells[b - n + 1][b] = prim + 2 * (b - a) + n - 1;
		SG->Cells[a][b - n + 1] = prim + 3 * (b - a) + n - 1;
	}
}

void espiral(TStringGrid *SG, int a, int b, int prim) {
	if (a >= b) {
		if (a == b) {
			SG->Cells[a][a] = prim;
			// SG->Cells[a][b] = prim;
		}
	}
	else {
		espiral(SG, a + 1, b - 1, prim + 4 * (b - a));
		anillo(SG, a, b, b - a, prim);
	}
}

// ---------------------------------------------------------------------------
/* Cargar la matriz caracol A(m*n)

 1   12   11  10
 2   13   16   9
 3   14   15   8
 4    5    6   7
 */

void abajo3(TStringGrid *v, byte fa, byte fb, byte c, byte &k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		v->Cells[c][fa] = k++;
		abajo3(v, fa + 1, fb, c, k);
	}
}

void derecha3(TStringGrid *v, byte ca, byte cb, byte f, byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k++;
		derecha3(v, ca + 1, cb, f, k);
	}
}

void arriba3(TStringGrid *v, byte fa, byte fb, byte c, byte &k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		v->Cells[c][fb] = k++;
		arriba3(v, fa, fb - 1, c, k);
	}
}

void izquierda3(TStringGrid *v, byte ca, byte cb, byte f, byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[cb][f] = k++;
		izquierda3(v, ca, cb - 1, f, k);
	}
}

void cargarCaracol(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
	byte m = fb - fa + 1;
	byte n = cb - ca + 1;
	if (m * n != 0) {
		if (m * n == 1) {
			v->Cells[ca][fa] = k;
		}
		else {
			abajo3(v, fa, fb - 1, ca, k);
			derecha3(v, ca, cb - 1, fb, k);
			arriba3(v, fa + 1, fb, cb, k);
			izquierda3(v, ca + 1, cb, fa, k);
			cargarCaracol(v, fa + 1, fb - 1, ca + 1, cb - 1, k);
		}
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz caracol A(m*n)

 1  1  1  2
 4  5  6  2
 4  8  7  2
 4  3  3  3
 */

void arriba2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[ca - 1][f - 1] = v;
		arriba2(m, f, ca + 1, cb, v);
	}
}

void derecha2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fb - 1] = v;
		derecha2(m, fa, fb - 1, c, v);
	}
}

void abajo2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[cb - 1][f - 1] = v;
		abajo2(m, f, ca, cb - 1, v);
	}
}

void izquierda2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fa - 1] = v;
		izquierda2(m, fa + 1, fb, c, v);
	}
}

void caracol2(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v) {
	if (fa <= fb && ca <= cb) {
		if (fa == fb && ca == cb)
			m->Cells[fa - 1][ca - 1] = v;
		else {
			arriba2(m, fa, ca, cb, v);
			v++;
			izquierda2(m, fa, fb, cb, v);
			v++;
			abajo2(m, fb, ca, cb, v);
			v++;
			derecha2(m, fa, fb, ca, v);
			v++;
		}
		caracol2(m, fa + 1, fb - 1, ca + 1, cb - 1, v);
	}
}
// ---------------------------------------------------------------------------
/* Cargar palabra en una matriz A(n)

 p  r  d  0
 r  a  o  0
 o  m  r  0
 g  a  0  0
 */

void aux_cad(TStringGrid* m, String &cad, Byte f, Byte c) {
	if (f <= m->RowCount && cad.Length() > 0) {
		char x = cad[1];
		cad.Delete(1, 1);
		m->Cells[c - 1][f - 1] = x;
		aux_cad(m, cad, f + 1, c);
	}
}

void cargar_cad(TStringGrid* m, String &cad, Byte c) {
	if (c <= m->ColCount) {
		aux_cad(m, cad, 1, c);
		cargar_cad(m, cad, c + 1);
	}
}
// ---------------------------------------------------------------------------
// Cargar cadena 1

void cargarFilCad1(TStringGrid *v, byte c, byte fa, byte fb, String &x) {
	byte m = fb - fa + 1;
	if (m > 0) {
		if (x != "") {
			v->Cells[c][fa] = x.SubString(1, 1);
			x.Delete(1, 1);
		}
		else {
			v->Cells[c][fa] = "";
		}
		cargarFilCad1(v, c, fa + 1, fb, x);
	}
}

void cargarColCad1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	String &x) {
	byte n = cb - ca + 1;
	if (n > 0) {
		cargarFilCad1(v, ca, fa, fb, x);
		cargarColCad1(v, fa, fb, ca + 1, cb, x);
	}
}
// ---------------------------------------------------------------------------
// Cargar cadena 2

void cargarCadena2(TStringGrid *v, byte a, byte b, String x) {
	byte N = v->ColCount;
	byte n = b - a + 1;
	if (n > 0) {
		if (x != "") {
			v->Cells[a % N][a / N] = String(x[1]);
			cargarCadena2(v, a + 1, b, x.Delete(1, 1));
		}
		else {
			v->Cells[a % N][a / N] = "";
			cargarCadena2(v, a + 1, b, x);
		}
	}
}
// ---------------------------------------------------------------------------
// Cargar cadena 3

void cargarCadenaMatrizVector(TStringGrid *v, byte a, byte b, String x) {
	byte N = v->ColCount;
	byte n = b - a + 1;
	if (n > 0) {
		if (x != "") {
			v->Cells[a % N][a / N] = String(x[1]);
			x.Delete(1, 1);
			cargarCadenaMatrizVector(v, a + 1, b, x);
		}
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz espiral o dona A(m*n)

 1  1  1  1  1
 1  2  2  2  1
 1  2  3  2  1
 1  2  2  2  1
 1  1  1  1  1
 */

void aux_dona(TStringGrid* m, Byte f, Byte c, Byte l, Cardinal v) {
	if (c > l) {
		int nf = m->RowCount;
		int nc = m->RowCount;
		m->Cells[c - 1][f - 1] = v;
		m->Cells[f - 1][c - 1] = v;
		m->Cells[nc - c][nf - f] = v;
		m->Cells[nf - f][nc - c] = v;
		aux_dona(m, f, c - 1, l, v);
	}
}

void dona(TStringGrid* m, Byte f, Byte c, Cardinal v) {
	if (f > m->RowCount / 2) {
		Byte l = m->ColCount - c;
		aux_dona(m, f, c, l, v);
		dona(m, f - 1, c - 1, v + 1);
	}
}
// ---------------------------------------------------------------------------

void rellenarFila(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][fa] = fa + 1;
		v->Cells[ca][fb] = fa + 1;
		rellenarFila(v, fa, fb, ca + 1, cb);
	}
}

void rellenarCol(TStringGrid *v, byte ca, byte cb, byte fa, byte fb) {
	byte m = fb - fa + 1;
	if (m > 0) {
		v->Cells[ca][fa] = ca + 1;
		v->Cells[cb][fa] = ca + 1;
		rellenarCol(v, ca, cb, fa + 1, fb);
	}
}

void cargarCuadrado(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte m = fb - fa + 1;
	byte n = cb - ca + 1;
	if (m * n != 0) {
		if (m * n == 1) {
			v->Cells[ca][fa] = ca + 1;
		}
		else {
			rellenarFila(v, fa, fb, ca, cb);
			rellenarCol(v, ca, cb, fa, fb);
			cargarCuadrado(v, fa + 1, fb - 1, ca + 1, cb - 1);
		}
	}
}

// ---------------------------------------------------------------------------
/* Cargar la matriz espiral o dona A(m*n)

 3  3  3  3  3
 3  2  2  2  3
 3  2  1  2  3
 3  2  2  2  3
 3  3  3  3  3
 */

void Llenar_Alrededor(TStringGrid *A, Word fa, Word fb, Word ca, Word cb,
	Word n, Word k) {
	if (n > 0) {
		Llenar_Alrededor(A, fa, fb, ca, cb, n - 1, k);
		A->Cells[ca + n - 1][fa] = k;
		A->Cells[ca + n - 1][fb] = k;
		A->Cells[ca][fa + n - 1] = k;
		A->Cells[cb][fa + n - 1] = k;
	}
}

void Cargar_Espiral(TStringGrid *A, Word fa, Word fb) {
	Word m = fb - fa + 1;
	if (m > 0) { // primer caso base no hace nada
		if (m == 1) // segundo caso base
				A->Cells[fa][fa] = 1;
		else { // caso general
			Cargar_Espiral(A, fa + 1, fb - 1);
			Llenar_Alrededor(A, fa, fb, fa, fb, m, (m + 1) / 2);
		}
	}
}

// ---------------------------------------------------------------------------
/* Cargar la matriz diagonal superior con fracciones A(m*n)

 8   4     2     1
 0  1/2   1/4   1/8
 0   0   1/16  1/32
 0   0     0   1/64
 */

void aux_frac(TStringGrid* m, Byte f, Byte c, Byte lim, Cardinal& num,
	Cardinal& den) {
	if (c > lim) {
		if (den == 1)
			m->Cells[c - 1][f - 1] = String(num);
		else
			m->Cells[c - 1][f - 1] = String(num) + "/" + String(den);
		if (den > 1)
			den /= 2;
		else if (den == 1)
			num *= 2;
		aux_frac(m, f, c - 1, lim, num, den);
	}
}

void cargar_frac(TStringGrid* m, Byte f, Byte c, Cardinal& num, Cardinal& den) {
	if (f > 0) {
		aux_frac(m, f, m->ColCount, c - 1, num, den);
		cargar_frac(m, f - 1, c - 1, num, den);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz serpiente A(m*n)

 4   3   2   1
 5   6   7   8
 12  11  10  9
 13  14  15  16
 */

void columnaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		if (fa % 2 == 1) {
			v->Cells[ca][fa] = k++;
			columnaSerpiente(v, fa, fb, ca + 1, cb, k);
		}
		else {
			v->Cells[cb][fa] = k++;
			columnaSerpiente(v, fa, fb, ca, cb - 1, k);
		}
	}
}

void filaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
	byte m = fb - fa + 1;
	if (m > 0) {
		columnaSerpiente(v, fa, fb, ca, cb, k);
		filaSerpiente(v, fa + 1, fb, ca, cb, k);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz serpiente A(m*n)

 1   64    81   256
 4   49   100   225
 9   36   121   196
 16   25   144   169
 */

void filSerpiente2(TStringGrid *v, byte c, byte fa, byte fb) {
	byte M = v->RowCount;
	byte m = fb - fa + 1;
	if (m > 0) {
		if (c % 2 == 0) {
			v->Cells[c][fa] = (c * M + (fa + 1)) * (c * M + (fa + 1));
			filSerpiente2(v, c, fa + 1, fb);
		}
		else {
			v->Cells[c][fb] = ((c + 1) * (M) - (fb)) * ((c + 1) * (M) - (fb));
			filSerpiente2(v, c, fa, fb - 1);
		}
	}
}

void colSerpiente2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte n = cb - ca + 1;
	if (n > 0) {
		filSerpiente2(v, ca, fa, fb);
		colSerpiente2(v, fa, fb, ca + 1, cb);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz diagonal A(n)

 1  1  1  1
 0  2  2  2
 0  0  3  3
 0  0  0  4
 */

void colTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][fa] = fa + 1;
		colTriangular1(v, fa, fb, ca + 1, cb);
	}
}

void filaTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte m = fb - fa + 1;
	if (m > 0) {
		colTriangular1(v, fa, fb, ca, cb);
		filaTriangular1(v, fa + 1, fb, ca + 1, cb);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz en forma diagonal A(m*n)

 4  5  6  7
 3  4  5  6
 2  3  4  5
 1  2  3  4
 */

void cargarFilD1(TStringGrid *v, byte f, byte ca, byte cb, byte k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k;
		cargarFilD1(v, f, ca + 1, cb, k + 1);
	}
}

void cargarD1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		cargarFilD1(v, fb, ca, cb, k);
		cargarD1(v, fa, fb - 1, ca, cb, k + 1);
	}
}
// ---------------------------------------------------------------------------

void secundario(TStringGrid *SG, int f, int n, int k) {
	if (n > 0) {
		secundario(SG, f, n - 1, k);
		SG->Cells[n - 1][f] = k + n - 1;
	}
}

void principal(TStringGrid *SG, int nf, int nc, int n) {
	if (n > 0) {
		principal(SG, nf, nc, n - 1);
		secundario(SG, n - 1, nc, nf - n + 1);
	}
}
// ---------------------------------------------------------------------------

void cargarDiagonal(TStringGrid *SG, int f, int c, int k, int nf, int nc) {
	if (f < nf && c < nc) {
		cargarDiagonal(SG, f + 1, c + 1, k, nf, nc);
		SG->Cells[c][f] = k;
	}
}

void cargarDiagonales(TStringGrid *SG, int n, int nf, int nc) {
	if (n > 0) {
		if (n > nf) {
			cargarDiagonal(SG, 0, n - nf, n, nf, nc);
		}
		else {
			cargarDiagonal(SG, nf - n, 0, n, nf, nc);
		}
		cargarDiagonales(SG, n - 1, nf, nc);
	}
}

// ---------------------------------------------------------------------------
/* Cargar la matriz A(m*n)

 4  3  2  1
 3  2  1  1
 2  1  1  1
 1  1  1  1
 */

void cargarColTri3(TStringGrid *v, byte f, byte ca, byte cb, byte k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k;
		if (k == 1) {
			cargarColTri3(v, f, ca + 1, cb, k);
		}
		else {
			cargarColTri3(v, f, ca + 1, cb, k - 1);
		}
	}
}

void cargarFilaTri3(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k)
{
	byte m = fb - fa + 1;
	if (m > 0) {
		cargarColTri3(v, fa, ca, cb, k);
		cargarFilaTri3(v, fa + 1, fb, ca, cb, k - 1);
	}
}
// ---------------------------------------------------------------------------
/* Cargar diagonal superior de una matriz serpiente

 1  7  8  10
 2  6  9  0
 3  5  0  0
 4  0  0  0
 */

void triangularFila3(TStringGrid *v, byte c, byte m, byte &k) {
	if (m > 0) {
		if (c % 2 == 1) {
			v->Cells[c][m - 1] = k++;
			triangularFila3(v, c, m - 1, k);
		}
		else {
			triangularFila3(v, c, m - 1, k);
			v->Cells[c][m - 1] = k++;
		}
	}
}

void triangular3(TStringGrid *v, byte m, byte n, byte &k) {
	if (n > 0) {
		triangular3(v, m + 1, n - 1, k);
		triangularFila3(v, n - 1, m, k);
	}
}
// ---------------------------------------------------------------------------
/* Algoritmo para cargar una matriz en forma de cuadrado m�gico

 17  24   1   8  15
 23   5   7  14  16
 4   6  13  20  22
 10  12  19  21   3
 11  18  25   2   9
 */

void Cuadrado_Magico(TStringGrid *A, Word m, Word n, Word &f, Word &c) {
	if (n == 1) { // primer caso base, coloca el primer dato
		f = 0;
		c = m / 2;
		A->Cells[c][f] = 1;
	}
	else { // caso general
		Cuadrado_Magico(A, m, n - 1, f, c);
		if ((n - 1) % m == 0) // si es multiplo
				f++; // una casilla abajo
		else {
			c++;
			if (c == m)
				c = 0;
			if (f == 0)
				f = m - 1;
			else
				f--;
		}
		A->Cells[c][f] = n;
	}
}
// ---------------------------------------------------------------------------
/* Cargar matriz pregunta de examen

 1   3   6  10
 2   5   9  13
 4   8  12  15
 7  11  14  16
 */

void Cargar(TStringGrid *A, byte m, byte k, byte &f, byte &c) {
	if (k == 1) {
		A->Cells[0][0] = 1;
		f = 0;
		c = 0;
	}
	else {
		Cargar(A, m, k - 1, f, c);
		if (c == m - 1) {
			c = f + 1;
			f = m - 1;
			A->Cells[c][f] = k;
		}
		else if (f == 0) {
			f = c + 1;
			c = 0;
			A->Cells[c][f] = k;
		}
		else {
			c++;
			f--;
			A->Cells[c][f] = k;
		}
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz inferior A(n)

 10  0  0  0
 9  6  0  0
 8  5  3  0
 7  4  2  1
 */

int sumatoria(int n) {
	return n * (n + 1) / 2;
}

void cargarColumna(TStringGrid *SG, int col, int n, int k) {
	if (n > 0) {
		SG->Cells[col][col + n - 1] = sumatoria(k - col) - n + 1;
		cargarColumna(SG, col, n - 1, k);
	}
}

void cargarMatriz(TStringGrid *SG, int n, int k) {
	if (n > 0) {
		cargarMatriz(SG, n - 1, k);
		cargarColumna(SG, n - 1, k - n + 1, k);
	}
}
// ---------------------------------------------------------------------------
/* Cargar cadena forma serpiente    (falla algo)

 p  a  n  0
 r  m  d  0
 o  a  o  0
 g  r  0  0
 */

void aux_serpiente(TStringGrid *m, byte f, byte c, String &cad) {
	if (f <= m->RowCount && cad.Length() > 0) {
		char x = cad[1];
		cad.Delete(1, 1);
		byte col = c - 1;
		byte fil;
		if (c % 2 == 1) {
			fil = f - 1;
		}
		else {
			fil = m->RowCount - f;
		}
		m->Cells[col][fil] = x;
		aux_serpiente(m, f + 1, c, cad);
	}
}

void serpiente_cadena(TStringGrid *m, byte c, String &cad) {
	if (c > 0) {
		serpiente_cadena(m, c - 1, cad);
		aux_serpiente(m, 1, c, cad);
	}
}
// ---------------------------------------------------------------------------
/* Cargar columnas A(n)

 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 */

void aux_cargar_cols(TStringGrid *m, int f, int c, int v) {
	if (f > 0) {
		m->Cells[c - 1][f - 1] = v;
		m->Cells[m->ColCount - c][f - 1] = v;
		aux_cargar_cols(m, f - 1, c, v);
	}
}

void cargar_cols(TStringGrid *m, int f, int c, int v) {
	if (c > m->ColCount / 2) {
		aux_cargar_cols(m, f, c, v);
		cargar_cols(m, f, c - 1, v - 1);
	}
}

// ---------------------------------------------------------------------------
/* Cargar la navidad A(n)

 0  0  1  0  0
 0  1  1  1  0
 1  1  1  1  1
 0  0  1  0  0
 0  0  1  0  0
 */

void aux_navidad(TStringGrid *m, int f, int ca, int cb) {
	if (ca < cb) {
		m->Cells[ca][f - 1] = 1;
		aux_navidad(m, f, ca + 1, cb);
	}
}

void navidad(TStringGrid *m, int f, int c) {
	if (f > 0) {
		if (f > (m->RowCount + 1) / 2) {
			int mitad = m->ColCount / 2;
			m->Cells[mitad][f - 1] = 1;
		}
		else {
			int nc = f * 2 - 1;
			int au = (m->ColCount - nc) / 2;
			int ca = au;
			int cb = au + nc;
			aux_navidad(m, f, ca, cb);
		}
		navidad(m, f - 1, c);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la triangular superior A(n)

 1  2  3  4
 0  1  2  3
 0  0  1  2
 0  0  0  1
 */

void aux_matriz(TStringGrid *m, int f, int c, int lim, int v) {
	if (c > lim) {
		m->Cells[c - 1][f - 1] = v;
		aux_matriz(m, f, c - 1, lim, v - 1);
	}
}

void matriz(TStringGrid *m, int f, int c) {
	if (f > 0) {
		int v = m->ColCount - f + 1;
		int lim = m->ColCount - v;
		aux_matriz(m, f, c, lim, v);
		matriz(m, f - 1, c);
	}
}

// ---------------------------------------------------------------------------
/* Escribir procesos para cargar una matriz de la siguiente forma:

 10 0  0  0
 9  8  0  0
 7  6  5  0
 4  3  2  1
 */

void aux_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		Byte fil = f - 1;
		Byte col = c - 1;
		m->Cells[col][fil] = v;
		v++;
		aux_sec_inf2(m, f, c - 1, v);
	}
}

void diag_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		aux_sec_inf2(m, f, c, v);
		diag_sec_inf2(m, f - 1, c - 1, v);
	}
}
// ---------------------------------------------------------------------------
/* Escribir procesos para cargar una matriz de la siguiente forma:

 1  0  0  0
 2  5  0  0                      // no funciona
 3  6  8  0
 4  7  9  10
 */

/* int sumatoria2(int n) {
 return n * (n + 1) / 2;
 } */

void cargarColumna2(TStringGrid *m, int col, int n, int &k) {
	if (n > 0) {
		// m->Cells[col][col + n - 1] = sumatoria2(k - col) - n + 1;
		m->Cells[col][col + n - 1] = k++;
		cargarColumna2(m, col, n - 1, k);
	}
}

void cargarMatriz2(TStringGrid *m, int n, int &k) {
	if (n > 0) {
		cargarMatriz2(m, n - 1, k);
		cargarColumna2(m, n - 1, k - n + 1, k);
	}
}
// ---------------------------------------------------------------------------
/* Cargar la matriz serpiente A(m*n)

 1   8    9   16
 2   7   10   15
 3   6   11   14
 4   5   12   13
 */

void filSerpiente3(TStringGrid *v, byte c, byte fa, byte fb, Cardinal &val) {
	byte m = fb - fa + 1;
	if (m > 0) {
		if (c % 2 == 0) {
			v->Cells[c][fa] = val++;
			filSerpiente3(v, c, fa + 1, fb, val);
		}
		else {
			v->Cells[c][fb] = val++;
			filSerpiente3(v, c, fa, fb - 1, val);
		}
	}
}

void colSerpiente3(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	Cardinal &val) {
	byte n = cb - ca + 1;
	if (n > 0) {
		filSerpiente3(v, ca, fa, fb, val);
		colSerpiente3(v, fa, fb, ca + 1, cb, val);
	}
}

// ---------------------------------------------------------------------------
/* Cargar la matriz en forma diagonal A(m*n)

 4  5  6  7
 3  4  5  6
 2  3  4  5
 1  2  3  4
 */

void cargarFilD2(TStringGrid *v, byte f, byte ca, byte cb, byte k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k;
		cargarFilD2(v, f, ca + 1, cb, k + 1);
	}
}

void cargarD2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		cargarFilD2(v, fb, ca, cb, k);
		cargarD2(v, fa, fb - 1, ca, cb, k + 1);
	}
}

// ---------------------------------------------------------------------------

void secundario2(TStringGrid *SG, int f, int n, int k) {
	if (n > 0) {
		secundario2(SG, f, n - 1, k);
		SG->Cells[n - 1][f] = k + n - 1;
	}
}

void principal2(TStringGrid *SG, int nf, int nc, int n) {
	if (n > 0) {
		principal2(SG, nf, nc, n - 1);
		secundario2(SG, n - 1, nc, nf - n + 1);
	}
}

//----------------------------------------------------------------------------

void Cargarfila5(TStringGrid *v , Word f, Word c, Word k)
{
 if (f>0) {
  Cargarfila5(v,f-1,c,k+1);
   v->Cells[c-1][f-1]=k;
 }
}


void CargarMatriz5(TStringGrid *v, Word f, Word c )
{
	   if (c >0) {
	   CargarMatriz5(v,f,c-1);
	   Cargarfila5(v,f,c,c);
	}
}
// ---------------------------------------------------------------------------
