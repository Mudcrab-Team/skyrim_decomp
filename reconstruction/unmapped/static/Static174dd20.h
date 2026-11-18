// Source exposure: binary-analysis; no external implementation source reused.
// Static174dd20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dd20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dd20*);
    virtual void release(Static174dd20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dd20*);
struct Static174dd20 {
    void* value;
    Static174dd20();
    ~Static174dd20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
