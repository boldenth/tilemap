// tilemap.cpp

#include "tilemap.h"



int main(int argc, char *argv[]) {
    Options config;

    if (argc < 2)
        print_help();

    if (argc == 2) {
        string option(argv[1]);
        if (option == "--help")
            print_help();
        else if (option == "-v" || option == "--version")
            print_version();
        else
            print_help();
    }

    if (!parse_args(argc, argv, config))
        print_help();
    else
        cout << "args parsed: " << endl
             << "index: " << std::boolalpha << config.index << endl
             << "num colors: " << config.num_colors << endl
             << "tile_pixel_width: " << config.tile_pixel_width << endl
             << "tile_pixel_height: " << config.tile_pixel_height << endl
             << "tilemap_tile_width: " << config.tilemap_tile_width << endl
             << "max_tiles: " << config.max_tiles << endl
             << "palette file: " << config.palette_file << endl;

    return 0;
}

void print_version() {
    cout << "tilemap " TILEMAP_VERSION "\n"
            "Copyright (C) 2019 Thomas Bolden\n"
            "\n"
            "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,\n"
            "EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES\n"
            "OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.\n"
            "IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,\n"
            "DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,\n"
            "TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE\n"
            "SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE."
    ;
    cout << endl;
}

// add arg for bytes in tilemap
// add args for h-flip / v-flip / 90-degree rotations
void print_help() {
    cout << "tilemap is released under the MIT license\n"
            "\n"
            "Usage:\n"
            "    tilemap [options] <image file>\n"
            "\n"
            "Options:"
            "    Options must be presented separately.\n"
            "    --help:\n"
            "            Prints usage information.\n"
            "    --version:\n"
            "            Prints version information.\n"
            "    -w <num> --width=<num>:\n"
            "            The pixel width of each tile.\n"
            "            By default, this value is 8.\n"
            "    -h <num> --height=<num>:\n"
            "            The pixel height of each tile.\n"
            "            By default, this value is 8.\n"
            "    -i <num> --index=<num>:\n"
            "            If this option is passed, tilemap will index the\n"
            "            image file to num colors.\n"
            "            By default, this value is 16.\n"
            "    -p <file> --palette=<file>:\n"
            "            A JASC palette file to use to colorize the image."
            "    -m <num> --max-tiles=<num>:\n"
            "            The maximum number of tiles in the tilemap.\n"
    ;
    cout << endl;
    exit(0);
}
