#include "ft_printf.h"

int	main(void)
{
	int	len;
	int	x;

	// Test %c
	len = ft_printf("Char: %c\n", 'A');
	ft_printf("Length: %d\n", len);
	// Test %s
	len = ft_printf("String: %s\n", "Hello World");
	ft_printf("Length: %d\n", len);
	// Test %p
	x = 42;
	len = ft_printf("Pointer: %p\n", &x);
	ft_printf("Length: %d\n", len);
	// Test %d and %i
	len = ft_printf("Int: %d, %i\n", 123, -456);
	ft_printf("Length: %d\n", len);
	// Test %u
	len = ft_printf("Unsigned: %u\n", 4294967295U);
	ft_printf("Length: %d\n", len);
	// Test %x and %X
	len = ft_printf("Hex: %x, %X\n", 255, 255);
	ft_printf("Length: %d\n", len);
	// Test %%
	len = ft_printf("Percent: %%\n");
	ft_printf("Length: %d\n", len);
	return (0);
}
