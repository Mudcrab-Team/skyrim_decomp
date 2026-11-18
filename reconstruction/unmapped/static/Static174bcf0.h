// Source exposure: binary-analysis; no external implementation source reused.
// Static174bcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bcf0*);
    virtual void release(Static174bcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bcf0*);
struct Static174bcf0 {
    void* value;
    Static174bcf0();
    ~Static174bcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
