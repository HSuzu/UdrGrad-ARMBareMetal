#ifndef IRQ_H
#define IRQ_H

#include <cmsis_gcc.h>

MAKE_DEFAULT_HANDLER(irq_name) (                            \
    void __attribute__((weak)) (irq_name)##_IRQHandler {    \
        __disable_irq();                                    \
        while(1);                                           \
    }                                                       \
)

#endif // IRQ_H