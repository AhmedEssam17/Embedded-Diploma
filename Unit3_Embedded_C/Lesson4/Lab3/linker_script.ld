/* 
	linker_script.ld for Cortex-M4
	Eng. Ahmed Essam
*/

MEMORY
{
	FLASH(RX): ORIGIN = 0x00000000, LENGTH = 512M
	SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text_ = .;
	}> FLASH

	.data :
	{
		_S_data_ = .;
		*(.data)
		. = ALIGN(4);
		_E_data_ = .;
	}> SRAM AT> FLASH

	.bss :
	{
		_S_bss_ = .;
		*(.bss)
		_E_bss_ = .;
	}> SRAM
}
