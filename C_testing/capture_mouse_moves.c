#include <windows.h>
#include <stdio.h>

// Define the window procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // Message handlers
    switch (uMsg) {
        case WM_MOUSEMOVE: { // Message is sent to the window whenever the mouse is moved 
            int x = LOWORD(lParam); // Low-order word (x-coordinate)
            int y = HIWORD(lParam); // High-order word (y-coordinate)
            printf("Mouse move: x=%d, y=%d\n", x, y);
            return 0;
        }
        case WM_DESTROY: {
            printf("Goodbye!\n");
            PostQuitMessage(0);
            return 0;
        }
        default:
            // default window procedure, processes any messages not handled
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {
    // Register the window class
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance; // Instance handle of the window
    wc.lpszClassName = "BasicWindowClass";

    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0, // Extended style
        "BasicWindowClass", // Class
        "Basic Window", // Title
        WS_OVERLAPPEDWINDOW, // Style
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // Size/Position
        NULL, // Parent
        NULL, // Menu
        hInstance,
        NULL // Additional data
    );

    // Initialize the window
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    // Message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) { // Retrieves a message from the message queue
        TranslateMessage(&msg); // Translates virtual key messages
        DispatchMessage(&msg); //Dispatche to the window procedure
    }

    return 0;
}
