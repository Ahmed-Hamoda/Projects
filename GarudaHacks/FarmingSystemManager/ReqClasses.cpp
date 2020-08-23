#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "mainwindow.h"

#define pb push_back
#define index(a, c) distance((a).begin(), find((a).begin(), (a).end(), (c)))

using namespace std;

class Item{
    public:
    float price;
    QString name;
    Item(QString n, float p){
        name = n;
        price = p;
    }
};

class Inventory{
public:
    unordered_map<QString,int> inventory;
    unordered_map<QString, float> prices;

    void addItem(Item item, int quantity){
        if (inventory.find(item.name)==inventory.end()){
            inventory[item.name] = quantity;
            prices[item.name] = item.price;
        }else{
            inventory[item.name] += quantity;
        }
    }

    void reduceItem(QString item, int quantity){
        if (quantity <= inventory[item]){
            inventory[item] -= quantity;
        }else{
            cout << "There is only " << inventory[item] << "in stock";
        }
    }

    void removeItem(QString item){
        inventory.erase(item);
        prices.erase(item);
    }

    float totalPrice(QString item){
        // to find total price of an item in the inventory
        float ans = prices[item] * inventory[item];  // price multiplied by quantity
        return ans;
    }

    float totalInventoryValue(){
        float ans = 0.0;
        for (auto &i : inventory){
            ans += totalPrice(i.first);
        }
        return ans;
    }
    void showInventory(){
        for(pair<QString, int> i : inventory){
            cout << i.first.toStdString() << ": " << i.second<<endl;
        }
    }

};


class Employee{
public:
    QString name;
    float salary;
    float hours;
    float deductions; //tax, late, missed over sick days

    Employee(QString a, float s, float h) : name(a) , salary(s), hours(h){}

    void employeeDeductions(float incomeTax, float federalTax){
        float first = incomeTax*salary;
        float second = federalTax*salary;
        deductions = salary - first - second;
    }
};

class PayRollSystem{
public:
    float cash;
    vector<Employee> employees;

    void payday(){
        for(Employee i : employees){
            cash -= i.salary + i.deductions;
        }
    }
};

class Task{
    public:
    QString task;
    bool isDone = false;
    Task(QString t){
        task = t;
    }
};

class TaskManager{
    public:
    vector<pair<Task,int>> tasks;

    void addTask(Task task, int imp){
        tasks.pb(pair<Task,int> (task, imp));
    }

    void finishTask(QString title){
        for (int i=0;i<(int)tasks.size();i++){
            if (tasks[i].first.task==title){
                tasks[i].first.isDone = true;
            }
        }
    }
};
