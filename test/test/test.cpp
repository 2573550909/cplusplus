#pragma once
#include "UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

class CDuiFrameWnd : public WindowImplBase{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString GetSkinFile() { 
		return _T("giff.xml");
	}
	//����ָ���ļ��� ����ŵ���Ƥ��ͼƬ
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
	virtual void Notify(TNotifyUI& msg) {
		//���������Ϣ
		if (msg.sType == _T("click")) {
			CDuiString strControlName = msg.pSender->GetName();
			if (strControlName == _T("�رմ���")) {
				Close();
			}
			else if (strControlName == _T("��С������")) {
				SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
			}
			else if (strControlName== _T("�����ļ�")) {
				LoadFile();
			}
			else if (strControlName == _T("��ȡ��Ƶ")) {
				CutView();
			}
			else if (strControlName == _T("BTN_GENERATE")) {
				//GenerateAssFile();
			}
			else if (strControlName == _T("BTN_LOADA_ASS")) {
				//LoadAss();
			}
			else if (strControlName == _T("����gif")) {
				GenerateGifWithPic();
				//����ѡ��ʽ ͼƬ �� ��Ƶ
				/*CComboBoxUI* pCombBox = (CComboBoxUI*)
				if (pCombBox->GetCurSel()) {
					GenerateGifWithPic();
				}
				else {
					GenerateGifWithView();
				}*/
			}
		}
		//���ڵĳ�ʼ��
		else if (msg.sType == _T("windowinit")) {
			m_pEditStart = (CEditUI*)m_PaintManager.FindControl(_T("��ʼʱ��"));//������
			m_pEditStart->SetMaxChar(8);
			m_pEditFinish = (CEditUI*)m_PaintManager.FindControl(_T("����ʱ��"));
			m_pEditFinish->SetMaxChar(8);

			//m_pRichEditUI = (CRichEditUI*)m_PaintManager.FindControl(_T("RICH_EDIT_WORD"));
		}
		//else if (msg.sType == _T("itemselect")) {
		//	if (strControlName == _T("List_Time_word")) {
		//		//��list ��ѡ�е��ı���ӵ� RichEdit
		//		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("LIST_TIME_WORD;"));
		//		CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel);
		//		CDuiString strWord = pItem->GetText(1);

		//		m_pRichEditUI->SetText(strWord);
		//	}
		//}
	}

	//�����ļ���·��
	void LoadFile() {
		OPENFILENAME ofn;
		TCHAR FileName[MAX_PATH];
		memset(&ofn, 0, sizeof(OPENFILENAME));
		memset(FileName, 0, sizeof(char)*MAX_PATH);
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = _T("�����ļ�(*.*)\0*.bmp;*.tga;*.pcx;*.mp4;*.jpg;*.jpeg;*.gif\0");
		//ofn.lpstrFilter = _T("�ı��ĵ�\0*.TXT");
		ofn.lpstrFile = FileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_FILEMUSTEXIST;
		//FileName�õ��û���ѡ���ļ���·�� 
		if (GetOpenFileName(&ofn)){
			MessageBox(NULL, FileName, NULL, NULL);
		}
	}
	//��ȡ��Ƶ��Դ
	void CutView() {
		CDuiString strStartTime = m_pEditStart->GetText();
		if (!IsValidTime(strStartTime)) {
			MessageBox(m_hWnd,_T("��ʼʱ������"),_T("GIFF"),IDOK);
			return;
		}
		CDuiString strFinishTime = m_pEditFinish->GetText();
		if (!IsValidTime(strFinishTime)) {
			MessageBox(m_hWnd,_T("��ֹʱ������"),_T("GIFF"),IDOK);
			return;
		}

		//������Ƶ������
		CDuiString strCMD;
		strCMD += _T("ffmpeg -ss");
		strCMD += strStartTime;
		strCMD += _T(" -t ");
		strCMD += strFinishTime;
		strCMD += _T(" -i "); 

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("EDIF_PATH")))->GetText();
		strCMD += strViewPath;
		strCMD += _T("-vcodec copy - acodec copy output.avi");
		
		SendCMD(strCMD);
	}

	//���� cmd ��������
	void SendCMD(const CDuiString& strCMD) {

		//1. ��ʼ���ṹ��
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd.exe");

		// IpParameters ��Ӧ�����û�������
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE; //���� cmd ����

		//2. ����cmd����
		ShellExecuteEx(&strSEInfo);
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
	}
	//��ȡ��ǰ����·��
	void GenerateGifWithPic() {
		//��ȡ��debugĿ¼
		CDuiString strFFmpegPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD(_T("/c"));
		strCMD += strFFmpegPath;
		strCMD += _T("ffmprg\\ffmpeg -r 1 -i ");
		strCMD += strFFmpegPath;
		strCMD +=_T("ffmpeg\\Picture\\%d.jpg .\..\output.gif");

		//��������
		SendCMD(strCMD);
	}

	//������Ƶ���ɵ�·��
	void GenerateGifWithView() {
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD;
		strCMD += _T("/c");
		strCMD += _T("ffmpeg\\output.avi .\\..\\debug\\ffmpeg\\viewgif.gif");
		SendCMD(strCMD);
	}

	//�������ʱ�����ȷ
	bool IsValidTime(const CDuiString& strTime) {
		if (8 != strTime.GetLength()) {
			return false;
		}
		for (int i = 0; i < 8; ++i) {
			if (':' == strTime[i]) {
				continue;
			}else if (isdigit(strTime[i])) {
				continue;
			}else {
				return false;
			}
		}
		return true;
	}
private:
	CEditUI* m_pEditStart;
	CEditUI* m_pEditFinish;
	CEditUI* m_pRichEditUI;
	int m_iSelect;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}
