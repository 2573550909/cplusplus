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
				//MessageBox(NULL, _T("ȷ�Ϲر�"), _T("GIFF"), IDOK);
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
		}
	}

	//�����ļ���·��
	void LoadFile() {
		OPENFILENAME ofn;
		char FileName[MAX_PATH];
		memset(&ofn, 0, sizeof(OPENFILENAME));
		memset(FileName, 0, sizeof(char)*MAX_PATH);
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = _T("�ı��ĵ�\0*.TXT");
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
private:
	CEditUI* m_pEditStart;
	CEditUI* m_pEditFinish;
public:
	//��ȡ��ǰ����·��
	void GenerateGifWithPic() {
		CDuiString strFFmpegPath = CPaintManagerUI::GetInstancePath();

		//��������
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strFFmpegPath;
		//����ͼƬ������
		strCMD += (_T("ffmprg\\ffmpeg -r 1 -i"));
		strCMD += strFFmpegPath;
		strCMD += (_T("ffmpeg\\Picture\\%d.jpg output.gif"));

		//��������
		SendCMD(strCMD);
	}

	void GenerateGifWithView() {
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		//
		strCMD += _T("ffmpeg\\output.avi .\\..\\debug\\ffmpeg\\viewgif.gif");
		SendCMD(strCMD);
	}

	bool IsValidTime(const CDuiString& strTime) {
		if (8 != strTime.GetLength()) {
			return false;
		}
		for (int i = 0; i < 8; ++i) {
			if (':' == strTime[i]) {
				continue;
			}
			else if (isdigit(strTime[i])) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
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
