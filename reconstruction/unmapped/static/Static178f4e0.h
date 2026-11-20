// Source exposure: binary-analysis; no external implementation source reused.
// Static178f4e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f4e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f4e0*);
    virtual void release(Static178f4e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f4e0*);
struct Static178f4e0 {
    void* value;
    Static178f4e0();
    ~Static178f4e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
