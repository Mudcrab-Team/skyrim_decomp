// Source exposure: binary-analysis; no external implementation source reused.
// Static178cce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cce0*);
    virtual void release(Static178cce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cce0*);
struct Static178cce0 {
    void* value;
    Static178cce0();
    ~Static178cce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
