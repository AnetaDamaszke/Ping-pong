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
        TTimer *Ball_;
        TTimer *Paddle1up;
        TTimer *Paddle1down;
        TTimer *Paddle2up;
        TTimer *Paddle2down;
        void __fastcall Ball_Timer(TObject *Sender);
        void __fastcall Paddle1downTimer(TObject *Sender);
        void __fastcall Paddle1upTimer(TObject *Sender);
        void __fastcall Paddle2downTimer(TObject *Sender);
        void __fastcall Paddle2upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
