/*!
 * @file: params-parser.h
 * @date: 2023-12-24
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of parameters parser functions.
 */

#ifndef PARAM_PARSER_H__
#define PARAM_PARSER_H__

#include "params-desc.h"

/*!
 * @brief Parse the parameter passed to main function.
 * @param[in]   argc    Number of parameters including application name.
 * @param[in]   argv    Parameter of application (including application name).
 * @param[out]  params  Pointer on struct param to store application parameters.
 * @return 0 on success otherwise -1
 */
int parse_application_parameters( int argc, \
                                  char ** argv, \
                                  struct params_t *params);

#endif /* PARAM_PARSER_H__ */
