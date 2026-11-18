// Source exposure: binary-analysis; no external implementation source reused.
// Static178ad10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ad10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ad10*);
    virtual void release(Static178ad10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ad10*);
struct Static178ad10 {
    void* value;
    Static178ad10();
    ~Static178ad10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
