// Source exposure: binary-analysis; no external implementation source reused.
// Static174fe00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fe00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fe00*);
    virtual void release(Static174fe00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fe00*);
struct Static174fe00 {
    void* value;
    Static174fe00();
    ~Static174fe00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
