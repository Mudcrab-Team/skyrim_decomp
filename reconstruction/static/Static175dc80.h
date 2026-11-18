// Source exposure: binary-analysis; no external implementation source reused.
// Static175dc80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dc80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dc80*);
    virtual void release(Static175dc80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dc80*);
struct Static175dc80 {
    void* value;
    Static175dc80();
    ~Static175dc80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
