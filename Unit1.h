//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cspin.h"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *va1;
	TMenuItem *Pomoc1;
	TMenuItem *Zamknijprogram1;
	TMenuItem *Oprogramie1;
	TMenuItem *Autorzy1;
	TImage *Image1;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TListView *ListView1;
	TCSpinEdit *CSpinEdit1;
	TCSpinEdit *CSpinEdit2;
	TCSpinEdit *CSpinEdit3;
	TCSpinEdit *CSpinEdit4;
	TSaveDialog *SaveDialog1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Zamknijprogram1Click(TObject *Sender);
	void __fastcall Oprogramie1Click(TObject *Sender);
	void __fastcall Autorzy1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
