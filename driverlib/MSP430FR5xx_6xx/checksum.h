/****************************************************************
 *
 * @file      checksum.h
 *
 * @brief     header file for MSP crc functions
 *
 * @version   1.0
 * @date      11/4/2021
 *
 * @authors   Michael Lang
 * @author    Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#include <stdint.h>   // for uint8_t and uint16_t

#ifndef CHECKSUM_H_
#define CHECKSUM_H_

void Setupcrc();
void Add_crc(uint8_t);
uint16_t Get_crc();
uint8_t Check_crc();

#endif /* CHECKSUM_H_ */
