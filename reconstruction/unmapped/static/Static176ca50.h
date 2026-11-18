// Source exposure: binary-analysis; no external implementation source reused.
// Static176ca50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ca50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ca50*);
    virtual void release(Static176ca50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ca50*);
struct Static176ca50 {
    void* value;
    Static176ca50();
    ~Static176ca50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
