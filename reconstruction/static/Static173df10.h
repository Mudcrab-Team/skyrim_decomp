// Source exposure: binary-analysis; no external implementation source reused.
// Static173df10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173df10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173df10*);
    virtual void release(Static173df10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173df10*);
struct Static173df10 {
    void* value;
    Static173df10();
    ~Static173df10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
