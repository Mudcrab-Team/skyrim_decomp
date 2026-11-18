// Source exposure: binary-analysis; no external implementation source reused.
// Static178b8b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178b8b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178b8b0*);
    virtual void release(Static178b8b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178b8b0*);
struct Static178b8b0 {
    void* value;
    Static178b8b0();
    ~Static178b8b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
