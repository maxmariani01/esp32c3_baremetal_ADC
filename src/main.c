#include <stdint.h>
#include "WDT_FEED.h"

#define BIT(n) (1U << (n))                    // Máscara de un bit
#define REG32(addr) (*(volatile uint32_t *)(addr)) // Acceso directo a registro de 32 bits
#define LOOP_DELAY      5000U
 



static void short_delay(void) {
    // Busy-wait simple (no timers configurados)
    for (volatile uint32_t i = 0; i < LOOP_DELAY; ++i) {
        __asm__ volatile("nop");
    }
}




int main(void) {
    disable_timg_wdt(TIMG0_BASE);
    disable_timg_wdt(TIMG1_BASE);
    disable_rtc_wdts();
}
 