// ---------------------------------------------------------------------------

#ifndef MatricesH
#define MatricesH
// ---------------------------------------------------------------------------
#include <vcl.h>
#include <Vcl.Grids.hpp>

void Llenar_Fila(TStringGrid *A, Word f, Word n, Word k);
void Cargar_Matriz(TStringGrid *A, Word m, Word n);

void Llenar_FilaColumna(TStringGrid *A, Word f, Word n);
void Cargar_Matriz2(TStringGrid *A, Word m, Word n);

void cargarCol(TStringGrid* m, Byte f, Byte c, Cardinal &v);
void cargarTodoFila(TStringGrid* m, Byte f, Byte c, Cardinal &v);

void cargarFil(TStringGrid* m, Byte f, Byte c, Cardinal &v);
void cargarTodoCol(TStringGrid* m, Byte f, Byte c, Cardinal &v);

void aux_sec_inf(TStringGrid* m, Byte f, Byte lc, Byte c, Cardinal &v);
void diag_sec_inf(TStringGrid* m, Byte f, Byte c, Cardinal &v);

void ext_fila(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube);
void ext_col(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube);
void cargar_exterior(TStringGrid* m, int f, int c);

void aux_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v);
void cargar_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v);

void colTriangular2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k);
void filaTriangular2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k);

void aux_matriz2(TStringGrid* m, Byte f, Byte c, Byte lim);
void cargar_matriz2(TStringGrid* m, Byte f, Byte c);

void arriba(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v);
void derecha(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v);
void abajo(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v);
void izquierda(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v);
void caracol(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v);

void anillo(TStringGrid *SG, int a, int b, int n, int prim);
void espiral(TStringGrid *SG, int a, int b, int prim);

void arriba2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v);
void derecha2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v);
void abajo2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v);
void izquierda2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v);
void caracol2(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v);

void abajo3(TStringGrid *v, byte fa, byte fb, byte c, byte &k);
void derecha3(TStringGrid *v, byte ca, byte cb, byte f, byte &k);
void arriba3(TStringGrid *v, byte fa, byte fb, byte c, byte &k);
void izquierda3(TStringGrid *v, byte ca, byte cb, byte f, byte &k);
void cargarCaracol(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k);

void aux_cad(TStringGrid* m, String &cad, Byte f, Byte c);
void cargar_cad(TStringGrid* m, String &cad, Byte c);

void cargarFilCad1(TStringGrid *v, byte c, byte fa, byte fb, String &x);
void cargarColCad1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	String &x);

void cargarCadena2(TStringGrid *v, byte a, byte b, String x);

void cargarCadenaMatrizVector(TStringGrid *v, byte a, byte b, String x);

void aux_dona(TStringGrid* m, Byte f, Byte c, Byte l, Cardinal v);
void dona(TStringGrid* m, Byte f, Byte c, Cardinal v);

void Llenar_Alrededor(TStringGrid *A, Word fa, Word fb, Word ca, Word cb,
	Word n, Word k);
void Cargar_Espiral(TStringGrid *A, Word fa, Word fb);

void aux_frac(TStringGrid* m, Byte f, Byte c, Byte lim, Cardinal& num,
	Cardinal& den);
void cargar_frac(TStringGrid* m, Byte f, Byte c, Cardinal& num, Cardinal& den);

void columnaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k);
void filaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k);

void filSerpiente2(TStringGrid *v, byte c, byte fa, byte fb);
void colSerpiente2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);

void colTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);
void filaTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);

void rellenarFila(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);
void rellenarCol(TStringGrid *v, byte ca, byte cb, byte fa, byte fb);
void cargarCuadrado(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);

void cargarFilD1(TStringGrid *v, byte f, byte ca, byte cb, byte k);
void cargarD1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k);

void secundario(TStringGrid *SG, int f, int n, int k);
void principal(TStringGrid *SG, int nf, int nc, int n);

void cargarDiagonal(TStringGrid *SG, int f, int c, int k, int nf, int nc);
void cargarDiagonales(TStringGrid *SG, int n, int nf, int nc);

void cargarColTri3(TStringGrid *v, byte f, byte ca, byte cb, byte k);
void cargarFilaTri3(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k);

void triangularFila3(TStringGrid *v, byte c, byte m, byte &k);
void triangular3(TStringGrid *v, byte m, byte n, byte &k);

void Cuadrado_Magico(TStringGrid *A, Word m, Word n, Word &f, Word &c);

void Cargar(TStringGrid *A, byte m, byte k, byte &f, byte &c);

int sumatoria(int n);
void cargarColumna(TStringGrid *SG, int col, int n, int k);
void cargarMatriz(TStringGrid *SG, int n, int k);

void aux_serpiente(TStringGrid *m, byte f, byte c, String &cad);
void serpiente_cadena(TStringGrid *m, byte c, String &cad);

void aux_cargar_cols(TStringGrid *m, int f, int c, int v);
void cargar_cols(TStringGrid *m, int f, int c, int v);

void aux_navidad(TStringGrid *m, int f, int ca, int cb);
void navidad(TStringGrid *m, int f, int c);

void aux_matriz(TStringGrid *m, int f, int c, int lim, int v);
void matriz(TStringGrid *m, int f, int c);

void aux_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v);
void diag_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v);

//int sumatoria2(int n);
void cargarColumna2(TStringGrid *m, int col, int n, int &k);
void cargarMatriz2(TStringGrid *m, int n, int &k);

void filSerpiente3(TStringGrid *v, byte c, byte fa, byte fb, Cardinal &val);
void colSerpiente3(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	Cardinal &val);

	void secundario2(TStringGrid *SG, int f, int n, int k);
    void principal2(TStringGrid *SG, int nf, int nc, int n);


	void cargarFilD2(TStringGrid *v, byte f, byte ca, byte cb, byte k);
	void cargarD2(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k);

	void Cargarfila5(TStringGrid *v , Word f, Word c, Word k);
    void CargarMatriz5(TStringGrid *v, Word f, Word c );

#endif
