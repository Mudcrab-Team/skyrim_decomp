// Source exposure: binary-analysis; no external implementation source reused.
// Static178f580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f580*);
    virtual void release(Static178f580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f580*);
struct Static178f580 {
    void* value;
    Static178f580();
    ~Static178f580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
