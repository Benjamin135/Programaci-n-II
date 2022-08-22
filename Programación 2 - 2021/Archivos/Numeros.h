// ---------------------------------------------------------------------------

#ifndef NumerosH
#define NumerosH
// ---------------------------------------------------------------------------
#include <vcl.h>

byte SumaDigitos(Cardinal x);

byte Mayor(Cardinal x);

void EliminarZ(Cardinal &x, byte z);

AnsiString RepetirDigito(Cardinal x, Cardinal v);
AnsiString Literal(Cardinal x);

Cardinal Rotar(Cardinal x);
void Rotar_2(Cardinal &x);

Cardinal suma_bin(Cardinal a, Cardinal b);

bool OrdenadoAsc(Cardinal x);
bool OrdenadoDesc(Cardinal x);

void Separar(Cardinal n, Cardinal &x, Cardinal &y);

void EliminarPar(Cardinal &x);

void EliminarPrimos(Cardinal &x);

byte Cantidad_Digitos(Cardinal x);
void Invertir(Cardinal &x);

void MoverMayor(Cardinal &x);

byte CantidadPares(Cardinal x);

byte CantidadDigitos(Cardinal x);

byte Cantidad_Pares(Cardinal x);
byte Cantidad_Impares(Cardinal x);

void Mover_Mayor(Cardinal &x);
void OrdenarAsc(Cardinal &x);

void Mover_Menor(Cardinal &x);
void OrdenarDesc(Cardinal &x);

byte MenorMayor(Cardinal x);

byte SumaPares(Cardinal x);
byte SumaImpares(Cardinal x);

byte Cantidad_Primos(Cardinal x);

byte SumaPrimos(Cardinal x);

short int Diferencia(Cardinal x);

void Insertar(Cardinal &x, byte pos, Word dig);

void CambiarDigito(Cardinal &x, byte digActual, byte digNuevo);
void CambiarDigitos(Cardinal &x, Word digActual, Word digNuevo);

byte Posicion(Cardinal x, byte digito);

#endif
