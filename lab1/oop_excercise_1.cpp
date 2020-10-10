#include <iostream>

class Rectangle {
public:
    Rectangle(double xl, double yl, double xr, double yr);

    ~Rectangle();

    //Rectangle &rec = Rectangle;
    double xl;
    double xr;
    double yl;
    double yr;

    double getSquare() {
        return (xr - xl) * (yr - yl);
    }

    double getPerimeter() {
        return 2 * (xr - xl + yr - yl);
    }

    void move(double x, double y) { //на сколько по x и y сдвинуть
        xr += x;
        xl += x;
        yr += y;
        yl += y;
    }

    void changeDimensions(double x, double y) { //увеличить на х по ОХ и на y по OY
        xr += x;
        yr += y;
    }

    bool isSquareLarger(Rectangle &rec2) {
        double square1 = getSquare();
        double square2 = rec2.getSquare();
        if (square1 > square2) {
            return true;
        } else {
            return false;
        }
    }

    bool isPerimeterLarger(Rectangle &rec2) {
        double perimeter1 = getPerimeter();
        double perimeter2 = rec2.getPerimeter();
        if (perimeter1 > perimeter2) {
            return true;
        } else {
            return false;
        }
    }

    bool is_point_on(double x, double y, Rectangle &rec) {
        if ((x >= rec.xl) && (x <= rec.xr) && (y >= rec.yl) && (y <= rec.yr)) {
            return true;
        } else {
            return false;
        }
    }

    Rectangle intersection(Rectangle &rec2, bool &code) {
        double int_x_left = 0;
        double int_x_right = 0;
        double int_y_left = 0;
        double int_y_right = 0;
        bool a, b, c, d;
        a = is_point_on(xl, yr, rec2); //upper left
        b = is_point_on(xr, yr, rec2); //upper right
        c = is_point_on(xl, yl, rec2); //down left
        d = is_point_on(xr, yl, rec2); //down right

        if (a) {
            if (b) {    //rec2 limits only on bottom
                int_x_left = xl;
                int_y_left = rec2.yl;
                int_x_right = xr;
                int_y_right = yr;
            } else
            if (c) {    //rec2 limits only on right border
                int_x_left = xl;
                int_y_left = yl;
                int_x_right = rec2.xr;
                int_y_right = yr;
            } else
            if (d) {    //that means that rec fully placed on rec2
                int_x_left = xl;
                int_y_left = yl;
                int_x_right = xr;
                int_y_right = yr;
            } else {    //that means only a placed on the rec2
                int_x_left = xl;
                int_y_left = rec2.yl;
                int_x_right = rec2.xr;
                int_y_right = yr;
            }
        } else
        if (b) {
            if (c) {
                int_x_left = rec2.xl;
                int_y_left = yl;
                int_x_right = xr;
                int_y_right = yr;
            } else {    //only b
                int_x_left = rec2.xl;
                int_y_left = rec2.yl;
                int_x_right = xr;
                int_y_right = yr;
            }
        } else
        if (c) {
            if (d) {
                int_x_left = xl;
                int_y_left = yl;
                int_x_right = xr;
                int_y_right = rec2.yr;
            } else {    //only c
                int_x_left = xl;
                int_y_left = yl;
                int_x_right = rec2.xr;
                int_y_right = rec2.yr;
            }
        } else
        if (d) {    //only d
            int_x_left = rec2.xl;
            int_y_left = yl;
            int_x_right = xr;
            int_y_right = rec2.yr;
        } else {
            code = false;
        }

        Rectangle rec_int(int_x_left, int_y_left, int_x_right, int_y_right);
        code = true;

        return rec_int;

    }
};

bool is_point_on(double x, double y, Rectangle &rec) {
    if ((x >= rec.xl) && (x <= rec.xr) && (y >= rec.yl) && (y <= rec.yr)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::cout << "Hello, world!\n";
}
