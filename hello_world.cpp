#include <iostream>
#include <typeinfo>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(10);
    
    // ===== 浮点数字面量后缀 =====
    std::cout << "=== 浮点数字面量类型 ===" << std::endl;
    
    // 不同的写法和对应的类型
    auto a = 3.14;      // double类型（默认）
    auto b = 3.14f;     // float类型
    auto c = 3.14F;     // float类型（大写F也可以）
    auto d = 3.14l;     // long double类型
    auto e = 3.14L;     // long double类型（大写L也可以）
    
    std::cout << "3.14 的类型: " << typeid(a).name() << ", 值: " << a << std::endl;
    std::cout << "3.14f 的类型: " << typeid(b).name() << ", 值: " << b << std::endl;
    std::cout << "3.14F 的类型: " << typeid(c).name() << ", 值: " << c << std::endl;
    std::cout << "3.14l 的类型: " << typeid(d).name() << ", 值: " << d << std::endl;
    std::cout << "3.14L 的类型: " << typeid(e).name() << ", 值: " << e << std::endl;
    
    // ===== 为什么需要f后缀 =====
    std::cout << "\n=== 为什么需要f后缀 ===" << std::endl;
    
    // 情况1：赋值给float变量
    float pi1 = 3.14;   // 隐式转换：double -> float（可能有精度损失）
    float pi2 = 3.14f;  // 直接使用float类型，无需转换
    
    std::cout << "float pi1 = 3.14: " << pi1 << std::endl;
    std::cout << "float pi2 = 3.14f: " << pi2 << std::endl;
    
    // 情况2：函数重载时的区别
    auto multiply_double = [](double x, double y) -> double {
        std::cout << "调用 double 版本: ";
        return x * y;
    };
    
    auto multiply_float = [](float x, float y) -> float {
        std::cout << "调用 float 版本: ";
        return x * y;
    };
    
    // 注意：这里为了演示，我们使用不同的函数名
    std::cout << "\n乘法运算示例：" << std::endl;
    double result1 = multiply_double(3.14, 2.0);     // 调用double版本
    std::cout << result1 << std::endl;
    
    float result2 = multiply_float(3.14f, 2.0f);     // 调用float版本
    std::cout << result2 << std::endl;
    
    // ===== 内存占用对比 =====
    std::cout << "\n=== 内存占用对比 ===" << std::endl;
    std::cout << "float 占用字节数: " << sizeof(float) << std::endl;
    std::cout << "double 占用字节数: " << sizeof(double) << std::endl;
    std::cout << "long double 占用字节数: " << sizeof(long double) << std::endl;
    
    // ===== 精度对比 =====
    std::cout << "\n=== 精度对比 ===" << std::endl;
    
    float f_val = 1.0f / 3.0f;
    double d_val = 1.0 / 3.0;
    long double ld_val = 1.0L / 3.0L;
    
    std::cout << std::setprecision(15);
    std::cout << "1/3 (float): " << f_val << std::endl;
    std::cout << "1/3 (double): " << d_val << std::endl;
    std::cout << "1/3 (long double): " << ld_val << std::endl;
    
    // ===== 整数字面量后缀 =====
    std::cout << "\n=== 整数字面量后缀 ===" << std::endl;
    
    auto int_val = 42;          // int
    auto long_val = 42l;        // long (小写l)
    auto long_val2 = 42L;       // long (大写L，推荐)
    auto longlong_val = 42ll;   // long long (小写ll)
    auto longlong_val2 = 42LL;  // long long (大写LL，推荐)
    auto uint_val = 42u;        // unsigned int
    auto uint_val2 = 42U;       // unsigned int
    auto ulong_val = 42ul;      // unsigned long
    auto ulong_val2 = 42UL;     // unsigned long
    
    std::cout << "42 类型: " << typeid(int_val).name() << std::endl;
    std::cout << "42L 类型: " << typeid(long_val2).name() << std::endl;
    std::cout << "42LL 类型: " << typeid(longlong_val2).name() << std::endl;
    std::cout << "42U 类型: " << typeid(uint_val2).name() << std::endl;
    std::cout << "42UL 类型: " << typeid(ulong_val2).name() << std::endl;
    
    // ===== 实际应用场景 =====
    std::cout << "\n=== 实际应用场景 ===" << std::endl;
    
    // 场景1：数组大小计算
    float vertex_data[] = {
        0.0f, 0.0f, 0.0f,    // 顶点1
        1.0f, 0.0f, 0.0f,    // 顶点2
        0.5f, 1.0f, 0.0f     // 顶点3
    };
    
    std::cout << "顶点数据数组大小: " << sizeof(vertex_data) / sizeof(float) << std::endl;
    
    // 场景2：性能敏感的计算
    const int ARRAY_SIZE = 1000000;
    float* float_array = new float[ARRAY_SIZE];
    double* double_array = new double[ARRAY_SIZE];
    
    // 初始化数组
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        float_array[i] = static_cast<float>(i) * 3.14f;
        double_array[i] = static_cast<double>(i) * 3.14;
    }
    
    std::cout << "float数组内存占用: " << sizeof(float) * ARRAY_SIZE / 1024 << " KB" << std::endl;
    std::cout << "double数组内存占用: " << sizeof(double) * ARRAY_SIZE / 1024 << " KB" << std::endl;
    
    // 清理内存
    delete[] float_array;
    delete[] double_array;
    
    // ===== 科学计数法 =====
    std::cout << "\n=== 科学计数法后缀 ===" << std::endl;
    
    float small_f = 1.23e-4f;      // 0.000123f
    double small_d = 1.23e-4;      // 0.000123
    float large_f = 1.23e6f;       // 1230000.0f
    double large_d = 1.23e6;       // 1230000.0
    
    std::cout << std::scientific;
    std::cout << "1.23e-4f: " << small_f << std::endl;
    std::cout << "1.23e-4: " << small_d << std::endl;
    std::cout << "1.23e6f: " << large_f << std::endl;
    std::cout << "1.23e6: " << large_d << std::endl;
    
    return 0;
}

/*
字面量后缀总结：

浮点数后缀：
- f 或 F: float 类型
- 无后缀: double 类型（默认）
- l 或 L: long double 类型

整数后缀：
- 无后缀: int 类型
- l 或 L: long 类型
- ll 或 LL: long long 类型
- u 或 U: unsigned 类型
- ul 或 UL: unsigned long 类型
- ull 或 ULL: unsigned long long 类型

组合后缀：
- 42ULL: unsigned long long
- 3.14f: float
- 1.5L: long double
*/