// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFunction_vtbl; size 0xa8
#pragma once

#include "CallResult.h"
#include "FunctionType.h"
struct IFunction_vtbl {
    void (*_dtor_IFunction)(void);
    char32_t*(*GetName)(void);
    char32_t*(*GetObjectTypeName)(void);
    char32_t*(*GetStateName)(void);
    void (*GetReturnType)(void);
    unsigned int (*GetParamCount)(void);
    void (*GetParam)(unsigned int, char32_t* , char32_t* );
    unsigned int (*GetStackFrameSize)(void);
    bool (*GetIsNative)(void);
    bool (*GetIsStatic)(void);
    bool (*GetIsEmpty)(void);
    FunctionType (*GetFunctionType)(void);
    unsigned int (*GetUserFlags)(void);
    char32_t*(*GetDocString)(void);
    void (*InsertLocals)(char32_t* );
    CallResult (*Call)(char32_t* , char32_t* , char32_t* , bool);
    char32_t*(*GetSourceFilename)(void);
    bool (*TranslateIPToLineNumber)(unsigned int, unsigned int* );
    bool (*GetVarNameForStackIndex)(unsigned int, char32_t* );
    bool (*CanBeCalledFromTasklets)(void);
    void (*SetCallableFromTasklets)(bool);
};
static_assert(sizeof(IFunction_vtbl) == 168, "IFunction_vtbl layout differs from the PDB");
