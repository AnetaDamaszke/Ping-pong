//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x = -8;
        int y = 8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ball_Timer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //--odbicie od g�rnej sciany
        if(ball->Top-5 <= background1->Top) y = -y;

        //--odbicie od dolnej sciany
        if(ball->Top+ball->Height+5 >= background1->Height)
                y = -y;
}
//---------------------------------------------------------------------------
 