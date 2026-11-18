// Source exposure: binary-analysis; no external implementation source reused.
// Static178ab30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ab30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ab30*);
    virtual void release(Static178ab30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ab30*);
struct Static178ab30 {
    void* value;
    Static178ab30();
    ~Static178ab30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
