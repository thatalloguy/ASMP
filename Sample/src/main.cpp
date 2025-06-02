//
// Created by allos on 02/06/2025.
//

#include <Globals.h>


int main () {

    Globals::initProject();

    while (!Globals::shouldClose()) {
        Globals::updateProject();
    }


    Globals::destroyProject();
}