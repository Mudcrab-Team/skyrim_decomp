// Source exposure: binary-analysis; no external implementation source reused.
// Static174bf10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bf10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bf10*);
    virtual void release(Static174bf10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bf10*);
struct Static174bf10 {
    void* value;
    Static174bf10();
    ~Static174bf10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
