// Source exposure: binary-analysis; no external implementation source reused.
// Static176a570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a570*);
    virtual void release(Static176a570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a570*);
struct Static176a570 {
    void* value;
    Static176a570();
    ~Static176a570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
