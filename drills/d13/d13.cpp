// g++ d13.cpp Graph.cpp Simple_window.cpp Window.cpp GUI.cpp -o d13 `fltk-config --ldflags --use-images` -w

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    //1
    Simple_window win {Point{100,100}, 800, 1000,"13.fejezet"};
    
    //2
    Lines mesh_grid;
    for(int i = 100; i<= 800; i += 100)
    {
        mesh_grid.add(Point{i,0}, Point{i, 800});
        mesh_grid.add(Point{0,i}, Point{800, i});
    }
    
    //3
    //creating rectangles
    Rectangle elso{Point{0,0},100,100};
    Rectangle masodik{Point{100,100},100,100};
    Rectangle harmadik{Point{200,200},100,100};
    Rectangle negyedik{Point{300,300},100,100};
    Rectangle otodik{Point{400,400},100,100};
    Rectangle hatodik{Point{500,500},100,100};
    Rectangle hetedik{Point{600,600},100,100};
    Rectangle nyolcadik{Point{700,700},100,100};

    //filling the rectangles
    elso.set_fill_color(Color::cyan);
    masodik.set_fill_color(Color::cyan);
    harmadik.set_fill_color(Color::cyan);
    negyedik.set_fill_color(Color::cyan);
    otodik.set_fill_color(Color::cyan);
    hatodik.set_fill_color(Color::cyan);
    hetedik.set_fill_color(Color::cyan);
    nyolcadik.set_fill_color(Color::cyan);

    //4
    Image i1{Point{0,200}, "1.gif"};
    Image i2{Point{600,200}, "2.gif"};
    Image i3{Point{0,500}, "3.gif"};
    Image i4{Point{600,400}, "4.gif"};

    //5
    Image mozog{Point{0,0}, "100x100.gif"};

    //attaching stuff to the win/canvas
    win.attach(mozog);
    win.attach(i1);
    win.attach(i2);
    win.attach(i3);
    win.attach(i4);
    win.attach(elso);
    win.attach(masodik);
    win.attach(harmadik);
    win.attach(negyedik);
    win.attach(otodik);
    win.attach(hatodik);
    win.attach(hetedik);
    win.attach(nyolcadik);
    win.attach(mesh_grid);
    win.set_label("ch13_exercises");


    //moving the imgage with a for loop
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            win.wait_for_button();
            if(j < 7){
                mozog.move(100,0);
            }
            else{
                mozog.move(-700,100);
            }
        }
    }
}
