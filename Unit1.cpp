//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x = 8;
        int y = -3;
        int pointLeft=0;
        int pointRight=0;
        int bounces = 0;

        AnsiString bouncesStr = bouncesStr = IntToStr(bounces);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ball_tTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //--odbicie od g�rnej sciany
        if(ball->Top-5 <= background1->Top) y = -y;

        //--odbicie od dolnej sciany
        if(ball->Top+ball->Height+5 >= background1->Height)
                y = -y;

        //--brak odbicia z lewej strony
        if(ball->Left + 60 <= paddle1->Left)
        {
            Ball_t->Enabled = false;
            ball->Visible = false;
            Label1->Visible = true;
            Label1->Caption = "Punkt dla gracza prawego  >";
            Label2->Visible = true;
            Label2->Caption = pointLeft + ":" + ++pointRight;
            Label3->Visible = true;
            Label3->Caption = "Ilo�� odbi�: " + bouncesStr;
            Button1->Visible = true;
            Button2->Visible = true;
            pointRight++;
        }
        else if(ball->Left < paddle1->Left+paddle1->Width && ball->Top >
        paddle1->Top-ball->Height/2 && ball->Top < paddle1->Top+paddle1->Height)
        {
                //--odbicie z lewej strony
                if(x<0) x = -x;
                bounces++;
        }

        //--brak odbicia z prawej strony
        if(ball->Left+ball->Width - 60 >= paddle2->Left+paddle2->Width)
        {
            Ball_t->Enabled = false;
            ball->Visible = false;
            Label1->Visible = true;
            Label1->Caption = "<  Punkt dla gracza lewego";
            Label2->Visible = true;
            Label2->Caption = pointLeft + ":" + ++pointRight;
            Label3->Visible = true;
            Label3->Caption = "Ilo�� odbi�: " + bouncesStr;
            Button1->Visible = true;
            Button2->Visible = true;
            pointLeft++;
        }
        else if(ball->Left+ball->Width > paddle2->Left &&
        ball->Top+ball->Height > paddle2->Top &&
        ball->Top < paddle2->Top+paddle2->Height-ball->Height/2)
        {
                //--odbicie z prawej strony
                if(x>0) x = -x;
                bounces++;
        }
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



void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ball->Left = 536;
        ball->Top = 232;

        x = -8; y = 3;

        ball->Visible = true;
        Ball_t->Enabled = true;
        Label1->Visible = false;
        Label2->Visible = false;
        Label3->Visible = false;
        Button1->Visible = false;
        Button2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
       ball->Left = 536;
       ball->Top = 232;

       paddle1->Top = 128;  paddle2->Top = 128;

       x = 7; y = 5;

       ball->Visible = true;
       Ball_t->Enabled = true;
       Label1->Visible = false; Label2->Visible = false;
       Label3->Visible = false;
       Button1->Visible = false; Button2->Visible = false;
}
//---------------------------------------------------------------------------

