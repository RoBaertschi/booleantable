#include <iostream>
#include "Window.h"
#include "Logging.h"
#include "TruthTable.h"

int main() {
    InitLogger();
    CWindow window{};
    window.run();
    return 0;
}
