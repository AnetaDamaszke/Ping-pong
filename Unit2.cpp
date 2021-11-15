//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

       int x = -8;
       int y = -3;
       int pointLeft=0;
       int pointRight=0;
       int bounces = 0;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Ball_tTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //--odbicie od górnej sciany
        if(ball->Top-5 <= background->Top) y = -y;

        //--odbicie od dolnej sciany
        if(ball->Top+ball->Height+5 >= background->Height)
                y = -y;

        //--brak odbicia z lewej strony
        if(ball->Left + 60 <= paddle1->Left)
        {
            pointRight++;
            Ball_t->Enabled = false;
            ball->Visible = false;
            Label1->Visible = true;
            Label1->Caption = "Punkt dla gracza prawego  >";
            Label2->Visible = true;
            Label2->Caption = IntToStr(pointLeft) + ":" + IntToStr(pointRight);
            Label3->Visible = true;
            Label3->Caption = "Iloœæ odbiæ: " + IntToStr(bounces);
            Button1->Visible = true;
            Button2->Visible = true;
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
            pointLeft++;
            Ball_t->Enabled = false;
            ball->Visible = false;
            Label1->Visible = true;
            Label1->Caption = "<  Punkt dla gracza lewego";
            Label2->Visible = true;
            Label2->Caption = IntToStr(pointLeft) + ":" + IntToStr(pointRight);
            Label3->Visible = true;
            Label3->Caption = "Iloœæ odbiæ: " + IntToStr(bounces);
            Button1->Visible = true;
            Button2->Visible = true;
        }
        else if(ball->Left+ball->Width > paddle2->Left &&
        ball->Top+ball->Height > paddle2->Top &&
        ball->Top < paddle2->Top+paddle2->Height-ball->Height/2)
        {
                //--odbicie z prawej strony
                if(x>0) x = -x;
                bounces++;
        }

        //--przyspieszenie pi³ki
}
//---------------------------------------------------------------------------

void __fastcall TForm2::paddle1downTimer(TObject *Sender)
{
        if(paddle1->Top+paddle1->Height < background->Height-11)
        paddle1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::paddle1upTimer(TObject *Sender)
{
        if(paddle1->Top > 10) paddle1->Top -= 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::paddle2downTimer(TObject *Sender)
{
        if(paddle2->Top+paddle2->Height < background->Height-11)
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::paddle2upTimer(TObject *Sender)
{
        if(paddle2->Top > 10) paddle2->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) paddle1up->Enabled = true;
        if(Key == VK_CONTROL) paddle1down->Enabled = true;
        if(Key == VK_UP) paddle2up->Enabled = true;
        if(Key == VK_DOWN) paddle2down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) paddle1up->Enabled = false;
        if(Key == VK_CONTROL) paddle1down->Enabled = false;
        if(Key == VK_UP) paddle2up->Enabled = false;
        if(Key == VK_DOWN) paddle2down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
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

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        if(Application->MessageBox("Czy na pewno chcesz rozpocz¹æ now¹ grê?",
        "PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
                ball->Visible = false;
                Ball_t->Enabled = false;
                bounces = 0;
                pointLeft = 0;
                pointRight = 0;
                paddle1->Top = 110;
                paddle2->Top = 110;
                ball->Left = 536;
                ball->Top = 236;
                Label1->Visible = false;
                Label2->Visible = false;
                Label3->Visible = false;
                Label4->Visible = true;
                Button1->Visible = false;
                Button2->Visible = false;
                Button3->Visible = true;
                Form2->Visible = false;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
      Label4->Visible = false;
      Button3->Visible = false;

      x = -9; y = -4;

      ball->Visible = true;
      Ball_t->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBox("Czy na pewno chcesz wy³¹czyæ grê?",
        "PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
                Action=caNone;
        }
        else
        {
            Application->Terminate();
        }
}
//---------------------------------------------------------------------------

