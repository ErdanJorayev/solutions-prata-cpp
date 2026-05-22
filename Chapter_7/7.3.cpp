#include <iostream>

struct box 
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(box kek);
void prod(box * kek);

int main()
{
    box lol = {"Alex corporation", 220, 34, 57, 0};
    prod(&lol);
    show(lol);

    return 0;
}

void prod(box * kek)
{
    kek->volume = kek->height * kek->width * kek->length;
}

void show(box kek)
{
    std::cout << "Maker: "  << kek.maker  << '\n'
              << "Height: " << kek.height << '\n'
              << "Width: "  << kek.width  << '\n'
              << "Length: " << kek.length << '\n'
              << "Volume: " << kek.volume << '\n';
}
