// Source exposure: binary-analysis; no external implementation source reused.
// Static175eea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175eea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175eea0*);
    virtual void release(Static175eea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175eea0*);
struct Static175eea0 {
    void* value;
    Static175eea0();
    ~Static175eea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
