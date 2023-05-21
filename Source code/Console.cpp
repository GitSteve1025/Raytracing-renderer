#include"Console.h"

int Console::x = 0;
int Console::y = 0;
stack<int> Console::stk;
vector<Light*> Console::lights;
vector<Object*> Console::objects;
vector<Material*> Console::materials;

bool Console::DLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DSphere[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::AddLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::AddSphere[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::AddMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::DeleteLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DeleteSphere[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DeleteMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::ChangeLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::ChangeSphere[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::ChangeMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::Back[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::PNGsize[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::ExitSign[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::CreatePNG[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::PNG256[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::PNG512[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::PNG1024[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::DPointLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DAmbientLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DDirectionalLight[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::DDot[DIGITHEIGHT][DIGITWIDTH] = { 0 };
bool Console::Minus[DIGITHEIGHT][DIGITWIDTH] = { 0 };
bool Console::Digit[10][DIGITHEIGHT][DIGITWIDTH] = { 0 };

bool Console::Colon[SIGNHEIGHT][SIGNWIDTH];
bool Console::Confirm[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::Position[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::Intensity[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::DR[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DO[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DDirection[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::DColor[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DSpecular[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::DReflective[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::NewMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::HadMaterial[SIGNHEIGHT][SIGNWIDTH] = { 0 };

bool Console::Number[SIGNHEIGHT][SIGNWIDTH] = { 0 };
bool Console::Search[SIGNHEIGHT][SIGNWIDTH] = { 0 };

static int UIPOS[3][2][2] = { { { 250, 50 }, { 550, 50 } }, { { 250, 100 },{ 550, 100 } },{ { 250, 150 }, { 550, 150 } } };
static int ADDUIPOS[6] = { 50, 75, 100, 125, 150, 175 };

vector<string> Spilt(string s, char del)
{
    vector<string> ans;
    stringstream ss;
    ss << s;
    while (getline(ss, s, del))
    {
        ans.push_back(s);
    }
    return ans;
}


void Console::Init()
{
    InitBack();
    InitData();
    InitWhite();
    InitLight();
    InitSphere();
    InitMaterial();
    InitPNGsize();
    InitExitSign();
    InitCreatePNG();
    InitAddLight();
    InitAddSphere();
    InitAddMaterial();
    InitDeleteLight();
    InitDeleteSphere();
    InitDeleteMaterial();
    InitChangeLight();
    InitChangeSphere();
    InitChangeMaterial();
    Init256X256PNG();
    Init512X512PNG();
    Init1024X1024PNG();
    InitPointLight();
    InitAmbientLight();
    InitDirectionalLight();
    InitDot();
    InitMinus();
    InitDigit();
    InitPosition();
    InitIntensity();
    InitColon();
    InitConfirm();
    InitR();
    InitO();
    InitDirection();
    InitColor();
    InitSpecular();
    InitReflective();
    InitNewMaterial();
    InitHadMaterial();
    InitNumber();
    InitSearch();
    stk.push(UI);
}

void Console::InitData()
{
    string s;
    fstream plfs("./Data/PointLight.txt", ios::in);
    if (!plfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    while (!plfs.eof())
    {
        getline(plfs, s);
        vector<string> ans = Spilt(s, ' ');
        if (ans.size() != 4)
        {
            break;
        }
        Light* l = new PointLight({ stod(ans[0]), stod(ans[1]), stod(ans[2]) }, stod(ans[3]));
        lights.push_back(l);
    }
    plfs.close();

    fstream alfs("./Data/AmbientLight.txt", ios::in);
    if (!alfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    while (!alfs.eof())
    {
        getline(alfs, s);
        vector<string> ans = Spilt(s, ' ');
        if (ans.size() != 1)
        {
            break;
        }
        Light* l = new AmbientLight(stod(ans[0]));
        lights.push_back(l);
    }
    alfs.close();

    fstream dlfs("./Data/DirectionalLight.txt", ios::in);
    if (!dlfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    while (!dlfs.eof())
    {
        getline(dlfs, s);
        vector<string> ans = Spilt(s, ' ');
        if (ans.size() != 4)
        {
            break;
        }
        Light* l = new DirectionalLight({ stod(ans[0]), stod(ans[1]), stod(ans[2]) }, stod(ans[3]));
        lights.push_back(l);
    }
    dlfs.close();

    fstream sfs("./Data/Sphere.txt", ios::in);
    if (!sfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    while (!sfs.eof())
    {
        getline(sfs, s);
        vector<string> ans = Spilt(s, ' ');
        if (ans.size() != 9)
        {
            break;
        }
        Object* l = new Sphere(stod(ans[0]), { stod(ans[1]), stod(ans[2]), stod(ans[3]) }, { {stoi(ans[4]), stoi(ans[5]), stoi(ans[6])}, stod(ans[7]), stod(ans[8]) });
        objects.push_back(l);
    }
    sfs.close();

    fstream mfs("./Data/Material.txt", ios::in);
    if (!mfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    while (!mfs.eof())
    {
        getline(mfs, s);
        vector<string> ans = Spilt(s, ' ');
        if (ans.size() != 5)
        {
            break;
        }
        Material* m = new Material({ stoi(ans[0]), stoi(ans[1]), stoi(ans[2]) }, stod(ans[3]), stod(ans[4]));
        materials.push_back(m);
    }
    mfs.close();
}

void Console::SaveData()
{
    fstream plfs("./Data/PointLight.txt", ios::out);
    if (!plfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }
    plfs.close();

    fstream alfs("./Data/AmbientLight.txt", ios::out);
    if (!alfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }
    alfs.close();

    fstream dlfs("./Data/DirectionalLight.txt", ios::out);
    if (!dlfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    dlfs.close();
    for (int i = 0; i < lights.size(); i++)
    {
        lights[i]->SaveData();
    }


    fstream sfs("./Data/Sphere.txt", ios::out);
    if (!sfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    sfs.close();
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->SaveData();
    }

    fstream mfs("./Data/Material.txt", ios::out);
    if (!mfs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    for (int i = 0; i < materials.size(); i++)
    {
        mfs << materials[i]->color.R << ' ' << materials[i]->color.G << ' ' << materials[i]->color.B << ' ' << materials[i]->specular << ' ' << materials[i]->reflective << endl;
    }

    mfs.close();
}

void Console::InitWhite()
{
    for (int i = 0; i < 25 * 6 * 1024; i++)
    {
        WhiteScreen[i] = 'M';
    }
}

void Console::InitBack()
{
    fstream fs("./UI/Back.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Back[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitLight()
{
    fstream fs("./UI/Light.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitSphere()
{
    fstream fs("./UI/Sphere.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DSphere[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitMaterial()
{
    fstream fs("./UI/Material.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitPNGsize()
{
    fstream fs("./UI/PNGsize.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                PNGsize[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitCreatePNG()
{
    fstream fs("./UI/CreatePNG.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                CreatePNG[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitExitSign()
{
    fstream fs("./UI/Exit.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                ExitSign[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitAddLight()
{
    fstream fs("./UI/AddLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                AddLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitAddSphere()
{
    fstream fs("./UI/AddSphere.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                AddSphere[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitAddMaterial()
{
    fstream fs("./UI/AddMaterial.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                AddMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDeleteLight()
{
    fstream fs("./UI/DeleteLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DeleteLight[i][j] = true;
            }
        }
    }
    fs.close();

}

void Console::InitDeleteSphere()
{
    fstream fs("./UI/DeleteSphere.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DeleteSphere[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDeleteMaterial()
{
    fstream fs("./UI/DeleteMaterial.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DeleteMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitChangeLight()
{
    fstream fs("./UI/ChangeLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                ChangeLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitChangeSphere()
{
    fstream fs("./UI/ChangeSphere.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                ChangeSphere[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitChangeMaterial()
{
    fstream fs("./UI/ChangeMaterial.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                ChangeMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::Init256X256PNG()
{
    fstream fs("./UI/256.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                PNG256[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::Init512X512PNG()
{
    fstream fs("./UI/512.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                PNG512[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::Init1024X1024PNG()
{
    fstream fs("./UI/1024.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                PNG1024[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitPointLight()
{
    fstream fs("./UI/PointLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DPointLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitAmbientLight()
{
    fstream fs("./UI/AmbientLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DAmbientLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDirectionalLight()
{
    fstream fs("./UI/DirectionalLight.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DDirectionalLight[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDot()
{
    fstream fs("./UI/Dot.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < DIGITHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < DIGITWIDTH; j++)
        {
            if (s[j] == '1')
            {
                DDot[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitMinus()
{
    fstream fs("./UI/Minus.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < DIGITHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < DIGITWIDTH; j++)
        {
            if (s[j] == '1')
            {
                Minus[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDigit()
{
    char file[] = "./UI/0.txt";
    for (char A = '0'; A <= '9'; A++)
    {
        file[5] = A;
        fstream fs(file, ios::in);
        if (!fs)
        {
            MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
            system("pause");
            exit(0);
        }

        string s;
        for (int i = 0; i < DIGITHEIGHT; i++)
        {
            getline(fs, s);
            for (int j = 0; j < DIGITWIDTH; j++)
            {
                if (s[j] == '1')
                {
                    Digit[A - '0'][i][j] = true;
                }
            }
        }
        fs.close();
    }
}

void Console::InitColon()
{
    fstream fs("./UI/Colon.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Colon[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitConfirm()
{
    fstream fs("./UI/Confirm.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Confirm[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitPosition()
{
    fstream fs("./UI/Position.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Position[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitIntensity()
{
    fstream fs("./UI/Intensity.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Intensity[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitR()
{
    fstream fs("./UI/R.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DR[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitO()
{
    fstream fs("./UI/SphereCenter.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DO[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitDirection()
{
    fstream fs("./UI/Direction.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DDirection[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitColor()
{
    fstream fs("./UI/Color.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DColor[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitSpecular()
{
    fstream fs("./UI/Specular.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DSpecular[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitReflective()
{
    fstream fs("./UI/Reflective.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                DReflective[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitNewMaterial()
{
    fstream fs("./UI/NewMaterial.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                NewMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitHadMaterial()
{
    fstream fs("./UI/HadMaterial.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                HadMaterial[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitNumber()
{
    fstream fs("./UI/Number.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Number[i][j] = true;
            }
        }
    }
    fs.close();
}

void Console::InitSearch()
{
    fstream fs("./UI/Search.txt", ios::in);
    if (!fs)
    {
        MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    string s;
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        getline(fs, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                Search[i][j] = true;
            }
        }
    }
    fs.close();
}


Color Console::RandColor()
{
    return Color(rand() % 256, rand() % 256, rand() % 256);
}


void Console::PrintSelectSign(const SHORT& X, const SHORT& Y, const Color& color)
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2 * min(i, (25 - i)); j++)
        {
            PutColor(j + X, i + Y, color);
        }
    }
}

void Console::PrintLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DLight[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintSphere(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DSphere[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DMaterial[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintPNGsize(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (PNGsize[i][j])
            {
                PutColor(j + 602, i + 100, color);
            }
            else
            {
                PutColor(j + 602, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintExitSign(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (ExitSign[i][j])
            {
                PutColor(j + 602, i + 150, color);
            }
            else
            {
                PutColor(j + 602, i + 150, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintCreatePNG(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (CreatePNG[i][j])
            {
                PutColor(j + 302, i + 150, color);
            }
            else
            {
                PutColor(j + 302, i + 150, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowUI()
{
    PrintLight(RandColor());
    PrintSphere(RandColor());
    PrintMaterial(RandColor());
    PrintPNGsize(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
    PrintSelectSign(250, 50, RandColor());
}


void Console::PrintBack(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Back[i][j])
            {
                PutColor(j + 602, i + 100, color);
            }
            else
            {
                PutColor(j + 602, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintAddBack(const int& x, const int& y, const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH / 2; j++)
        {
            if (Back[i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}


void Console::PrintAddLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (AddLight[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDeleteLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DeleteLight[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintChangeLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (ChangeLight[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowLightUI()
{
    PrintAddLight(RandColor());
    PrintDeleteLight(RandColor());
    PrintChangeLight(RandColor());
    PrintBack(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
}


void Console::PrintAddSphere(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (AddSphere[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDeleteSphere(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DeleteSphere[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintChangeSphere(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (ChangeSphere[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowSphereUI()
{
    PrintAddSphere(RandColor());
    PrintDeleteSphere(RandColor());
    PrintChangeSphere(RandColor());
    PrintBack(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
}


void Console::PrintAddMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (AddMaterial[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDeleteMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DeleteMaterial[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintChangeMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (ChangeMaterial[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowMaterialUI()
{
    PrintAddMaterial(RandColor());
    PrintDeleteMaterial(RandColor());
    PrintChangeMaterial(RandColor());
    PrintBack(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
}


void Console::Print256X256PNG(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (PNG256[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::Print512X512PNG(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (PNG512[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::Print1024X1024PNG(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (PNG1024[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowSizeUI()
{
    Print256X256PNG(RandColor());
    Print512X512PNG(RandColor());
    Print1024X1024PNG(RandColor());
    PrintBack(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
}

void Console::PrintPointLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DPointLight[i][j])
            {
                PutColor(j + 302, i + 50, color);
            }
            else
            {
                PutColor(j + 302, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintAmbientLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DAmbientLight[i][j])
            {
                PutColor(j + 602, i + 50, color);
            }
            else
            {
                PutColor(j + 602, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDirectionalLight(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DDirectionalLight[i][j])
            {
                PutColor(j + 302, i + 100, color);
            }
            else
            {
                PutColor(j + 302, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::ShowAddLightUI()
{
    PrintPointLight(RandColor());
    PrintAmbientLight(RandColor());
    PrintDirectionalLight(RandColor());
    PrintBack(RandColor());
    PrintCreatePNG(RandColor());
    PrintExitSign(RandColor());
}



void Console::PrintDot(const int& x, const int& y, const Color& color)
{
    for (int i = 0; i < DIGITHEIGHT; i++)
    {
        for (int j = 0; j < DIGITWIDTH; j++)
        {
            if (DDot[i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintMinus(const int& x, const int& y, const Color& color)
{
    for (int i = 0; i < DIGITHEIGHT; i++)
    {
        for (int j = 0; j < DIGITWIDTH; j++)
        {
            if (Minus[i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDigit(const int& x, const int& y, const int& d, const Color& color)
{
    for (int i = 0; i < DIGITHEIGHT; i++)
    {
        for (int j = 0; j < DIGITWIDTH; j++)
        {
            if (Digit[d][i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintConfirm(const int& x, const int& y, const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Confirm[i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintColon(const int& x, const int& y, const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Colon[i][j])
            {
                PutColor(j + x, i + y, color);
            }
            else
            {
                PutColor(j + x, i + y, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintPosition(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Position[i][j])
            {
                PutColor(j + 100, i + 100, color);
            }
            else
            {
                PutColor(j + 100, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintIntensity(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Intensity[i][j])
            {
                PutColor(j + 100, i + 75, color);
            }
            else
            {
                PutColor(j + 100, i + 75, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintR(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DR[i][j])
            {
                PutColor(j + 100, i + 75, color);
            }
            else
            {
                PutColor(j + 100, i + 75, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintO(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DO[i][j])
            {
                PutColor(j + 100, i + 100, color);
            }
            else
            {
                PutColor(j + 100, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintDirection(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DDirection[i][j])
            {
                PutColor(j + 100, i + 100, color);
            }
            else
            {
                PutColor(j + 100, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintColor(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DColor[i][j])
            {
                PutColor(j + 100, i + 75, color);
            }
            else
            {
                PutColor(j + 100, i + 75, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintSpecular(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DSpecular[i][j])
            {
                PutColor(j + 100, i + 100, color);
            }
            else
            {
                PutColor(j + 100, i + 100, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintReflective(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (DReflective[i][j])
            {
                PutColor(j + 100, i + 125, color);
            }
            else
            {
                PutColor(j + 100, i + 125, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintNewMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (NewMaterial[i][j])
            {
                PutColor(j + 100, i + 125, color);
            }
            else
            {
                PutColor(j + 100, i + 125, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintHadMaterial(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (HadMaterial[i][j])
            {
                PutColor(j + 100, i + 150, color);
            }
            else
            {
                PutColor(j + 100, i + 150, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintAddSphereUI(string r, string o)
{
    PrintAddBack(100, 50, RandColor());
    PrintSelectSign(50, 50, RandColor());
    PrintR(RandColor());
    PrintColon(160, 75, RandColor());
    PrintO(RandColor());
    PrintColon(160, 100, RandColor());
    PrintNewMaterial(RandColor());
    PrintHadMaterial(RandColor());
    PrintConfirm(100, 175, RandColor());
    for (int pos = 190, i = 0; i < r.size(); i++, pos += 30)
    {
        if ('0' <= r[i] && r[i] <= '9')
        {
            PrintDigit(pos, 75, r[i] - '0', RandColor());
        }
        else
        {
            PrintDot(pos, 75, RandColor());
        }
    }

    for (int pos = 190, i = 0; i < o.size(); i++, pos += 30)
    {
        if ('0' <= o[i] && o[i] <= '9')
        {
            PrintDigit(pos, 100, o[i] - '0', RandColor());
        }
        else if(o[i] == '.')
        {
            PrintDot(pos, 100, RandColor());
        }
        else if(o[i] == '-')
        {
            PrintMinus(pos, 100, RandColor());
        }
        else
        {
            PrintBlock(pos, 100, 25, 30, RandColor());
        }
    }
}

void Console::PrintNumber(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Number[i][j])
            {
                PutColor(j + 100, i + 50, color);
            }
            else
            {
                PutColor(j + 100, i + 50, { 255, 255, 255 });
            }
        }
    }
}

void Console::PrintSearch(const Color& color)
{
    for (int i = 0; i < SIGNHEIGHT; i++)
    {
        for (int j = 0; j < SIGNWIDTH; j++)
        {
            if (Search[i][j])
            {
                PutColor(j + 100, i + 100, color);
            }
            else
            {
                PutColor(j + 100, i + 100, { 255, 255, 255 });
            }
        }
    }
}



void Console::CreatePicture()
{
    Camera Cam({ 0, 0, -(double)Height }, Width, Height, (double)Height);
    FILE* fp = fopen("./PNG/rgb.png", "wb");
    int p = 0;
    int XHalf = Width / 2;
    int YHalf = Height / 2;
    InitScreen(Width, Height / 2, 1);
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            double X = XHalf - j;
            double Y = YHalf - i;
            int sample = 5;
            double R = 0, G = 0, B = 0;

            for (int k = 0; k < sample; k++)
            {
                X = X + rand() % 1 - 0.5;
                Y = Y + rand() % 1 - 0.5;
                Ray ray = Cam.GetRay(X, Y);
                Color tep = Cam.RayTracing(objects, lights, ray);
                R += tep.R;
                G += tep.G;
                B += tep.B;
            }


            Color color(R / sample, G / sample, B / sample);
            image[p++] = color.R;
            image[p++] = color.G;
            image[p++] = color.B;
            if (i & 1)
            {
                PutColor(j, i / 2, color);
            }
        }
    }
    svpng(fp, Width, Height, image);
    fclose(fp);
}

void Console::PrintBlock(const int& x, const int& y, const int& height, const int& width, const Color& color)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            PutColor(j + x, i + y, color);
        }
    }
}


void Console::ClearUI()
{
    PutColor(0, 50, { 255, 255, 255 });
    std::cout << WhiteScreen;
}

void Console::BackOperation()
{
    stk.pop();
    switch (stk.top())
    {
    case UI:
        ShowUI();
        break;
    case LIGHT_UI:
        ShowLightUI();
        break;
    case SPHERE_UI:
        ShowSphereUI();
        break;
    case MATERIAL_UI:
        ShowMaterialUI();
        break;
    case PNGSIZE_UI:
        ShowSizeUI();
        break;
    case ADDLIGHT:
        ShowAddLightUI();
        break;
    }
}

void Console::UIMove()
{
    while (_kbhit())
    {
        int operation = _getch();
        switch (operation)
        {
        case UP:
        case 'W':
        case 'w':
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
            y = ((y - 1) + 3) % 3;
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], RandColor());
            break;
        case DOWN:
        case 'S':
        case 's':
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
            y = (y + 1) % 3;
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], RandColor());
            break;
        case LEFT:
        case 'A':
        case 'a':
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
            x = ((x - 1) + 2) % 2;
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], RandColor());
            break;
        case RIGHT:
        case 'D':
        case 'd':
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
            x = (x + 1) % 2;
            PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], RandColor());
            break;
        case ENTER:
            if (y == 2)
            {
                SaveData();
                if (x == 1)
                {
                    exit(0);//退出
                }
                else
                {
                    CreatePicture();
                    Gotoxy(Width, Height / 2 - 1);
                    MessageBoxW(NULL, L"按任意键继续", L"Tips", MB_OK);
                    system("pause");
                    exit(0);
                }
                break;
            }
            switch (stk.top())
            {
            case UI:
                if (y == 0)
                {
                    if (x == 0)//光源类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(LIGHT_UI);
                        ShowLightUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = 0, y = 0;
                    }
                    else//球类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(SPHERE_UI);
                        ShowSphereUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = 0, y = 0;
                    }
                }
                else
                {
                    if (x == 0)//材质类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(MATERIAL_UI);
                        ShowMaterialUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = 0, y = 0;
                    }
                    else//改变PNG大小
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(PNGSIZE_UI);
                        ShowSizeUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = 0, y = 0;
                    }
                }
                break;
            case LIGHT_UI:
                if (y == 0)
                {
                    if (x == 0)//添加光源
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(ADDLIGHT);
                        ShowAddLightUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = 0, y = 0;
                    }
                    else//删除光源
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(DELETELIGHT);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                else
                {
                    if (x == 0)//修改光源
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(CHANGELIGHT);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//返回上一级
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                break;
            case SPHERE_UI:
                if (y == 0)
                {
                    if (x == 0)//添加球类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(ADDSPHERE);
                        ClearUI();
                        AddSphereUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//删除球类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(DELETESPHERE);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                else
                {
                    if (x == 0)//修改球类
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(CHANGESPHERE);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//返回上一级
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                break;
            case MATERIAL_UI:
                if (y == 0)
                {
                    if (x == 0)//添加材质
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(ADDMATERIAL);
                        ClearUI();
                        AddMaterialUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//删除材质
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(DELETEMATERIAL);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                else
                {
                    if (x == 0)//修改材质
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(CHANGEMATERIAL);
                        SubUIMove();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else //返回上一级
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                break;
            case PNGSIZE_UI:
                if (y == 0)
                {
                    if (x == 0)//256 X 256
                    {
                        Height = Width = 256;
                        MessageBoxW(NULL, L"设置成功", L"Tips", MB_OK);
                    }
                    else// 512 X 512
                    {
                        Height = Width = 512;
                        MessageBoxW(NULL, L"设置成功", L"Tips", MB_OK);
                    }
                }
                else
                {
                    if (x == 0)//1024 X 1024
                    {
                        Height = Width = 1024;
                        MessageBoxW(NULL, L"设置成功", L"Tips", MB_OK);
                    }
                    else//返回上一级
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                break;
            case ADDLIGHT:
                if (y == 0)
                {
                    if (x == 0)//点光源
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(POINTLIGHT);
                        ClearUI();
                        AddPointLightUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//环境光
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(AMBIENTLIGHT);
                        ClearUI();
                        AddAmbientUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                else
                {
                    if (x == 0)//平行光
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        stk.push(DIRECTIONALLIGHT);
                        ClearUI();
                        AddDirectionUI();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                    else//返回上一级
                    {
                        PrintSelectSign(UIPOS[y][x][0], UIPOS[y][x][1], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(UIPOS[0][0][0], UIPOS[0][0][1], RandColor());
                        x = y = 0;
                    }
                }
                break;
            }
        }
    }
}

void Console::SubUIMove()
{
    switch (stk.top())
    {
    case DELETESPHERE:
        ClearUI();
        ShowObjectsSearch();
        break;
    case CHANGESPHERE:
        ClearUI();
        ShowObjectsSearch();
        break;
    case DELETEMATERIAL:
        ClearUI();
        ShowMaterialsSearch();
        break;
    case CHANGEMATERIAL:
        ClearUI();
        ShowMaterialsSearch();
        break;
    case DELETELIGHT:
        ClearUI();
        ShowLightSearch();
        break;
    case CHANGELIGHT:
        ClearUI();
        ShowLightSearch();
        break;
    }
}

bool Console::AddPointLightUI()
{
    int cur = 0;
    bool flag = false, is_intensity = false, is_position = false, ok = false;
    string sintensity = "", sposition = "";
    int curpos1 = 190, curpos2 = 190;
    PrintSelectSign(50, 50, RandColor());
    PrintAddBack(100, 50, RandColor());
    PrintIntensity(RandColor());
    PrintColon(160, 75, RandColor());
    PrintPosition(RandColor());
    PrintColon(160, 100, RandColor());
    PrintConfirm(100, 125, RandColor());
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();
            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = ((cur - 1) + 4) % 4;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = (cur + 1) % 4;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 1, RandColor());
                    sintensity += '1';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 1, RandColor());
                    sposition += '1';
                    curpos2 += 30;
                }
                break;
            case '2':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 2, RandColor());
                    sintensity += '2';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 2, RandColor());
                    sposition += '2';
                    curpos2 += 30;
                }
                break;
            case '3':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 3, RandColor());
                    sintensity += '3';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 3, RandColor());
                    sposition += '3';
                    curpos2 += 30;
                }
                break;
            case '4':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 4, RandColor());
                    sintensity += '4';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 4, RandColor());
                    sposition += '4';
                    curpos2 += 30;
                }
                break;
            case '5':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 5, RandColor());
                    sintensity += '5';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 5, RandColor());
                    sposition += '5';
                    curpos2 += 30;
                }
                break;
            case '6':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 6, RandColor());
                    sintensity += '6';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 6, RandColor());
                    sposition += '6';
                    curpos2 += 30;
                }
                break;
            case '7':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 7, RandColor());
                    sintensity += '7';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 7, RandColor());
                    sposition += '7';
                    curpos2 += 30;
                }
                break;
            case '8':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 8, RandColor());
                    sintensity += '8';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 8, RandColor());
                    sposition += '8';
                    curpos2 += 30;
                }
                break;
            case '9':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 9, RandColor());
                    sintensity += '9';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 9, RandColor());
                    sposition += '9';
                    curpos2 += 30;
                }
                break;
            case '0':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 0, RandColor());
                    sintensity += '0';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 0, RandColor());
                    sposition += '0';
                    curpos2 += 30;
                }
                break;
            case '-':
                if (cur == 2)
                {
                    PrintMinus(curpos2, 100, RandColor());
                    sposition += '-';
                    curpos2 += 30;
                }
                break;
            case ' ':
                if (cur == 2)
                {
                    PrintBlock(curpos2, 100, 25, 30, RandColor());
                    sposition += ' ';
                    curpos2 += 30;
                }
                break;
            case '.':
                if (cur == 1)
                {
                    PrintDot(curpos1, 75, RandColor());
                    sintensity += '.';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDot(curpos2, 100, RandColor());
                    sposition += '.';
                    curpos2 += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 1)
                {
                    if (!sintensity.empty())
                    {
                        sintensity.pop_back();
                        curpos1 -= 30;
                        PrintBlock(curpos1, 75, 25, 30, { 255, 255, 255 });
                    }
                }
                else
                {
                    if (!sposition.empty())
                    {
                        sposition.pop_back();
                        curpos2 -= 30;
                        PrintBlock(curpos2, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 0)
                {
                    flag = true;
                }
                
                if (cur == 1)
                {
                    is_intensity = true;
                    MessageBoxW(NULL, L"光强确认", L"Tips", MB_OK);
                }

                if (cur == 2)
                {
                    vector<string> ans = Spilt(sposition, ' ');
                    if (ans.size() != 3)
                    {
                        MessageBoxW(NULL, L"位置数据错误", L"Warning", MB_OK);
                        break;
                    }
                    is_position = true;
                    MessageBoxW(NULL, L"位置确认", L"Tips", MB_OK);
                }

                if (cur == 3)
                {
                    if (!is_intensity || !is_position)
                    {
                        MessageBoxW(NULL, L"数据不完全", L"Warning", MB_OK);
                        break;
                    }
                    vector<string> ans = Spilt(sposition, ' ');
                    Light* l = new PointLight({ stod(ans[0]), stod(ans[1]), stod(ans[2]) }, stod(sintensity));
                    lights.push_back(l);
                    MessageBoxW(NULL, L"数据添加成功", L"Tips", MB_OK);
                    flag = true;
                    ok = true;
                }
            }
        }

        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return ok;
}

bool Console::AddAmbientUI()
{
    int cur = 0;
    bool flag = false, is_intensity = false, ok = false;
    string sintensity = "";
    int curpos1 = 190;
    PrintSelectSign(50, 50, RandColor());
    PrintAddBack(100, 50, RandColor());
    PrintIntensity(RandColor());
    PrintColon(160, 75, RandColor());
    PrintConfirm(100, 100, RandColor());
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();
            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = ((cur - 1) + 3) % 3;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = (cur + 1) % 3;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 1, RandColor());
                    sintensity += '1';
                    curpos1 += 30;
                }
                break;
            case '2':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 2, RandColor());
                    sintensity += '2';
                    curpos1 += 30;
                }
                break;
            case '3':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 3, RandColor());
                    sintensity += '3';
                    curpos1 += 30;
                }
                break;
            case '4':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 4, RandColor());
                    sintensity += '4';
                    curpos1 += 30;
                }
                break;
            case '5':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 5, RandColor());
                    sintensity += '5';
                    curpos1 += 30;
                }
                break;
            case '6':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 6, RandColor());
                    sintensity += '6';
                    curpos1 += 30;
                }
                break;
            case '7':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 7, RandColor());
                    sintensity += '7';
                    curpos1 += 30;
                }
                break;
            case '8':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 8, RandColor());
                    sintensity += '8';
                    curpos1 += 30;
                }
                break;
            case '9':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 9, RandColor());
                    sintensity += '9';
                    curpos1 += 30;
                }
                break;
            case '0':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 0, RandColor());
                    sintensity += '0';
                    curpos1 += 30;
                }
                break;
            case '-':

                break;
            case ' ':

                break;
            case '.':
                if (cur == 1)
                {
                    PrintDot(curpos1, 75, RandColor());
                    sintensity += '.';
                    curpos1 += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 1)
                {
                    if (!sintensity.empty())
                    {
                        sintensity.pop_back();
                        curpos1 -= 30;
                        PrintBlock(curpos1, 75, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 0)
                {
                    flag = true;
                }

                if (cur == 1)
                {
                    is_intensity = true;
                    MessageBoxW(NULL, L"光强确认", L"Tips", MB_OK);
                }

                if (cur == 2)
                {
                    if (!is_intensity)
                    {
                        MessageBoxW(NULL, L"数据不完全", L"Warning", MB_OK);
                        break;
                    }
                    Light* l = new AmbientLight(stod(sintensity));
                    lights.push_back(l);
                    MessageBoxW(NULL, L"数据添加成功", L"Tips", MB_OK);
                    flag = true;
                    ok = true;
                }
            }
        }

        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return ok;
}

bool Console::AddDirectionUI()
{
    int cur = 0;
    bool flag = false, is_intensity = false, is_direction = false, ok = false;
    string sintensity = "", sdirection = "";
    int curpos1 = 190, curpos2 = 190;
    PrintSelectSign(50, 50, RandColor());
    PrintAddBack(100, 50, RandColor());
    PrintIntensity(RandColor());
    PrintColon(160, 75, RandColor());
    PrintDirection(RandColor());
    PrintColon(160, 100, RandColor());
    PrintConfirm(100, 125, RandColor());
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();
            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = ((cur - 1) + 4) % 4;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = (cur + 1) % 4;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 1, RandColor());
                    sintensity += '1';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 1, RandColor());
                    sdirection += '1';
                    curpos2 += 30;
                }
                break;
            case '2':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 2, RandColor());
                    sintensity += '2';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 2, RandColor());
                    sdirection += '2';
                    curpos2 += 30;
                }
                break;
            case '3':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 3, RandColor());
                    sintensity += '3';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 3, RandColor());
                    sdirection += '3';
                    curpos2 += 30;
                }
                break;
            case '4':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 4, RandColor());
                    sintensity += '4';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 4, RandColor());
                    sdirection += '4';
                    curpos2 += 30;
                }
                break;
            case '5':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 5, RandColor());
                    sintensity += '5';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 5, RandColor());
                    sdirection += '5';
                    curpos2 += 30;
                }
                break;
            case '6':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 6, RandColor());
                    sintensity += '6';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 6, RandColor());
                    sdirection += '6';
                    curpos2 += 30;
                }
                break;
            case '7':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 7, RandColor());
                    sintensity += '7';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 7, RandColor());
                    sdirection += '7';
                    curpos2 += 30;
                }
                break;
            case '8':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 8, RandColor());
                    sintensity += '8';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 8, RandColor());
                    sdirection += '8';
                    curpos2 += 30;
                }
                break;
            case '9':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 9, RandColor());
                    sintensity += '9';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 9, RandColor());
                    sdirection += '9';
                    curpos2 += 30;
                }
                break;
            case '0':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 0, RandColor());
                    sintensity += '0';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 0, RandColor());
                    sdirection += '0';
                    curpos2 += 30;
                }
                break;
            case '-':
                if (cur == 2)
                {
                    PrintMinus(curpos2, 100, RandColor());
                    sdirection += '-';
                    curpos2 += 30;
                }
                break;
            case ' ':
                if (cur == 2)
                {
                    PrintBlock(curpos2, 100, 25, 30, RandColor());
                    sdirection += ' ';
                    curpos2 += 30;
                }
                break;
            case '.':
                if (cur == 1)
                {
                    PrintDot(curpos1, 75, RandColor());
                    sintensity += '.';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDot(curpos2, 100, RandColor());
                    sdirection += '.';
                    curpos2 += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 1)
                {
                    if (!sintensity.empty())
                    {
                        sintensity.pop_back();
                        curpos1 -= 30;
                        PrintBlock(curpos1, 75, 25, 30, { 255, 255, 255 });
                    }
                }
                else
                {
                    if (!sdirection.empty())
                    {
                        sdirection.pop_back();
                        curpos2 -= 30;
                        PrintBlock(curpos2, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 0)
                {
                    flag = true;
                }

                if (cur == 1)
                {
                    is_intensity = true;
                    MessageBoxW(NULL, L"光强确认", L"Tips", MB_OK);
                }

                if (cur == 2)
                {
                    vector<string> ans = Spilt(sdirection, ' ');
                    if(ans.size() != 3)
                    {
                        MessageBoxW(NULL, L"方向数据错误", L"Warning", MB_OK);
                        break;
                    }
                    is_direction = true;
                    MessageBoxW(NULL, L"方向确认", L"Tips", MB_OK);
                }

                if (cur == 3)
                {
                    if (!is_intensity || !is_direction)
                    {
                        MessageBoxW(NULL, L"数据不完全", L"Warning", MB_OK);
                        break;
                    }
                    vector<string> ans = Spilt(sdirection, ' ');
                    Light* l = new PointLight({ stod(ans[0]), stod(ans[1]), stod(ans[2]) }, stod(sintensity));
                    lights.push_back(l);
                    MessageBoxW(NULL, L"数据添加成功", L"Tips", MB_OK);
                    flag = true;
                    ok = true;
                }
            }
        }

        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return ok;
}

bool Console::AddSphereUI()
{
    int cur = 0;
    bool flag = false, is_R = false, is_O = false, is_M = false, ok = false;
    string sR = "", sO = "";
    int curpos1 = 190, curpos2 = 190;
    Material m({ 0, 0, 0 }, 0, 0);
    PrintAddSphereUI(sR, sO);
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();
            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = ((cur - 1) + 6) % 6;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = (cur + 1) % 6;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 1, RandColor());
                    sR += '1';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 1, RandColor());
                    sO += '1';
                    curpos2 += 30;
                }
                break;
            case '2':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 2, RandColor());
                    sR += '2';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 2, RandColor());
                    sO += '2';
                    curpos2 += 30;
                }
                break;
            case '3':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 3, RandColor());
                    sR += '3';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 3, RandColor());
                    sO += '3';
                    curpos2 += 30;
                }
                break;
            case '4':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 4, RandColor());
                    sR += '4';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 4, RandColor());
                    sO += '4';
                    curpos2 += 30;
                }
                break;
            case '5':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 5, RandColor());
                    sR += '5';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 5, RandColor());
                    sO += '5';
                    curpos2 += 30;
                }
                break;
            case '6':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 6, RandColor());
                    sR += '6';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 6, RandColor());
                    sO += '6';
                    curpos2 += 30;
                }
                break;
            case '7':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 7, RandColor());
                    sR += '7';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 7, RandColor());
                    sO += '7';
                    curpos2 += 30;
                }
                break;
            case '8':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 8, RandColor());
                    sR += '8';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 8, RandColor());
                    sO += '8';
                    curpos2 += 30;
                }
                break;
            case '9':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 9, RandColor());
                    sR += '9';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 9, RandColor());
                    sO += '9';
                    curpos2 += 30;
                }
                break;
            case '0':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 0, RandColor());
                    sR += '0';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 0, RandColor());
                    sO += '0';
                    curpos2 += 30;
                }
                break;
            case '-':
                if (cur == 2)
                {
                    PrintMinus(curpos2, 100, RandColor());
                    sO += '-';
                    curpos2 += 30;
                }
                break;
            case ' ':
                if (cur == 2)
                {
                    PrintBlock(curpos2, 100, 25, 30, RandColor());
                    sO += ' ';
                    curpos2 += 30;
                }
                break;
            case '.':
                if (cur == 1)
                {
                    PrintDot(curpos1, 75, RandColor());
                    sR += '.';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDot(curpos2, 100, RandColor());
                    sO += '.';
                    curpos2 += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 1)
                {
                    if (!sR.empty())
                    {
                        sR.pop_back();
                        curpos1 -= 30;
                        PrintBlock(curpos1, 75, 25, 30, { 255, 255, 255 });
                    }
                }
                else
                {
                    if (!sO.empty())
                    {
                        sO.pop_back();
                        curpos2 -= 30;
                        PrintBlock(curpos2, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 0)
                {
                    flag = true;
                }

                if (cur == 1)
                {
                    is_R = true;
                    MessageBoxW(NULL, L"半径确认", L"Tips", MB_OK);
                }

                if (cur == 2)
                {
                    vector<string> ans = Spilt(sO, ' ');
                    if (ans.size() != 3)
                    {
                        MessageBoxW(NULL, L"球心数据错误", L"Warning", MB_OK);
                        break;
                    }
                    is_O = true;
                    MessageBoxW(NULL, L"球心确认", L"Tips", MB_OK);
                }

                if (cur == 3)
                {
                    ClearUI();
                    stk.push(ADDMATERIAL);
                    pair<Material, bool> tep = AddMaterialUI();
                    ClearUI();
                    cur = 0;
                    PrintAddSphereUI(sR, sO);
                    if (tep.second)
                    {
                        is_M = true;
                        m = tep.first;
                    }
                }

                if (cur == 4)
                {
                    stk.push(SEARCHMATERIAL);
                    ClearUI();
                    pair<Material, bool> tep = ShowMaterialsSearch();
                    if (tep.second)
                    {
                        MessageBoxW(NULL, L"材质添加成功", L"Tips", MB_OK);
                        m = tep.first;
                        is_M = true;
                    }
                    ClearUI();
                    cur = 0;
                    PrintAddSphereUI(sR, sO);
                    
                }

                if (cur == 5)
                {
                    if (!is_R || !is_O || !is_M)
                    {
                        MessageBoxW(NULL, L"数据不完全", L"Warning", MB_OK);
                        break;
                    }
                    vector<string> ans = Spilt(sO, ' ');
                    Object* o = new Sphere(stod(sR), { stod(ans[0]), stod(ans[1]), stod(ans[2]) }, m);
                    objects.push_back(o);
                    MessageBoxW(NULL, L"数据添加成功", L"Tips", MB_OK);
                    flag = true;
                    ok = true;
                }
            }
        }

        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return ok;
}


void Console::ShowLightSearch()
{
    int cur = 1, cnt = lights.size();
    ShowLightNumber();
    string snumber = "";
    int curpos = 250;
    bool flag = false;
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();

            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 1, RandColor());
                    snumber += '1';
                    curpos += 30;
                }
                break;
            case '2':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 2, RandColor());
                    snumber += '2';
                    curpos += 30;
                }
                break;
            case '3':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 3, RandColor());
                    snumber += '3';
                    curpos += 30;
                }
                break;
            case '4':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 4, RandColor());
                    snumber += '4';
                    curpos += 30;
                }
                break;
            case '5':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 5, RandColor());
                    snumber += '5';
                    curpos += 30;
                }
                break;
            case '6':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 6, RandColor());
                    snumber += '6';
                    curpos += 30;
                }
                break;
            case '7':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 7, RandColor());
                    snumber += '7';
                    curpos += 30;
                }
                break;
            case '8':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 8, RandColor());
                    snumber += '8';
                    curpos += 30;
                }
                break;
            case '9':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 9, RandColor());
                    snumber += '9';
                    curpos += 30;
                }
                break;
            case '0':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 0, RandColor());
                    snumber += '0';
                    curpos += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 2)
                {
                    if (!snumber.empty())
                    {
                        snumber.pop_back();
                        curpos -= 30;
                        PrintBlock(curpos, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 1)
                {
                    flag = true;
                }

                if (cur == 2)
                {
                    if (snumber.size() == 0 || stoi(snumber) > cnt || (snumber.size() == 1 && snumber[0] == '0'))
                    {
                        MessageBoxW(NULL, L"数据错误", L"Warning", MB_OK);
                        break;
                    }
                    ClearUI();
                    int pos = stoi(snumber) - 1;
                    if (stk.top() == CHANGELIGHT)
                    {
                        bool ok = false;
                        stk.push(CHANGELIGHT);
                        if (lights[pos]->type == "Point")
                        {
                            ok = AddPointLightUI();
                        }
                        else if (lights[pos]->type == "Ambient")
                        {
                            ok = AddAmbientUI();
                        }
                        else
                        {
                            ok = AddDirectionUI();
                        }
                        if (ok)
                        {
                            MessageBoxW(NULL, L"更改成功", L"Tips", MB_OK);
                            for (int i = pos; i < cnt - 1; i++)
                            {
                                lights[i] = lights[i + 1];
                            }
                            lights.pop_back();
                        }
                    }
                    else
                    {
                        MessageBoxW(NULL, L"删除成功", L"Tips", MB_OK);
                        for (int i = pos; i < cnt - 1; i++)
                        {
                            lights[i] = lights[i + 1];
                        }
                        lights.pop_back();
                    }
                    ClearUI();
                    ShowLightNumber();
                    cur = 1;
                }
            }
        }
        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
}

void Console::ShowLightNumber()
{
    int cnt = lights.size();
    PrintNumber(RandColor());
    PrintColon(220, 50, RandColor());
    vector<int> digit;
    if (cnt == 0)
    {
        digit.push_back(0);
    }
    else
    {
        int tep = cnt;
        while (tep)
        {
            digit.push_back(tep % 10);
            tep /= 10;
        }
    }
    reverse(digit.begin(), digit.end());
    for (int i = 0, curpos = 250; i < digit.size(); i++, curpos += 30)
    {
        PrintDigit(curpos, 50, digit[i], RandColor());
    }
    PrintSelectSign(50, 75, RandColor());
    PrintAddBack(100, 75, RandColor());
    PrintSearch(RandColor());
    PrintColon(220, 100, RandColor());
}

void Console::ShowObjectsNumber()
{
    int cnt = objects.size();
    PrintNumber(RandColor());
    PrintColon(220, 50, RandColor());
    vector<int> digit;
    if (cnt == 0)
    {
        digit.push_back(0);
    }
    else
    {
        int tep = cnt;
        while (tep)
        {
            digit.push_back(tep % 10);
            tep /= 10;
        }
    }
    reverse(digit.begin(), digit.end());
    for (int i = 0, curpos = 250; i < digit.size(); i++, curpos += 30)
    {
        PrintDigit(curpos, 50, digit[i], RandColor());
    }
    PrintSelectSign(50, 75, RandColor());
    PrintAddBack(100, 75, RandColor());
    PrintSearch(RandColor());
    PrintColon(220, 100, RandColor());
}

void Console::ShowObjectsSearch()
{
    int cur = 1, cnt = objects.size();
    ShowObjectsNumber();
    string snumber = "";
    int curpos = 250;
    bool flag = false;
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();

            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 1, RandColor());
                    snumber += '1';
                    curpos += 30;
                }
                break;
            case '2':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 2, RandColor());
                    snumber += '2';
                    curpos += 30;
                }
                break;
            case '3':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 3, RandColor());
                    snumber += '3';
                    curpos += 30;
                }
                break;
            case '4':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 4, RandColor());
                    snumber += '4';
                    curpos += 30;
                }
                break;
            case '5':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 5, RandColor());
                    snumber += '5';
                    curpos += 30;
                }
                break;
            case '6':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 6, RandColor());
                    snumber += '6';
                    curpos += 30;
                }
                break;
            case '7':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 7, RandColor());
                    snumber += '7';
                    curpos += 30;
                }
                break;
            case '8':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 8, RandColor());
                    snumber += '8';
                    curpos += 30;
                }
                break;
            case '9':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 9, RandColor());
                    snumber += '9';
                    curpos += 30;
                }
                break;
            case '0':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 0, RandColor());
                    snumber += '0';
                    curpos += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 2)
                {
                    if (!snumber.empty())
                    {
                        snumber.pop_back();
                        curpos -= 30;
                        PrintBlock(curpos, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 1)
                {
                    flag = true;
                }

                if (cur == 2)
                {
                    if (snumber.size() == 0 || stoi(snumber) > cnt || (snumber.size() == 1 && snumber[0] == '0'))
                    {
                        MessageBoxW(NULL, L"数据错误", L"Warning", MB_OK);
                        break;
                    }
                    ClearUI();
                    int pos = stoi(snumber) - 1;
                    if (stk.top() == CHANGESPHERE)
                    {
                        bool ok = false;
                        stk.push(CHANGESPHERE);
                        ok = AddSphereUI();
                        if (ok)
                        {
                            MessageBoxW(NULL, L"更改成功", L"Tips", MB_OK);
                            for (int i = pos; i < cnt - 1; i++)
                            {
                                objects[i] = objects[i + 1];
                            }
                            objects.pop_back();
                        }
                    }
                    else
                    {
                        MessageBoxW(NULL, L"删除成功", L"Tips", MB_OK);
                        for (int i = pos; i < cnt - 1; i++)
                        {
                            objects[i] = objects[i + 1];
                        }
                        objects.pop_back();
                    }
                    ClearUI();
                    ShowObjectsNumber();
                    cur = 1;
                }
            }
        }
        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
}

void Console::ShowMaterialsNumber()
{
    int cnt = materials.size();
    PrintNumber(RandColor());
    PrintColon(220, 50, RandColor());
    vector<int> digit;
    if (cnt == 0)
    {
        digit.push_back(0);
    }
    else
    {
        int tep = cnt;
        while (tep)
        {
            digit.push_back(tep % 10);
            tep /= 10;
        }
    }
    reverse(digit.begin(), digit.end());
    for (int i = 0, curpos = 250; i < digit.size(); i++, curpos += 30)
    {
        PrintDigit(curpos, 50, digit[i], RandColor());
    }
    PrintSelectSign(50, 75, RandColor());
    PrintAddBack(100, 75, RandColor());
    PrintSearch(RandColor());
    PrintColon(220, 100, RandColor());
}

pair<Material, bool> Console::ShowMaterialsSearch()
{
    int cur = 1, cnt = materials.size();
    ShowMaterialsNumber();
    string snumber = "";
    int curpos = 250;
    bool flag = false;
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();

            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                if (cur == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 1, RandColor());
                    snumber += '1';
                    curpos += 30;
                }
                break;
            case '2':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 2, RandColor());
                    snumber += '2';
                    curpos += 30;
                }
                break;
            case '3':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 3, RandColor());
                    snumber += '3';
                    curpos += 30;
                }
                break;
            case '4':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 4, RandColor());
                    snumber += '4';
                    curpos += 30;
                }
                break;
            case '5':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 5, RandColor());
                    snumber += '5';
                    curpos += 30;
                }
                break;
            case '6':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 6, RandColor());
                    snumber += '6';
                    curpos += 30;
                }
                break;
            case '7':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 7, RandColor());
                    snumber += '7';
                    curpos += 30;
                }
                break;
            case '8':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 8, RandColor());
                    snumber += '8';
                    curpos += 30;
                }
                break;
            case '9':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 9, RandColor());
                    snumber += '9';
                    curpos += 30;
                }
                break;
            case '0':
                if (cur == 2)
                {
                    PrintDigit(curpos, 100, 0, RandColor());
                    snumber += '0';
                    curpos += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 2)
                {
                    if (!snumber.empty())
                    {
                        snumber.pop_back();
                        curpos -= 30;
                        PrintBlock(curpos, 100, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 1)
                {
                    flag = true;
                }

                if (cur == 2)
                {
                    if (snumber.size() == 0 || stoi(snumber) > cnt || (snumber.size() == 1 && snumber[0] == '0'))
                    {
                        MessageBoxW(NULL, L"数据错误", L"Warning", MB_OK);
                        break;
                    }
                    ClearUI();
                    int pos = stoi(snumber) - 1;
                    if (stk.top() == CHANGEMATERIAL)
                    {
                        stk.push(CHANGEMATERIAL);
                        pair<Material, bool> tep = AddMaterialUI();
                        if (tep.second)
                        {
                            MessageBoxW(NULL, L"更改成功", L"Tips", MB_OK);
                            for (int i = pos; i < cnt - 1; i++)
                            {
                                materials[i] = materials[i + 1];
                            }
                            materials.pop_back();
                        }
                    }

                    if(stk.top() == DELETEMATERIAL)
                    {
                        MessageBoxW(NULL, L"删除成功", L"Tips", MB_OK);
                        for (int i = pos; i < cnt - 1; i++)
                        {
                            materials[i] = materials[i + 1];
                        }
                        materials.pop_back();
                    }
                    ClearUI();
                    ShowMaterialsNumber();
                    cur = 1;
                    if (stk.top() == SEARCHMATERIAL)
                    {
                        ClearUI();
                        PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                        BackOperation();
                        PrintSelectSign(250, 50, RandColor());
                        return { *materials[pos], true };
                    }

                }
            }
        }
        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return { Material(), false };
}

pair<Material,bool> Console::AddMaterialUI()
{
    int cur = 0;
    bool flag = false, is_color = false, is_specular = false, is_reflective = false, ok = false;
    string scolor = "", sspecular = "", sreflective = "";
    int curpos1 = 190, curpos2 = 250, curpos3 = 250;
    PrintAddBack(100, 50, RandColor());
    PrintSelectSign(50, 50, RandColor());
    PrintColor(RandColor());
    PrintColon(160, 75, RandColor());
    PrintSpecular(RandColor());
    PrintColon(220, 100, RandColor());
    PrintReflective(RandColor());
    PrintColon(220, 125, RandColor());
    PrintConfirm(100, 150, RandColor());
    while (true)
    {
        while (_kbhit())
        {
            int operation = _getch();
            switch (operation)
            {
            case UP:
            case 'W':
            case 'w':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = ((cur - 1) + 5) % 5;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case DOWN:
            case 'S':
            case 's':
                PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
                cur = (cur + 1) % 5;
                PrintSelectSign(50, ADDUIPOS[cur], RandColor());
                break;
            case '1':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 1, RandColor());
                    scolor += '1';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 1, RandColor());
                    sspecular += '1';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 1, RandColor());
                    sreflective += '1';
                    curpos3 += 30;
                }
                break;
            case '2':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 2, RandColor());
                    scolor += '2';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 2, RandColor());
                    sspecular += '2';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 2, RandColor());
                    sreflective += '2';
                    curpos3 += 30;
                }
                break;
            case '3':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 3, RandColor());
                    scolor += '3';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 3, RandColor());
                    sspecular += '3';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 3, RandColor());
                    sreflective += '3';
                    curpos3 += 30;
                }
                break;
            case '4':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 4, RandColor());
                    scolor += '4';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 4, RandColor());
                    sspecular += '4';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 4, RandColor());
                    sreflective += '4';
                    curpos3 += 30;
                }
                break;
            case '5':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 5, RandColor());
                    scolor += '5';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 5, RandColor());
                    sspecular += '5';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 5, RandColor());
                    sreflective += '5';
                    curpos3 += 30;
                }
                break;
            case '6':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 6, RandColor());
                    scolor += '6';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 6, RandColor());
                    sspecular += '6';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 6, RandColor());
                    sreflective += '6';
                    curpos3 += 30;
                }
                break;
            case '7':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 7, RandColor());
                    scolor += '7';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 7, RandColor());
                    sspecular += '7';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 7, RandColor());
                    sreflective += '7';
                    curpos3 += 30;
                }
                break;
            case '8':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 8, RandColor());
                    scolor += '8';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 8, RandColor());
                    sspecular += '8';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 8, RandColor());
                    sreflective += '8';
                    curpos3 += 30;
                }
                break;
            case '9':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 9, RandColor());
                    scolor += '9';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 9, RandColor());
                    sspecular += '9';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 9, RandColor());
                    sreflective += '9';
                    curpos3 += 30;
                }
                break;
            case '0':
                if (cur == 1)
                {
                    PrintDigit(curpos1, 75, 0, RandColor());
                    scolor += '0';
                    curpos1 += 30;
                }

                if (cur == 2)
                {
                    PrintDigit(curpos2, 100, 0, RandColor());
                    sspecular += '0';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDigit(curpos3, 125, 0, RandColor());
                    sreflective += '0';
                    curpos3 += 30;
                }
                break;
            case '-':

                break;
            case ' ':
                if (cur == 1)
                {
                    PrintBlock(curpos1, 75, 25, 30, RandColor());
                    scolor += ' ';
                    curpos1 += 30;
                }
                break;
            case '.':

                if (cur == 2)
                {
                    PrintDot(curpos2, 100, RandColor());
                    sspecular += '.';
                    curpos2 += 30;
                }

                if (cur == 3)
                {
                    PrintDot(curpos3, 125, RandColor());
                    sreflective += '.';
                    curpos3 += 30;
                }
                break;
            case BACKSPACE:
                if (cur == 1)
                {
                    if (!scolor.empty())
                    {
                        scolor.pop_back();
                        curpos1 -= 30;
                        PrintBlock(curpos1, 75, 25, 30, { 255, 255, 255 });
                    }
                }
                else
                {
                    if (!sspecular.empty())
                    {
                        sspecular.pop_back();
                        curpos2 -= 30;
                        PrintBlock(curpos2, 100, 25, 30, { 255, 255, 255 });
                    }
                }

                if (cur == 3)
                {
                    if (!sreflective.empty())
                    {
                        sreflective.pop_back();
                        curpos3 -= 30;
                        PrintBlock(curpos2, 125, 25, 30, { 255, 255, 255 });
                    }
                }
                break;
            case ENTER:
                if (cur == 0)
                {
                    flag = true;
                }

                if (cur == 1)
                {
                    vector<string> ans = Spilt(scolor, ' ');
                    if (ans.size() != 3)
                    {
                        MessageBoxW(NULL, L"颜色数据错误", L"Warning", MB_OK);
                        break;
                    }
                    is_color = true;
                    MessageBoxW(NULL, L"颜色确认", L"Tips", MB_OK);
                }

                if (cur == 2)
                {
                    is_specular = true;
                    MessageBoxW(NULL, L"闪亮程度确认", L"Tips", MB_OK);
                }

                if (cur == 3)
                {
                    is_reflective = true;
                    MessageBoxW(NULL, L"反射系数确认", L"Tips", MB_OK);
                }

                if (cur == 4)
                {
                    if (!is_color || !is_specular || !is_reflective)
                    {
                        MessageBoxW(NULL, L"数据不完全", L"Warning", MB_OK);
                        break;
                    }
                    vector<string> ans = Spilt(scolor, ' ');
                    Material* m = new Material({ stoi(ans[0]),stoi(ans[1]),stoi(ans[2]) }, stod(sspecular), stod(sreflective));
                    materials.push_back(m);
                    MessageBoxW(NULL, L"数据添加成功", L"Tips", MB_OK);
                    ok = flag = true;
                }
            }
        }

        if (flag)
        {
            break;
        }
        Sleep(100);
    }
    ClearUI();
    PrintSelectSign(50, ADDUIPOS[cur], Color(255, 255, 255));
    BackOperation();
    PrintSelectSign(250, 50, RandColor());
    return { materials.empty() ? Material() : *materials.back(), ok};
}





void Console::Control()
{
    while (true)
    {
        UIMove();
        
        Sleep(100);
    }
}






