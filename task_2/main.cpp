#include "task.hpp"
#include <iostream>

int main(){
    HashTable priceGuide;

    priceGuide.Add("Nuts", 120.50);
    priceGuide.Add("Tile", 424.00);
    priceGuide.Add("Cement", 470.30);
    priceGuide.Add("Wallpaper", 1105.10);
    priceGuide.Add("Glue", 165.90);

    std::cout.precision(2);
    std::cout << "Product price of Wallpaper: " << std::fixed << priceGuide.Find("Wallpaper") << std::endl;

    std::cout << "Product price Nuts: " << std::fixed << priceGuide.Find("Nuts") << std::endl;
    priceGuide.Add("Nuts", 100.00);
    std::cout << "Product price Nuts: " << std::fixed << priceGuide.Find("Nuts") << std::endl;

    std::cout << std::fixed << (priceGuide.Delete("Glue") ? "Glue removed" : "Glue is not on the list") << std::endl;

    std::cout << "The number of products in the directory: " << std::fixed << priceGuide.size() << std::endl;

    system("pause");
    return 0;
}