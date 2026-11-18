// Source exposure: binary-analysis; no external implementation source reused.
// Static178e010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e010*);
    virtual void release(Static178e010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e010*);
struct Static178e010 {
    void* value;
    Static178e010();
    ~Static178e010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
