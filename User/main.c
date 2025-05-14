#include "main.h"
#include "freertos_demo.h"

int main(void)
{
	HAL_Init();
	system_clock_init(RCC_PLL_MUL9);
	delay_init(72);
	u1_init(921600);
	led_init();
	button_init();
	Timer3_Init(500-1,72-1);
	lvgl_demo();

	while (1)
	{
		u1_printf("the program will not run at here\r\n");
	}

	return 0;
}
