// Source exposure: binary-analysis; no external implementation source reused.
// Static176bd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bd80*);
    virtual void release(Static176bd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bd80*);
struct Static176bd80 {
    void* value;
    Static176bd80();
    ~Static176bd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
