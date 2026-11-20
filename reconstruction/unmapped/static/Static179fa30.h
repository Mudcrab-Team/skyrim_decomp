// Source exposure: binary-analysis; no external implementation source reused.
// Static179fa30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179fa30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179fa30*);
    virtual void release(Static179fa30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179fa30*);
struct Static179fa30 {
    void* value;
    Static179fa30();
    ~Static179fa30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
