//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;

       int x = -8;
       int y = -3;
       int pointLeft=0;
       int pointRight=0;
       int bounces = 0;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Ball_tTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //--odbicie od g?rnej sciany
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
            Label3->Caption = "Ilo?? odbi?: " + IntToStr(bounces);
            Button1->Visible = true;
            Button2->Visible = true;
        }
        else if(ball->Left < paddle1->Left+paddle1->Width && ball->Top >
        paddle1->Top-ball->Height/2 && ball->Top < paddle1->Top+paddle1->Height)
        {
                //--odbicie z lewej strony
                if(x<0) x = -x;
                bounces++;
                sndPlaySound("sounds/bounce.wav", SND_ASYNC);

                if(ball->Top > paddle1->Top+paddle1->Height/4 &&
                ball->Top+ball->Height <
                paddle1->Top+paddle1->Height-paddle1->Height/4)
                {
                   while(Ball_t->Interval > 1)
                   {
                       Ball_t->Interval--;
                   }
                }
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
            Label3->Caption = "Ilo?? odbi?: " + IntToStr(bounces);
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
                sndPlaySound("sounds/bounce.wav", SND_ASYNC);

                if(ball->Top > paddle2->Top+paddle2->Height/4 &&
                ball->Top+ball->Height <
                paddle2->Top+paddle2->Height-paddle2->Height/4)
                {
                   while(Ball_t->Interval > 1)
                   {
                       Ball_t->Interval--;
                   }
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm5::paddle1upTimer(TObject *Sender)
{
        if(paddle1->Top > 10) paddle1->Top -= 10;         
}
//---------------------------------------------------------------------------
void __fastcall TForm5::paddle1downTimer(TObject *Sender)
{
      if(paddle1->Top+paddle1->Height < background->Height-11)
        paddle1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::paddle2downTimer(TObject *Sender)
{
        if(paddle2->Top+paddle2->Height < background->Height-11)
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::paddle2upTimer(TObject *Sender)
{
        if(paddle2->Top > 10) paddle2->Top -= 10;        
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) paddle1up->Enabled = true;
        if(Key == VK_CONTROL) paddle1down->Enabled = true;
        if(Key == VK_UP) paddle2up->Enabled = true;
        if(Key == VK_DOWN) paddle2down->Enabled = true;         
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_SHIFT) paddle1up->Enabled = false;
        if(Key == VK_CONTROL) paddle1down->Enabled = false;
        if(Key == VK_UP) paddle2up->Enabled = false;
        if(Key == VK_DOWN) paddle2down->Enabled = false;        
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
        ball->Left = 536;
        ball->Top = 232;
        Ball_t->Interval = 20;

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
void __fastcall TForm5::Button2Click(TObject *Sender)
{
        if(Application->MessageBox("Czy na pewno chcesz rozpocz?? now? gr??",
        "Potwierd?", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
                ball->Visible = false;
                Ball_t->Enabled = false;
                Ball_t->Interval = 20;
                bounces = 0;
                pointLeft = 0;
                pointRight = 0;
                paddle1->Top = 170;
                paddle2->Top = 170;
                ball->Left = 536;
                ball->Top = 236;
                Label1->Visible = false;
                Label2->Visible = false;
                Label3->Visible = false;
                Label4->Visible = true;
                Button1->Visible = false;
                Button2->Visible = false;
                Button3->Visible = true;
                Form5->Visible = false;
       }
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
      Label4->Visible = false;
      Button3->Visible = false;

      x = -9; y = -4;

      ball->Visible = true;
      Ball_t->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
      if(Application->MessageBox("Czy na pewno chcesz wy??czy? gr??",
        "Potwierd?", MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
                Action=caNone;
        }
        else
        {
            Application->Terminate();
        }
}
//---------------------------------------------------------------------------

