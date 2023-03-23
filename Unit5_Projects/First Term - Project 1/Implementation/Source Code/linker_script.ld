/* 
	linker_script.ld for Cortex-M3
	Eng. Ahmed Essam
*/

MEMORY
{
	FLASH(RX): ORIGIN = 0x08000000, LENGTH = 128K
	SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 20K
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
		. = ALIGN(4);
		_E_bss_ = .;
	}> SRAM

	. = . + 0X1000;
	_STACK_top = .;
}