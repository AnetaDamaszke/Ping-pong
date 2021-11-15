//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Form2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Form4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Form5->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
         if(Application->MessageBox("Czy na pewno chcesz wy³¹czyæ grê?",
        "PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
                Action=caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application->MessageBox(
        "Czeka Ciê rozgrywka na 3 poziomach trudnoœci. /n"
        "Aby sterowaæ lewym graczem u¿yj SHIFT (góra) oraz CTRL (dó³). /n"
        "Aby sterowa prawym graczem u¿yj strza³ek GÓRA i DÓ£. /n"
        "UWAGA: /n"
        "Przy ka¿dym trafieniu w œrodek paletki pi³ka przyspiesza! /n"
        "Udanej zabawy!",
        "Witaj w grze!", MB_OK);
}
//---------------------------------------------------------------------------

