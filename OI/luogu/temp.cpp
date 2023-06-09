#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <random>

// 极坐标对象
struct PolarVector
{
    double radius; // 半径
    double angle;  // 角度弧度制
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

int main()
{

    const double D = 1.0;
    // 定义对象列表
    std::vector<std::vector<std::pair<double, double>>> objects = {
        {{1.0, 2.0}, {3.0, 4.0}},   // 对象1的坐标列表
        {{5.0, 6.0}, {7.0, 8.0}},   // 对象2的坐标列表
        {{9.0, 10.0}, {11.0, 12.0}} // 对象3的坐标列表
        // 可根据需要添加更多对象和坐标
    };

    // 定义存储参数的向量列表
    std::vector<std::vector<std::vector<double>>> parameters;

    // 设置随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> angleDist(0.0, 180.0);

    // 遍历每个对象的坐标
    for (const auto &object : objects)
    {
        // 存储当前对象的参数列表
        std::vector<std::vector<double>> objectParameters;

        // 遍历当前对象的每个坐标
        for (const auto &coordinate : object)
        {
            // 随机选择m个单位向量，并计算参数
            int m = 4; // 调整m的值根据需要
            std::vector<double> coordinateParameters;
            double firstangle=angleDist(gen)/180*M_PI;
            for (int i = 0; i < m; ++i)
            {

                // 调用函数h()计算结果
                double result = calculateH(PolarVector(1.0,firstangle+(M_PI/(m)*i)), convertToPolar(CartesianVector(coordinate.first, coordinate.second)), D);

                // 存储参数和计算结果
                // coordinateParameters.push_back(parameter1);
                // coordinateParameters.push_back(parameter2);
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
                std::cout << parameter << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}