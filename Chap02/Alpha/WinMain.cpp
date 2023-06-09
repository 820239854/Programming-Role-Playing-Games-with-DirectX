/**************************************************
WinMain.cpp
Chapter 2 Alpha Blending Demo

Programming Role-Playing Games with DirectX, 2nd Edition
by Jim Adams (Jan 2004)

Required libraries:
  D3D9.LIB
**************************************************/

// Include files
#include <windows.h>
#include <stdio.h>
#include "d3d9.h"

// Window handles, class and caption text
HWND          g_hWnd;
HINSTANCE     g_hInst;
static char   g_szClass[]   = "AlphaClass";
static char   g_szCaption[] = "Alpha Blending Demo by Jim Adams";

// The Direct3D and Device object
IDirect3D9       *g_pD3D       = NULL;
IDirect3DDevice9 *g_pD3DDevice = NULL;

// The 2-D vertex format and descriptor
typedef struct {
  FLOAT x, y, z;     // 2-D coordinates
  FLOAT rhw;         // rhw
  D3DCOLOR Diffuse;  // Diffuse color component
} sVertex;
#define VERTEXFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

// Vertex buffer
IDirect3DVertexBuffer9 *g_pVB      = NULL;

// Function prototypes
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrev,          \
                   LPSTR szCmdLine, int nCmdShow);
long FAR PASCAL WindowProc(HWND hWnd, UINT uMsg,              \
                           WPARAM wParam, LPARAM lParam);

BOOL DoInit();
BOOL DoShutdown();
BOOL DoFrame();
BOOL SetupMeshes();

int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrev,          \
                   LPSTR szCmdLine, int nCmdShow)
{
  WNDCLASSEX wcex;
  MSG        Msg;

  g_hInst = hInst;

  // Create the window class here and register it
  wcex.cbSize        = sizeof(wcex);
  wcex.style         = CS_CLASSDC;
  wcex.lpfnWndProc   = WindowProc;
  wcex.cbClsExtra    = 0;
  wcex.cbWndExtra    = 0;
  wcex.hInstance     = hInst;
  wcex.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = NULL;
  wcex.lpszMenuName  = NULL;
  wcex.lpszClassName = g_szClass;
  wcex.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
  if(!RegisterClassEx(&wcex))
    return FALSE;

  // Create the Main Window
  g_hWnd = CreateWindow(g_szClass, g_szCaption,
        WS_CAPTION | WS_SYSMENU,
        0, 0, 400, 400,
        NULL, NULL,
        hInst, NULL );
  if(!g_hWnd)
    return FALSE;
  ShowWindow(g_hWnd, SW_NORMAL);
  UpdateWindow(g_hWnd);

  // Run init function and return on error
  if(DoInit() == FALSE)
    return FALSE;

  // Start message pump, waiting for signal to quit
  ZeroMemory(&Msg, sizeof(MSG));
  while(Msg.message != WM_QUIT) {
    if(PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)) {
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
    }
    if(DoFrame() == FALSE)
      break;
  }

  // Run shutdown function
  DoShutdown();
  
  UnregisterClass(g_szClass, hInst);

  return Msg.wParam;
}

long FAR PASCAL WindowProc(HWND hWnd, UINT uMsg,              \
                           WPARAM wParam, LPARAM lParam)
{
  switch(uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL DoInit()
{
  D3DPRESENT_PARAMETERS d3dpp;
  D3DDISPLAYMODE        d3ddm;
  BYTE *Ptr;
  sVertex Verts[8] = {
      { 100.0f, 100.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(0,64,128,255) },
      { 300.0f, 100.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(0,64,128,255) },
      { 100.0f, 300.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(0,64,128,255) },
      { 300.0f, 300.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(0,64,128,255) },
      {  50.0f, 150.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(128,0,0,128)  },
      { 350.0f, 150.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(128,0,0,128)  },
      {  50.0f, 350.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(128,0,0,128)  },
      { 350.0f, 350.0f, 1.0f, 1.0f, D3DCOLOR_RGBA(128,0,0,128)  }
    };

  // Do a windowed mode initialization of Direct3D
  if((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
    return FALSE;
  if(FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
    return FALSE;
  ZeroMemory(&d3dpp, sizeof(d3dpp));
  d3dpp.Windowed = TRUE;
  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dpp.BackBufferFormat = d3ddm.Format;
  d3dpp.EnableAutoDepthStencil = FALSE;
  if(FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
                                  D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                  &d3dpp, &g_pD3DDevice)))
    return FALSE;

  // Create the vertex buffer and set data
  g_pD3DDevice->CreateVertexBuffer(sizeof(sVertex)*8, 0,      \
                          VERTEXFVF, D3DPOOL_DEFAULT,         \
                          &g_pVB, NULL);
  g_pVB->Lock(0,0, (void**)&Ptr, 0);
  memcpy(Ptr, Verts, sizeof(Verts));
  g_pVB->Unlock();

  return TRUE;
}

BOOL DoShutdown()
{
  // Release vertex buffer
  if(g_pVB != NULL)
    g_pVB->Release();

  // Release device and 3D objects
  if(g_pD3DDevice != NULL)
    g_pD3DDevice->Release();

  if(g_pD3D != NULL)
    g_pD3D->Release();

  return TRUE;
}

BOOL DoFrame()
{
  // Clear device backbuffer
  g_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET,               \
                           D3DCOLOR_RGBA(0,0,0,255), 1.0f, 0);

  // Begin scene
  if(SUCCEEDED(g_pD3DDevice->BeginScene())) {

    // Set the vertex stream and shader
    g_pD3DDevice->SetStreamSource(0, g_pVB, 0, sizeof(sVertex));
    g_pD3DDevice->SetFVF(VERTEXFVF);

    // Disable alpha blending and draw 2 polygons
    g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    g_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

    // Enable alpha blending and draw 2 polygons
    g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    g_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4, 2);

    // End the scene
    g_pD3DDevice->EndScene();
  }

  // Display the scene
  g_pD3DDevice->Present(NULL, NULL, NULL, NULL);

  return TRUE;
}
