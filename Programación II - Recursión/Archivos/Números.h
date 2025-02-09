// ---------------------------------------------------------------------------

#ifndef N�merosH
#define N�merosH
// ---------------------------------------------------------------------------
#include <vcl.h>

Cardinal factorial(byte n);

Cardinal auxPotencia(byte n);
Cardinal potencia(Cardinal n);

Cardinal Potencia(int numero, byte exp);

String Repetir(Cardinal n, Cardinal v);
String Literal(Cardinal n);

Byte Cantidad_Pares(Cardinal n);
byte CantDigPares(Cardinal numero);
byte parAntesImpar(Cardinal n);

void Recorrer(Cardinal &n, Cardinal pos);
Cardinal Posicion_Mayor(Cardinal n);
void Mover_Mayor(Cardinal &n);

void MoverMayor(Cardinal &numero);

Cardinal suma_bin(Cardinal a, Cardinal b, Cardinal carry, Cardinal r);
Cardinal suma_binarios(Cardinal a, Cardinal b);

byte Cantidad_Digitos(Cardinal n);
void Invertir(Cardinal &n);

void InvertirNumero(Cardinal &n);

int Cantidad_Digitos(int numero);

void Mover_Mayor_Final(Cardinal &n);

void Mover_Menor_Final(Cardinal &n);
void Ordenar(Cardinal &n);

Cardinal Conversion_Binario(Cardinal n);

String Conversion_Bases(Cardinal n, byte base);

byte digitoMayorMenor(Cardinal n);

byte digitoMayor(Cardinal n);
byte DigitoMayor(Cardinal x);

bool estaOrdenadoAsc(Cardinal n);

bool estaOrdenadoDesc(Cardinal n);

byte cantidadPares(Cardinal n);
byte CantidadPares(Cardinal x);

byte CantidadImpares(Cardinal x);

Word sumaDigitos(Cardinal numero);

Word sumaPares(Cardinal n);

byte Suma_Digitos_Pares(Cardinal numero);

Word sumaDigitosPrimos(Cardinal numero);

bool Es_Primo(Cardinal num);
Word CantidadPrimos(Cardinal numero);

short int DifParImpar(Cardinal numero);

void eliminar_digito_par(Cardinal &n);

void insertar_digito(Cardinal n, byte digito, byte pos);

void Rotar(Cardinal &n);

void ordenarNumero(Cardinal &n);

String Repetir_Digito(Cardinal n, Cardinal v);
String Cadena_De_Digitos(Cardinal n);

#endif
