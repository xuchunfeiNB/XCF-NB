#include<windows.h>
#define X 250
#define Y 150
#define HEIGHT 600
#define WIDTH 900
#define NAME "TO 高二（4）电教"
//窗口处理函数
LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		TextOut(hdc, 70, 20, TEXT(" "), 0);
		
		EndPaint(hwnd, &ps);
		return 0;
	case WM_CLOSE:DestroyWindow(hwnd); break;
	case WM_DESTROY:PostQuitMessage(0); break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

int WINAPI WinMain(HINSTANCE hInsance, HINSTANCE hPreInstance, LPSTR lpCmdtine, int nCmdShow) 
{
	
	//弹出一个窗口
	//MessageBox(NULL, L"打劫", L"南通社会人徐飞 ", MB_YESNO|MB_ICONERROR); //弹出窗口
	//窗口应用：
	//1设计窗口类
	wchar_t szAppClassName[] = L"XuChunFeiNB";
	WNDCLASS wc;
	wc.style = CS_HREDRAW|CS_VREDRAW;//风格
	wc.lpfnWndProc = WindowsProc;//窗口处理
	wc.cbClsExtra = 0; //窗口类的额外空间内存
	wc.cbWndExtra = 0; //窗口额外空间内存大小
	wc.hInstance = hInsance;//实例句柄类型
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);//加载左上角图标
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(0,255,0));
	wc.lpszMenuName = NULL; 
	wc.lpszClassName = szAppClassName; //窗口类型名



	//2注册窗口类
	if (RegisterClass(&wc) == false) {
		MessageBox(NULL, L"窗口创建失败！", L"错误！", MB_RETRYCANCEL | MB_ICONERROR);
		return 0;
	}


	//3创建窗口
	HWND hWnd= CreateWindow(
		szAppClassName,     //name
		L"TO 高二（4）电教", //title
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //style
		X,//x
		Y,//y
		WIDTH,//width
		HEIGHT,//height
		NULL,//fu窗口
		NULL,//菜单
		hInsance,//实例句柄
		NULL //extra 消息
	);
	//4显示窗口
	ShowWindow(hWnd,SW_SHOW);
	//5更新
	UpdateWindow(hWnd);
	//6消息循环
	MSG msg;
	while (GetMessage(&msg,NULL,0,0)) {
		//虚拟键消息转换为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}

	return 0;
}
