//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matrices.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Algoritmo que carga una matriz por filas de izquierda a derecha
/*
	 1  2  3  4
	 5  6  7  8
	 9 10 11 12
	13 14 15 16
*/

void LlenarFila(TStringGrid *A, byte m, byte n, byte num) {
	if (n > 0) {
		LlenarFila(A, m, n - 1, num - 1);
		A->Cells[n - 1][m] = num;
	}
}

void CargarFilas(TStringGrid *A, byte m, byte n) {
	if (m > 0) {
		CargarFilas(A, m - 1, n);
		LlenarFila(A, m - 1, n, m * n);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz por filas de derecha a izquierda
/*
	4  3  2  1
	8  7  6  5
	12 11 10 9
	16 15 14 13
*/

void Llenar_HDI(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
		Llenar_HDI(v, row, col - 1, serie);
    }
}

void Matriz_DIAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HDI(M, row, col, serie);
	} else {
		Matriz_DIAB(M, row - 1, col, serie);
		Llenar_HDI(M, row, col, serie);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz por filas de izquierda a derecha
/*
	 1  2  3  4
	 5  6  7  8
	 9 10 11 12
	13 14 15 16
*/

void Llenar_HID(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_HID(v, row, col - 1, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	}
}

void Matriz_IDAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HID(M, row, col, serie);
	} else {
		Matriz_IDAB(M, row - 1, col, serie);
		Llenar_HID(M, row, col, serie);
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz por columnas de arriba a abajo
/*
	 1 5 9  13
	 2 6 10 14
	 3 7 11 15
	 4 8 12 16
*/

void Llenar_VAB(TStringGrid *v, byte row, byte col, byte &serie) {
	if (row == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_VAB(v, row - 1, col, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
    }
}

void Matriz_ABID(TStringGrid *M, byte row, byte col, byte &serie) {
	if (col == 1) {
		Llenar_VAB(M, row, col, serie);
	} else {
		Matriz_ABID(M, row, col - 1, serie);
		Llenar_VAB(M, row, col, serie);
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz por columnas de arriba a abajo
/*
	 1 5 9  13
	 2 6 10 14
	 3 7 11 15
	 4 8 12 16
*/

void Llenar_VBA(TStringGrid *v, byte row, byte col, byte &serie) {
	if (row == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
		Llenar_VBA(v, row - 1, col, serie);
	}
}

void Matriz_BADI(TStringGrid *M, byte row, byte col, byte &serie) {
	if (col == 1) {
		Llenar_VBA(M, row, col, serie);
	} else {
		Llenar_VBA(M, row, col, serie);
		Matriz_BADI(M, row, col - 1, serie);
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz en serpiente de izq a der
/*
	 1   2   3   4
	 8   7   6   5
	 9   10  11  12
	 16  15  14  13
*/

void Matriz_Serpiente_IDDI_AB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HID(M, row, col, serie);
	} else {
		Matriz_Serpiente_IDDI_AB(M, row - 1, col, serie);
		if (row % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
        }
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz en serpiente de izq a der
/*
	 13 14 15 16
	 12 11 10 9
	 5  6  7  8
	 4  3  2  1
*/

void Matriz_Serpiente_DIID_BA(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		if ((col - row) % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
		}
	} else {
		if ((col - row) % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
		}
		Matriz_Serpiente_DIID_BA(M, row - 1, col, serie);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz triangular de izq a der
/*
	 1  2 3 4
	 5  6 7 0
	 8  9 0 0
	 10 0 0 0
*/

void Triangular_SI_IDAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HID(M, row, col, serie);
	} else {
		Triangular_SI_IDAB(M, row - 1, col, serie);
		Llenar_HID(M, row, col - (row - 1), serie);
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz triangular de der a izq
/*
	 4 3 2 1
	 0 7 6 5
	 0 0 9 8
	 0 0 0 10
*/

void Llenar_HDI_Diagonal(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col <= row) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
		Llenar_HDI_Diagonal(v, row, col - 1, serie);
	}
}

void Triangular_SD_DIAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row <= 1) {
		Llenar_HDI_Diagonal(M, row, col, serie);
	} else {
    	Triangular_SD_DIAB(M, row - 1, col, serie);
		Llenar_HDI_Diagonal(M, row, col, serie);
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que carga una matriz triangular de der a izq
/*
	 1 5 8 10
	 2 6 9 0
	 3 7 0 0
	 4 0 0 0
*/

void Triangular_SI_ABID(TStringGrid *M, byte row, byte col, byte &serie) {
	if (col <= 1) {
		Llenar_VAB(M, row, col, serie);
	} else {
		Triangular_SI_ABID(M, row, col - 1, serie);
		Llenar_VAB(M, row - (col - 1), col, serie);
    }
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
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
