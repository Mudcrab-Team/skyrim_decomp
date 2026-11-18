// Source exposure: binary-analysis; no external implementation source reused.
// Static176b830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b830*);
    virtual void release(Static176b830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b830*);
struct Static176b830 {
    void* value;
    Static176b830();
    ~Static176b830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
