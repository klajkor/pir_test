/**
* PIR sensor driver description
*/
typedef enum pirDriverRetVal_e
{
    pirDriverRetVal_OK = 0,
    pirDriverRetVal_ERROR
} pirDriverRetVal_e;

typedef enum pirDriverPinPIRStatus_e
{
    pirDriverPinPIRStatus_Enabled = 0,
    pirDriverPinPIRStatus_Disabled
} pirDriverPinPIRStatus_e;

typedef enum pirDriverPinActiveState_e
{
    pirDriverPinActiveState_LOW = 0,
    pirDriverPinActiveState_HIGH
} pirDriverPinActiveState_e;

typedef struct
{
    uint32_t pirDriverPin;
    uint8_t pirDriverPinPullUp_Enabled;
    uint8_t pirDriverPinPullDown_Enabled;
    pirDriverPinActiveState_e pirDriverPinActiveState;    
    pirDriverPinPIRStatus_e pirDriverPinPIRStatus;
} pirDriverPinParameters_s;



//pirDriverRetVal_e pir_DriverInit(void);
//pirDriverRetVal_e pir_DriverDeInit(void);
//static pirDriverRetVal_e pir_DriverInitPin(pirDriverPinParameters_s pinParameters_i);
//pirDriverRetVal_e pir_DriverSetDuty(pirDriverPinParameters_s pinParameters_i);
//pirDriverRetVal_e pir_DriverSetFrequency(pirDriverPinParameters_s pinParameters_i);
//pirDriverRetVal_e pir_DriverGetParameters(pirDriverPinList_e pirDriverPin_i);
//pirDriverRetVal_e pir_DriverEnablepir(pirDriverPinParameters_s pinParameters_i);
//pirDriverRetVal_e pir_DriverDisablepir(pirDriverPinParameters_s pinParameters_i);
//pirDriverRetVal_e pir_DriverGetPinpirStatus(pirDriverPinParameters_s *pPinParameters_i);

void func(void);
