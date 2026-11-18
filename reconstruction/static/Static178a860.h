// Source exposure: binary-analysis; no external implementation source reused.
// Static178a860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a860*);
    virtual void release(Static178a860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a860*);
struct Static178a860 {
    void* value;
    Static178a860();
    ~Static178a860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
