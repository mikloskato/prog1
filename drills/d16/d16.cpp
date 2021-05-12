#include "../GUI/GUI.h"
#include "../GUI/std_lib_facilities.h"

//g++ d16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o d16 `fltk-config --ldflags --use-images`

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window
{
	Lines_window(Point xy, int w, int h, const string& title);
private:
	
	Open_polyline lines;

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button color_button;
	Menu style_menu;
	Button style_button;

	void quit();

    void next();

	void red_pressed() { change_c(Color::red); hide_color(); }
	void blue_pressed() { change_c(Color::blue); hide_color(); }
	void black_pressed() { change_c(Color::black); hide_color(); }
	void color_pressed() { color_button.hide(); color_menu.show(); }
	void style_pressed(){ style_button.hide(); style_menu.show(); }

	void change_c(Color c) { lines.set_color(c); }
	void change_s(Line_style s) { lines.set_style(s); }
	void hide_color() { color_menu.hide(); color_button.show(); }	
	void hide_style() { style_menu.hide(); style_button.show(); }

	void dot_pressed() { change_s(Line_style::dot), hide_style(); }
	void dash_pressed() { change_s(Line_style::dash), hide_style(); }
	void solid_pressed() { change_s(Line_style::solid), hide_style(); }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	: Window{xy, w, h, title},
	next_button{Point{x_max()-150,0}, 70, 20, "Köv. pont",
	[](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
	quit_button{Point{x_max()-70, 0}, 70, 20, "Kilépés",
	[](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
	next_x{Point{x_max()-310, 0}, 50, 20, "Köv. x:"},
	next_y{Point{x_max()-210, 0}, 50, 20, "Köv y:"},
	xy_out{Point{100, 0}, 100, 20, "Jelenlegi (x,y):"},
	color_menu{Point{x_max() - 70, 30}, 70, 20, Menu::vertical, "color"},
    color_button{Point{x_max() - 80, 30}, 80, 20, "Szin menü",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).color_pressed();
        }
    },
    style_menu{Point{10, 30}, 70, 20, Menu::vertical, "Stílus"},
    style_button{Point{0, 30}, 80, 20, "Stílus menü",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).style_pressed();
        }
    }
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "Piros",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).red_pressed();
        }
    });
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "Kék",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).blue_pressed();
        }
    });
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "Fekete",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).black_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "Pontozott",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).dot_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "Szaggatott",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).dash_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "Folytonos",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).solid_pressed();
        }
    });

    
    attach(style_menu);
    attach(color_menu);
    color_menu.hide();
    style_menu.hide();
    attach(color_button);
    attach(style_button);
    attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point{x, y});
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

int main()
try{
	Lines_window win {Point{100, 100}, 600, 400, "Vonalak"};
	return gui_main();
}
catch(exception& e){
	cerr << "Erorr message: " << e.what() << '\n';
	return 1; 
}
catch(...){
	cerr << "Error\n";
	return 2;
}