
#include "ipa_canopen_core/pcan_compat.h"

//#define DEFAULT_NODE "/dev/pcan32"

HANDLE h;

TPCANMsg msg;
//TPCANRdMsg *tpcmsg;
unsigned short crc;
unsigned char header[6]; 
unsigned char data[1];
char can_id = 0x64;
