// ---------------------------------------------------------------------------

#ifndef Recursi�nH
#define Recursi�nH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "N�meros.h"
#include "Cadenas.h"
#include "Vectores.h"
#include "Matrices.h"
#include "Series.h"
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Nmeros1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *Series;
	TTabSheet *Cadenas;
	TTabSheet *Vectores;
	TTabSheet *TabSheet2;
	TMenuItem *Series1;
	TMenuItem *Cadenas1;
	TMenuItem *Vectores1;
	TMenuItem *Matrices1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TMenuItem *Literal1;
	TMenuItem *CantidadParantesdeImpar1;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *EliminarPrimeraLetra1;
	TMenuItem *LeerConjunto1;
	TMenuItem *EsPalndrome1;
	TMenuItem *Invertir1;
	TStringGrid *StringGrid1;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Txt_Dimension;
	TButton *Dimencionar;
	TMenuItem *InsertionSort1;
	TStringGrid *StringGrid2;
	TMenuItem *CargarSerie11;
	TMenuItem *MoverMayoralFinal1;
	TMenuItem *VerificarOrden1;
	TMenuItem *SumadeDigitos1;
	TMenuItem *CargarOrdenadoCadena1;
	TStringGrid *StringGrid3;
	TEdit *Edit7;
	TEdit *Edit8;
	TMenuItem *CargarTodasLasFilas1;
	TLabel *Label5;
	TLabel *Label6;
	TMenuItem *CargarTodasLasColumnas1;
	TButton *Button1;
	TMenuItem *CargarDiagonalSecundariaInferioe1;
	TMenuItem *OrdenBurbuja1;
	TButton *Button2;
	TMenuItem *CargarExterior1;
	TMenuItem *SumadeBinarios1;
	TEdit *Edit9;
	TLabel *Label7;
	TMenuItem *CargarDiagonalSecundaria21;
	TMenuItem *CargarDiagonalSuperior1;
	TMenuItem *CargarCaracol1;
	TMenuItem *CargarCaracol21;
	TMenuItem *InsertarVectorenOtrov2v2p1;
	TEdit *Txt_Dimension2;
	TButton *Button3;
	TMenuItem *NmeroMayor1;
	TMenuItem *CargarFraseenunVector1;
	TMenuItem *CargarPalabra1;
	TMenuItem *EliminarElemento1;
	TMenuItem *CargarEspiral1;
	TMenuItem *CargarVocaeles1;
	TMenuItem *CargarFraccin1;
	TMenuItem *CargarFrecuencias1;
	TMenuItem *Invertir2;
	TMenuItem *MoverMayoralFinal2;
	TMenuItem *Ordenar1;
	TMenuItem *DecimalaBinario1;
	TMenuItem *ConversindeBases1;
	TMenuItem *Invertir3;
	TMenuItem *EliminarVocale1;
	TMenuItem *PalabramsLarga1;
	TMenuItem *InvertirPalabra1;
	TMenuItem *Fibonacci1;
	TEdit *Edit10;
	TEdit *Edit11;
	TLabel *Label8;
	TLabel *Label9;
	TMenuItem *Serie1;
	TMenuItem *SumaSerie1;
	TEdit *Edit12;
	TMenuItem *SumadeElementosPres1;
	TMenuItem *ContarPalabras1;
	TMenuItem *Cargar1;
	TMenuItem *CadenaconNmerosInvertidosdeunvector1;
	TMenuItem *CargarSerie1;
	TMenuItem *CargarMatrizSerpiente1;
	TMenuItem *CargarDiagonalSuperior2;
	TMenuItem *s1;
	TMenuItem *Serie13571531631;
	TMenuItem *Suma1;
	TMenuItem *CargarCaracteresdeCadena1;
	TMenuItem *Factorial1;
	TMenuItem *Potencia1;
	TMenuItem *GitioMayoryMenor1;
	TMenuItem *DigitoMayor1;
	TMenuItem *VerificarOrdenAscendente1;
	TMenuItem *VerificarOrdenDescendente1;
	TMenuItem *CantidaddeDigitosPares1;
	TMenuItem *SumadeDigitosPares1;
	TMenuItem *c1;
	TMenuItem *CargarCaracol31;
	TMenuItem *CargarDiagonalInferiorcon11;
	TMenuItem *CargarMatrizSerpiente21;
	TMenuItem *CargarCadena1;
	TMenuItem *CargarCadena21;
	TMenuItem *Cargardiagonalsuperior3;
	TMenuItem *CargarCadena31;
	TMenuItem *DigitodelaSerie24681;
	TMenuItem *CantidaddeDigitosa1;
	TMenuItem *SumaDigitosPares1;
	TMenuItem *DiferenciaentrePareseImpares1;
	TMenuItem *ContarEspacios1;
	TMenuItem *ContarVocales1;
	TMenuItem *BusquedaBinaria1;
	TMenuItem *CargarporFilas1;
	TMenuItem *CargarMatriz1;
	TMenuItem *CargarEspiral21;
	TMenuItem *CargarDona1;
	TMenuItem *CuadradoMgico1;
	TMenuItem *CargarOrdenado1;
	TMenuItem *NmeroMayordeunaCadena1;
	TMenuItem *CargarMatrizExamen1;
	TMenuItem *CargarSerie012367141;
	TMenuItem *QuickSort1;
	TMenuItem *CargarTriangularInferior1;
	TMenuItem *SumadeDigitosPrimos1;
	TMenuItem *InvertirCadena1;
	TMenuItem *SumadeDigitos2;
	TMenuItem *CantidaddeDigitoaImpares1;
	TMenuItem *CantidaddeDigitosPrimos1;
	TMenuItem *EliminarDigitosPares1;
	TMenuItem *InsertarDigito1;
	TMenuItem *RotarelprimerDigito1;
	TMenuItem *OrdenarAscendentemente1;
	TMenuItem *SumaDigitosenu1;
	TMenuItem *ConstruirCadenaconDigitos1;
	TMenuItem *CantidaddeLetras1;
	TMenuItem *CargarPalabrassinVocales1;
	TMenuItem *CargarNmeroRetonarSuma1;
	TMenuItem *ConstruitcadenaconUltimasLetras1;
	TMenuItem *CargarPalabraInvertida1;
	TMenuItem *InvertirFrase1;
	TMenuItem *VectoraNmero1;
	TMenuItem *CargarCadenaenSerpiente1;
	TMenuItem *CargarColumnasInvertido1;
	TMenuItem *Navidad1;
	TMenuItem *CargarTriangularSuperior1;
	TMenuItem *CargarTriangularInferiorP11;
	TMenuItem *CargarMatrizSerpienteColumnas1;
	TMenuItem *CargarTriangularInferiorColumnas1;
	TMenuItem *CadenadeDigitos1;
	TMenuItem *CargarDiagonales1;
	TMenuItem *ElimnarElementos1;
	TMenuItem *SumaDigitosPares2;
	TMenuItem *InsertionSort2;

	void __fastcall Literal1Click(TObject *Sender);
	void __fastcall CantidadParantesdeImpar1Click(TObject *Sender);
	void __fastcall EliminarPrimeraLetra1Click(TObject *Sender);
	void __fastcall LeerConjunto1Click(TObject *Sender);
	void __fastcall EsPalndrome1Click(TObject *Sender);
	void __fastcall Invertir1Click(TObject *Sender);
	void __fastcall DimencionarClick(TObject *Sender);
	void __fastcall InsertionSort1Click(TObject *Sender);
	void __fastcall CargarSerie11Click(TObject *Sender);
	void __fastcall MoverMayoralFinal1Click(TObject *Sender);
	void __fastcall VerificarOrden1Click(TObject *Sender);
	void __fastcall SumadeDigitos1Click(TObject *Sender);
	void __fastcall CargarOrdenadoCadena1Click(TObject *Sender);
	void __fastcall Edit7Change(TObject *Sender);
	void __fastcall Edit8Change(TObject *Sender);
	void __fastcall CargarTodasLasFilas1Click(TObject *Sender);
	void __fastcall CargarTodasLasColumnas1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CargarDiagonalSecundariaInferioe1Click(TObject *Sender);
	void __fastcall OrdenBurbuja1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CargarExterior1Click(TObject *Sender);
	void __fastcall SumadeBinarios1Click(TObject *Sender);
	void __fastcall CargarDiagonalSecundaria21Click(TObject *Sender);
	void __fastcall CargarDiagonalSuperior1Click(TObject *Sender);
	void __fastcall CargarCaracol1Click(TObject *Sender);
	void __fastcall CargarCaracol21Click(TObject *Sender);
	void __fastcall InsertarVectorenOtrov2v2p1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall NmeroMayor1Click(TObject *Sender);
	void __fastcall CargarFraseenunVector1Click(TObject *Sender);
	void __fastcall CargarPalabra1Click(TObject *Sender);
	void __fastcall EliminarElemento1Click(TObject *Sender);
	void __fastcall CargarEspiral1Click(TObject *Sender);
	void __fastcall CargarVocaeles1Click(TObject *Sender);
	void __fastcall CargarFraccin1Click(TObject *Sender);
	void __fastcall CargarFrecuencias1Click(TObject *Sender);
	void __fastcall Invertir2Click(TObject *Sender);
	void __fastcall MoverMayoralFinal2Click(TObject *Sender);
	void __fastcall Ordenar1Click(TObject *Sender);
	void __fastcall DecimalaBinario1Click(TObject *Sender);
	void __fastcall ConversindeBases1Click(TObject *Sender);
	void __fastcall Invertir3Click(TObject *Sender);
	void __fastcall EliminarVocale1Click(TObject *Sender);
	void __fastcall PalabramsLarga1Click(TObject *Sender);
	void __fastcall InvertirPalabra1Click(TObject *Sender);
	void __fastcall Fibonacci1Click(TObject *Sender);
	void __fastcall Serie1Click(TObject *Sender);
	void __fastcall SumaSerie1Click(TObject *Sender);
	void __fastcall SumadeElementosPres1Click(TObject *Sender);
	void __fastcall ContarPalabras1Click(TObject *Sender);
	void __fastcall Cargar1Click(TObject *Sender);
	void __fastcall CadenaconNmerosInvertidosdeunvector1Click(TObject *Sender);
	void __fastcall CargarSerie1Click(TObject *Sender);
	void __fastcall CargarMatrizSerpiente1Click(TObject *Sender);
	void __fastcall CargarDiagonalSuperior2Click(TObject *Sender);
	void __fastcall s1Click(TObject *Sender);
	void __fastcall Serie13571531631Click(TObject *Sender);
	void __fastcall Suma1Click(TObject *Sender);
	void __fastcall CargarCaracteresdeCadena1Click(TObject *Sender);
	void __fastcall Factorial1Click(TObject *Sender);
	void __fastcall Potencia1Click(TObject *Sender);
	void __fastcall GitioMayoryMenor1Click(TObject *Sender);
	void __fastcall DigitoMayor1Click(TObject *Sender);
	void __fastcall VerificarOrdenAscendente1Click(TObject *Sender);
	void __fastcall VerificarOrdenDescendente1Click(TObject *Sender);
	void __fastcall CantidaddeDigitosPares1Click(TObject *Sender);
	void __fastcall SumadeDigitosPares1Click(TObject *Sender);
	void __fastcall c1Click(TObject *Sender);
	void __fastcall CargarCaracol31Click(TObject *Sender);
	void __fastcall CargarDiagonalInferiorcon11Click(TObject *Sender);
	void __fastcall CargarMatrizSerpiente21Click(TObject *Sender);
	void __fastcall CargarCadena1Click(TObject *Sender);
	void __fastcall CargarCadena21Click(TObject *Sender);
	void __fastcall Cargardiagonalsuperior3Click(TObject *Sender);
	void __fastcall CargarCadena31Click(TObject *Sender);
	void __fastcall DigitodelaSerie24681Click(TObject *Sender);
	void __fastcall CantidaddeDigitosa1Click(TObject *Sender);
	void __fastcall SumaDigitosPares1Click(TObject *Sender);
	void __fastcall DiferenciaentrePareseImpares1Click(TObject *Sender);
	void __fastcall ContarEspacios1Click(TObject *Sender);
	void __fastcall ContarVocales1Click(TObject *Sender);
	void __fastcall BusquedaBinaria1Click(TObject *Sender);
	void __fastcall CargarporFilas1Click(TObject *Sender);
	void __fastcall CargarMatriz1Click(TObject *Sender);
	void __fastcall CargarEspiral21Click(TObject *Sender);
	void __fastcall CargarDona1Click(TObject *Sender);
	void __fastcall CuadradoMgico1Click(TObject *Sender);
	void __fastcall CargarOrdenado1Click(TObject *Sender);
	void __fastcall NmeroMayordeunaCadena1Click(TObject *Sender);
	void __fastcall CargarMatrizExamen1Click(TObject *Sender);
	void __fastcall CargarSerie012367141Click(TObject *Sender);
	void __fastcall QuickSort1Click(TObject *Sender);
	void __fastcall CargarTriangularInferior1Click(TObject *Sender);
	void __fastcall SumadeDigitosPrimos1Click(TObject *Sender);
	void __fastcall InvertirCadena1Click(TObject *Sender);
	void __fastcall SumadeDigitos2Click(TObject *Sender);
	void __fastcall CantidaddeDigitoaImpares1Click(TObject *Sender);
	void __fastcall CantidaddeDigitosPrimos1Click(TObject *Sender);
	void __fastcall EliminarDigitosPares1Click(TObject *Sender);
	void __fastcall InsertarDigito1Click(TObject *Sender);
	void __fastcall RotarelprimerDigito1Click(TObject *Sender);
	void __fastcall OrdenarAscendentemente1Click(TObject *Sender);
	void __fastcall SumaDigitosenu1Click(TObject *Sender);
	void __fastcall ConstruirCadenaconDigitos1Click(TObject *Sender);
	void __fastcall CantidaddeLetras1Click(TObject *Sender);
	void __fastcall CargarPalabrassinVocales1Click(TObject *Sender);
	void __fastcall CargarNmeroRetonarSuma1Click(TObject *Sender);
	void __fastcall ConstruitcadenaconUltimasLetras1Click(TObject *Sender);
	void __fastcall CargarPalabraInvertida1Click(TObject *Sender);
	void __fastcall InvertirFrase1Click(TObject *Sender);
	void __fastcall VectoraNmero1Click(TObject *Sender);
	void __fastcall CargarCadenaenSerpiente1Click(TObject *Sender);
	void __fastcall CargarColumnasInvertido1Click(TObject *Sender);
	void __fastcall Navidad1Click(TObject *Sender);
	void __fastcall CargarTriangularSuperior1Click(TObject *Sender);
	void __fastcall CargarTriangularInferiorP11Click(TObject *Sender);
	void __fastcall CargarMatrizSerpienteColumnas1Click(TObject *Sender);
	void __fastcall CargarTriangularInferiorColumnas1Click(TObject *Sender);
	void __fastcall CadenadeDigitos1Click(TObject *Sender);
	void __fastcall CargarDiagonales1Click(TObject *Sender);
	void __fastcall ElimnarElementos1Click(TObject *Sender);
	void __fastcall SumaDigitosPares2Click(TObject *Sender);
	void __fastcall InsertionSort2Click(TObject *Sender);



private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
