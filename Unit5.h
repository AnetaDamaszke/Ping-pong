//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
        TImage *background;
        TImage *ball;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *Ball_t;
        TTimer *paddle1up;
        TTimer *paddle1down;
        TTimer *paddle2up;
        TTimer *paddle2down;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TMediaPlayer *MediaPlayer1;
        void __fastcall Ball_tTimer(TObject *Sender);
        void __fastcall paddle1upTimer(TObject *Sender);
        void __fastcall paddle1downTimer(TObject *Sender);
        void __fastcall paddle2downTimer(TObject *Sender);
        void __fastcall paddle2upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
 