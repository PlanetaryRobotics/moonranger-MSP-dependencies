/****************************************************************
 *
 * @file      checksum.c
 *
 * @brief     source file for MSP crc functions
 *
 * @version   1.0
 * @date      11/4/2021
 *
 * @authors   Michael Lang
 * @author    Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/
#include "checksum.h"

#include "crc.h"

/**
 * @brief Sets the inital values needed for CRC16-CCITT. Should be called once
 * at the very beginning of main. Can also be called whenever the CRC needs to
 * be reset. The CRC engine uses a polynomial of 0x1021 in the normal
 * representation with an initial value that is user defined. 0xFFFF
 * is choosen as the starting value. For more information refer to TI
 * publication SLAU367P section 15. Avoid section 16 as that module is not
 * present on the FR5969
 *
 * @note Calling this function erases previous results
 */
void Setupcrc()
{
    //CRC_BASE is the starting memory mapped address for the CRC module.
    CRC_setSeed(CRC_BASE, 0xFFFF);
    return;
}

/**
 * @brief Adds 8 bits of data to the crc calculation
 *
 * @param data The 8 bit input data to the crc engine. The reverse
 * representation is used since the computers are little endian
 * @note The result is computed immediately without delay
 */
void Add_crc(uint8_t data)
{
    CRC_set8BitDataReversed(CRC_BASE, data);
    return;
}

/**
 * @brief Returns the current result in the crc register
 *
 * @note Calling this function doesn't reset the register contents
 */
uint16_t Get_crc()
{
    return CRC_getResult(CRC_BASE);
}

/**
 * @brief Compares the result in the crc registers and received crc
 *
 * @param packet_crc The crc of the packet
 * 
 * @note the crc results are cleared before the call returns
 *
 * @return uint8_t 1 if crc is the same 0 if different
 */
inline uint8_t Check_crc(uint16_t packet_crc)
{
    if (packet_crc == CRC_getResult(CRC_BASE))
    {
        Setupcrc();
        return 1;
    }
    Setupcrc();
    return 0;
}
