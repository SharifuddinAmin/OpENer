/*******************************************************************************
 * Copyright (c) 2016, Rockwell Automation, Inc.
 * All rights reserved.
 *
 ******************************************************************************/

#ifndef SRC_CIP_CIPEPATH_H_
#define SRC_CIP_CIPEPATH_H_

#include <stdbool.h>

#include "ciptypes.h"
#include "cipelectronickey.h"

#define SEGMENT_TYPE_PORT_SEGMENT 0x00 /**< Message value of the Port segment */
#define SEGMENT_TYPE_LOGICAL_SEGMENT 0x20 /**< Message value of the Logical segment */
#define SEGMENT_TYPE_NETWORK_SEGMENT 0x40 /**< Message value of the Network segment */
#define SEGMENT_TYPE_SYMBOLIC_SEGMENT 0x60 /**< Message value of the Symbolic segment */
#define SEGMENT_TYPE_DATA_SEGMENT 0x80 /**< Message value of the Data segment */
#define SEGMENT_TYPE_DATA_TYPE_CONSTRUCTED 0xA0 /**< Message value of the Data type constructed */
#define SEGMENT_TYPE_DATA_TYPE_ELEMENTARTY 0xC0 /**< Message value of the Data type elementary */
#define SEGMENT_TYPE_SEGMENT_RESERVED 0xE0 /**< Reserved value */

#define LOGICAL_SEGMENT_TYPE_CLASS_ID 0x00 /**< Message value of the logical segment/logical type Class ID */
#define LOGICAL_SEGMENT_TYPE_INSTANCE_ID 0x04 /**< Message value of the logical segment/logical type Instance ID */
#define LOGICAL_SEGMENT_TYPE_MEMBER_ID 0x08 /**< Message value of the logical segment/logical type Member ID */
#define LOGICAL_SEGMENT_TYPE_CONNECTION_POINT 0x0C /**< Message value of the logical segment/logical type Connection Point */
#define LOGICAL_SEGMENT_TYPE_ATTRIBUTE_ID 0x10 /**< Message value of the logical segment/logical type Attribute ID */
#define LOGICAL_SEGMENT_TYPE_SPECIAL 0x14 /**< Message value of the logical segment/logical type Special */
#define LOGICAL_SEGMENT_TYPE_SERVICE_ID 0x18 /**< Message value of the logical segment/logical type Service ID */
#define LOGICAL_SEGMENT_TYPE_EXTENDED_LOGICAL 0x1C /**< Message value of the logical segment/logical type Extended Logical */

#define LOGICAL_SEGMENT_FORMAT_EIGHT_BIT 0x00 /**< Message value indicating an 8 bit value */
#define LOGICAL_SEGMENT_FORMAT_SIXTEEN_BIT 0x01 /**< Message value indicating an 16 bit value */
#define LOGICAL_SEGMENT_FORMAT_THIRTY_TWO_BIT 0x02 /**< Message value indicating an 32 bit value */

#define LOGICAL_SEGMENT_EXTENDED_TYPE_RESERVED 0x00 /**< Message value indicating an reserved/unused Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_ARRAY_INDEX 0x01 /**< Message value indicating the Array Index Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_INDIRECT_ARRAY_INDEX 0x02 /**< Message value indicating the Indirect Array Index Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_BIT_INDEX 0x03 /**< Message value indicating the Bit Index Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_INDIRECT_BIT_INDEX 0x04 /**< Message value indicating the Indirect Bit Index Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_STRUCTURE_MEMBER_NUMBER 0x05 /**< Message value indicating the Structured Member Number Extended Logical Segment type */
#define LOGICAL_SEGMENT_EXTENDED_TYPE_STRUCTURE_MEMBER_HANDLE 0x06 /**< Message value indicating the Structured Member Handler Extended Logical Segment type */

#define LOGICAL_SEGMENT_SPECIAL_TYPE_FORMAT_ELECTRONIC_KEY 0x00 /**< Message value indicating an electronic key */

#define NETWORK_SEGMENT_SUBTYPE_SCHEDULE 0x01 /**< Message value indicating a network segment schedule message */
#define NETWORK_SEGMENT_SUBTYPE_FIXED_TAG 0x02 /**< Message value indicating a network segment fixed tag message */
#define NETWORK_SEGMENT_SUBTYPE_PRODUCTION_INHIBIT_TIME_IN_MILLISECONDS 0x03 /**< Message value indicating a network segment PIT in milliseconds message */
#define NETWORK_SEGMENT_SUBTYPE_SAFETY 0x04 /**< Message value indicating a network segment safety message */
#define NETWORK_SEGMENT_SUBTYPE_PRODUCTION_INHIBIT_TIME_IN_MICROSECONDS 0x10 /**< Message value indicating a network segment PIT in microseconds message */
#define NETWORK_SEGMENT_SUBTYPE_EXTENDED_NETWORK 0x1F /**< Message indicating a network message extended network message */

/** @brief All types of network segment types for the use in all code
 *
 *  Enum constants for the different network segment subtypes to decouple code from the actual needed message values
 */
typedef enum network_segment_subtype {
  kNetworkSegmentSubtypeReserved, /**< Reserverd */
  kNetworkSegmentSubtypeScheduleSegment, /**< Schedule segment */
  kNetworkSegmentSubtypeFixedTagSegment, /**< Fixed tag segment */
  kNetworkSegmentSubtypeProductionInhibitTimeInMilliseconds, /**< Production Inhibit Time in milliseconds segment */
  kNetworkSegmentSubtypeSafetySegment, /**< Safety segment */
  kNetworkSegmentSubtypeProductionInhibitTimeInMicroseconds, /**< Production Inhibit Time in microseconds segment */
  kNetworkSegmentSubtypeExtendedNetworkSegment /**< Extended network segment */
} NetworkSegmentSubtype;

/** @brief Electronic key formats
 *
 */
typedef enum electronic_key_segment_format {
  kElectronicKeySegmentFormatReserved, /**< Reserved */
  kElectronicKeySegmentFormatKeyFormat4 /**< Electronic key format 4 key */
} ElectronicKeySegmentFormat;

/** @brief Data segment sub types
 *
 */
typedef enum data_segment_subtype {
  kDataSegmentSubtypeReserved, /**< Reserved */
  kDataSegmentSubtypeSimpleData, /**< Simple Data segment */
  kDataSegmentSubtypeANSIExtendedSymbol /**< ANSI extended symbol segment */
} DataSegmentSubtype;

/** @brief Symbolic segment formats
 *
 */
typedef enum symbolic_segment_format {
  kSymbolicSegmentFormatASCII, /**< ASCII format */
  kSymbolicSegmentFormatExtendedString /**< Extended String format */
} SymbolicSegmentFormat;

/** @brief Extended symbolic symbol formats
 *
 */
typedef enum symbolic_segment_extended_format {
  kSymbolicSegmentExtendedFormatDoubleByteChars, /**< Double byte character encoding */
  kSymbolicSegmentExtendedFormatTripleByteChars, /**< Triple byte character encoding */
  kSymbolicSegmentExtendedFormatNumericSymbolUSINT, /**< Numeric USINT symbol */
  kSymbolicSegmentExtendedFormatNumericSymbolUINT, /**< Numeric UINT symbol */
  kSymbolicSegmentExtendedFormatNumericSymbolUDINT, /**< Numeric UDINT symbol */
  kSymbolicSegmentExtendedFormatReserved /**< Reserved */
} SymbolicSegmentExtendedFormat;

/** @brief Gets the basic segment type of a CIP EPath
 *
 * @param cip_path The start of the EPath message
 * @return The basic segment type
 */
SegmentType GetPathSegmentType(const unsigned char *const cip_path);

/** @brief Sets the basic segment type of an CIP EPath to be sent
 *
 * @param segment_type The segment type
 * @param cip_path A message buffer - Will be written on!
 */
void SetPathSegmentType(SegmentType segment_type,unsigned char *const cip_path);

/*********************************************************
* Port Segment functions
*********************************************************/

/** @brief Only to be used on Port Segments. Returns if the Port Segment has the extended link address size bit set
 *
 * @param cip_path The start of the EPath message
 * @return True if extended link addres size bit set, false otherwise
 */
bool GetPathPortSegmentExtendedLinkAddressSizeBit(
  const unsigned char *const cip_path);

/** @brief Only to be used on Port Segments. Returns the Port Identifier
 *
 * @param cip_path The start of the EPath message
 * @return The Port Identifier
 */
unsigned int GetPathPortSegmentPortIdentifier(
  const unsigned char *const cip_path);

/** @brief Sets the Port Identifier form an Port Segment EPath to be sent.
 *
 * @param port_identifier The port identifier
 * @param cip_path A message buffer - Will be written on!
 */
void SetPathPortSegmentPortIdentifier(const unsigned int port_identifier,
                                      unsigned char *const cip_path);

/** @brief Only to be used on Port Segments. Gets the Link Address Size
 *
 * @param cip_path The start of the EPath message
 * @return The Link Address Size
 */
unsigned int GetPathPortSegmentLinkAddressSize(
  const unsigned char *const cip_path);

/** @brief Only to be used on Port Segments with Extended Port Number. Gets the Extended Port Number
 *
 * @param cip_path The start of the EPath message
 * @return The Link Address Size
 */
unsigned int GetPathPortSegmentExtendedPortNumber(
  const unsigned char *const cip_path);

/** @brief Sets the Extended Port Identifier in a EPath Port Segment message
 *
 * @param extended_port_identifier The extended port identifier to be encoded into the message
 * @param cip_path The start for the EPatch message
 */
void SetPathPortSegmentExtendedPortIdentifier(
  const unsigned int extended_port_identifier, unsigned char *const cip_path);

/** @brief Gets the Logical Type of an EPath Logical Segment message
 *
 * @param cip_path The start of the EPath message
 * @return The logical type of the logical segment
 */
LogicalSegmentLogicalType GetPathLogicalSegmentLogicalType(
  const unsigned char *const cip_path);

/** @brief Gets the Logical Format of a Logical Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The logical format of the logical format
 */
LogicalSegmentLogicalFormat GetPathLogicalSegmentLogicalFormat(
  const unsigned char *const cip_path);

/** @brief  Gets the Extended Logical Type of a Logical Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The extended logical type of the logical segment
 */
LogicalSegmentExtendedLogicalType GetPathLogicalSegmentExtendedLogicalType(
  const unsigned char *const cip_path);

/** @brief Gets the Special Type Logical Type of a Logical Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The Special Type Logical Format subtype of a Logical Segment EPath message
 */
LogicalSegmentSpecialTypeLogicalFormat
GetPathLogicalSegmentSpecialTypeLogicalType(const unsigned char *const cip_path);

/** @brief Gets the Electronic Key format of a Logical Segment Special Type EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The Electronic Key Format used in the EPath
 */
ElectronicKeySegmentFormat GetPathLogicalSegmentElectronicKeyFormat(
  const unsigned char *const cip_path);

/** @brief Gets the data for an Electronic Key of format 4 from the EPath message
 *
 * @param cip_path The start of the EPath message
 * @param Writes the data on the user provided data electronic key struct
 */
void GetPathLogicalSegmentElectronicKeyFormat4(
  const unsigned char *const cip_path, ElectronicKeyFormat4 *key);

/** @brief Gets the Network Segment Subtype of a EPatch Network Segement EPath message
 *
 * @param cip_path The start of the EPath message
 * @return Network Segment subtype
 */
NetworkSegmentSubtype GetPathNetworkSegmentSubtype(
  const unsigned char *const cip_path);

/** @brief Gets the Production Inhibit Time in Milliseconds
 *
 * @param cip_path The start of the EPath message
 * @return The production Inhibit Time in Milliseconds
 */
CipUsint GetPathNetworkSegmentProductionInhibitTimeInMilliseconds(
  const unsigned char *const cip_path);

/** @brief Gets the Production Inhibit Time in Microseconds
 *
 * @param cip_path The start of the EPath message
 * @return The production Inhibit Time in Microseconds
 */
CipUdint GetPathNetworkSegmentProductionInhibitTimeInMicroseconds(
  const unsigned char *const cip_path);

/** @brief Gets the Data Segment subtype of a Data Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The Data Segment subtype
 */
DataSegmentSubtype GetPathDataSegmentSubtype(const unsigned char *const cip_path);

/** @brief Gets the data word length of a Simple Data segment
 *
 * @param cip_path The start of the EPath message
 * @return The length in words of the Simple Data segment
 */
CipUsint GetPathDataSegmentSimpleDataWordLength(
  const unsigned char *const cip_path);

/** @brief Gets the Symbolic Segment Format of the Symbolic Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The Symbolic Segment Format
 */
SymbolicSegmentFormat GetPathSymbolicSegmentFormat(
  const unsigned char *const cip_path);

/** @brief Gets the Numeric subtype of a Symbolic Segment Extended Format EPath message
 *
 * @param cip_path The start of the EPath message
 * @return The Numeric Extended Format subtype
 */
SymbolicSegmentExtendedFormat GetPathSymbolicSegmentNumericType(
  const unsigned char *const cip_path);

/** @brief Gets the Extended Format subtype of a Symbolic Segment EPath message
 *
 * @param cip_path The start of the EPath message
 * @return Symbolic Segment Extended Format
 */
SymbolicSegmentExtendedFormat GetPathSymbolicSegmentExtendedFormat(
  const unsigned char *const cip_path);

#endif /* SRC_CIP_CIPEPATH_H_ */
