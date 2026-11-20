// Source exposure: binary-analysis; no external implementation source reused.
// Static177df80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177df80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177df80*);
    virtual void release(Static177df80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177df80*);
struct Static177df80 {
    void* value;
    Static177df80();
    ~Static177df80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
