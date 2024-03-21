/*!
 * @file: lib-utils-fifo.h
 * @date: 2024-03-21
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of FIFO macro.
 */
#ifndef LIB_UTILS_FIFO_H__
#define LIB_UTILS_FIFO_H__

/*!
 * @brief Declare and initialize FIFO
 * @param name  Name of struct variable.
 * @param type  Type of element in FIFO.
 * @param nb_element    Number of element in FIFO. 
 */
#define DECL_AND_INIT_FIFO(name, type, nb_element) \
    struct \
    { \
        volatile uint32_t ptr_in; \
        volatile uint32_t ptr_out; \
        uint32_t size; \
        volatile type data[nb_element]; \
    } name = \
        { \
            .ptr_in = 0, \
            .ptr_out = 0, \
            .size = nb_element, \
        }

/*!
 * @brief Declare FIFO
 * @param name  Name of struct variable.
 * @param type  Type of element in FIFO.
 * @param nb_element    Number of element in FIFO. 
 */
#define DECL_FIFO(name, type, nb_element) \
    struct \
    { \
        volatile uint32_t ptr_in; \
        volatile uint32_t ptr_out; \
        uint32_t size; \
        volatile type data[nb_element]; \
    } name

/*!
 * @brief Initialize FIFO.
 * @param f  FIFO to initialize. 
 */
#define INIT_FIFO( f ) { \
        f->ptr_in = 0; \
        f->ptr_out = 0; \
        f->size = sizeof(f->data) / sizeof(f->data[0]); \
    }

/*!
 * @brief Empty the FIFO.
 * @param f  FIFO to empty. 
 */
#define EMPTY_FIFO( f ) { \
        f->ptr_in = 0; \
        f->ptr_out = 0; \
    }

/*!
 * @brief Check if FIFO is empty.
 * @param f Pointer on FIFO to check if it's empty. 
 */
#define IS_FIFO_EMPTY( f ) (f->ptr_in == f->ptr_out)

/*!
 * @brief Check if FIFO is full.
 * @param f Pointer on FIFO to check if it's full. 
 */
#define IS_FIFO_FULL( f ) (f->ptr_out == ( ( f->ptr_in + 1 ) % f->size ) )

/*!
 * @brief Increment input pointer of FIFO.
 * @param f Pointer on FIFO to increment input pointer.
 */
#define INC_PTR_IN( f ) f->ptr_in = ( ( f->ptr_in + 1 ) % f->size )

/*!
 * @brief Increment output pointer of FIFO.
 * @param f Pointer on FIFO to increment output pointer.
 */
#define INC_PTR_OUT( f ) f->ptr_out = ( ( f->ptr_out + 1 ) % f->size )

#endif /* LIB_UTILS_FIFO_H__ */