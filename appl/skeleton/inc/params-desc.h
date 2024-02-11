/*!
 * @file: params-desc.h
 * @date: 2023-12-24
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of parameter descriptions.
 */

#ifndef PARAM_DESC_H__
#define PARAM_DESC_H__

#include <stdbool.h>
#include <stdint.h>

/*!
 * @struct params_t
 * @brief Application parameters.
 */
typedef struct params_t
{
    bool display_help;       /*!< Display application help. */
    bool display_version;    /*!< Display version. */
} params_t;

extern struct params_t g_default_parameters;

/*!
 * @struct param_type_t
 * @brief Parameters type enumeration.
 */
typedef enum param_type_t
{
    U8_TYPE         = 0,    /*!< Parameter is uint8_t*/
    I8_TYPE         = 1,    /*!< Parameter is int8_t */
    HEX8_TYPE       = 2,    /*!< Parameter is hex store in uint8_t */
    U16_TYPE        = 3,    /*!< Parameter is uint16_t*/
    I16_TYPE        = 4,    /*!< Parameter is int16_t */
    HEX16_TYPE      = 5,    /*!< Parameter is hex store in uint16_t */
    U32_TYPE        = 6,    /*!< Parameter is uint32_t*/
    I32_TYPE        = 7,    /*!< Parameter is int32_t */
    HEX32_TYPE      = 8,    /*!< Parameter is hex store in uint32_t */
    U64_TYPE        = 9,    /*!< Parameter is uint64_t*/
    I64_TYPE        = 10,   /*!< Parameter is int64_t */
    HEX64_TYPE      = 11,   /*!< Parameter is hex store in uint64_t */
    DFLOAT_TYPE     = 12,   /*!< Parameter is double float */
    STR_TYPE        = 13,   /*!< Parameter is C string. */
    BOOL_TYPE       = 14,   /*!< Parameter is boolean. */
    CHAR_TYPE       = 15,   /*!< Parameter is char. */
    SENTINEL_TYPE   = -1,   /*!< Sentinelle value. */
} param_type_t;

/*!
 * @struct appl_parameter_description_t
 * @brief Application parameters description.
 */
typedef struct parameter_description_t
{
    int8_t  type;      /*!< Parameter type (see param_type_t enum). */
    uint32_t offset;    /*!< Offset in params_t struct (in bytes). */
    uint32_t size;      /*!< Size of parameters (in bytes). */
    char     arg_shortname;     /*!< Short name of parameter option in command
                                     line. */
    char *   arg_longname;      /*!< Long name of parameter option in command
                                     line. */
    char *   help;      /*!< Help string to describe how to use parameter. */
} parameter_description_t;

extern const struct parameter_description_t g_parameters_description[];

extern const char * g_application_description;

/*!
 * @brief Return the number of elements in g_parameters_description table.
 * @return Number of elements in g_parameters_description.
 */
uint32_t get_number_parameters( void );

/*!
 * @brief Display parameters help.
 * @return None.
 */
void display_parameters_help( const char * application_name );

#endif /* PARAM_DESC_H__ */
