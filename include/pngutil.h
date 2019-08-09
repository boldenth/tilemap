#ifndef PNG_UTIL_H
#define PNG_UTIL_H

#include <string>
using std::string;

typedef uint8_t byte;
typedef vector<byte> bytearray;

// TODO: alpha
struct color {
    byte red;
    byte green;
    byte blue;
    color(unsigned r, unsigned g, unsigned b) {
        if (r > 0xFF) r = 0xFF;
        if (g > 0xFF) g = 0xFF;
        if (b > 0xFF) b = 0xFF;
        red = r; green = g; blue = b;
    }
    color() : color(0,0,0) {}
    unsigned to_binary() {
        return (red | (green << 5) | (blue << 10));
    };
};

//struct color_table {
    //
//};

//vector<byte>
const byte png_header[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

class png {

public:

    png(string filename);

    size_t color_count();
    vector<color> color_table();

    void save();
    void save(string filename);

    void set_bit_depth(int depth);
    void set_palette(vector<color> palette);

    int pixel_width() const;
    int pixel_height() const;

    // what are chunks?
    int chunk(int chunk_width, int chunk_height);// return is num chunks created (that are unique? or not empty)
    int chunk_width() const;// size of the chunks in the image
    int chunk_height() const;

private:

    string filepath_;
    vector<color> color_table_;

    int width_;
    int height_;

    int chunk_width_;
    int chunk_height_;

    // chunks
    bytearray ihdr_;
    bytearray plte_;
    bytearray idat_;
};

png read_png(string filename);

#endif // PNG_UTIL_H
