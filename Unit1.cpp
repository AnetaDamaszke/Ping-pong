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

        //--brak odbicia

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1downTimer(TObject *Sender)
{
     if(paddle1->Top+paddle1->Height < background1->Height-11)
        paddle1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1upTimer(TObject *Sender)
{
     if(paddle1->Top > 10) paddle1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle2downTimer(TObject *Sender)
{
      if(paddle2->Top+paddle2->Height < background1->Height-11)
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle2upTimer(TObject *Sender)
{
      if(paddle2->Top > 10) paddle2->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) Paddle1up->Enabled = true;
        if(Key == VK_CONTROL) Paddle1down->Enabled = true;
        if(Key == VK_UP) Paddle2up->Enabled = true;
        if(Key == VK_DOWN) Paddle2down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) Paddle1up->Enabled = false;
        if(Key == VK_CONTROL) Paddle1down->Enabled = false;
        if(Key == VK_UP) Paddle2up->Enabled = false;
        if(Key == VK_DOWN) Paddle2down->Enabled = false;
}
//---------------------------------------------------------------------------

