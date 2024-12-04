#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>
#include <stdbool.h>

/* Размер буфера */
#define FIFO_SIZE 128

/* Структура для FIFO */
typedef struct {
    uint8_t buffer[FIFO_SIZE]; /* Буфер данных */
    uint16_t head;             /* Указатель на место записи */
    uint16_t tail;             /* Указатель на место чтения */
} fifo_t;

/* Инициализация FIFO */
void fifo_init(fifo_t *fifo);

/* Запись байта в FIFO */
bool fifo_put(fifo_t *fifo, uint8_t data);

/* Чтение байта из FIFO */
bool fifo_get(fifo_t *fifo, uint8_t *data);

/* Проверка, пуст ли FIFO */
bool fifo_is_empty(fifo_t *fifo);

/* Проверка, полный ли FIFO */
bool fifo_is_full(fifo_t *fifo);

#endif
