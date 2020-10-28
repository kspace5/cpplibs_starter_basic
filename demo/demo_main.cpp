#include <Windows.h>
#include <iostream>
#include <string>
#include <stddef.h>
#include <stdlib.h>

#define __SIZE_TYPE__ uintptr_t // Check if good

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

typedef struct TessT {
	float f1;
	float f2;
	float f3;
	float f4;
	float f5;
	int32_t v1;
	int32_t v2;
} Tess;

typedef struct Proc2_returnT {
	GoInt r0;
	GoInt r1;
	GoFloat32 r2;
} Proc2_return;

typedef struct RectT {
	GoInt width;
	GoInt height;
} Rect;

typedef struct AShapesT {
	Rect r1, r2, r3;
} AShapes;

typedef Mat (*CHECK_EVEN_ODD_FNPTR)(int);
typedef GoInt (*Add_FNPTR)(GoInt a, GoInt b);
typedef Proc2_return(*PROC2_FNPTR)(GoInt a, GoInt b);

typedef GoUintptr(*PROC1_FNPTR)(GoInt a);
typedef void(*PROC1FREE_FNPTR)(GoUintptr ptr);


//typedef AShapes (*PROC1_FNPTR)();
//typedef Rect(*PROC2_FNPTR)();


int main()
{
	//Enter the dll path here, after building "GetEvenOdd.sln" project. (Don't forget to out double backslash(\\) in the Path
	//HINSTANCE hInst_fgproc_dll = LoadLibrary("C:/KSPACE/204_SEASON/go_lab_starter/golib1/fgproc.dll");

	//if (!hInst_fgproc_dll)
	//{
	//	std::cout << "\nCould Not Load the Library:hInst_fgproc_dll";
	//	return EXIT_FAILURE;
	//}

	//HINSTANCE hInst_awesome_dll = LoadLibrary("C:/KSPACE/204_SEASON/go_lab_starter/awesome.dll");
	HINSTANCE hInst_awesome_dll = LoadLibrary("C:/KSPACE/204_SEASON/cgo-by-example/gbridge01.dll");

	if (!hInst_awesome_dll)
	{
		std::cout << "\nCould Not Load the Library:hInst_awesome_dll";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	//CHECK_EVEN_ODD_FNPTR fn_1 = (CHECK_EVEN_ODD_FNPTR)GetProcAddress(hInst_fgproc_dll, "CheckEvenOdd");
	//if (!fn_1)
	//{
	//	std::cout << "\nCould not locate the function";
	//	return EXIT_FAILURE;
	//}


	//Resolve the function address
	Add_FNPTR fn_add = (Add_FNPTR)GetProcAddress(hInst_awesome_dll, "Add");
	if (!fn_add)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	PROC2_FNPTR fn_proc2 = (PROC2_FNPTR)GetProcAddress(hInst_awesome_dll, "Proc2");
	if (!fn_proc2)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	PROC1FREE_FNPTR fn_PROC1FREE = (PROC1FREE_FNPTR)GetProcAddress(hInst_awesome_dll, "Proc1Free");
	if (!fn_PROC1FREE)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	PROC1_FNPTR fn_proc1 = (PROC1_FNPTR)GetProcAddress(hInst_awesome_dll, "Proc1");
	if (!fn_proc1)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}
	//GoUintptr retptrT = fn_proc1(34);
	//char* retptr = (char*)retptrT;
	//std::string str = retptr;
	//std::cout << "\nCGO says :" << str;
	//fn_PROC1FREE(retptrT);

	GoUintptr retptrT = fn_proc1(34);
	Tess* tessarray = (Tess*)retptrT;

	std::cout << "\nTESS from CGO says :" << tessarray[0].f1 << "|" << tessarray[8].v2 << std::endl;
	fn_PROC1FREE(retptrT);


	//free(retptr);
	//int iNum = 0;
	//std::cout << "\nPlease Enter a number: ";
	////std::cin >> iNum;
	//iNum = 4;
	//Mat m = fn_1(iNum);
	//std::cout << "\nThe DLL Says: " << m.title << m.mat_id2;

	std::cout << "\nThe GO DLL Says: " << fn_add(2, 4) << std::endl;
	std::cout << "\nThe GO DLL Says: " << fn_add(4, 3) << std::endl;
	std::cout << "\nThe GO DLL Says: " << fn_add(4, 3) << std::endl;
	std::cout << "\nThe GO DLL Says: " << fn_add(4, 3) << std::endl;
	fn_add = nullptr;

	Proc2_return pr = fn_proc2(3, 4);
	std::cout << "\nThe GO DLL Says: " << pr.r0 << ":" << pr.r2 << std::endl;


	//std::cout << "\nThe GO DLL Says: " << fn_add(2, 4) << std::endl;
	//
	//PROC2_FNPTR fn_rect = (PROC2_FNPTR)GetProcAddress(hInst_awesome_dll, "Proc2");
	//if (!fn_rect)
	//{
	//	std::cout << "\nCould not locate the function:RectList";
	//	return EXIT_FAILURE;
	//}
	////https://stackoverflow.com/questions/52309383/how-to-return-a-slice-in-go-and-calling-from-c
	//Rect rect = fn_rect();
	////Rect* rectlist = (Rect*)rect_list.data;

	//std::cout << "\nThe GO DLL Says: " << rect.height << std::endl;
	
	if (hInst_awesome_dll)
	{
		//FreeLibrary(hInst_awesome_dll); // Crashing here
		hInst_awesome_dll = nullptr;
	}
	//FreeLibrary(hInst_fgproc_dll);
	//FreeLibrary(hInst_awesome_dll);
	
	return EXIT_SUCCESS;
}