// Source exposure: binary-analysis; no external implementation source reused.
// Static175fad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fad0*);
    virtual void release(Static175fad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fad0*);
struct Static175fad0 {
    void* value;
    Static175fad0();
    ~Static175fad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
