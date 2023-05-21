#ifndef CONSOLE_H
#define CONSOLE_H
#define _CRT_SECURE_NO_WARNINGS     //这个宏定义最好要放到.c文件的第一行
#include"DirectionalLight.h"
#include"AmbientLight.h"
#include"PointLight.h"
#include"Screen.h"
#include"Camera.h"
#include"Object.h"
#include"Sphere.h"
#include"Light.h"
#include"SVPNG.h"
#include"SVPNG.cpp"
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<stack>
#include<omp.h> 
#define DIGITWIDTH 30
#define DIGITHEIGHT 25
#define SIGNWIDTH 120
#define SIGNHEIGHT 25
using std::stringstream;
using std::fstream;
using std::reverse;
using std::string;
using std::vector;
using std::stack;
using std::pair;
using std::endl;
using std::ios;

static int Width = 1024;
static int Height = 1024;
static unsigned char image[1024 * 1024 * 3];
static char WhiteScreen[25 * 6 * 1024];
enum { BACKSPACE = 8, ENTER = 13, SPACEBAR = 32, UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80 };
enum { UI, LIGHT_UI, SPHERE_UI, MATERIAL_UI, PNGSIZE_UI, ADDLIGHT, DELETELIGHT, CHANGELIGHT, POINTLIGHT, AMBIENTLIGHT, DIRECTIONALLIGHT, ADDSPHERE, DELETESPHERE, CHANGESPHERE, ADDMATERIAL, DELETEMATERIAL, CHANGEMATERIAL, SEARCHMATERIAL };

class Console
{
public:
	static int x, y;
	static stack<int> stk;
	static vector<Light*> lights;
	static vector<Object*> objects;
	static vector<Material*> materials;

	static bool DLight[SIGNHEIGHT][SIGNWIDTH];
	static bool DSphere[SIGNHEIGHT][SIGNWIDTH];
	static bool DMaterial[SIGNHEIGHT][SIGNWIDTH];

	static bool AddLight[SIGNHEIGHT][SIGNWIDTH];
	static bool AddSphere[SIGNHEIGHT][SIGNWIDTH];
	static bool AddMaterial[SIGNHEIGHT][SIGNWIDTH];

	static bool DeleteLight[SIGNHEIGHT][SIGNWIDTH];
	static bool DeleteSphere[SIGNHEIGHT][SIGNWIDTH];
	static bool DeleteMaterial[SIGNHEIGHT][SIGNWIDTH];

	static bool ChangeLight[SIGNHEIGHT][SIGNWIDTH];
	static bool ChangeSphere[SIGNHEIGHT][SIGNWIDTH];
	static bool ChangeMaterial[SIGNHEIGHT][SIGNWIDTH];

	static bool Back[SIGNHEIGHT][SIGNWIDTH];
	static bool PNGsize[SIGNHEIGHT][SIGNWIDTH];
	static bool ExitSign[SIGNHEIGHT][SIGNWIDTH];
	static bool CreatePNG[SIGNHEIGHT][SIGNWIDTH];

	static bool PNG256[SIGNHEIGHT][SIGNWIDTH];
	static bool PNG512[SIGNHEIGHT][SIGNWIDTH];
	static bool PNG1024[SIGNHEIGHT][SIGNWIDTH];

	static bool DPointLight[SIGNHEIGHT][SIGNWIDTH];
	static bool DAmbientLight[SIGNHEIGHT][SIGNWIDTH];
	static bool DDirectionalLight[SIGNHEIGHT][SIGNWIDTH];

	static bool DDot[DIGITHEIGHT][DIGITWIDTH];
	static bool Minus[DIGITHEIGHT][DIGITWIDTH];
	static bool Digit[10][DIGITHEIGHT][DIGITWIDTH];

	static bool Colon[SIGNHEIGHT][SIGNWIDTH];
	static bool Confirm[SIGNHEIGHT][SIGNWIDTH];

	static bool Position[SIGNHEIGHT][SIGNWIDTH];
	static bool Intensity[SIGNHEIGHT][SIGNWIDTH];


	static bool DR[SIGNHEIGHT][SIGNWIDTH];
	static bool DO[SIGNHEIGHT][SIGNWIDTH];
	static bool DDirection[SIGNHEIGHT][SIGNWIDTH];

	static bool DColor[SIGNHEIGHT][SIGNWIDTH];
	static bool DSpecular[SIGNHEIGHT][SIGNWIDTH];
	static bool DReflective[SIGNHEIGHT][SIGNWIDTH];

	static bool NewMaterial[SIGNHEIGHT][SIGNWIDTH];
	static bool HadMaterial[SIGNHEIGHT][SIGNWIDTH];

	static bool Number[SIGNHEIGHT][SIGNWIDTH];
	static bool Search[SIGNHEIGHT][SIGNWIDTH];


	void Init();

	void InitData();

	void SaveData();

	void InitWhite();

	void InitBack();

	void InitLight();

	void InitSphere();

	void InitMaterial();

	void InitPNGsize();

	void InitCreatePNG();

	void InitExitSign();

	void InitAddLight();

	void InitAddSphere();

	void InitAddMaterial();

	void InitDeleteLight();

	void InitDeleteSphere();

	void InitDeleteMaterial();

	void InitChangeLight();

	void InitChangeSphere();

	void InitChangeMaterial();

	void Init256X256PNG();

	void Init512X512PNG();

	void Init1024X1024PNG();

	void InitPointLight();

	void InitAmbientLight();

	void InitDirectionalLight();

	void InitDot();

	void InitMinus();

	void InitDigit();

	void InitColon();

	void InitConfirm();

	void InitPosition();

	void InitIntensity();

	void InitR();

	void InitO();

	void InitDirection();

	void InitColor();

	void InitSpecular();

	void InitReflective();

	void InitNewMaterial();

	void InitHadMaterial();

	void InitNumber();
	
	void InitSearch();


	Color RandColor();


	void PrintSelectSign(const SHORT& X, const SHORT& Y, const Color& color);

	void PrintLight(const Color& color);

	void PrintSphere(const Color& color);

	void PrintMaterial(const Color& color);

	void PrintPNGsize(const Color& color);

	void PrintExitSign(const Color& color);

	void PrintCreatePNG(const Color& color);

	void ShowUI();


	void PrintBack(const Color& color);

	void PrintAddBack(const int& x, const int& y, const Color& color);


	void PrintAddLight(const Color& color);

	void PrintDeleteLight(const Color& color);

	void PrintChangeLight(const Color& color);

	void ShowLightUI();


	void PrintAddSphere(const Color& color);

	void PrintDeleteSphere(const Color& color);

	void PrintChangeSphere(const Color& color);

	void ShowSphereUI();


	void PrintAddMaterial(const Color& color);

	void PrintDeleteMaterial(const Color& color);

	void PrintChangeMaterial(const Color& color);

	void ShowMaterialUI();

	
	void Print256X256PNG(const Color& color);

	void Print512X512PNG(const Color& color);

	void Print1024X1024PNG(const Color& color);

	void ShowSizeUI();


	void PrintPointLight(const Color& color);

	void PrintAmbientLight(const Color& color);

	void PrintDirectionalLight(const Color& color);

	void ShowAddLightUI();


	void PrintDot(const int& x, const int& y, const Color& color);

	void PrintMinus(const int& x, const int& y, const Color& color);

	void PrintDigit(const int& x, const int& y, const int& d,const Color& color);


	void PrintConfirm(const int& x, const int& y, const Color& color);

	void PrintColon(const int& x, const int& y, const Color& color);

	void PrintPosition(const Color& color);

	void PrintIntensity(const Color& color);

	void PrintR(const Color& color);

	void PrintO(const Color& color);

	void PrintDirection(const Color& color);

	void PrintColor(const Color& color);

	void PrintSpecular(const Color& color);

	void PrintReflective(const Color& color);

	void PrintNewMaterial(const Color& color);

	void PrintHadMaterial(const Color& color);

	void PrintAddSphereUI(string r, string o);

	void PrintNumber(const Color& color);

	void PrintSearch(const Color& color);


	void CreatePicture();

	void PrintBlock(const int& x, const int& y, const int& height, const int& width, const Color& color);

	void ClearUI();

	void BackOperation();

	void UIMove();

	void SubUIMove();

	bool AddPointLightUI();

	bool AddAmbientUI();

	bool AddDirectionUI();

	bool AddSphereUI();

	void ShowLightSearch();

	void ShowLightNumber();

	void ShowObjectsSearch();

	void ShowObjectsNumber();

	pair<Material, bool> ShowMaterialsSearch();

	void ShowMaterialsNumber();

	 

	pair<Material, bool> AddMaterialUI();

	


	void Control();
};
#endif
