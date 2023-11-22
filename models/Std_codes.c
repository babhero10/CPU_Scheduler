/**
 * @file Std_codes.h
 * @author Abdullah Elsayed Ahmed
 * @brief Functions defintion for Std_codes
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/** Libraries **/
#include <string.h>
#include "Std_codes.h"

/** Functions declaration **/

/**
 * @brief Gives string to descript the std_code.
 * 
 * @param status target std code.
 * @param res_msg distinction to store the description (Can be NULL).
 * @return Std_code returns the same code if it's valid code.
 */
Std_code std_code_msg(Std_code status, char *res_msg)
{
    Std_code ret = status;
    char temp[50];

    switch (status) 
    {
        case STD_NULL_POINTER:
            strcpy(temp, "Access NULL pointer!");
            break;
        case STD_OUT_OF_MEMORY:
            strcpy(temp, "Out of memory!");
            break;
        case STD_NOT_OK:
            strcpy(temp, "Something went wrong!");
            break;
        case STD_OK:
            strcpy(temp, "OK!");
            break;
        default:
            strcpy(temp, "Invalid Code");  
            ret = STD_INVALID;          
    }

    if (res_msg != NULL)
    {
       strcpy(res_msg, temp);  
    }

    return ret;
}