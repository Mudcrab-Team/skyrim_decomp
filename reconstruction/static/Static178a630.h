// Source exposure: binary-analysis; no external implementation source reused.
// Static178a630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a630*);
    virtual void release(Static178a630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a630*);
struct Static178a630 {
    void* value;
    Static178a630();
    ~Static178a630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
