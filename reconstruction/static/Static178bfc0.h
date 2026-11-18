// Source exposure: binary-analysis; no external implementation source reused.
// Static178bfc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bfc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bfc0*);
    virtual void release(Static178bfc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bfc0*);
struct Static178bfc0 {
    void* value;
    Static178bfc0();
    ~Static178bfc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
