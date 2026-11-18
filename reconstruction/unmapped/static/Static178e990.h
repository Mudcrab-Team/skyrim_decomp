// Source exposure: binary-analysis; no external implementation source reused.
// Static178e990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e990*);
    virtual void release(Static178e990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e990*);
struct Static178e990 {
    void* value;
    Static178e990();
    ~Static178e990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
