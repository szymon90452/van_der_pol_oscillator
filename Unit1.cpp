//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

float zmienna_x[10000];
float zmienna_y[10000];
float krok;
float zmienna_u;
int zmienna_czas;
float iteracja;

void rysuj_wykres_faz()
{
        Form2->Visible = true;
        Form2->Brush->Color = clWhite;
        Form2->Canvas->Pen->Color = clBlack;
        Form2->Canvas->FillRect(Rect(0, 0, Form2->Width, Form2->Height));
        for(int i=1; i<=7;i++)
        {
        Form2->Canvas->TextOut(0, 50*i, 4-i);
        Form2->Canvas->MoveTo(10, 50*i);
        Form2->Canvas->LineTo(385,50*i );
        }
         Form2->Canvas->Font->Color = clBlue;
         Form2->Canvas->TextOut(0, 0, "Wykres X");
         Form2->Canvas->Font->Color = clRed;
         Form2->Canvas->TextOut(0, 15, "Wykres Y");
         Form2->Canvas->Font->Color = clBlack;


         Form2->Canvas->MoveTo(10,(4*50-zmienna_x[0]*50));

        int dzielnik = iteracja/375;
        for(int i=0; i<iteracja; i++)
        {
        if(i!=0){
             zmienna_y[i]=zmienna_y[i-1]+krok/2*(zmienna_u*(1-zmienna_x[i-1]*zmienna_x[i-1])*zmienna_y[i-1]-zmienna_x[i-1])+krok/2*(zmienna_u*(1-zmienna_x[i-1]*zmienna_x[i-1])*zmienna_y[i-1]-zmienna_x[i-1]);
             zmienna_x[i]=zmienna_x[i-1]+krok/2*zmienna_y[i-1]+krok/2*zmienna_y[i];
                }
        Form2->Canvas->Pen->Color = clBlue;
        Form2->Canvas->LineTo(10+i/dzielnik,(4*50-zmienna_x[i]*50));
        Form2->Canvas->MoveTo(10+i/dzielnik,(4*50-zmienna_x[i]*50));
        }
        Form2->Canvas->MoveTo(10,(4*50-zmienna_y[0]*50));
        for(int i=0; i<iteracja; i++)
        {
        Form2->Canvas->Pen->Color = clRed;
        Form2->Canvas->LineTo(10+i/dzielnik,(4*50-zmienna_y[i]*50));
        Form2->Canvas->MoveTo(10+i/dzielnik,(4*50-zmienna_y[i]*50));
        }
}

void rysuj_wykres(){

     Form3->Visible = true;
        Form3->Brush->Color = clWhite;
        Form3->Canvas->FillRect(Rect(0, 0, Form3->Width, Form3->Height));
        Form3->Canvas->Pen->Color = clBlack;
        Form3->Canvas->MoveTo(193, 0);
        Form3->Canvas->LineTo(193, 385);
        Form3->Canvas->MoveTo(0, 193);
        Form3->Canvas->LineTo(385, 193);

        for(int i=0; i<=6; i++)
        {
           Form3->Canvas->MoveTo(190, 43+50*i);
           Form3->Canvas->LineTo(197, 43+50*i);
           if(i!=3)
           {
			Form3->Canvas->TextOut(198, 43+50*i, 3-i);
           	Form3->Canvas->TextOut(43+50*i,200, -3+i);
           }
           Form3->Canvas->MoveTo(43+50*i,190);
           Form3->Canvas->LineTo(43+50*i,197);


        }
        Form3->Canvas->Pen->Color = clBlue;
         Form3->Canvas->MoveTo((193+zmienna_x[0]*50),(193-zmienna_y[0]*50));

        for(int i=0; i<iteracja; i++)
        {


        Form3->Canvas->LineTo((193+zmienna_x[i]*50),(193-zmienna_y[i]*50));
        Form3->Canvas->MoveTo((193+zmienna_x[i]*50),(193-zmienna_y[i]*50));


        }

}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   try
{
		zmienna_x[0] = CSpinEdit1->Value;     //Startowa wartosc X
		zmienna_y[0] = CSpinEdit2->Value;       //Startowa wartosc Y
        zmienna_u = CSpinEdit3->Value;    //Wartosc u
        krok = StrToFloat(Edit1->Text);   //Wartosc kroku
        zmienna_czas = CSpinEdit4->Value;   //Czas potrzebny do wykonania

        iteracja = zmienna_czas/krok;  //Obliczenie ile potrzebnych jest iteracji

        ListView1->Clear();     //Wyczyszczenie listy

        for(int i=0; i<iteracja; i++)
        {
                if(i!=0){
                        zmienna_y[i]=zmienna_y[i-1]+krok/2*(zmienna_u*(1-zmienna_x[i-1]*zmienna_x[i-1])*zmienna_y[i-1]-zmienna_x[i-1])+krok/2*(zmienna_u*(1-zmienna_x[i-1]*zmienna_x[i-1])*zmienna_y[i-1]-zmienna_x[i-1]);
                        zmienna_x[i]=zmienna_x[i-1]+krok/2*zmienna_y[i-1]+krok/2*zmienna_y[i];
                }
                ListView1->Items->Add();
                ListView1->Items->Item[i]->Caption = i+1;
                ListView1->Items->Item[i]->SubItems->Add(zmienna_x[i]);
                ListView1->Items->Item[i]->SubItems->Add(zmienna_y[i]);
        }

        if(Form3->Visible == true){
                rysuj_wykres();
        }
        if(Form2->Visible == true){
                rysuj_wykres_faz();
        }
}
catch(...)
{
                ShowMessage("Prosze sprawdzic czy wartosci zostaly wpisane poprawnie!");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
    rysuj_wykres_faz();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    rysuj_wykres();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zamknijprogram1Click(TObject *Sender)
{
     Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
     Form5->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Autorzy1Click(TObject *Sender)
{
      Form4->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if (SaveDialog1->Execute()){

        try{
               TFileStream *File = new TFileStream(SaveDialog1->FileName, fmCreate);
                File->WriteComponent(ListView1);
                delete File;
        }

        catch(...){
                ShowMessage("B³¹d zapisu pliku.");
        }

      }
}
//---------------------------------------------------------------------------

