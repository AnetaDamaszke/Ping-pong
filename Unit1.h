//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *background1;
        TImage *ball;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *Ball_t;
        TTimer *Paddle1up;
        TTimer *Paddle1down;
        TTimer *Paddle2up;
        TTimer *Paddle2down;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        void __fastcall Ball_tTimer(TObject *Sender);
        void __fastcall Paddle1downTimer(TObject *Sender);
        void __fastcall Paddle1upTimer(TObject *Sender);
        void __fastcall Paddle2downTimer(TObject *Sender);
        void __fastcall Paddle2upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
