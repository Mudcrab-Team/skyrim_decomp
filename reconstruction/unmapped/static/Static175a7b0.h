// Source exposure: binary-analysis; no external implementation source reused.
// Static175a7b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a7b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a7b0*);
    virtual void release(Static175a7b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a7b0*);
struct Static175a7b0 {
    void* value;
    Static175a7b0();
    ~Static175a7b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
