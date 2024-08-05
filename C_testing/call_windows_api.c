#include <windows.h>

int main() {
    MessageBox(
        NULL,                   // Ownership of the window
        "Hi, from windows API",
        "Tittle of MessageBox",
        MB_OK                   // Type of MessageBox (MB_OK = Simple OK button)
    );
    return 0;
}
