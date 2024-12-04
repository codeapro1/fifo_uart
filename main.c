#include "fifo.h"
#include <stdio.h>

fifo_t uart_fifo;

/* В реальных обработчиках прерываний не может быть аргументов. В данном случае 
received_byte имитирует регистр данных (Например, USART->DR), из которого считывается принятый байт.*/

void uart_interrupt_handler(uint8_t received_byte) {
    if (!fifo_put(&uart_fifo, received_byte)) {
        printf("FIFO Overflow\n");
    }
}

int main() {
    fifo_init(&uart_fifo);

    uart_interrupt_handler('A');
    uart_interrupt_handler('B');
    uart_interrupt_handler('C');

    uint8_t data;
    while (!fifo_is_empty(&uart_fifo)) {
        if (fifo_get(&uart_fifo, &data)) {
            printf("%c\n", data);
        }
    }

    return 0;
}