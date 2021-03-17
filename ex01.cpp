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

        Point t1{100,100};
        Simple_window win {t1, 600,600, "ch12 labor"};
        win.wait_for_button();

        //01
        Rectangle r {Point {50,50}, 50, 25};
        r.set_color(Color::blue);
        win.attach(r);

        Polygon rect;
        rect.add(Point{125,50});
        rect.add(Point{175,50});
        rect.add(Point{175,75});
        rect.add(Point{125,75});
        rect.set_color(Color::red);
        win.attach(rect);

        win.set_label("Feladat 1");
        win.wait_for_button();

        //02
        Rectangle rt{Point{200,500}, 100, 30};
        win.attach(rt);
        Text t {Point{205,75}, "textbox"};
        t.set_font(Font::helvetica_bold);
        t.set_font_size(20);
        win.attach(t);

        win.set_label("Feladat 2");
        win.wait_for_button();

        //03
        Text t2 {Point{50,350}, "K"};
        t2.set_font(Font::courier);
        t2.set_font_size(150);

        Text t3 {Point{250,350}, "M"};
        t2.set_font(Font::courier);
        t2.set_font_size(150);

        t2.set_color(Color::blue);
        t3.set_color(Color::red);

        win.attach(t2);
        win.attach(t3);
        win.set_label("Feladat 3");
        win.wait_for_button();



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