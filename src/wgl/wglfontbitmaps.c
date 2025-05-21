/*
 * Copyright (C) 2016, VMware, Inc.
 *
 * SPDX-License-Identifier: MIT
 */

#include <windows.h>
#include <stdlib.h>
#include <GL/gl.h>

int
main(int argc, char *argv[])
{
   WNDCLASS wc;
   HWND hwnd;
   HDC hdc;
   PIXELFORMATDESCRIPTOR pfd;
   int iPixelFormat;
   HGLRC hglrc;

   ZeroMemory(&wc, sizeof wc);
   wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc = DefWindowProc;
   wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   wc.hCursor = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
   wc.lpszClassName = "wglfont";

   if (!RegisterClass(&wc)) {
      abort();
   }

   hwnd = CreateWindowEx(0,
                         wc.lpszClassName,
                         "wglfont",
                         WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_TILEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                         NULL, NULL,
                         wc.hInstance,
                         NULL);
   if (!hwnd) {
      abort();
   }

   hdc = GetDC(hwnd);
   if (!hdc) {
      abort();
   }

   ZeroMemory(&pfd, sizeof pfd);
   pfd.nSize = sizeof pfd;
   pfd.nVersion = 1;
   pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
   pfd.iPixelType = PFD_TYPE_RGBA;
   pfd.cColorBits = 24;
   pfd.cDepthBits = 0;
   pfd.iLayerType = PFD_MAIN_PLANE;

   iPixelFormat = ChoosePixelFormat(hdc, &pfd);
   if (!iPixelFormat) {
      abort();
   }

   if (!SetPixelFormat(hdc, iPixelFormat, &pfd)) {
      abort();
   }

   hglrc = wglCreateContext(hdc);
   if (!hglrc) {
      abort();
   }

   wglMakeCurrent(hdc, hglrc);

   glClearColor(0.0, 0.0, 0.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   SelectObject(hdc, GetStockObject(SYSTEM_FONT));

   wglUseFontBitmaps(hdc, 0, 256, 1000);

   glListBase(1000);

   glCallLists(12, GL_UNSIGNED_BYTE, "Hello World!");

   SwapBuffers(hdc);

   Sleep(1000);

   wglMakeCurrent(NULL, NULL);

   wglDeleteContext(hglrc);

   ReleaseDC(hwnd, hdc);

   DestroyWindow(hwnd);

   return 0;
}
