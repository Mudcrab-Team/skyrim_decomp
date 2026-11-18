// Source exposure: binary-analysis; no external implementation source reused.
// Static178bde0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bde0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bde0*);
    virtual void release(Static178bde0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bde0*);
struct Static178bde0 {
    void* value;
    Static178bde0();
    ~Static178bde0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
