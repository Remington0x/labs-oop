#include <iostream>

class Rectangle {
public:
    Rectangle(double, double, double, double);

    Rectangle &rec = Rectangle;

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

    Rectangle &compareSquare(Rectangle &rec2) {
        double square1 = getSquare();
        double square2 = rec2::getSquare();
        if (square1 >= square2) {
            return rec;
        } else {
            return rec2;
        }
    }

    Rectangle &comparePerimeter(Rectangle &rec2) {
        double perimeter1 = getPerimeter();
        double perimeter2 = rec2.getPerimeter();
        if (perimeter1 >= perimeter2) {
            return rec;
        } else {
            return rec2;
        }
    }

    Rectangle &intersection(Rectangle &rec2) {
        double int_x_left, int_x_right, int_y_left, int_y_right;
        bool a, b, c, d;
        a = is_point_on(rec.xl, rec.yr, &rec2); //upper left
        b = is_point_on(rec.xr, rec.yr, &rec2); //upper right
        c = is_point_on(rec.xl, rec.yl, &rec2); //down left
        d = is_point_on(rec.xr, rec.yl, &rec2); //down right

        if (a) {
            if (b) {    //rec2 limits only on bottom
                int_x_left = rec.xl;
                int_y_left = rec2.yl;
                int_x_right = rec.xr;
                int_y_right = rec.yr; 
            } else
            if (c) {    //rec2 limits only on right border
                int_x_left = rec.xl;
                int_y_left = rec.yl;
                int_x_right = rec2.xr;
                int_y_right = rec.yr;
            } else
            if (d) {    //that means that rec fully placed on rec2
                int_x_left = rec.xl;
                int_y_left = rec.yl;
                int_x_right = rec.xr;
                int_y_right = rec.yr;
            } else {    //that means only a placed on the rec2
                int_x_left = rec.xl;
                int_y_left = rec2.yl;
                int_x_right = rec2.xr;
                int_y_right = rec.yr;
            }
        } else
        if (b) {
            if (c) {
                int_x_left = rec2.xl;
                int_y_left = rec.yl;
                int_x_right = rec.xr;
                int_y_right = rec.yr;
            } else {    //only b
                int_x_left = rec2.xl;
                int_y_left = rec2.yl;
                int_x_right = rec.xr;
                int_y_right = rec.yr;
            }
        } else
        if (c) {
            if (d) {
                int_x_left = rec.xl;
                int_y_left = rec.yl;
                int_x_right = rec.xr;
                int_y_right = rec2.yr;
            } else {    //only c
                int_x_left = rec.xl;
                int_y_left = rec.yl;
                int_x_right = rec2.xr;
                int_y_right = rec2.yr;
            }
        } else
        if (d) {    //only d
            int_x_left = rec2.xl;
            int_y_left = rec.yl;
            int_x_right = rec.xr;
            int_y_right = rec2.yr;
        } else {
            return NULL;
        }


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

}
