// Source exposure: binary-analysis; no external implementation source reused.
// Static176db30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176db30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176db30*);
    virtual void release(Static176db30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176db30*);
struct Static176db30 {
    void* value;
    Static176db30();
    ~Static176db30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
