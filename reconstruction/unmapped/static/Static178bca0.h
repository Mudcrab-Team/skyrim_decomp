// Source exposure: binary-analysis; no external implementation source reused.
// Static178bca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bca0*);
    virtual void release(Static178bca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bca0*);
struct Static178bca0 {
    void* value;
    Static178bca0();
    ~Static178bca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
