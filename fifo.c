#include "fifo.h"

void fifo_init(fifo_t *fifo) {
    fifo->head = 0;
    fifo->tail = 0;
}

bool fifo_put(fifo_t *fifo, uint8_t data) {
    uint16_t next_head = (fifo->head + 1) % FIFO_SIZE;


    if (next_head == fifo->tail) {
        return false;
    }

    fifo->buffer[fifo->head] = data;
    fifo->head = next_head;
    return true;
}

bool fifo_get(fifo_t *fifo, uint8_t *data) {
    if (fifo->head == fifo->tail) {
        return false; 
    }

    *data = fifo->buffer[fifo->tail];
    fifo->tail = (fifo->tail + 1) % FIFO_SIZE; 
    return true;
}


bool fifo_is_empty(fifo_t *fifo) {
    return fifo->head == fifo->tail;
}

bool fifo_is_full(fifo_t *fifo) {
    return ((fifo->head + 1) % FIFO_SIZE) == fifo->tail;
}
