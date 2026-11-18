// Source exposure: binary-analysis; no external implementation source reused.
// Static178dc60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178dc60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178dc60*);
    virtual void release(Static178dc60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178dc60*);
struct Static178dc60 {
    void* value;
    Static178dc60();
    ~Static178dc60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
