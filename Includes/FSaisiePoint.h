#ifndef _FSAISIEPOINT_H_
#define _FSAISIEPOINT_H_

#include "afxwin.h"	// Pour CDialog

class FSaisiePoint : public CDialog
{
// Construction
public:
   DECLARE_DYNCREATE(FSaisiePoint)
   //FSaisiePoint();
   FSaisiePoint(CWnd* pParent = NULL, const char *szTitle = "",int x = 10,int y = 10,int cx = 200,int cy = 80);   // standard constructor

    ~FSaisiePoint();
	 LPDLGTEMPLATE lpdt;
	 void Initialiser();
	 void OnOK() ;
	 void OnCancel();
// Dialog Data
   //{{AFX_DATA(FSaisiePoint)
      // NOTE: the ClassWizard will add data members here
   //}}AFX_DATA
   void SetDynamicDlg(int x,int y,int cx,int cy,const char *szTitle,CWnd* pParent = NULL);
// Implementation
private:
   HGLOBAL m_hgbl;
	CButton	*OKButton,
				*CancelButton;
	CEdit		*XEdit,
				*YEdit,
				*ZEdit;
	CStatic	*XText,
				*YText,
				*ZText;
protected:

   // Generated message map functions
   //{{AFX_MSG(FSaisiePoint)
      // NOTE: the ClassWizard will add member functions here
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
}; 

#endif