// Source exposure: binary-analysis; no external implementation source reused.
// Static176fe80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fe80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fe80*);
    virtual void release(Static176fe80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fe80*);
struct Static176fe80 {
    void* value;
    Static176fe80();
    ~Static176fe80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
