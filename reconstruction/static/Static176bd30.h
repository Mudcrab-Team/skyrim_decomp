// Source exposure: binary-analysis; no external implementation source reused.
// Static176bd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bd30*);
    virtual void release(Static176bd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bd30*);
struct Static176bd30 {
    void* value;
    Static176bd30();
    ~Static176bd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
