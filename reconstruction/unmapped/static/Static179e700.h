// Source exposure: binary-analysis; no external implementation source reused.
// Static179e700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e700*);
    virtual void release(Static179e700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e700*);
struct Static179e700 {
    void* value;
    Static179e700();
    ~Static179e700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
