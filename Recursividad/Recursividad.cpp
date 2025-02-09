//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recursividad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// RECURSIVIDAD

 Cardinal Factorial(Cardinal num){
	Cardinal resultado;

	if (num == 0) {    // Caso base
		resultado = 1;
	}
	else {             // Caso general
		resultado = num * Factorial(num - 1);
	}
	return resultado;
 }

 Cardinal Factorial_2(Cardinal num){
	Cardinal resultado = (num == 0)? 1: num * Factorial_2(num - 1);
	return resultado;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Factorial1Click(TObject *Sender)
{
	Cardinal num;
	num = StrToInt(Txt_Numero->Text);
	Txt_Resultado->Text = Factorial_2(num);
}
//---------------------------------------------------------------------------
 void Invertir_Numero(int &n){
  int num = 0;
  byte digito;
  while (n > 0){
	digito = n % 10;
	n = n/10;
	num = num * 10 + digito;
  }
  n = num;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::InvertirNmero1Click(TObject *Sender)
{
	int num = StrToInt(Txt_Numero->Text);
	Invertir_Numero(num);
	Txt_Resultado->Text = StrToInt(num);
}
//---------------------------------------------------------------------------
// 2,4,6,8...
// Forma Normal

 byte Serie(byte n){
  byte s = 0;
  for (int i = 1; i <= n; i++) {
		s = s + 2;
  }
  return s;
 }

 // Forma Recursiva
 byte Serie_2(byte n){
 byte res = 2;
	if (n == 1) {
		res = 2;
	}
	else{
		res = res + Serie_2(n - 1);
	}
	return res;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::NmeroSerie1Click(TObject *Sender)
{
	byte n = StrToInt(Txt_Numero->Text);
	Txt_Resultado->Text = Serie_2(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_SalirClick(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------
  // CARGAR VECTORES

  // Cargar Random
  void Cargar_Random(TStringGrid *v, byte n){
	if (n > 0) {
		Cargar_Random(v, n-1);
		v->Cells[n-1][0] = Random(30);
	}
  }

  // Cargar Manual
  void Cargar_Manual(TStringGrid *v, byte n){
	if (n > 0) {
		Cargar_Manual(v, n-1);
		v->Cells[n-1][0] = InputBox("","Inserte un Elemento:","");
	}
  }

  // LIMPIAR VECTORES
  void Limpiar(TStringGrid *v, byte n){
	if (n > 0) {
		Limpiar(v, n-1);
		v->Cells[n-1][0] = "";
	}
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_CargarManualClick(TObject *Sender)
{
	// Cargar Manual v1
	byte n = StrToInt(InputBox("","","3"));
	StringGrid1->ColCount = n;
	Cargar_Manual(StringGrid1, n);

	Limpiar(StringGrid1,n);
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::Btn_CargarManual2Click(TObject *Sender)
{
	// Cargar Manual v2
	byte n = StrToInt(InputBox("","","3"));
	StringGrid2->ColCount = n;
	Cargar_Manual(StringGrid2, n);
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::Btn_CargarManual3Click(TObject *Sender)
{
	// Cargar Manual v3
	byte n = StrToInt(InputBox("","","3"));
	StringGrid3->ColCount = n;
	Cargar_Manual(StringGrid3, n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_Cargar_v1Click(TObject *Sender)
{
	// Cargar Random v1
	byte n = StrToInt(InputBox("","","3"));
	StringGrid1->ColCount = n;
	Cargar_Random(StringGrid1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Cargar_v2Click(TObject *Sender)
{
	// Cargar Random v2
	byte n = StrToInt(InputBox("","","3"));
	StringGrid2->ColCount = n;
	Cargar_Random(StringGrid2, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Cargar_v3Click(TObject *Sender)
{
	// Cargar Random v3
	byte n = StrToInt(InputBox("","","3"));
	StringGrid3->ColCount = n;
	Cargar_Random(StringGrid3, n);
}
//---------------------------------------------------------------------------
 // SUMA DE VECTORES
 int Suma_Vectores(TStringGrid *v,byte n){
  int suma;

  if (n > 0) {     // Caso general
	  suma = Suma_Vectores(v, n-1);
	  suma = suma + StrToInt(v->Cells[n-1][0]);
  }
  else{   // Caso base
	 suma = 0;
  }
  return suma;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SumadeVectores1Click(TObject *Sender)
{
	byte n = StringGrid1->ColCount;
	Txt_Resultado->Text = Suma_Vectores(StringGrid1, n);
}
//---------------------------------------------------------------------------
// CANTIDAD DE DIGITOS QUE TIENE UN N�MERO

byte Cantidad_Digitos(int n){
	byte resultado;
	if (n < 10) {  // Caso base
		resultado = 1;
	}else{     // Caso general
		resultado = Cantidad_Digitos(n/10) + 1;
	}
	return resultado;
}

byte Cantidad_Digitos_2(int n){
	byte resultado = (n < 10)?1:Cantidad_Digitos_2(n/10) + 1;
	return resultado;
}

void __fastcall TForm1::CantidaddeunNmero1Click(TObject *Sender)
{
	int n = StrToInt(InputBox("","N�mero:",""));
	ShowMessage(IntToStr(Cantidad_Digitos_2(n)));
}
//---------------------------------------------------------------------------
// PREGUNTAS DE EXAMEN ANTERIOR SEMESTRE

// PRIMERA PREGUNUTA DE VECTORES
void Insertar(TStringGrid *v,byte &n, byte x)
{
  if (x==0) {
	  v->Cells[0][0]=x;
	  n=1;
  } else {
	   if (x>=v->Cells[n-1][0]) {
		  v->Cells[n][0]=x;
		  n++;
	   } else {
		  String z = v->Cells[n-1][0];
		  n--;
		  Insertar(v,n,x);
		  v->Cells[n][0]=z;
		  n++;
	   }
  }
}

void CargarOrden(Cardinal x, TStringGrid *v, byte &n)
{
  if (x<10) {
	  v->Cells[0][0]=x;
	  n=1;
  } else {
	  CargarOrden(x/10,v,n);
	  Insertar(v,n,x%10);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CargarOrdenado1Click(TObject *Sender)
{
	byte n;
	CargarOrden(StrToInt(Txt_Numero->Text),StringGrid1, n);
	StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

// SEGUNDA PREGUNTA DE CADENAS

bool EsDigito(char z)
{
    return (z>'0') && (z<'9');
}

String PrimerNumero(String x)
{
	String num;
	if (x=="") {
		num="";
	} else {
		char aux=x[1];
		x.Delete(1,1);
		if (!EsDigito(aux)) {
			num=PrimerNumero(x);
		} else {
			if ((x!="")&& (EsDigito(x[1]))) {
				num=String(aux)+PrimerNumero(x);
			} else {
				num=String(aux);
            }
        }
	}
	return num;
}

Cardinal NumeroMayor(String x)
{
	Cardinal num;
	if (x=="") {
		num=0;
	} else {
		String aux = PrimerNumero(x);
		if (aux!="") {
			x.Delete(1,x.Pos(aux)+aux.Length()-1);
			num=NumeroMayor(x);
			if (StrToInt(aux)>num) {
				num=StrToInt(aux);
			}
		} else {
			num=0;
		}

	}
	return num;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NmeroMayordeunTexto1Click(TObject *Sender)
{
	Txt_Resultado->Text = NumeroMayor(Txt_Numero->Text);
}
//---------------------------------------------------------------------------

// TERCERA PREGUNTA DE MATRIZ

void Cargar(TStringGrid *A, byte m, byte k, byte &f, byte &c)
{
	if (k==1) {
		A->Cells[0][0]=1;
		f=0;c=0;
	} else {
		Cargar(A,m,k-1,f,c);
		if (c==m-1) {
			c=f+1; f=m-1;
			A->Cells[c][f]=k;
		} else if (f==0) {
			f=c+1; c=0;
			A->Cells[c][f]=k;
		} else {
			c++; f--;
			A->Cells[c][f]=k;
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CargarMatrizenDiagonal1Click(TObject *Sender)
{
	byte f,c,m=StrToInt(Txt_Numero->Text);
	StringGrid3->ColCount=m;
	StringGrid3->RowCount=m;
	Cargar(StringGrid3,m,m*m,f,c);
}
//---------------------------------------------------------------------------

byte SumaDigPares(Cardinal numero)
{
   byte suma;
   if (numero < 10){ //caso base  n=1
	  if (numero%2 == 0)
		 suma = numero;
	  else
		 suma = 0;
   } else{ //caso general  n>1
		suma = SumaDigPares(numero/10);
		if (numero%2 == 0) {
			suma = suma + numero%10;
		}
   }
   return suma;
}

void __fastcall TForm1::SumaDigitosPares1Click(TObject *Sender)
{
	Txt_Resultado->Text = SumaDigPares(StrToInt(Txt_Numero->Text));
}
//---------------------------------------------------------------------------

short int DifParImpar(Cardinal numero)
{
	short int resultado;
	if (numero < 10) {  // caso base
		if (numero%2 == 0)
			resultado = numero;
		else
			resultado = -numero;

	} else { // caso general
		resultado = DifParImpar(numero/10);
		if (numero%2 == 0)
		   resultado = resultado + numero%10;
		else
		   resultado = resultado - numero%10;
	}
	return resultado;
}

void __fastcall TForm1::DiferenciaPareseImpares1Click(TObject *Sender)
{
	Txt_Resultado->Text = DifParImpar(StrToInt(Txt_Numero->Text));
}
//---------------------------------------------------------------------------

// Funci�n potencia
Cardinal Potencia (int numero, byte exp)
{
	Cardinal resultado;
	if (exp == 0) {
		resultado = 1;
	} else {
		resultado = Potencia(numero, exp/2);
		if (exp % 2 == 0)
			resultado = resultado * resultado;
		else
			resultado = numero * resultado * resultado;
	}
	return resultado;
}

void __fastcall TForm1::FuncinPotencia1Click(TObject *Sender)
{
   Txt_Resultado->Text = Potencia(StrToInt(Txt_Numero->Text),StrToInt(Txt_Numero2->Text));
}
//---------------------------------------------------------------------------

/* Escribir una funci�n que devuelva el mayor de los d�gitos
de un n�mero.
Ej. Mayor(385267) ==> 8 */

byte DigitoMayor(Cardinal x)
{
  byte resultado;
  if (x<10) { // caso base   x=12345
	resultado = x;
  } else { //caso general
	resultado = DigitoMayor(x/10);
	if (x%10 > resultado){
		resultado = x%10;
	}
  }
  return resultado;
}

void __fastcall TForm1::DgitoMayordeunNmero1Click(TObject *Sender)
{
   Txt_Resultado->Text = DigitoMayor(StrToInt(Txt_Numero->Text));
}
//---------------------------------------------------------------------------

/* Escribir una funci�n que devuelva la cantidad de d�gitos pares
que est�n inmediatamente antes de uno impar.
Ej. CantDigPares(3827435) ==> 2  */

byte CantidadPares(Cardinal x)
{
 byte resultado;
  if (x<10) { // caso base
      if (x%2==0){
		  resultado = 1;
      } else {
		  resultado = 0;
      }
  } else { // caso general
	  resultado = CantidadPares(x/10);
	  if (x%2 == 0) {
		 resultado = resultado + 1;
	  }
  }
  return resultado;
}

void __fastcall TForm1::CantidadDgitosPares1Click(TObject *Sender)
{
  Txt_Resultado->Text = CantidadPares(StrToInt(Txt_Numero->Text));
}
//---------------------------------------------------------------------------

/* Escribir un proceso que lleve el mayor de los d�gitos al final de
un n�mero.

Ej.   x=382731;

	 MoverMayor(x);
	 // x=327318 */

void MoverMayor(Cardinal &x)
{
   byte m;
   if (x<10) {                //16243
	   m = x;
	   x = m;
   } else {
	   m = x%10;
	   x = x /10;
	   MoverMayor(x);
	   if (m < x%10) {
		  m = x%10;
          x = x*10 + m;
	   }
   }
}


void __fastcall TForm1::MoverDgitoMayoralFinaldelNmero1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Txt_Numero->Text);
	MoverMayor(num);
	Txt_Resultado->Text = StrToInt(num);
}
//---------------------------------------------------------------------------

// Contar espacios en una cadena
// Ej: "Hola a todos " => 3

byte CantidadEspacio(AnsiString x)
{
  byte cantidad;

  if (x == "") { // caso base n=0
	  cantidad = 0;
  }else if (x.Length() == 1){ // 2do caso base
	   if (x == " ")
		  cantidad = 1;
	   else
			cantidad = 0;

  } else { // caso general
	  /* char z = x[x.Length()];
	  x.Delete(x.Length(),1);
	  cantidad = CantidadEspacio(x);

	  if (z == ' ')
		   cantidad++; */

	  char y = x[1];
	  char z = x[x.Length()];
	  x.Delete(1,1);
	  x.Delete(x.Length(),1);
	  cantidad = CantidadEspacio(x);

	  if (y == ' ')
		  cantidad++;

	  if (z == ' ')
		  cantidad++;

  }
  return cantidad;
}

void __fastcall TForm1::ContarEspacios1Click(TObject *Sender)
{
   Txt_Resultado->Text = CantidadEspacio(Txt_Numero->Text);
}
//---------------------------------------------------------------------------
// algoritmo palabra mas larga

AnsiString Palabra_Larga(AnsiString cadena)
{
	AnsiString resultado, aux;
	cadena = cadena.Trim();
	byte n = cadena.Length();
	cadena = cadena + ' ';
	if (n == 0) { // caso base
		resultado = "";
	} else { // caso general
		byte pos = cadena.Pos(' ');
		aux = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		resultado = Palabra_Larga(cadena);
		if (aux.Length() >= resultado.Length()) {
			resultado = aux;
		}
	}
	return resultado;
}

void __fastcall TForm1::PalabramsLarga1Click(TObject *Sender)
{
	Txt_Resultado->Text = Palabra_Larga(Txt_Numero->Text);
}
//---------------------------------------------------------------------------
// Algoritmo para invertir cada palabra

 AnsiString InvertirPalabra(AnsiString palabra)
 {
	AnsiString resultado;
	if (palabra == "") { // caso base
		resultado = "";
	} else {  // caso general
		char aux = palabra[1];
		palabra.Delete(1,1);
		resultado = InvertirPalabra(palabra);
		resultado = resultado + aux;
	}
	return resultado;
 }

 void Invertir_Cada_Palabra(AnsiString &cadena)
{
	cadena = cadena.Trim();
	byte n = cadena.Length();
	cadena = cadena + ' ';
	if (n == 0) { // caso base
		cadena = "";
	} else {  // caso general
		byte pos = cadena.Pos(' ');
		AnsiString aux = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		aux = InvertirPalabra(aux);
		Invertir_Cada_Palabra(cadena);
		cadena = aux + ' ' + cadena;
	}
}

void __fastcall TForm1::InvertirCadaPalabra1Click(TObject *Sender)
{
	AnsiString resultado = Txt_Numero->Text;
	Invertir_Cada_Palabra(resultado);
	Txt_Resultado->Text = resultado;
}
//---------------------------------------------------------------------------

