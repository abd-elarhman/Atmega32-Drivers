/**
 * @file SSD_lcfg.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  this file contains the configuration of the Seven Segment Display
 *         it contains the configuration of the SSDs used in the project
 *         - SSD_POLARITY_CATHOD
 *         - SSD_POLARITY_ANOD
 *         - SSD_CONNECTION_NORMAL
 *         - SSD_CONNECTION_BCD
 * @version 0.1
 * @date 2024-03-31
 * @see SSD_lcfg.h to configure the quantity of SSDs used in the project
 * @copyright Copyright (c) 2024
 * 
 */

/*
* LIB
*/
#include "Std_Types.h"

/*
* Include MCAL layer files
*/
#include "DIO_Interface.h"

/*
* Include own files
*/
#include "SSD_interface.h"
#include "SSD_lcfg.h"
#include "SSD_private.h"


const SSD_CONFIG_t  SSD_arrOfSSD[copy_SSD_Quantity]={
    
    
    /*Example of the configuration of the SSDs used in the project*/
    /*
    {SSD_POLARITY_CATHOD,SSD_CONNECTION_NORMAL,{PA0,PA1,PA2,PA3,PA4,PA5,PA6},PA7},
    {SSD_POLARITY_CATHOD,SSD_CONNECTION_BCD,{PD2,PD3,PD4,PD5},PD6}
    */
    /*or
    .ssd_polarity = SSD_POLARITY_CATHOD,
    .ssd_connection = SSD_CONNECTION_NORMAL,
    .ssd_seg = {PA0,PA1,PA2,PA3,PA4,PA5,PA6},
    .ssd_dot = PA7

    .ssd_polarity = SSD_POLARITY_CATHOD,
    .ssd_connection = SSD_CONNECTION_BCD,
    .ssd_seg = {PD2,PD3,PD4,PD5},
    .ssd_dot = PD6
    */
    {SSD_POLARITY_CATHOD,SSD_CONNECTION_BCD,{PA0,PA1,PA2,PA3}},
    {SSD_POLARITY_CATHOD,SSD_CONNECTION_BCD,{PA4,PA5,PA6,PA7}}

};
