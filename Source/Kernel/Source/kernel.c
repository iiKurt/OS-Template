/**
 * Thanks to https://wiki.osdev.org/User:No92/UEFI_Bare_Bones for the basic "Hello World" code,
 * some parts of the makefile, and a link to the Zircon EFI headers
 */

#include <efi/boot-services.h>
#include <efi/runtime-services.h>
#include <efi/system-table.h>
#include <efi/types.h>

#include <stdbool.h>

#include "test.h"

/* I'm too lazy to type this out five times */
#define ERR(x) if(EFI_ERROR((x))) return (x)
 
efi_status efi_main(efi_handle handle __attribute__((unused)), efi_system_table *st) {
	efi_status status = 0;
	efi_input_key key;

	/* reset the watchdog timer */
	st->BootServices->SetWatchdogTimer(0, 0, 0, NULL);
	ERR(status);

	/* clear the screen */
	status = st->ConOut->ClearScreen(st->ConOut);
	ERR(status);

	/* print 'Hello World' */
	status = st->ConOut->OutputString(st->ConOut, L"Hello World!");
	ERR(status);

	add(3, 4);

	/* flush console input buffer */
	status = st->ConIn->Reset(st->ConIn, false);
	ERR(status);

	/* poll for a keystroke */
	while((status = st->ConIn->ReadKeyStroke(st->ConIn, &key)) == EFI_NOT_READY);
	ERR(status);

	return EFI_SUCCESS;
}
