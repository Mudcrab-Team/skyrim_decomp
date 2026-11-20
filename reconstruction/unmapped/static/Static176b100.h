// Source exposure: binary-analysis; no external implementation source reused.
// Static176b100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b100*);
    virtual void release(Static176b100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b100*);
struct Static176b100 {
    void* value;
    Static176b100();
    ~Static176b100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
