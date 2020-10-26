#include <Windows.h>
#include <iostream>
#include <string>


typedef struct MatT {
	char  title[50];
	int   mat_id1;
	int   mat_id2;
	int   mat_id3;
	float   mat_id4;
} Mat;

typedef Mat(*FNPTR)(int);

int main()
{
	//Enter the dll path here, after building "GetEvenOdd.sln" project. (Don't forget to out double backslash(\\) in the Path
	HINSTANCE hInst = LoadLibrary("E:/mnt/spacerock/35_ENGINE_BASE_CYGNUS/A_GO_LAB/go_lab_starter/golib1/fgproc.dll");

	if (!hInst)
	{
		std::cout << "\nCould Not Load the Library";
		return EXIT_FAILURE;
	}

	//Resolve the function address
	FNPTR fn = (FNPTR)GetProcAddress(hInst, "CheckEvenOdd");
	if (!fn)
	{
		std::cout << "\nCould not locate the function";
		return EXIT_FAILURE;
	}

	int iNum = 0;
	std::cout << "\nPlease Enter a number: ";
	//std::cin >> iNum;
	iNum = 4;
	Mat m = fn(iNum);
	std::cout << "\nThe DLL Says: " << m.title << m.mat_id1;

	FreeLibrary(hInst);

	return EXIT_SUCCESS;
}