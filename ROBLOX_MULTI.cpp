#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	SetLastError(0);
	HANDLE mutex = CreateMutex(NULL, TRUE, "ROBLOX_singletonMutex"); //bInitialOwner is TRUE, takes ownership and holds it until this process exits
	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		printf("A client was opened prior to starting this program.\n"
				"Opening future clients will close the first client but allow multiple to run afterwards.\n");
		WaitForSingleObject(mutex, INFINITE);
	}

	printf("You can now use multiple ROBLOX clients. Closing this will cause all ROBLOX clients to terminate except for one.\n"
			"Press any key to close");
	_getch_nolock();
	return 0;
}
