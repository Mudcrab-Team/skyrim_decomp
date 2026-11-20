// Source exposure: binary-analysis; no external implementation source reused.
// Static178dad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178dad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178dad0*);
    virtual void release(Static178dad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178dad0*);
struct Static178dad0 {
    void* value;
    Static178dad0();
    ~Static178dad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
