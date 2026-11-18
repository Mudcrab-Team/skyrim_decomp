// Source exposure: binary-analysis; no external implementation source reused.
// Static176db80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176db80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176db80*);
    virtual void release(Static176db80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176db80*);
struct Static176db80 {
    void* value;
    Static176db80();
    ~Static176db80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
