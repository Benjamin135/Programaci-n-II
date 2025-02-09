//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recursion.h"
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
void __fastcall TForm1::SumadeDigitos1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = SumaDigitos(x);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DigitoMayor1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Mayor(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitoxdig1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	byte z = StrToInt(Edit2->Text);
	EliminarZ(x, z);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Literal1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Literal(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RotarPrimerDigitoalaDerecha1Click(TObject *Sender)
{
//  Cardinal x = StrToInt(Edit1->Text);
//	Edit3->Text = Rotar(x);

	Cardinal x = StrToInt(Edit1->Text);
	Rotar_2(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VerificarOrdenAscendente1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	bool b = OrdenadoAsc(x);
	if (b) {
		Edit3->Text = "True";
	} else {
		Edit3->Text = "False";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VerificarOrdenDescendente1Click(TObject *Sender)
{
    Cardinal x = StrToInt(Edit1->Text);
	bool b = OrdenadoDesc(x);
	if (b) {
		Edit3->Text = "True";
	} else {
		Edit3->Text = "False";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SepararenDigitosPareseImpares1Click(TObject *Sender)
{
	Cardinal n = StrToInt(Edit1->Text);
	Cardinal x = 0;
	Cardinal y = 0;
	Separar(n, x, y);
	Edit3->Text = x;
	Edit2->Text = y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosPares1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	EliminarPar(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosPrimos1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	EliminarPrimos(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Invertir1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Invertir(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MoverMayoralFinal1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	MoverMayor(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadParesantesdeImpar1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = CantidadPares(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeDigitos1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = CantidadDigitos(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadDigitosPares1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Cantidad_Pares(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadDigitosImpares1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Cantidad_Impares(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarAscendentemente1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	OrdenarAsc(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarAscendentemente2Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	OrdenarDesc(x);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DigitoMenoryMayor1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = MenorMayor(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosPares1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = SumaPares(x);
	//Edit3->Text = SumaImpares(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadDigitosPrimos1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Cantidad_Primos(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosPrimos1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = SumaPrimos(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DiferenciaentreDigitosPareseImpares1Click(TObject *Sender)

{
	Cardinal x = StrToInt(Edit1->Text);
	Edit3->Text = Diferencia(x);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::InsertarDigitoxpdig1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	byte pos = StrToInt(Edit2->Text);
	Word dig = StrToInt(Edit4->Text);
	Insertar(x, pos - 1, dig);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CambiarunDigitoporOtro1Click(TObject *Sender)
{
//	Cardinal x = StrToInt(Edit1->Text);
//	byte digActual = StrToInt(Edit2->Text);
//	byte digNuevo = StrToInt(Edit4->Text);
//	CambiarDigito(x, digActual, digNuevo);
//	Edit3->Text = x;

	Cardinal x = StrToInt(Edit1->Text);
	Word digActual = StrToInt(Edit2->Text);
	Word digNuevo = StrToInt(Edit4->Text);
	CambiarDigitos(x, digActual, digNuevo);
	Edit3->Text = x;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PosicindeunDigito1Click(TObject *Sender)
{
	Cardinal x = StrToInt(Edit1->Text);
	byte digito = StrToInt(Edit2->Text);
	Edit3->Text = Posicion(x, digito);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeVocales1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = CantidadVocales(cadena);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Invertir2Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	InvertirCadena_3(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirPalabras1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	InvertirPalabras(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PalabraMsLarga1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = PalabraMasLarga(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarPrimeraLetra1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	EliminarPrimerLetra(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EsPalindrome1Click(TObject *Sender)
{
    AnsiString cadena = Edit5->Text;
	bool result = EsPalindrome(cadena);
	if (result) {
		Edit6->Text = "True";
	} else {
		Edit6->Text = "False";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirOrden1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	InvertirOrden(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExistePalabra1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	AnsiString palabra = Edit7->Text;
	bool result = ExistePalabra(cadena, palabra);
	if (result) {
		Edit6->Text = "True";
	} else {
		Edit6->Text = "False";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarPrimeryUltimaLetra1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	EliminarPriUltLetra(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NmeroMayor1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = NumeroMayor(cadena);

//    AnsiString cadena = Edit5->Text;
//	Edit6->Text = PrimerNumero(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddePalabras1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = CantidadPalabras(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeLetras1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = CantidadLetras(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeEspacios2Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	CadenaDigitos(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeEspacios1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = CantidadEspacios_2(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumadeDigitos2Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = SumaDigitos(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CadenaPareseImpares1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	CadenaPares(cadena);
	Edit6->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NmeroMenor1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = NumeroMenor(cadena);

//	AnsiString cadena = Edit5->Text;
//	Edit6->Text = UltimoNumero(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_DimensionarClick(TObject *Sender)
{
	byte dimension = StrToInt(Txt_Dimension->Text);
	Vector1->ColCount = dimension;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Dimensionar2Click(TObject *Sender)
{
	byte dimension = StrToInt(Txt_Dimension2->Text);
	Vector2->ColCount = dimension;
}
//---------------------------------------------------------------------------

void Cargar_Random(TStringGrid *v, byte n) {
	if (n > 0) {
		Cargar_Random(v, n - 1);
		v->Cells[n - 1][0] = Random(20);
    }
}

void __fastcall TForm1::Btn_RandomClick(TObject *Sender)
{
	byte n = StrToInt(InputBox("Dimensi�n", "Nro Elementos:", ""));
	Vector1->ColCount = n;
	Cargar_Random(Vector1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Suma1Click(TObject *Sender)
{
	Word n = Vector1->ColCount;
	Edit9->Text = Suma(Vector1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumaPares1Click(TObject *Sender)
{
//	Word n = StrToInt(Edit8->Text);
//	Edit9->Text = SumaPares(Vector1, n);

	Word n = StrToInt(Edit8->Text);
	Edit9->Text = SumaImpares(Vector1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExisteElemento1Click(TObject *Sender)
{
	Word a = StrToInt(Edit8->Text);
	Word b = StrToInt(Edit11->Text);
	Word elemento = StrToInt(Edit10->Text);
	bool result = ExisteElemento(Vector1, a, b, elemento);
	if (result) {
		ShowMessage("SI est� en el vector");
	} else {
		ShowMessage("NO est� en el vector");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarvocalesdeunaCadena1Click(TObject *Sender)
{
	Vector2->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	CargarVocales(Vector2, cadena);
//	CargarVocales_2(Vector2, cadena);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Btn_LimpiarClick(TObject *Sender)
{
	Cardinal c = Vector1->ColCount;
	for (int i = 0; i < c; i++) {
		Vector1->Cells[i][0] = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Limpiar2Click(TObject *Sender)
{
	Cardinal c = Vector2->ColCount;
	for (int i = 0; i < c; i++) {
		Vector2->Cells[i][0] = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CadenaconlasUltimasLetras1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	Edit9->Text = UltimasLetras(Vector2, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarconPrimeraletraenMayuscula1Click(TObject *Sender)
{
	Vector2->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	CargarPalabras(Vector2, cadena);
	//Edit9->Text = LetraMayuscula(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarPalabras1Click(TObject *Sender)
{
	Vector2->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	CargarPalabra(Vector2, cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CadenaconlasPrimerasLetras1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	Edit9->Text = PrimerasLetras(Vector2, n);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CargarVocales1Click(TObject *Sender)
{
	Vector1->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	Cargar_Vocales(Vector1, cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarCadenaInvertida1Click(TObject *Sender)
{
	Vector1->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	CargarCadenaInvertida(Vector1, cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarPalabrassinVocales1Click(TObject *Sender)
{
	Vector2->ColCount = 1;
	AnsiString cadena = Edit8->Text;
	CargarSinVocales(Vector2, cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GenerarNmeroInvertido1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	unsigned long long num = 0;
	GenerarNumeros(Vector1, n, num);
	Edit9->Text = num;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarAscendentemente3Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	OrdenarAsc(Vector1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarDescendentemente1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	OrdenarDesc(Vector1, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarSegmentoAscendentemente1Click(TObject *Sender)
{
	Word a = StrToInt(Edit8->Text);
	Word b = StrToInt(Edit11->Text);
	OrdenarSegmentoAsc(Vector1, a, b);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirSegmento1Click(TObject *Sender)
{
	Word a = StrToInt(Edit8->Text);
	Word b = StrToInt(Edit11->Text);
	InvertirSegmento(Vector1, a, b);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarunElemento1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	Word elemento = StrToInt(Edit11->Text);
	EliminarElemento(Vector1, n, elemento);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarSegmento1Click(TObject *Sender)
{
	byte a = StrToInt(Edit8->Text);
	byte b = StrToInt(Edit11->Text);
	EliminarElementos(Vector1, a, b);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Txt_FilasChange(TObject *Sender)
{
	if (Txt_Filas->Text != "") {
		Cardinal filas = StrToInt(Txt_Filas->Text);
		StringGrid1->RowCount = filas;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Txt_ColumnasChange(TObject *Sender)
{
	if (Txt_Columnas->Text != "") {
		Cardinal columnas = StrToInt(Txt_Columnas->Text);
		StringGrid1->ColCount = columnas;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Limpiar3Click(TObject *Sender)
{
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			StringGrid1->Cells[j][i] = "";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarFilas1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte m = StringGrid1->RowCount;
	byte n = StringGrid1->ColCount;
	CargarFilas(StringGrid1, m, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarFilasDeraIzq1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_DIAB(StringGrid1, row, col, serie);
	Llenar_HDI(StringGrid1, row, col, serie);

//	Matriz_IDAB(StringGrid1, row, col, serie);
//	Llenar_HID(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarColumnasArribaaAbajo1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_ABID(StringGrid1, row, col, serie);
//	Llenar_VAB(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarColumnasAbajoaArriba1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_BADI(StringGrid1, row, col, serie);
//	Llenar_VBA(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SerpienteIzqaDer1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_Serpiente_IDDI_AB(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SerpienteDeraIzq1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_Serpiente_DIID_BA(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::riangularSuperiorIzqaDer1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Filas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SI_IDAB(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::riangularSuperiorDeraIzq1Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Columnas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SD_DIAB(StringGrid1, row, col, serie);
//	Llenar_HDI_Diagonal(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::riangularSuperiorArribaaAbajo1Click(TObject *Sender)
{
    StringGrid1->RowCount = StrToInt(Txt_Filas->Text);
	StringGrid1->ColCount = StrToInt(Txt_Filas->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SI_ABID(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadVocales1Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	Edit9->Text = Cantidad_Vocales(Vector2, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadDigitosPrimos2Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	Edit9->Text = Cantidad_Primos(Vector2, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PalabraMsCorta1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = PalabraMasCorta(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeCaracteresEspeciales1Click(TObject *Sender)
{
	AnsiString cadena = Edit5->Text;
	Edit6->Text = CantidadCaracter(cadena);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosPares2Click(TObject *Sender)
{
	Word n = StrToInt(Edit8->Text);
	// Edit9->Text = SumaParesIterativo(Vector1, n);
	Edit9->Text = SumaParesRecursivo(Vector1, n);
}
//---------------------------------------------------------------------------

