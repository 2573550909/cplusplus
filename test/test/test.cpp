#pragma once
#include "UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "F:\\c_exercise\\xiaomaze\\test\\test\\lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetText(_T("Hello World"));   // ��������
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};
#endif
//================================================

#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { 
		return _T("DUIMainFrame");
	}
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   
			// duilib.xml��Ҫ�ŵ�exeĿ¼��
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this); 
			// ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ����
			//���ǿ�����Notify����������Ϣ����
			return lRes;

#if 0
			CControlUI *pWnd = new CButtonUI;
			// ���ÿؼ������ƣ�����������ڱ�ʶÿһ���ؼ���
			//����Ψһ���൱��MFC����Ŀؼ�ID	
			pWnd->SetName(_T("btnHello"));      

			pWnd->SetText(_T("Hello World"));   // ��������
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ
			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);

			m_PaintManager.AddNotifier(this); 
			// ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ����
			//���ǿ�����Notify����������Ϣ����
			return lRes;
#endif
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();//������ʾ
	duiFrame.ShowModal();
	return 0;
}
#endif	

#if 0
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { 
		return _T("DUIMainFrame_Maze");
	}
	virtual CDuiString GetSkinFile(){ 
		return _T("duilib.xml"); 
	}

	virtual CDuiString GetSkinFolder(){ 
		return _T("");
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}
#endif

#if 0
class CDuiFramWnd : public CWindowWnd , public INotifyUI
{
public:
	// CWindowWnd��Ĵ��麯�����ڸú����б��뷵���û������崰�ڵ������ƣ�
	//ע�ᴰ��ʱ��Ҫ�õ�
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}

	//����һ����ť
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			// ����һ����ť
			CControlUI *pWnd = new CButtonUI;
			// ���ð�ť�ϵ���ʾ�ı�
			pWnd->SetText(_T("Hello World"));
			// ��ť�ı�����ɫ
			pWnd->SetBkColor(0xFF00FF00);

			// ��ʼ��m_PaintManager����Ĵ��ھ����������Ϣʱ��Ҫ�õ�	
			m_PaintManager.Init(m_hWnd);
			// ����ť���������ƹ�������
			m_PaintManager.AttachDialog(pWnd);

			// ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ����
			// �Ϳ�����Notify����������Ϣ����
			m_PaintManager.AddNotifier(this);

			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
		// ע�⣺__superΪvs��չ��һ���ؼ��֣���˼�ǵ��û���ĳ�Ա
		// �û���WM_CREATE��Ϣ�����������Ϣ���������HandleMessage
		//�������д���
		return __super::HandleMessage(uMsg, wParam, lParam);
	}

	// �Ի��� Notify �麯��������д
	virtual void Notify(TNotifyUI& msg){
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("Hello Maze"), _T("DuiFramWnd"), IDOK);
		}
	}

private:
	CPaintManagerUI m_PaintManager;
};
#endif
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("Cashier.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("Hello World"), _T("DuiFramWnd"), IDOK);
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ�
	//���б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);//��ʾ���ڣ�������Ϣѭ��
	framWnd.ShowModal();

	return 0;
}