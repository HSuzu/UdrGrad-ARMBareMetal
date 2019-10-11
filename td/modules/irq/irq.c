MAKE_DEFAULT_HANDLER(WWDG);
MAKE_DEFAULT_HANDLER(PVD_PVM);
MAKE_DEFAULT_HANDLER(TAMP_STAMP);
MAKE_DEFAULT_HANDLER(RTC_WKUP);
MAKE_DEFAULT_HANDLER(EXTI0);
MAKE_DEFAULT_HANDLER(EXTI1);
MAKE_DEFAULT_HANDLER(EXTI2);
MAKE_DEFAULT_HANDLER(EXTI3);
MAKE_DEFAULT_HANDLER(EXTI4);
MAKE_DEFAULT_HANDLER(DMA1_CH1);
MAKE_DEFAULT_HANDLER(DMA1_CH2);
MAKE_DEFAULT_HANDLER(DMA1_CH3);
MAKE_DEFAULT_HANDLER(DMA1_CH4);
MAKE_DEFAULT_HANDLER(DMA1_CH5);
MAKE_DEFAULT_HANDLER(DMA1_CH6);
MAKE_DEFAULT_HANDLER(DMA1_CH7);
MAKE_DEFAULT_HANDLER(ADC1_2);
MAKE_DEFAULT_HANDLER(CAN1_TX);
MAKE_DEFAULT_HANDLER(CAN1_RX0);
MAKE_DEFAULT_HANDLER(CAN1_RX1);
MAKE_DEFAULT_HANDLER(CAN1_SCE);
MAKE_DEFAULT_HANDLER(EXTI9_5);
MAKE_DEFAULT_HANDLER(TIM1_BRK);
MAKE_DEFAULT_HANDLER(TIM1_UP);
MAKE_DEFAULT_HANDLER(TIM1_TRG_COM);
MAKE_DEFAULT_HANDLER(TIM1_CC);
MAKE_DEFAULT_HANDLER(TIM2);
MAKE_DEFAULT_HANDLER(TIM3);
MAKE_DEFAULT_HANDLER(TIM4);
MAKE_DEFAULT_HANDLER(I2C1_EV);
MAKE_DEFAULT_HANDLER(I2C1_ER);
MAKE_DEFAULT_HANDLER(I2C2_EV);
MAKE_DEFAULT_HANDLER(I2C2_ER);
MAKE_DEFAULT_HANDLER(SPI1);
MAKE_DEFAULT_HANDLER(SPI2);
MAKE_DEFAULT_HANDLER(USART1);
MAKE_DEFAULT_HANDLER(USART2);
MAKE_DEFAULT_HANDLER(USART3);
MAKE_DEFAULT_HANDLER(EXTI15_10);
MAKE_DEFAULT_HANDLER(RTC_ALARM);


void *vector_table[] = {
    // Stack and Reset Handler
    &_init_sp,            /* Top of stack */
    _start,             /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,        /* NMI handler */
    HardFault_Handler,  /* Hard Fault handler */
    MemManage_Handler, 
    BusFault_Handler,
    UsageFault_Handler,
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    SVC_Handler,        /* SVC handler */
    0,                  /* Reserved */
    0,                  /* Reserved */
    PendSV_Handler,     /* Pending SVC handler */
    SysTick_Handler,    /* SysTick hanlder */

    // STM32L475 External interrupts
    WWDG_IRQHandler,         /* Watchdog IRQ */
    PVD_PVM_IRQHandler,      /* PVD/PVM1/PVM2/PVM3/PVM4 through EXTI lines 16/35/36/37/38 interrupts */
    TAMP_STAMP_IRQHandler,   /* RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts */
    RTC_WKUP_IRQHandler,     /* RTC Wakeup timer through EXTI line 20 interrupt */
    FLASH_IRQHandler,        /* Flash global interrupt */
    RCC_IRQHandler,          /* RCC global interrupt */
    EXTI0_IRQHandler,        /* EXTI Line0 interrupt */
    EXTI1_IRQHandler,        /* EXTI Line1 interrupt */
    EXTI2_IRQHandler,        /* EXTI Line2 interrupt */
    EXTI3_IRQHandler,        /* EXTI Line3 interrupt */
    EXTI4_IRQHandler,        /* EXTI Line4 interrupt */
    DMA1_CH1_IRQHandler,     /* DMA1 channel 1 interrupt */
    DMA1_CH2_IRQHandler,     /* DMA1 channel 2 interrupt */
    DMA1_CH3_IRQHandler,     /* DMA1 channel 3 interrupt */
    DMA1_CH4_IRQHandler,     /* DMA1 channel 4 interrupt */
    DMA1_CH5_IRQHandler,     /* DMA1 channel 5 interrupt */
    DMA1_CH6_IRQHandler,     /* DMA1 channel 6 interrupt */
    DMA1_CH7_IRQHandler,     /* DMA1 channel 7 interrupt */
    ADC1_2_IRQHandler,       /* ADC1 and ADC2 global interrupt */
    CAN1_TX_IRQHandler,      /* CAN1_TX interrupts */
    CAN1_RX0_IRQHandler,     /* CAN1_RX0 interrupts */
    CAN1_RX1_IRQHandler,     /* CAN1_RX1 interrupt */
    CAN1_SCE_IRQHandler,     /* CAN1_SCE interrupt */
    EXTI9_5_IRQHandler,      /* EXTI Line[9:5] interrupts */
    TIM1_BRK_IRQHandler,     /* TIM1 Break/TIM15 global interrupts */
    TIM1_UP_IRQHandler,      /* TIM1 Update/TIM16 global interrupts */
    TIM1_TRG_COM_IRQHandler, /* TIM1 trigger and commutation/TIM17 interrupts */
    TIM1_CC_IRQHandler,      /* TIM1 capture compare interrupt */
    TIM2_IRQHandler,         /* TIM2 global interrupt */
    TIM3_IRQHandler,         /* TIM3 global interrupt */
    TIM4_IRQHandler,         /* TIM4 global interrupt */
    I2C1_EV_IRQHandler,      /* I2C1 event interrupt */
    I2C1_ER_IRQHandler,      /* I2C1 error interrupt */
    I2C2_EV_IRQHandler,      /* I2C2 event interrupt */
    I2C2_ER_IRQHandler,      /* I2C2 error interrupt */
    SPI1_IRQHandler,         /* SPI1 global interrupt */
    SPI2_IRQHandler,         /* SPI1 global interrupt */
    USART1_IRQHandler,       /* USART1 global interrupt */
    USART2_IRQHandler,       /* USART2 global interrupt */
    USART3_IRQHandler,       /* USART3 global interrupt */
    EXTI15_10_IRQHandler,    /* EXTI Line[15:10] interrupts */
    RTC_ALARM_IRQHandler,    /* RTC alarms through EXTI line 18 interrupts */
}