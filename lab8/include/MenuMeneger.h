#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "ListAlgorithm.h"
#include <iostream>
#include <string>

class MenuManager {
private:
    Container<int> intContainer;
    Container<std::string> stringContainer;
    Container<double> doubleContainer;

    int selectDataType() const;
    void loadIntPreset();
    void loadStringPreset();
    void loadDoublePreset();

    void performIntOperation(int operation);
    void performStringOperation(int operation);
    void performDoubleOperation(int operation);

public:
    void loadPresetMenu();
    void addCustomDataMenu();
    void operationsMenu();
    void showAllContainers() const;
    void showMenu();
};

#endif