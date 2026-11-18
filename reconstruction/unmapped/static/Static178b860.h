// Source exposure: binary-analysis; no external implementation source reused.
// Static178b860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178b860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178b860*);
    virtual void release(Static178b860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178b860*);
struct Static178b860 {
    void* value;
    Static178b860();
    ~Static178b860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
