// Source exposure: binary-analysis; no external implementation source reused.
// Static176ae30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ae30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ae30*);
    virtual void release(Static176ae30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ae30*);
struct Static176ae30 {
    void* value;
    Static176ae30();
    ~Static176ae30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
