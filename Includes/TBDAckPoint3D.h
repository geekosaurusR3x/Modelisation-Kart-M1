//----------------------------------------------------------------------------
#ifndef TBDAckPoint3DH
#define TBDAckPoint3DH

class TOKBottomDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TLabel *LabelX;
	TLabel *LabelY;
	TLabel *LabelZ;
	TEdit *EditX;
	TEdit *EditY;
	TEdit *EditZ;
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall EditXChange(TObject *Sender);
	void __fastcall EditYChange(TObject *Sender);
	void __fastcall EditZChange(TObject *Sender);
private:
public:
	virtual __fastcall TOKBottomDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg *OKBottomDlg;
//----------------------------------------------------------------------------
#endif    
