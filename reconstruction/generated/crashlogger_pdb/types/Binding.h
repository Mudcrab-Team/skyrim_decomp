// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Binding; size 0x28
#pragma once
struct Binding {
    unsigned int bindingPath;
    unsigned int pad04;
    unsigned int arrayElementSize;
    unsigned int padC;
    int memberOffset;
    int arrayElementOffset;
    unsigned int unk18;
    int variableIndex;
    unsigned char bitIndex;
    unsigned char bindingMode;  // BindingMode in the PDB is wider than this slot
    unsigned char memberType;
    unsigned char unk23;
    unsigned char flags;
    unsigned char unk25[3];
};
static_assert(sizeof(Binding) == 40, "Binding layout differs from the PDB");
