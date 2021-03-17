// g++ d12.cpp Graph.cpp Simple_window.cpp Window.cpp GUI.cpp -o d12 `fltk-config --ldflags --use-images` -w

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
	Point tl {175,175};
	Simple_window win {tl,600,400,"My window"};
	win.wait_for_button();

    //x tengely
	Axis xa {Axis::x, Point{20,350}, 300, 10, "x tengely"};
    xa.set_color(Color::yellow);
    xa.label.set_color(Color::red);
	win.attach(xa);
	win.set_label("Második oldal");
	win.wait_for_button(); 

    //y tengely
	Axis ya {Axis::y, Point{20,350}, 300, 10, "y tengely"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::green);
	win.attach(ya);
	win.set_label("Harmadik oldal");
	win.wait_for_button();

    //sin
	Function sine {sin,0,100,Point{20,180},200,20,20};
	win.attach(sine);
	win.set_label("Negyedik oldal");
	win.wait_for_button();
	sine.set_color(Color::yellow);

    //polygon
	Polygon poly;
	poly.add(Point{150,100});
	poly.add(Point{350,120});
	poly.add(Point{450,200});
	poly.set_color(Color::green);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Ötödik oldal");
	win.wait_for_button();

    //rectangle
	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);
	win.set_label("Hatodik oldal");
	win.wait_for_button();

    //closed polyline
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,75});

    //coloring the rectanlges
	r.set_fill_color(Color::cyan);
	poly.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::blue);
	win.set_label("Hetedik oldal");
	win.wait_for_button();	

    //text
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Nyolcadik oldal");
	win.wait_for_button();

    //text styling
	t.set_font(Font::times_bold);
	t.set_font_size(40);
	win.set_label("Kilencedik oldal");
	win.wait_for_button();

    //img 
	Image ii {Point(100,50),"badge.jpg"};
	win.attach(ii);
	win.set_label("Tizedik oldal");
	win.wait_for_button();
    //moving the img
	ii.move(100,200);
	win.set_label("Tizenegyedik oldal");
	win.wait_for_button();

    //circle
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::blue);
	Mark m {Point(100,200),'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
    
	//gif
    Image cal {Point{225,225},"dog.gif"};
	cal.set_mask(Point{40,40},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Dia #12");
	win.wait_for_button();


}
catch (exception& e) {
    return 1;
}
catch (...) {
    return 2;
}