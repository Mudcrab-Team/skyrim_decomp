// Source exposure: binary-analysis; no external implementation source reused.
// Static178a350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a350*);
    virtual void release(Static178a350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a350*);
struct Static178a350 {
    void* value;
    Static178a350();
    ~Static178a350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
