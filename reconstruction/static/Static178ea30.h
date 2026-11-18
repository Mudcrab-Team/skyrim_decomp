// Source exposure: binary-analysis; no external implementation source reused.
// Static178ea30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ea30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ea30*);
    virtual void release(Static178ea30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ea30*);
struct Static178ea30 {
    void* value;
    Static178ea30();
    ~Static178ea30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
