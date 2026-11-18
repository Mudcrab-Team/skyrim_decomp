// Source exposure: binary-analysis; no external implementation source reused.
// Static178be30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178be30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178be30*);
    virtual void release(Static178be30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178be30*);
struct Static178be30 {
    void* value;
    Static178be30();
    ~Static178be30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
