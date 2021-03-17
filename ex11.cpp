#include "./GUI/GUI.h"
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include "./GUI/Window.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main(){
    try{



    }
    catch(exception&e ){
        cerr << "exception: " << e.what();
        return 1;
    }
    catch(...){
        cerr << "error";
        return 1;
    }
}