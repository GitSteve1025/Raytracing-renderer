#define _CRT_SECURE_NO_WARNINGS     //这个宏定义最好要放到.c文件的第一行
#include<iostream>
#include<fstream>
#include"DirectionalLight.h"
#include"AmbientLight.h"
#include"PointLight.h"
#include"Object.h"
#include"Sphere.h"
#include"Camera.h"
#include"Screen.h"
#include"Console.h"
#include<omp.h> 
using namespace std;

void CreateUI() 
{
    SetConsoleTitle(L"加载中");
    int HEIGHT = 1024;
    int WIDTH = 1024;
    Object* p1 = new Sphere(100, { 100, 0, 50 }, { {0, 0, 155}, 300, 0.3 });
    Object* p2 = new Sphere(100, { -100, 0, 50 }, { {0, 155, 0}, 700, 0.3 });
    Object* p3 = new Sphere(2650, { 0, -2500, 1000 }, { {155, 155, 0},0, 0 });
    Object* p4 = new Sphere(100, { -300, -20, -100 }, { {255, 0, 255}, 1000, 0.5 });
    Object* p5 = new Sphere(100, { 300, -20, -100 }, { {155, 155, 155}, 4000, 0.2 });
    Object* p6 = new Sphere(100, { 0, -150, -450 }, { {255, 0, 0}, 100, 0.1 });
    Light* l1 = new AmbientLight(0.3);
    Light* l2 = new PointLight({ 100, 500, -700 }, 0.5);
    vector<Light*> light;
    light.push_back(l1);
    light.push_back(l2);
    vector<Object*> Objects;
    Objects.push_back(p1);
    Objects.push_back(p2);
    Objects.push_back(p3);
    Objects.push_back(p4);
    Objects.push_back(p5);
    Objects.push_back(p6);
    Camera Cam({ 0, 0, -(double)HEIGHT }, WIDTH, HEIGHT, (double)HEIGHT);
    int XHalf = WIDTH / 2;
    int YHalf = HEIGHT / 2;
    InitScreen(WIDTH, HEIGHT / 2, 1);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int X = XHalf - j;
            int Y = YHalf - i;
            Ray ray = Cam.GetRay(X, Y);
            Color color = Cam.RayTracing(Objects, light, ray);
            if (i & 1) 
            {
                PutColor(j, i / 2, color);
            }
        }
    }
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete l1;
    delete l2;
    SetConsoleTitle(L"RayTracing");
}

int main()
{
    srand((unsigned int)time(NULL));
    CreateUI();
    Console C;
    C.Init();
    C.ShowUI();
    C.Control();
	return 0;
}