// Disarm Grenades For GTA SA

int _tick = 0;


int main()
{
 while(true)
 {
  if(_tick < GetTickCount())
  {
    if(*(DWORD*)0xB6F5F0 != NULL) // IsPed
    {
      for (byte i = 0; i < 32; i++)
      {
        if (*(DWORD*)(0xC891A8 + i * 0x24) == 16 || *(DWORD*)(0xC891A8 + i * 0x24) == 18)
        {
         *(byte*)(0xC891A8 + i * 0x24 + 0x10) = 0;
        }
      }
    }
    _tick = GetTickCount() + 800;
  }  
 }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
 switch (fdwReason)
 {
     case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, NULL, 0, 0);
            break;
  }
  return true;
 }
