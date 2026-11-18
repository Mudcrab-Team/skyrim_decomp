// Source exposure: binary-analysis; no external implementation source reused.
// Static178ead0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ead0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ead0*);
    virtual void release(Static178ead0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ead0*);
struct Static178ead0 {
    void* value;
    Static178ead0();
    ~Static178ead0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
