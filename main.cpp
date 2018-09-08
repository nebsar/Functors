/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on August 27, 2018, 12:05 AM
 */

/// https://www.youtube.com/watch?v=qcuYSqHxqLk

#include <cstdlib>
#include<iostream>

#include <algorithm>
#include <vector>

#include <utility>

using namespace std;

/*
 * 
 */
struct MatchFirstFunctor {

    MatchFirstFunctor(int i)
    : m_i(i) {
    }

    bool operator()(const pair<int, bool>& pair) {
        return pair.first == m_i;
    }

    int m_i;
};

template <typename T>

struct MatchFirstFunctorTemplate {

    MatchFirstFunctorTemplate(T t)
    : m_t(t) {
    }

    template <typename U>
    bool operator()(const U& pair) {
        return pair.first == m_t;
    }

    T m_t;
};

struct Dog {

    Dog(int age)
    : m_age(age) {
    }

    bool operator<(const Dog& other) const {
        return m_age < other.m_age;
    }

    bool operator==(int age) const {
        return m_age == age;
    }

    int m_age;
};

struct DogWithWeight {

    DogWithWeight(int age, int weight)
    : m_age(age),
    m_weight(weight) {
    }

    int m_age;
    int m_weight;

};

struct SortByWeightFunctor {

    bool operator()(const DogWithWeight& lhs, const DogWithWeight& rhs) {
        return lhs.m_weight < rhs.m_weight;
    }
};

struct FindByWeightFunctor {

    FindByWeightFunctor(int weight)
    : m_weight(weight) {
    }

    bool operator()(const DogWithWeight& dog) const {
        return m_weight == dog.m_weight;
    }

    int m_weight;
};




void doSomething(int i, bool b, float f, double d, unsigned int u, char c);

struct Object {

    int operator()(int i) const { // we are overloading the "()" operator here.
        return i;
    }
};

struct AddFunctor {

    int operator()(int i, int j) const { // we are overloading the "()" operator here.
        return i + j;
    }

};

struct AddWithSingleParameter {

    AddWithSingleParameter(int z)
    : m_x(z) {
    }

    int operator()(int s) const {
        return m_x + s;
    }

    int m_x;
};

struct DoSomethingFunctor {

    DoSomethingFunctor(int i, bool b, float f, double d, unsigned int u)
    : m_i(i),
    m_b(b),
    m_f(f),
    m_d(d),
    m_u(u) {
    }

    void operator()(char c) const {
        // do sth. 
        doSomething(5, true, 2.f, 4., 4u, 'a');
        ++m_count;
    }

    int m_i;
    bool m_b;
    float m_f;
    double m_d;
    unsigned int m_u;
    mutable unsigned int m_count;
};

int Foo(int i) {
    return i;
}

int Add(int x, int y) {
    return x + y;
}

void doSomething(int i, bool b, float f, double d, unsigned int u, char c) {
    // does sth.
}

int main() {

    Foo(45);
    Object o;
    o(45);

    int i = 1;
    int k = 5;

    AddFunctor a;
    int z = a(5, 7);
    cout << z << endl;

    AddWithSingleParameter af(3);
    cout << af(i) << endl;
    cout << af(k) << endl;

    DoSomethingFunctor d(5, true, 2.f, 3., 4u);
    d('a');
    d('b');

    vector<Dog> v = {Dog(3), Dog(1), Dog(5), Dog(2), Dog(4)};
    sort(begin(v), end(v)); // sorts the dogs according to their ages with "<" operator overload;

    find(begin(v), end(v), 3); //finds the dog according to its age;


    for (int i = 0; i < v.size(); i++) {
        cout << v[i].m_age << endl;
    }

    vector<DogWithWeight> vw = {DogWithWeight(3, 40), DogWithWeight(1, 20), DogWithWeight(5, 10), DogWithWeight(2, 30), DogWithWeight(4, 50)};
    sort(begin(vw), end(vw), SortByWeightFunctor()); // sorts the Dogs with weight according to their weights;


    find_if(begin(vw), end(vw), FindByWeightFunctor(40)); // find the dog with 40 weight;

    vector < pair<int, bool>> v1 = {make_pair(1, true), make_pair(2, false)};
    vector < pair<bool, float>> v2 = {make_pair(true, 1.f), make_pair(false, 2.f)};


    find(begin(v1), end(v1), make_pair(1, true));

    find_if(begin(v1), end(v1), MatchFirstFunctor(2));

    find_if(begin(v1), end(v1), MatchFirstFunctorTemplate<int>(2));
    find_if(begin(v2), end(v2), MatchFirstFunctorTemplate<bool>(true));

    return 0;
}

