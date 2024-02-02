/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 38.0.2 Fri Jan 26 15:23:11 2024.
 */

#ifndef TCS_H
#define TCS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define TCS_GEAR_FRAME_ID (0x654u)
#define TCS_CLUTCH_POSITION_FRAME_ID (0x659u)
#define TCS_UPDATE_CLUTCH_POSITION_FRAME_ID (0x65au)
#define TCS_ANALOG_INPUT_FRAME_ID (0x65bu)
#define TCS_UPDATE_CLUTCH_SETTINGS_FRAME_ID (0x658u)
#define TCS_UPDATE_SHIFT_SETTINGS_FRAME_ID (0x656u)
#define TCS_CLUTCH_SETTINGS_FRAME_ID (0x657u)
#define TCS_SHIFT_SETTINGS_FRAME_ID (0x655u)

/* Frame lengths in bytes. */
#define TCS_GEAR_LENGTH (2u)
#define TCS_CLUTCH_POSITION_LENGTH (2u)
#define TCS_UPDATE_CLUTCH_POSITION_LENGTH (2u)
#define TCS_ANALOG_INPUT_LENGTH (8u)
#define TCS_UPDATE_CLUTCH_SETTINGS_LENGTH (7u)
#define TCS_UPDATE_SHIFT_SETTINGS_LENGTH (8u)
#define TCS_CLUTCH_SETTINGS_LENGTH (7u)
#define TCS_SHIFT_SETTINGS_LENGTH (8u)

/* Extended or standard frame types. */
#define TCS_GEAR_IS_EXTENDED (0)
#define TCS_CLUTCH_POSITION_IS_EXTENDED (0)
#define TCS_UPDATE_CLUTCH_POSITION_IS_EXTENDED (0)
#define TCS_ANALOG_INPUT_IS_EXTENDED (0)
#define TCS_UPDATE_CLUTCH_SETTINGS_IS_EXTENDED (0)
#define TCS_UPDATE_SHIFT_SETTINGS_IS_EXTENDED (0)
#define TCS_CLUTCH_SETTINGS_IS_EXTENDED (0)
#define TCS_SHIFT_SETTINGS_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/**
 * Signals in message gear.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_gear_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t gear;
};

/**
 * Signals in message clutch_position.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_clutch_position_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t position;
};

/**
 * Signals in message update_clutch_position.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_update_clutch_position_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t position;
};

/**
 * Signals in message analog_input.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_analog_input_t {
    /**
     * Dummy signal in empty message.
     */
    uint8_t dummy;
};

/**
 * Signals in message update_clutch_settings.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_update_clutch_settings_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t start;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t end;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t friction;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    int8_t auto_launch;
};

/**
 * Signals in message update_shift_settings.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_update_shift_settings_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t up_delay;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t down_delay;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t output;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t timeout;
};

/**
 * Signals in message clutch_settings.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_clutch_settings_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t start;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t end;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t friction;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    int8_t auto_launch;
};

/**
 * Signals in message shift_settings.
 *
 * All signal values are as on the CAN bus.
 */
struct tcs_shift_settings_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t up_delay;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t down_delay;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t output;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t timeout;
};

/**
 * Pack message gear.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_gear_pack(
    uint8_t *dst_p,
    const struct tcs_gear_t *src_p,
    size_t size);

/**
 * Unpack message gear.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_gear_unpack(
    struct tcs_gear_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_gear_gear_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_gear_gear_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_gear_gear_is_in_range(uint16_t value);

/**
 * Pack message clutch_position.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_clutch_position_pack(
    uint8_t *dst_p,
    const struct tcs_clutch_position_t *src_p,
    size_t size);

/**
 * Unpack message clutch_position.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_clutch_position_unpack(
    struct tcs_clutch_position_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_clutch_position_position_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_clutch_position_position_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_clutch_position_position_is_in_range(uint16_t value);

/**
 * Pack message update_clutch_position.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_update_clutch_position_pack(
    uint8_t *dst_p,
    const struct tcs_update_clutch_position_t *src_p,
    size_t size);

/**
 * Unpack message update_clutch_position.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_update_clutch_position_unpack(
    struct tcs_update_clutch_position_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_clutch_position_position_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_clutch_position_position_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_clutch_position_position_is_in_range(uint16_t value);

/**
 * Pack message analog_input.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_analog_input_pack(
    uint8_t *dst_p,
    const struct tcs_analog_input_t *src_p,
    size_t size);

/**
 * Unpack message analog_input.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_analog_input_unpack(
    struct tcs_analog_input_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Pack message update_clutch_settings.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_update_clutch_settings_pack(
    uint8_t *dst_p,
    const struct tcs_update_clutch_settings_t *src_p,
    size_t size);

/**
 * Unpack message update_clutch_settings.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_update_clutch_settings_unpack(
    struct tcs_update_clutch_settings_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_clutch_settings_start_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_clutch_settings_start_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_clutch_settings_start_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_clutch_settings_end_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_clutch_settings_end_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_clutch_settings_end_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_clutch_settings_friction_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_clutch_settings_friction_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_clutch_settings_friction_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int8_t tcs_update_clutch_settings_auto_launch_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_clutch_settings_auto_launch_decode(int8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_clutch_settings_auto_launch_is_in_range(int8_t value);

/**
 * Pack message update_shift_settings.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_update_shift_settings_pack(
    uint8_t *dst_p,
    const struct tcs_update_shift_settings_t *src_p,
    size_t size);

/**
 * Unpack message update_shift_settings.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_update_shift_settings_unpack(
    struct tcs_update_shift_settings_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_shift_settings_up_delay_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_shift_settings_up_delay_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_shift_settings_up_delay_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_shift_settings_down_delay_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_shift_settings_down_delay_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_shift_settings_down_delay_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_shift_settings_output_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_shift_settings_output_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_shift_settings_output_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_update_shift_settings_timeout_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_update_shift_settings_timeout_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_update_shift_settings_timeout_is_in_range(uint16_t value);

/**
 * Pack message clutch_settings.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_clutch_settings_pack(
    uint8_t *dst_p,
    const struct tcs_clutch_settings_t *src_p,
    size_t size);

/**
 * Unpack message clutch_settings.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_clutch_settings_unpack(
    struct tcs_clutch_settings_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_clutch_settings_start_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_clutch_settings_start_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_clutch_settings_start_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_clutch_settings_end_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_clutch_settings_end_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_clutch_settings_end_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_clutch_settings_friction_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_clutch_settings_friction_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_clutch_settings_friction_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int8_t tcs_clutch_settings_auto_launch_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_clutch_settings_auto_launch_decode(int8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_clutch_settings_auto_launch_is_in_range(int8_t value);

/**
 * Pack message shift_settings.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int tcs_shift_settings_pack(
    uint8_t *dst_p,
    const struct tcs_shift_settings_t *src_p,
    size_t size);

/**
 * Unpack message shift_settings.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int tcs_shift_settings_unpack(
    struct tcs_shift_settings_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_shift_settings_up_delay_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_shift_settings_up_delay_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_shift_settings_up_delay_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_shift_settings_down_delay_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_shift_settings_down_delay_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_shift_settings_down_delay_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_shift_settings_output_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_shift_settings_output_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_shift_settings_output_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t tcs_shift_settings_timeout_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double tcs_shift_settings_timeout_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool tcs_shift_settings_timeout_is_in_range(uint16_t value);


#ifdef __cplusplus
}
#endif

#endif