#include <windows.h>
#include <stdlib.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HWND hResult, hTurn;

int p1Choice = -1;
int p2Choice = -1;
int turn = 1; // 1 = Player1, 2 = Player2

const char* getName(int c)
{
    if (c == 0) return "Rock";
    if (c == 1) return "Paper";
    return "Scissors";
}

const char* getWinner(int p1, int p2)
{
    if (p1 == p2)
        return "Draw!";

    if ((p1 == 0 && p2 == 2) ||
        (p1 == 1 && p2 == 0) ||
        (p1 == 2 && p2 == 1))
        return "Player 1 Wins!";

    return "Player 2 Wins!";
}

void resetGame()
{
    p1Choice = -1;
    p2Choice = -1;
    turn = 1;
}

void updateUI(HWND hwnd)
{
    if (turn == 1)
        SetWindowText(hTurn, "Player 1 Turn");
    else
        SetWindowText(hTurn, "Player 2 Turn");
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:

        CreateWindow("BUTTON", "Rock",
            WS_VISIBLE | WS_CHILD,
            50, 50, 100, 40,
            hwnd, (HMENU)1, NULL, NULL);

        CreateWindow("BUTTON", "Paper",
            WS_VISIBLE | WS_CHILD,
            160, 50, 100, 40,
            hwnd, (HMENU)2, NULL, NULL);

        CreateWindow("BUTTON", "Scissors",
            WS_VISIBLE | WS_CHILD,
            270, 50, 100, 40,
            hwnd, (HMENU)3, NULL, NULL);

        hTurn = CreateWindow("STATIC", "Player 1 Turn",
            WS_VISIBLE | WS_CHILD,
            50, 110, 300, 30,
            hwnd, NULL, NULL, NULL);

        hResult = CreateWindow("STATIC", "Make your move!",
            WS_VISIBLE | WS_CHILD,
            50, 150, 300, 40,
            hwnd, NULL, NULL, NULL);

        break;

    case WM_COMMAND:
    {
        int choice = -1;

        if (wp == 1) choice = 0;
        if (wp == 2) choice = 1;
        if (wp == 3) choice = 2;

        if (choice == -1) break;

        
        if (turn == 1)
        {
            p1Choice = choice;
            turn = 2;
            SetWindowText(hResult, "Player 2 turn now!");
        }
        
        else
        {
            p2Choice = choice;

            const char* result = getWinner(p1Choice, p2Choice);

            char buffer[200];
            sprintf(buffer,
                "P1: %s | P2: %s\n%s",
                getName(p1Choice),
                getName(p2Choice),
                result);

            SetWindowText(hResult, buffer);

            resetGame();
            updateUI(hwnd);
        }

        updateUI(hwnd);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR args, int ncmdshow)
{
    WNDCLASS wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "MP_RPS";
    wc.lpfnWndProc = WindowProcedure;

    RegisterClass(&wc);

    CreateWindow("MP_RPS",
        "Multiplayer Rock Paper Scissors",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 450, 250,
        NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}