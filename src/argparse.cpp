// argparse.cpp

#include "tilemap.h"



bool parse_args(int argc, char *argv[], Options &config) {
    bool error = false;

    for (int i = 1; i < argc; i++) {
        string option(argv[i]);

        if (option == "-w") {
            string val(argv[++i]);
            config.tile_pixel_width = stoi(val, nullptr, 0);
        } else if (option.find("--width=") != string::npos) {
            string val(option.erase(0, 8));
            config.tile_pixel_width = stoi(val, nullptr, 0);
        } else if (option == "-h") {
            string val(argv[++i]);
            config.tile_pixel_height = stoi(val, nullptr, 0);
        } else if (option.find("--height=") != string::npos) {
            string val(option.erase(0, 9));
            config.tile_pixel_height = stoi(val, nullptr, 0);
        } else if (option == "-i") {
            string val(argv[++i]);
            config.index = true;
            config.num_colors = stoi(val, nullptr, 0);
        } else if (option.find("--index=") != string::npos) {
            string val(option.erase(0, 8));
            config.index = true;
            config.num_colors = stoi(val, nullptr, 0);
        } else if (option == "-p") {
            config.palette_file = argv[++i];
        } else if (option.find("--palette=") != string::npos) {
            config.palette_file = option.erase(0, 10);
        } else if (option == "-m") {
            string val(argv[++i]);
            config.max_tiles = stoi(val, nullptr, 0);
        } else if (option.find("--max-tiles=") != string::npos) {
            string val(option.erase(0, 12));
            config.max_tiles = stoi(val, nullptr, 0);
        } else {
            // TODO: add better error tracking
            error = true;
        }
    }

    return !error;
}
