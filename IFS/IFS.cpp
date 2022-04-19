
#include"IFS.h"
inline float get_random_float()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_real_distribution<float> dist(0.f, 1.f); // distribution in range [1, 6]

    return dist(rng);
}

IFS::IFS(const char* filename) :transFunc(), transProb() {
    ifstream in;
    in.open(filename, ifstream::in);
    if (in.fail()) return;
    string line;

    getline(in, line);
    istringstream iss(line.c_str());
    iss >> transNum;

    for (int i = 0; i < transNum; i++)
    {
        getline(in, line);
        iss.clear(); iss.str(line);
        float temp = 0; iss >> temp;
        transProb.push_back(temp);
        float m[16] = { 0 };
        for (int j = 0; j < 3; j++)
        {
            getline(in, line);
            iss.clear(); iss.str(line);
 
            for (int k = 0; k < 3; k++)
                iss >> m[4 * j + k];
        }
        transFunc.push_back(m);
    }

}
IFS::~IFS() {}
void IFS::render(Image& img, int pointsNum, int iterNum)
{
    for (int i = 0; i < pointsNum; i++)
    {
        Vec4f point(get_random_float(), get_random_float(), 1, 0);
        for (int k = 0; k < iterNum; k++)
        {
            float prob = get_random_float();
            float pdf = 0;
            Matrix func;
            for (int j = 0; j < transNum; j++)
            {
                pdf = pdf + transProb[j];
                if (prob < pdf)
                {
                    func = transFunc[j];
                    break;
                }
            }
            func.Transform(point);
        }
        img.SetPixel(point[0] * img.Width(), point[1] * img.Height(), Vec3f{ 255,255,255 });
    }
}