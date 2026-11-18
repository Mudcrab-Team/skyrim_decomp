// Source exposure: binary-analysis; no external implementation source reused.
// Static176a070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a070*);
    virtual void release(Static176a070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a070*);
struct Static176a070 {
    void* value;
    Static176a070();
    ~Static176a070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
