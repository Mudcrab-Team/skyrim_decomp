// Source exposure: binary-analysis; no external implementation source reused.
// Static174d260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d260*);
    virtual void release(Static174d260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d260*);
struct Static174d260 {
    void* value;
    Static174d260();
    ~Static174d260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
