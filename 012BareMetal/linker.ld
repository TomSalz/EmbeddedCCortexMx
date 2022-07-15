ENTRY(Reset_Handler) /* entry point, the program will start here, can also be an ASM function */

/* descripe the memory of the device */
/* Syntax of a memory
 * label(attr): ORIGIN = origin, LENGTH = len
 * 
 * label: defines name of the memory region which will be referenced later by other parts of the
 *       the linker script
 * origin: defines the origin address of the memory region
 * length: defines the length of the _label_
 * attr: R	read-only section
 *	     W  read and write sections
 *       X  Sections containing executable code
 *       A  Allocated sections
 *       I  Initialized sections
 *       !  Invert the sense of any of the following attributes
 */
MEMORY
{
    FLASH(rx)    :    ORIGIN = 0x08000000            , LENGTH = 1024K /* K = kilobytes) */
    SRAM(rwx)    :    ORIGIN = 0x20000000            , LENGTH = 128K  /* for simplification the SRAM area is combined */
    /* SRAM1(rwx)   :    ORIGIN = 0x20000000            , LENGTH = 116K */
    /* SRAM2(rwx)   :    ORIGIN = 0x20000000 + 116K - 4 , LENGTH = 16K  */
}

SECTION
{
    .text
	{
	    *(.irs_vector) /* take all with '*' */
	    *(.text)
		*(.rodata)
		__END_OF_TEXT__ = .; /* stores the updated location counter value in to the symbol '__END_OF_TEXT__' */
	} >FLASH
	
	.data
	{
	    __START_OF_DATA__ = .;
	    *(.data)
		__END_OF_DATA__ = .;
	} >SRAM AT> FLASH /* absolut addreses are inside SRAM */
	
	.bss
	{
	    *(.bss)
	} >SRAM
}