/**
 * @file Std_codes.h
 * @author Abdullah Elsayed Ahmed
 * @brief Helps with error codes.
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STD_CODES_H_
#define STD_CODES_H_

/** Libraries **/

/** Macro defintions **/

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    STD_NULL_POINTER,  // Accessing null pointer.
    STD_OUT_OF_MEMORY, // No more memory.
    STD_NOT_OK,        // Something went wrong.
    STD_OK,            // Everything executed correctly.
    STD_INVALID        // Invalid code.
}
Std_code;

/** Functions declaration **/

/**
 * @brief Gives string to descript the std_code.
 * 
 * @param status target std code.
 * @param res_msg distinction to store the description (Can be NULL).
 * @return Std_code returns the same code if it's valid code.
 */
Std_code std_code_msg(Std_code status, char *res_msg);

#endif