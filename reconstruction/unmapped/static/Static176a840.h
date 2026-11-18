// Source exposure: binary-analysis; no external implementation source reused.
// Static176a840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a840*);
    virtual void release(Static176a840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a840*);
struct Static176a840 {
    void* value;
    Static176a840();
    ~Static176a840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
