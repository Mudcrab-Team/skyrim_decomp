// Source exposure: binary-analysis; no external implementation source reused.
// Static175ada0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ada0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ada0*);
    virtual void release(Static175ada0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ada0*);
struct Static175ada0 {
    void* value;
    Static175ada0();
    ~Static175ada0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
