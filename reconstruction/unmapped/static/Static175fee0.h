// Source exposure: binary-analysis; no external implementation source reused.
// Static175fee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fee0*);
    virtual void release(Static175fee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fee0*);
struct Static175fee0 {
    void* value;
    Static175fee0();
    ~Static175fee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
