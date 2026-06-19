#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 抽象图形类
class Shape {
public:
    // 纯虚函数
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    virtual void scale(double factor) = 0;
    
    // 普通函数
    void setColor(const string& c) { color = c; }
    string getColor() const { return color; }
    
    // 虚析构函数
    virtual ~Shape() = default;

protected:
    string color = "black";
};

// 具体实现：圆形
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() const override {
        cout << "绘制圆形: 半径=" << radius 
             << ", 颜色=" << color << endl;
    }
    
    void scale(double factor) override {
        radius *= factor;
    }
};

// 具体实现：矩形
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "绘制矩形: " << width << "x" << height 
             << ", 颜色=" << color << endl;
    }
    
    void scale(double factor) override {
        width *= factor;
        height *= factor;
    }
};

// 图形管理器
class ShapeManager {
private:
    vector<Shape*> shapes;
    
public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }
    
    void drawAll() const {
        for (const auto& shape : shapes) {
            shape->draw();
            cout << "面积: " << shape->area() 
                 << ", 周长: " << shape->perimeter() << endl;
            cout << "---" << endl;
        }
    }
    
    double totalArea() const {
        double total = 0;
        for (const auto& shape : shapes) {
            total += shape->area();
        }
        return total;
    }
    
    ~ShapeManager() {
        for (auto shape : shapes) {
            delete shape;
        }
    }
};

int main() {
    ShapeManager manager;
    
    // 创建各种图形
    Circle* circle = new Circle(5.0);
    circle->setColor("red");
    
    Rectangle* rect = new Rectangle(4.0, 6.0);
    rect->setColor("blue");
    
    // 添加到管理器
    manager.addShape(circle);
    manager.addShape(rect);
    
    // 统一操作
    cout << "所有图形:" << endl;
    manager.drawAll();
    
    cout << "总面积: " << manager.totalArea() << endl;
    
    return 0;
}