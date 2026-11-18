// Source exposure: binary-analysis; no external implementation source reused.
// Static175dcd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dcd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dcd0*);
    virtual void release(Static175dcd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dcd0*);
struct Static175dcd0 {
    void* value;
    Static175dcd0();
    ~Static175dcd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
