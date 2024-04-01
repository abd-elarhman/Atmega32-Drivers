/**
 * @file Utils_BitMath.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief This file is a header file that contains the bit manipulation macros
 *        and commonly used bit manipulation functions.
 *        The macros and functions in this file are used to manipulate bits and masks in values. 
 *        The functions include getting, setting, clearing, writing, and toggling bits, as well as getting and setting masked values.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UTILS_H_
#define UTILS_H_

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  BIT MANIPULATION MACROS                     */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  commonly used                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*---------------------*/
/* bit manipulation   */
/*---------------------*/
/**
 * @brief Get the value of a specific bit in a given value.
 * @param value The value to extract the bit from.
 * @param bit The index of the bit to get (0-7).
 * @return The value of the specified bit (0 or 1).
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * uint8_t bitValue = get_bit(value, 3); // bitValue = 0
 * @endcode
 */
#define get_bit(value, bit) ((value >> bit) & 1)

/**
 * @brief Check if a specific bit in a given value is set (1).
 * @param value The value to check the bit in.
 * @param bit The index of the bit to check (0-7).
 * @return True if the bit is set, false otherwise.
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * bool isSet = is_bit_set(value, 2); // isSet = true
 * @endcode
 */
#define is_bit_set(value, bit) ((value >> bit) & 1)

/**
 * @brief Check if a specific bit in a given value is clear (0).
 * @param value The value to check the bit in.
 * @param bit The index of the bit to check (0-7).
 * @return True if the bit is clear, false otherwise.
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * bool isClear = is_bit_clear(value, 1); // isClear = false
 * @endcode
 */
#define is_bit_clear(value, bit) (!(value >> bit) & 1)

/**
 * @brief Set a specific bit in a given value to 1.
 * @param value The value to set the bit in.
 * @param bit The index of the bit to set (0-7).
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * set_bit(value, 0); // value = 0b10101011
 * @endcode
 */
#define set_bit(value, bit) (value |= (1 << bit))

/**
 * @brief Clear a specific bit in a given value to 0.
 * @param value The value to clear the bit in.
 * @param bit The index of the bit to clear (0-7).
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * clear_bit(value, 1); // value = 0b10101000
 * @endcode
 */
#define clear_bit(value, bit) (value &= ~(1 << bit))

/**
 * @brief Write a specific bit in a given value to the specified bit value (0 or 1).
 * @param value The value to write the bit in.
 * @param bit The index of the bit to write (0-7).
 * @param bitValue The value to write to the bit (0 or 1).
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * write_bit(value, 2, 1); // value = 0b10101110
 * @endcode
 */
#define write_bit(value,bit,bitValue) (value = ((value & (~(1 << bit))) | (bitValue << bit)) )

/**
 * @brief Toggle a specific bit in a given value.
 * If the bit is 1, it will be set to 0. If the bit is 0, it will be set to 1.
 * @param value The value to toggle the bit in.
 * @param bit The index of the bit to toggle (0-7).
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * toggle_bit(value, 2); // value = 0b10101110
 * @endcode
 */
#define toggle_bit(value, bit) (value ^= (1 << bit))

/*---------------------*/
/* mask manipulation  */
/*---------------------*/

/**
 * @brief Set a specific mask in a given value to a new value.
 * @param value The value to set the mask in.
 * @param mask The mask to set in the value.
 * @param newValue The new value for the mask.
 *
 * Example usage:
 * @code
 * uint8_t value = 0b11110000;
 * uint8_t mask = 0b00001111;
 * set_masked_value(value, mask, 0b00000101); // value = 0b11110101
 * @endcode
 */
#define write_masked_value(value, mask, newValue) (value = (value & ~mask) | (newValue & mask))

/**
 * @brief Get the value of a specific mask in a given value.
 * @param value The value to extract the mask from.
 * @param mask The mask to extract from the value.
 * @return The value of the specified mask.
 *
 * Example usage:
 * @code
 * uint8_t value = 0b10101010;
 * uint8_t mask = 0b00001111;
 * uint8_t maskValue = get_masked_value(value, mask); // maskValue = 0b00001010
 * @endcode
 */ 
#define get_masked_value(value, mask) (value & mask)

/**
 * @brief Concatenate 8 bits into an 8-bit integer.
 * @param bit1 The value of the first bit (0 or 1).
 * @param bit2 The value of the second bit (0 or 1).
 * @param bit3 The value of the third bit (0 or 1).
 * @param bit4 The value of the fourth bit (0 or 1).
 * @param bit5 The value of the fifth bit (0 or 1).
 * @param bit6 The value of the sixth bit (0 or 1).
 * @param bit7 The value of the seventh bit (0 or 1).
 * @param bit8 The value of the eighth bit (0 or 1).
 * @return The 8-bit integer value of the concatenated bits.
 *
 * Example usage:
 * @code
 * uint8_t value = concat_bits(1, 0, 1, 0, 1, 0, 1, 0); // value = 0b10101010
 * @endcode
 */
#define concat_bits(bit1,bit2,bit3,bit4,bit5,bit6,bit7,bit8) (bit1<<7|bit2<<6|bit3<<5|bit4<<4|bit5<<3|bit6<<2|bit7<<1|bit8) /**< Concatenate 8 bits into an 8-bit integer */

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  less commonly used                           */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*---------------------*/
/* nibble manipulation */
/*---------------------*/

/**
 * @brief Swaps the nibbles (4 bits) of a value.
 * 
 * @param value The value to swap the nibbles of.
 * @return The value with swapped nibbles.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = swap_nibbles(value); // result is 0xBA (1011 1010)
 * @endcode
 */
#define swap_nibbles(value) (((value & 0x0F) << 4) | ((value & 0xF0) >> 4))

/**
 * @brief Get the low nibble of a value.
 * @param value The value to extract the low nibble from.
 * @return The low nibble of the value.
 *
 * Example usage:
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t lowNibble = get_low_nibble(value); // lowNibble = 0x0B
 * @endcode
 */
#define get_low_nibble(value) (value & 0x0F)

/**
 * @brief Get the high nibble of a value.
 * @param value The value to extract the high nibble from.
 * @return The high nibble of the value.
 *
 * Example usage:
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t highNibble = get_high_nibble(value); // highNibble = 0x0A
 * @endcode
 */
#define get_high_nibble(value) ((value >> 4) & 0x0F)

/**
 * @brief Set the low nibble of a value to a given nibble.
 * @param value The value to set the low nibble in.
 * @param nibble The nibble to set in the low nibble of the value.
 *
 * Example usage:
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * set_low_nibble(value, 0x0C); // value = 0xAC (1010 1100)
 * @endcode
 */
#define set_low_nibble(value, nibble) (value = (value & 0xF0) | (nibble & 0x0F))

/**
 * @brief Set the high nibble of a value to a given nibble.
 * @param value The value to set the high nibble in.
 * @param nibble The nibble to set in the high nibble of the value.
 *
 * Example usage:
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * set_high_nibble(value, 0x0C); // value = 0xCB (1100 1011)
 * @endcode
 */
#define set_high_nibble(value, nibble) (value = (value & 0x0F) | ((nibble & 0x0F) << 4))

/**
 * @brief Clears the low nibble (4 bits) of a value.
 * 
 * @param value The value to clear the low nibble of.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * clear_low_nibble(value); // value is now 0xA0 (1010 0000)
 * @endcode
 */
#define clear_low_nibble(value) (value &= 0xF0)

/**
 * @brief Clears the high nibble (4 bits) of a value.
 * 
 * @param value The value to clear the high nibble of.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * clear_high_nibble(value); // value is now 0x0B (0000 1011)
 * @endcode
 */
#define clear_high_nibble(value) (value &= 0x0F)

/**
 * @brief Toggles the low nibble (4 bits) of a value.
 * 
 * @param value The value to toggle the low nibble of.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * toggle_low_nibble(value); // value is now 0xA4 (1010 0100)
 * @endcode
 */
#define toggle_low_nibble(value) (value ^= 0x0F)

/**
 * @brief Toggles the high nibble (4 bits) of a value.
 * 
 * @param value The value to toggle the high nibble of.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * toggle_high_nibble(value); // value is now 0x54 (0101 0100)
 * @endcode
 */
#define toggle_high_nibble(value) (value ^= 0xF0)

/**
 * @brief Gets a range of bits from a value.
 * 
 * @param value The value to get the bit range from.
 * @param startBit The starting bit index (0-based) of the range.
 * @param endBit The ending bit index (0-based) of the range.
 * @return The value of the bit range.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = get_bit_range(value, 2, 5); // result is 0x0A (0000 1010)
 * @endcode
 */
#define get_bit_range(value, startBit, endBit) ((value >> startBit) & ((1 << (endBit - startBit + 1)) - 1))

/*----------------*/
/* bit rotation  */
/*----------------*/

/**
 * @brief Sets a range of bits in a value to a new value.
 * 
 * @param value The value to set the bit range in.
 * @param startBit The starting bit index (0-based) of the range.
 * @param endBit The ending bit index (0-based) of the range.
 * @param newValue The new value for the bit range.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * set_bit_range(value, 2, 5, 0x0F); // value is now 0xAF (1010 1111)
 * @endcode
 */
#define set_bit_range(value, startBit, endBit, newValue) (value = (value & ~(((1 << (endBit - startBit + 1)) - 1) << startBit)) | ((newValue & ((1 << (endBit - startBit + 1)) - 1)) << startBit))

/**
 * @brief Clears a range of bits in a value.
 * 
 * @param value The value to clear the bit range in.
 * @param startBit The starting bit index (0-based) of the range.
 * @param endBit The ending bit index (0-based) of the range.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * clear_bit_range(value, 2, 5); // value is now 0xA3 (1010 0011)
 * @endcode
 */
#define clear_bit_range(value, startBit, endBit) (value &= ~(((1 << (endBit - startBit + 1)) - 1) << startBit))

/**
 * @brief Toggles a range of bits in a value.
 * 
 * @param value The value to toggle the bit range in.
 * @param startBit The starting bit index (0-based) of the range.
 * @param endBit The ending bit index (0-based) of the range.
 * @return None.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * toggle_bit_range(value, 2, 5); // value is now 0xA3 (1010 0011)
 * @endcode
 */
#define toggle_bit_range(value, startBit, endBit) (value ^= (((1 << (endBit - startBit + 1)) - 1) << startBit))

/**
 * @brief Rotates the bits of a value to the right by a specified number of positions.
 * 
 * @param value The value to rotate.
 * @param n The number of positions to rotate by.
 * @return The rotated value.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = rotate_right(value, 3); // result is 0xD5 (1101 0101)
 * @endcode
 */
#define rotate_right(value, n) ((value >> n) | (value << (8 - n)))

/**
 * @brief Rotates the bits of a value to the left by a specified number of positions.
 * 
 * @param value The value to rotate.
 * @param n The number of positions to rotate by.
 * @return The rotated value.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = rotate_left(value, 3); // result is 0x6D (0110 1101)
 * @endcode
 */
#define rotate_left(value, n) ((value << n) | (value >> (8 - n)))

/**
 * @brief Reverses the bits of a value.
 * 
 * @param value The value to reverse the bits of.
 * @return The value with reversed bits.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = reverse_bits(value); // result is 0xD5 (1101 0101)
 * @endcode
 */
#define reverse_bits(value) (((value & 0x01) << 7) | ((value & 0x02) << 5) | ((value & 0x04) << 3) | ((value & 0x08) << 1) | ((value & 0x10) >> 1) | ((value & 0x20) >> 3) | ((value & 0x40) >> 5) | ((value & 0x80) >> 7))

/*--------------*/
/* bit counting */
/*--------------*/
/**
 * @brief Counts the number of set bits (1s) in a value.
 * 
 * @param value The value to count the set bits in.
 * @return The number of set bits.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = count_set_bits(value); // result is 5
 * @endcode
 */
#define count_set_bits(value) (((value & 0x01) + ((value >> 1) & 0x01) + ((value >> 2) & 0x01) + ((value >> 3) & 0x01) + ((value >> 4) & 0x01) + ((value >> 5) & 0x01) + ((value >> 6) & 0x01) + ((value >> 7) & 0x01))

/**
 * @brief Counts the number of clear bits (0s) in a value.
 * 
 * @param value The value to count the clear bits in.
 * @return The number of clear bits.
 * 
 * @code
 * uint8_t value = 0xAB; // 1010 1011
 * uint8_t result = count_clear_bits(value); // result is 3
 * @endcode
 */
#define count_clear_bits(value) (8 - count_set_bits(value))





#endif /* UTILS_H_ */
