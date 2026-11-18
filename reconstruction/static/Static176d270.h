// Source exposure: binary-analysis; no external implementation source reused.
// Static176d270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d270*);
    virtual void release(Static176d270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d270*);
struct Static176d270 {
    void* value;
    Static176d270();
    ~Static176d270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
