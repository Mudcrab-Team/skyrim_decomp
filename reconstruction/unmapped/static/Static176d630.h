// Source exposure: binary-analysis; no external implementation source reused.
// Static176d630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d630*);
    virtual void release(Static176d630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d630*);
struct Static176d630 {
    void* value;
    Static176d630();
    ~Static176d630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
