// Source exposure: binary-analysis; no external implementation source reused.
// Static178cdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cdd0*);
    virtual void release(Static178cdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cdd0*);
struct Static178cdd0 {
    void* value;
    Static178cdd0();
    ~Static178cdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
