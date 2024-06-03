#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <list>

// Базовий клас
class Function {
public:
    virtual double compute(double x) = 0; // Віртуальна функція
    virtual ~Function() = default;
};

// Похідний клас 1
class LinearFunction : public Function {
public:
    double compute(double x) override {
        return x; // f(x) = x
    }
};

// Похідний клас 2
class QuadraticFunction : public Function {
public:
    double compute(double x) override {
        return x * x; // f(x) = x^2
    }
};

// Похідний клас 3
class CubicFunction : public Function {
public:
    double compute(double x) override {
        return x * x * x; // f(x) = x^3
    }
};

// Клас-контейнер
class FunctionContainer {
private:
    std::list<Function*> functions; // заміна std::vector на std::list
public:
    void add(Function* function) {
        functions.push_back(function);
    }
    double computeSum(double x) {
        double sum = 0;
        for (Function* function : functions) {
            sum += function->compute(x);
        }
        return sum;
    }
    ~FunctionContainer() {
        for (Function* function : functions) {
            delete function;
        }
    }
};

#endif // FUNCTIONS_H
