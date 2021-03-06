// tilemap.h

#ifndef GUARD_TILEMAP_H_
#define GUARD_TILEMAP_H_

#include <cstdio>
using std::fprintf;

#include <cstdlib>
using std::exit;

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string; using std::stoi;

#include <vector>
using std::vector;



#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)          \
do                                        \
{                                         \
    fprintf(stderr, format, __VA_ARGS__); \
    exit(1);                              \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (0)

#endif // _MSC_VER

// tilemap.cpp
class png {
    png()=default;
    int num_colors;
    vector<color> color_table;
};

// argparse.cpp
struct options {
    bool index = false;
    string palette_file;
    int tile_pixel_width = 8;
    int tile_pixel_height = 8;
    int tilemap_tile_width = 0x10;
    int num_colors = 0;
    unsigned max_tiles = -1;
    int calls = 0;
    string image_filepath;
};

bool parse_args(int argc, char *argv[], options &config);

#define TILEMAP_VERSION "0.1.0"

// main.cpp
void print_help();
void print_version();

#endif // GUARD_TILEMAP_H_
