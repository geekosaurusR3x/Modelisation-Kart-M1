#if !defined(AFX_PANEL_H__FD8E7433_5688_4972_B462_440782798CDC__INCLUDED_)
#define AFX_PANEL_H__FD8E7433_5688_4972_B462_440782798CDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Panel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Panel dialog

class Panel : public CDialog
{
// Construction
public:
	Panel(CWnd* pParent , UINT id);   // standard constructor

	void Creer(CPoint hg, int largeur, int hauteur);
	void PostNcDestroy( );
	int Width;
	int Height;
	UINT Id() const;

// Dialog Data
	//{{AFX_DATA(Panel)
//	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Panel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


	
protected:

	// Generated message map functions
	//{{AFX_MSG(Panel)
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	bool  cree;
	UINT idd;
	


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANEL_H__FD8E7433_5688_4972_B462_440782798CDC__INCLUDED_)
