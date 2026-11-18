// Source exposure: binary-analysis; no external implementation source reused.
// Static178fcb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178fcb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178fcb0*);
    virtual void release(Static178fcb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178fcb0*);
struct Static178fcb0 {
    void* value;
    Static178fcb0();
    ~Static178fcb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
