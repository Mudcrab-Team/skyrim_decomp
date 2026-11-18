// Source exposure: binary-analysis; no external implementation source reused.
// Static174d620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d620*);
    virtual void release(Static174d620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d620*);
struct Static174d620 {
    void* value;
    Static174d620();
    ~Static174d620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
