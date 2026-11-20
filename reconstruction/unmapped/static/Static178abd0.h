// Source exposure: binary-analysis; no external implementation source reused.
// Static178abd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178abd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178abd0*);
    virtual void release(Static178abd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178abd0*);
struct Static178abd0 {
    void* value;
    Static178abd0();
    ~Static178abd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
