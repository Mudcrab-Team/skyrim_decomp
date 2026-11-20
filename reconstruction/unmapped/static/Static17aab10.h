// Source exposure: binary-analysis; no external implementation source reused.
// Static17aab10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aab10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aab10*);
    virtual void release(Static17aab10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aab10*);
struct Static17aab10 {
    void* value;
    Static17aab10();
    ~Static17aab10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
