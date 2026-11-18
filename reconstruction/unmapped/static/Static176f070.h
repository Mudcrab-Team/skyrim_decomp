// Source exposure: binary-analysis; no external implementation source reused.
// Static176f070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f070*);
    virtual void release(Static176f070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f070*);
struct Static176f070 {
    void* value;
    Static176f070();
    ~Static176f070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
