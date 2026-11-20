// Source exposure: binary-analysis; no external implementation source reused.
// Static175eae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175eae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175eae0*);
    virtual void release(Static175eae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175eae0*);
struct Static175eae0 {
    void* value;
    Static175eae0();
    ~Static175eae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
