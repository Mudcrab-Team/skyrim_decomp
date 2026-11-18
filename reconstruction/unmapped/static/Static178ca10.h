// Source exposure: binary-analysis; no external implementation source reused.
// Static178ca10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ca10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ca10*);
    virtual void release(Static178ca10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ca10*);
struct Static178ca10 {
    void* value;
    Static178ca10();
    ~Static178ca10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
