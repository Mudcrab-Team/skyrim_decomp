// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IVirtualMachine_vtbl; size 0x1b0
#pragma once

#include "RawType.h"
#include "Severity.h"
struct IVirtualMachine_vtbl {
    void (*_dtor_IVirtualMachine)(void);
    void (*SetLinkedCallback)(char32_t* );
    void (*TraceStack)(unsigned char* , char32_t* , Severity);
    void (*FormatAndPostMessage)(unsigned char* , Severity);
    void (*Update)(float);
    void (*UpdateTasklets)(float);
    void (*SetOverstressed)(bool);
    bool (*IsCompletelyFrozen)(void);
    bool (*RegisterObjectType)(char32_t* , unsigned char* );
    bool (*GetScriptObjectType1)(char32_t* , char32_t* );
    bool (*GetScriptObjectType2)(char32_t* , char32_t* );
    bool (*GetScriptObjectTypeNoLoad1)(char32_t* , char32_t* );
    bool (*GetScriptObjectTypeNoLoad2)(char32_t* , char32_t* );
    bool (*GetTypeIDForScriptObject)(char32_t* , char32_t* );
    void (*GetScriptObjectsWithATypeID)(char32_t* );
    bool (*GetParentNativeType)(char32_t* , char32_t* );
    bool (*TypeIsValid)(char32_t* );
    bool (*ReloadType)(unsigned char* );
    void (*TasksToJobs)(char32_t* );
    void (*CalculateFullReloadList)(void);
    bool (*CreateObject1)(char32_t* , void* , char32_t* );
    bool (*CreateObject2)(char32_t* , char32_t* );
    bool (*CreateArray1)(char32_t* , unsigned int, char32_t* );
    bool (*CreateArray2)(RawType, char32_t* , unsigned int, char32_t* );
    bool (*BindNativeMethod)(char32_t* );
    void (*SetCallableFromTasklets1)(unsigned char* , unsigned char* , unsigned char* , bool);
    void (*SetCallableFromTasklets2)(unsigned char* , unsigned char* , bool);
    void (*ForEachBoundObject)(char32_t* , char32_t* );
    bool (*FindBoundObject)(char32_t* , unsigned char* , char32_t* );
    void (*MoveBoundObjects)(char32_t* , char32_t* );
    void (*ResetAllBoundObjects)(char32_t* );
    bool (*CastObject)(char32_t* , char32_t* , char32_t* );
    bool (*SetPropertyValue)(char32_t* , unsigned char* , char32_t* );
    bool (*GetPropertyValue)(char32_t* , unsigned char* , char32_t* );
    bool (*GetVariableValue1)(char32_t* , unsigned int, char32_t* );
    bool (*GetVariableValue2)(char32_t* , char32_t* , int, char32_t* );
    void (*SendEvent)(char32_t* , char32_t* , char32_t* );
    void (*SendEventAll)(char32_t* , char32_t* );
    bool (*DispatchStaticCall)(char32_t* , char32_t* , char32_t* , char32_t* );
    bool (*DispatchMethodCall1)(char32_t* , char32_t* , char32_t* , char32_t* );
    bool (*DispatchMethodCall2)(char32_t* , char32_t* , char32_t* , char32_t* , char32_t* );
    bool (*DispatchUnboundMethodCall)(void);
    bool (*IsWaitingOnLatent)(char32_t* );
    void (*ReturnFromLatent)(char32_t* , char32_t* );
    char32_t*(*GetErrorLogger)(void);
    char32_t*(*GetObjectHandlePolicy1)(void);
    char32_t*(*GetObjectHandlePolicy2)(void);
    char32_t*(*GetObjectBindPolicy1)(void);
    char32_t*(*GetObjectBindPolicy2)(void);
    char32_t*(*GetSavePatcherInterface)(void);
    void (*RegisterForLogEvent)(char32_t* );
    void (*UnregisterForLogEvent)(char32_t* );
    void (*RegisterForStatsEvent)(char32_t* );
    void (*UnregisterForStatsEvent)(char32_t* );
};
static_assert(sizeof(IVirtualMachine_vtbl) == 432, "IVirtualMachine_vtbl layout differs from the PDB");
