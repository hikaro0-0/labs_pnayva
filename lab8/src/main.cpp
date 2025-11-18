#include "MenuMeneger.h"
#include <locale>

int main() {
    setlocale(0, "rus");
    std::cout << "=== ÏĞÎÃĞÀÌÌÀ ÄËß ĞÀÁÎÒÛ Ñ ÊÎÍÒÅÉÍÅĞÀÌÈ È ÀËÃÎĞÈÒÌÀÌÈ ===" << std::endl;

    MenuManager manager;
    manager.showMenu();

    return 0;
}