//======================================================================
/**
 *  @file
 *  functions_can.h
 *
 *  @section functions_can.h_general General file information
 *
 *  @brief
 *  
 *
 *  @author Marc Benetó
 *  @date   14.09.2012
 *  
 *  
 *  @section functions_can.h_copyright Copyright
 *  
 *  Copyright 2012 Robotnik Automation, SLL
 *  
 *  The distribution of this code and excerpts thereof, neither in 
 *  source nor in any binary form, is prohibited, except you have our 
 *  explicit and written permission to do so.
 *
 */
//======================================================================


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------



//------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------
// Constants definitions  - CAN message types
//------------------------------------------------------------------------
#define MSGTYPE_STANDARD 0x00   // Standard Data frame (11-bit ID)
#define MSGTYPE_RTR      0x01   // 1, if Remote Request frame
#define MSGTYPE_EXTENDED 0x02   // 1, if Extended Data frame (CAN 2.0B, 29-bit ID)
#define MSGTYPE_STATUS   0x80   // 1, if Status information

//------------------------------------------------------------------------
// Error codes (bit code)
// Represent the PCAN error and status codes
//------------------------------------------------------------------------
#define CAN_ERR_OK            0x00000  // No error
#define CAN_ERR_XMTFULL       0x00001  // Transmit buffer in CAN controller is full
#define CAN_ERR_OVERRUN       0x00002  // CAN controller was read too late
#define CAN_ERR_BUSLIGHT      0x00004  // Bus error: an error counter reached the 'light' limit
#define CAN_ERR_BUSHEAVY      0x00008  // Bus error: an error counter reached the 'heavy' limit
#define CAN_ERR_BUSOFF        0x00010  // Bus error: the CAN controller is in bus-off state
#define CAN_ERR_ANYBUSERR     (CAN_ERR_BUSLIGHT | CAN_ERR_BUSHEAVY | CAN_ERR_BUSOFF) // Mask for all bus errors
#define CAN_ERR_QRCVEMPTY     0x00020  // Receive queue is empty
#define CAN_ERR_QOVERRUN      0x00040  // Receive queue was read too late
#define CAN_ERR_QXMTFULL      0x00080  // Transmit queue is full
#define CAN_ERR_REGTEST       0x00100  // Test of the CAN controller hardware registers failed (no hardware found)
#define CAN_ERR_NODRIVER      0x00200  // Driver not loaded
#define CAN_ERR_HWINUSE       0x00400  // Hardware already in use by a Net
#define CAN_ERR_NETINUSE      0x00800  // A Client is already connected to the Net
#define CAN_ERR_ILLHW         0x01400  // Hardware handle is invalid
#define CAN_ERR_ILLNET        0x01800  // Net handle is invalid
#define CAN_ERR_ILLCLIENT     0x01C00  // Client handle is invalid
#define CAN_ERR_ILLHANDLE     (CAN_ERR_ILLHW | CAN_ERR_ILLNET | CAN_ERR_ILLCLIENT)  // Mask for all handle errors
#define CAN_ERR_RESOURCE      0x02000  // Resource (FIFO, Client, timeout) cannot be created
#define CAN_ERR_ILLPARAMTYPE  0x04000  // Invalid parameter
#define CAN_ERR_ILLPARAMVAL   0x08000  // Invalid parameter value
#define CAN_ERR_UNKNOWN       0x10000  // Unknow error
// All further error conditions <> 0 please ask PEAK when required.......internal driver failure ........

//------------------------------------------------------------------------
// Typedefs, enums, structs
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------


//------------------------------------------------------------------------
// Function declaration
//------------------------------------------------------------------------

// CAN bus management functions
bool CAN_connect( const char *dev );
void CAN_disconnect( void );

// Goto/grasp commands
void homing( void );
int move( float width, float speed );
int grasp( float objWidth, float speed );
int release( float width, float speed );
//int stop( void );
//int ack_fault( void );

// Set functions
void setAcceleration( float acc );
void setGraspingForceLimit( float force );

// Get functions
float getOpening( void );
float getGraspingForceLimit( void );
float getAcceleration( void );
//const char * systemState( void );
//int graspingState( void );


#ifdef __cplusplus
}
#endif

#endif /* FUNCTIONS_H_ */
