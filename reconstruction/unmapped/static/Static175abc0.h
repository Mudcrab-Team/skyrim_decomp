// Source exposure: binary-analysis; no external implementation source reused.
// Static175abc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175abc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175abc0*);
    virtual void release(Static175abc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175abc0*);
struct Static175abc0 {
    void* value;
    Static175abc0();
    ~Static175abc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
