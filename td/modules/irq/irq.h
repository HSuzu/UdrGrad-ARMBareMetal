#ifndef IRQ_H
#define IRQ_H

#include <stm32l475xx.h>
#include <stm32l4xx.h>
#include <stdint.h>


#define MAKE_DEFAULT_HANDLER(irq_name)                      \
    void __attribute__((weak)) irq_name() {  \
        __disable_irq();                                    \
        while(1);                                           \
    }

#endif // IRQ_H
