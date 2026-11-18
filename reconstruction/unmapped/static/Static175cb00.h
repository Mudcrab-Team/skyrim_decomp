// Source exposure: binary-analysis; no external implementation source reused.
// Static175cb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cb00*);
    virtual void release(Static175cb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cb00*);
struct Static175cb00 {
    void* value;
    Static175cb00();
    ~Static175cb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
