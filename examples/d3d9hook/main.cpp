// Copyright (C) 2010-2013 Joshua Boyce.
// See the file COPYING for copying permission.

#include <windows.h>

#include <hadesmem/error.hpp>
#include <hadesmem/config.hpp>

#include "d3d9mgr.hpp"

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved);

extern "C" HADESMEM_DLLEXPORT DWORD_PTR Load(LPCVOID module);

extern "C" HADESMEM_DLLEXPORT DWORD_PTR Free(LPCVOID module);

extern "C" HADESMEM_DLLEXPORT DWORD_PTR Load(LPCVOID /*module*/)
{
  try
  {
    InitializeD3D9Hooks();
  }
  catch (std::exception const& e)
  {
    // TODO: Add proper logging.
    OutputDebugStringA(boost::diagnostic_information(e).c_str());
  }

  return 0;
}

extern "C" HADESMEM_DLLEXPORT DWORD_PTR Free(LPCVOID /*module*/)
{
  return 0;
}

BOOL WINAPI DllMain(HINSTANCE /*instance*/, DWORD /*reason*/, 
  LPVOID /*reserved*/)
{
  return TRUE;
}