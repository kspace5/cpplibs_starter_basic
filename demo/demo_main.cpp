#include <Windows.h>
#include <iostream>
#include <string>
#include <stddef.h>

#define __SIZE_TYPE__ long unsigned int

//--GO--
typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;

typedef struct { void* t; void* v; } GoInterface;
typedef struct { void* data; GoInt len; GoInt cap; } GoSlice;

//--end--

typedef struct MatT {
	char  title[50];
	int   mat_id1;
	int   mat_id2;
	int   mat_id3;
	float   mat_id4;
} Mat;


typedef struct RectT {
	GoInt width;
	GoInt height;
} Rect;

typedef Mat (*CHECK_EVEN_ODD_FNPTR)(int);
typedef GoInt (*Add_FNPTR)(GoInt a, GoInt b);
//typedef Rvoiect* (*PROC1_FNPTR)();


int main()
{
	//Enter the dll path here, after building "GetEvenOdd.sln" project. (Don't forget to out double backslash(\\) in the Path
	HINSTANCE hInst_fgproc_dll = LoadLibrary("C:/KSPACE/204_SEASON/go_lab_starter/golib1/fgproc.dll");

	if (!hInst_fgproc_dll)
	{
		std::cout << "\nCould Not Load the Library:hInst_fgproc_dll";
		return EXIT_FAILURE;
	}

	HINSTANCE hInst_awesome_dll = LoadLibrary("C:/KSPACE/204_SEASON/go_lab_starter/awesome.dll");
	if (!hInst_awesome_dll)
	{
		std::cout << "\nCould Not Load the Library:hInst_awesome_dll";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	CHECK_EVEN_ODD_FNPTR fn_1 = (CHECK_EVEN_ODD_FNPTR)GetProcAddress(hInst_fgproc_dll, "CheckEvenOdd");
	if (!fn_1)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}


	//Resolve the function address
	Add_FNPTR fn_add = (Add_FNPTR)GetProcAddress(hInst_awesome_dll, "Add");
	if (!fn_add)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}

	int iNum = 0;
	std::cout << "\nPlease Enter a number: ";
	//std::cin >> iNum;
	iNum = 4;
	Mat m = fn_1(iNum);
	std::cout << "\nThe DLL Says: " << m.title << m.mat_id2;

	std::cout << "\nThe GO DLL Says: " << fn_add(2, 4) << std::endl;
	/*
	PROC1_FNPTR fn_rectlist = (PROC1_FNPTR)GetProcAddress(hInst_awesome_dll, "Proc1");
	if (!fn_rectlist)
	{
		std::cout << "\nCould not locate the function:RectList";
		return EXIT_FAILURE;
	}
	//https://stackoverflow.com/questions/52309383/how-to-return-a-slice-in-go-and-calling-from-c
	Rect rect_list = fn_rectlist();
	//Rect* rectlist = (Rect*)rect_list.data;

	std::cout << "\nThe GO DLL Says: " << rect_list[0].width << std::endl;
	*/
	FreeLibrary(hInst_fgproc_dll);

	return EXIT_SUCCESS;
}