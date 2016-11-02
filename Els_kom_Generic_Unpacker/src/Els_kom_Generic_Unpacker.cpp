/*
	Els_kom_Generic_Unpacker.cpp
*/
/*
	Crypto++ Wrapper for Els_kom to support Algorithm 3 in kom files.
	Note: This is a work in Progress it does not work with Algorithm 3 yet.
*/

/*
	TODO: Use zlib for CRC32 Calculating here. Will also be used for Calculating the Checksum and FileTimes datas in a CRC XML file.
*/

#ifdef __CPLUSPLUS
extern "C" {
#endif

#include <Windows.h>
#include <string>
#include "Alg0.h"
#include "Alg1.h"
#include "Alg2.h"
#include "Alg3.h"
#include "Els_kom_Generic_Unpacker.h"
#include "ZManager.h"

static HINSTANCE Els_kom_Wrapper_inst;

int Unpack_Alg0(std::string FileName)
{
	Alg0_Unpacker(FileName);
	return 0;
}

int Unpack_Alg1(std::string FileName)
{
	Alg1_Unpacker(FileName);
	return 0;
}

int Unpack_Alg2(std::string FileName)
{
	Alg2_Unpacker(FileName);
	return 0;
}

int Unpack_Alg3(std::string FileName)
{
	Alg3_Unpacker(FileName);
	return 0;
}

int Pack_Alg0(std::string FileName)
{
	Alg0_Packer(FileName);
	return 0;
}

int Pack_Alg1(std::string FileName)
{
	Alg1_Packer(FileName);
	return 0;
}

int Pack_Alg2(std::string FileName)
{
	Alg2_Packer(FileName);
	return 0;
}

int Pack_Alg3(std::string FileName)
{
	Alg3_Packer(FileName);
	return 0;
}

Els_kom_Wrapper_Extern int __cdecl Unpack_KOM_Generic(std::string FileName, int Alg)
{
	/*
		This Function is simply a Good way of Calling the Actual Unpackers so that way I can just Export 2 functions in total.
	*/
	/*
		This now Expects that the Compressed Data files awas saved to Process them after Saving the Files on disc to iterate through afterwards.
		This is one of the only ways to do this I think and have zlib to not worry about it.
	*/
	if (Alg == 0)
	{
		Unpack_Alg0(FileName);
	}
	if (Alg == 1)
	{
		//NOT USED SO UNPACKING FROM ALG 1 IS IMPOSSIBLE.
		Unpack_Alg1(FileName);
	}
	if (Alg == 2)
	{
		Unpack_Alg2(FileName);
	}
	if (Alg == 3)
	{
		Unpack_Alg3(FileName);
	}
	return 0;
}

Els_kom_Wrapper_Extern int __cdecl Pack_KOM_Generic(std::string FileName, int Alg)
{
	/*
		This Function is simply a Good way of Calling the Actual Packers so that way I can just Export 2 functions in total.
	*/
	if (Alg == 0)
	{
		Pack_Alg0(FileName);
	}
	if (Alg == 1)
	{
		//NOT USED SO PACKING TO ALG 1 IS IMPOSSIBLE.
		Pack_Alg1(FileName);
	}
	if (Alg == 2)
	{
		Pack_Alg2(FileName);
	}
	if (Alg == 3)
	{
		Pack_Alg3(FileName);
	}
	return 0;
}

Els_kom_Wrapper_Extern int __cdecl GetCRC32FromFile(std::string FileName)
{
	int value;
	value = CalculateCRC32(FileName);
	return value;
}

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			Els_kom_Wrapper_inst=hDLL;
			DisableThreadLibraryCalls(hDLL);
			break;
	}
	return TRUE;
}

#ifdef __CPLUSPLUS
}
#endif