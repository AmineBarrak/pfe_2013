
/*déclaration des variables*/
   #define UNSIGNED8       unsigned char
   #define UNSIGNED16      unsigned int
   #define UNSIGNED32      unsigned long int
   #define UNSIGNED64      unsigned long long int
   #define INTEGER8        char
   #define INTEGER16       int
   #define INTEGER32       long int
   #define INTEGER64       long long int
   #define REAL32          float
   #define REAL64          long double

   
   
   /*les défines de la COB-ID values*/

   #define CANOPEN_MAX_ID      0x007F  //Node ID Max
   #define CAN_ID_NMT_SERVICE  0x0000
   #define CAN_ID_SYNC         0x0080
   #define CAN_ID_EMERGENCY    0x0080   // + NODE ID
   #define CAN_ID_TIME_STAMP   0x0100
   #define CAN_ID_TPDO1        0x0180   // + NODE ID
   #define CAN_ID_RPDO1        0x0200   // + NODE ID
   #define CAN_ID_TPDO2        0x0280   // + NODE ID
   #define CAN_ID_RPDO2        0x0300   // + NODE ID
   #define CAN_ID_TPDO3        0x0380   // + NODE ID
   #define CAN_ID_RPDO3        0x0400   // + NODE ID
   #define CAN_ID_TPDO4        0x0480   // + NODE ID
   #define CAN_ID_RPDO4        0x0500   // + NODE ID
   #define CAN_ID_TSDO         0x0580   // + NODE ID
   #define CAN_ID_RSDO         0x0600   // + NODE ID
   #define CAN_ID_HEARTBEAT    0x0700   // + NODE ID
   
   
   
   
   /*déclaration des erreurs qui peuvent être survenue*/
 enum CO_ReturnError{
      CO_ERROR_NO                = 0,
      CO_ERROR_ILLEGAL_ARGUMENT  = -1,
      CO_ERROR_OUT_OF_MEMORY     = -2,
      CO_ERROR_TIMEOUT           = -3,
      CO_ERROR_ILLEGAL_BAUDRATE  = -4,
      CO_ERROR_RX_OVERFLOW       = -5,
      CO_ERROR_RX_PDO_OWERFLOW   = -6,
      CO_ERROR_RX_MSG_DLC     = -7,
      CO_ERROR_RX_PDO_DLC     = -8,
      CO_ERROR_TX_OVERFLOW       = -9,
      CO_ERROR_TX_PDO_WINDOW     = -10,
      CO_ERROR_TX_UNCONFIGURED   = -11,
   };
   
 

   
   
   
   
typedef struct{
	UNSIGNED8 ccs;
	UNSIGNED8 x;
	UNSIGNED8 n;
	UNSIGNED8 e;
	UNSIGNED8 s;
	UNSIGNED8 Mux[3];
	UNSIGNED8 Data[4];

}init_down_SDO_client;

typedef struct{
	UNSIGNED8 scs;
	UNSIGNED8 x;
	UNSIGNED8 Mux[3];
	UNSIGNED8 reserv[4] ;

}init_down_SDO_server;



typedef struct{
	UNSIGNED8 ccs;
	UNSIGNED8 t;
	UNSIGNED8 n;
	UNSIGNED8 c;
	UNSIGNED8 seg_data[7];

}down_SDO_seg_client;



typedef struct{
	UNSIGNED8 scs;
	UNSIGNED8 t;
	UNSIGNED8 x;
	UNSIGNED8 reserved[7];

}down_SDO_seg_server;


typedef struct{
	UNSIGNED8 ccs;
	UNSIGNED8 x;
	UNSIGNED8 Mux[3];
	UNSIGNED8 reserv[4];

}init_up_SDO_client;




typedef struct{
	UNSIGNED8 scs;
	UNSIGNED8 x;
	UNSIGNED8 n;
	UNSIGNED8 e;
	UNSIGNED8 s;
	UNSIGNED8 Mux[3];
	UNSIGNED8 Data[4];

}init_up_SDO_server;



typedef struct{
	UNSIGNED8 ccs;
	UNSIGNED8 t;
	UNSIGNED8 x;
	UNSIGNED8 reserved[7];

}up_SDO_seg_client;



typedef struct{
	UNSIGNED8 scs;
	UNSIGNED8 t;
	UNSIGNED8 n;
	UNSIGNED8 c;
	UNSIGNED8 seg_data[7];

}up_SDO_seg_server;


//déclaration des fonctions
void Abort_SDO_transfert(UNSIGNED8 Mux[3],UNSIGNED32 abort_code);

void SDO_DO_stockage(UNSIGNED8 Mux[3],UNSIGNED8 data[4] );
UNSIGNED32 DO_read(UNSIGNED8 Mux[2]);
UNSIGNED32 Mapping_appel(UNSIGNED8 Mux1[2],UNSIGNED8 Mux2[2]);
void sleep(UNSIGNED32 n);
void timer();

