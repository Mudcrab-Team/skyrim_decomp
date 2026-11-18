// Source exposure: binary-analysis; no external implementation source reused.
// Static174ad50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ad50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ad50*);
    virtual void release(Static174ad50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ad50*);
struct Static174ad50 {
    void* value;
    Static174ad50();
    ~Static174ad50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
