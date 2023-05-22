#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

#include <random>
using namespace std;

// 定义轨迹数据采样点的结构
struct Point
{
    int OID;
    int timestamp;
    double longitude;
    double latitude;
};

// 定义对象类定义轨迹数据类
class Object
{
public:
    int ID;
    std::vector<Point> trajectory;

    Object(int id) : ID(id) {}
};

// 极坐标对象
struct PolarVector
{
    double radius; // 半径
    double angle;  // 角度
    PolarVector(double r, double a) : radius(r), angle(a) {}
};
// 直角坐标向量
struct CartesianVector
{
    double x; // x坐标
    double y; // y坐标

    CartesianVector(double xVal, double yVal) : x(xVal), y(yVal) {}
};

// 直角坐标向量的点乘运算
double operator*(const CartesianVector &a, const CartesianVector &b)
{
    // 直角坐标向量的点乘运算
    double dotProduct = a.x * b.x + a.y * b.y;

    return dotProduct;
}
// 极坐标向量乘法运算
double operator*(const PolarVector &a, const PolarVector &b)
{
    // 将极坐标向量转换为直角坐标系下的向量
    double x1 = a.radius * std::cos(a.angle);
    double y1 = a.radius * std::sin(a.angle);

    double x2 = b.radius * std::cos(b.angle);
    double y2 = b.radius * std::sin(b.angle);

    // 直角坐标系下的向量乘法
    return x1 * x2 + y1 * y2;
}
// 将平面坐标转换为极坐标
PolarVector convertToPolar(const CartesianVector &cartesianVector)
{
    PolarVector polarVector(std::sqrt(cartesianVector.x * cartesianVector.x + cartesianVector.y * cartesianVector.y), std::atan2(cartesianVector.y, cartesianVector.x) * 180.0 / M_PI);
    return polarVector;
}
// 将极坐标转换为平面坐标
CartesianVector polarToCartesian(const PolarVector &polar)
{
    double x = polar.radius * std::cos(polar.angle);
    double y = polar.radius * std::sin(polar.angle);

    return CartesianVector(x, y);
}
// 函数用于计算 h 的值
double calculateH(const PolarVector &a, const PolarVector &p, double D)
{
    // 计算 a 向量乘 p 向量的结果
    double apProduct = a * p;
    // 计算 b 的值
    double b = ((apProduct / D) + 0.5) * D - apProduct + D / 2;
    // 计算 h 的值
    double h = (apProduct + b) / D;
    return h;
}

void to_mat(const vector<Object> objects, const double D)
{

    // 设置随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> angleDist(0.0, 180.0);
    // 定义存储参数的向量列表
    std::vector<std::vector<std::vector<double>>> parameters;
    for (const auto &object : objects)
    {
        // 存储当前对象的参数列表
        std::vector<std::vector<double>> objectParameters;

        // 遍历当前对象的每个坐标
        for (const auto &coordinate : object.trajectory)
        {
            // 随机选择m个单位向量，并计算参数
            int m = 4; // 调整m的值根据需要
            std::vector<double> coordinateParameters;
            double firstangle = angleDist(gen) / 180 * M_PI;
            double step = (M_PI / (m));
            for (int i = 0; i < m; ++i)
            {

                // 调用函数h()计算结果
                double result = calculateH(PolarVector(1.0, firstangle + step * i), convertToPolar(CartesianVector(coordinate.longitude, coordinate.latitude)), D);
                coordinateParameters.push_back(result);
            }

            // 将当前坐标的参数存入坐标参数列表中
            objectParameters.push_back(coordinateParameters);
        }

        // 将当前对象的坐标参数列表存入整体参数列表中
        parameters.push_back(objectParameters);
    }

    // 输出参数列表
    for (const auto &objectParameters : parameters)
    {
        for (const auto &coordinateParameters : objectParameters)
        {
            for (const auto &parameter : coordinateParameters)
            {
                std::cout << parameter << ",";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// 主函数
int main()
{
    // 读取数据集文件

    std::ifstream inputFile("data.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open data file!" << std::endl;
        return 1;
    }

    int numObjects = 0;
    std::vector<Object> objects;
    objects.emplace_back(0);
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(iss, token, ','))
        {

            tokens.push_back(token);
            // cout << token << endl;
        }
        if (tokens.size() != 4)
        {
            std::cerr << "Invalid data format!" << std::endl;
            return 1;
        }
        int objectID = std::stoi(tokens[0]);
        int timestamp = std::stoi(tokens[1]);
        double longitude = std::stod(tokens[2]);
        double latitude = std::stod(tokens[3]);
        if (objectID != numObjects)
        {
            objects.push_back(objectID);
            numObjects = objectID;
        }
        objects[objectID].trajectory.push_back({objectID, timestamp, longitude, latitude});
    }
    inputFile.close();
    cout << objects.size() << endl;
    to_mat(objects, 1);
    return 0;
}
